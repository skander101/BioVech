#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "autohidedockwidget.h"
#include <QQuickWidget>
#include <QQmlContext>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QDate>
#include <QString>
#include <QRegularExpression>
#include <QInputDialog>
#include <QLineEdit>
#include <QtMath>
#include <QDialog>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QDialogButtonBox>
#include <QLabel>
#include <QHBoxLayout>
#include <QSqlDatabase>
#include <QSqlError>
#include <QTimer>
#include <QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), m_locationName(""), lastIdUsed(0), mapForAddEvent(false)
{
    ui->setupUi(this);
    QDockWidget *oldDockWidget = ui->dockWidget;
    QList<QStringList> data = Etmp.ListEvent();
    QStringList head;
    serial=new QSerialPort(this);
    connect(serial,&QSerialPort::readyRead,this,&MainWindow::readSerial);


    head << "Id" << "Title" << "Sponsor" << "Description" << "Date" << "Type" << "Position";
    ui->tableWidget->setHorizontalHeaderLabels(head);

    // Find the maximum ID from existing events
    lastIdUsed = 0;
    for(int r=0; r < data.size(); r++){
        const QStringList& rowData=data[r];
        if (!rowData.isEmpty()) {
            bool ok;
            int currentId = rowData[0].toInt(&ok);
            if (ok && currentId > lastIdUsed) {
                lastIdUsed = currentId;
            }
        }

        for(int c=0;c<rowData.size();c++){
            QTableWidgetItem* item= new QTableWidgetItem(rowData[c]);
            ui->tableWidget->setItem(r,c,item);
            item->setTextAlignment(Qt::AlignCenter);
        }
    }

    qDebug() << "Initialized lastIdUsed to:" << lastIdUsed;
    connect(ui->tableWidget, &QTableWidget::cellClicked, this, &MainWindow::on_tableWidget_cellClicked);
    connect(ui->Search_Button, &QPushButton::clicked, this, &MainWindow::on_Search_Button_clicked);


    // Connect to our new Suggestions button
    if (ui->Suggestions_Button) {
        connect(ui->Suggestions_Button, &QPushButton::clicked, this, &MainWindow::on_Suggestions_Button_clicked);
    }

    ui->AlineEdit->setReadOnly(true);
    ui->AlineEdit_2->setPlaceholderText("Enter the title of the Event (3 characters at least)");
    ui->AlineEdit_3->setPlaceholderText("Set Sponsor Name(3 characters at least)");
    ui->AlineEdit_7->setPlaceholderText("Enter the PlusCode here(plusCode format : string + string)");
    ui->AlineEdit_2->setPlaceholderText("Enter the title of the Event (3 characters at least)");
    ui->AlineEdit_3->setPlaceholderText("Set Sponsor Name(3 characters at least)");
    ui->AlineEdit_7->setPlaceholderText("Enter the PlusCode here (PlusCode format example:9C4X+J5.)");
    ui->AlineEdit_4->setPlaceholderText("Enter the Description (3 characters at least)");
    ui->AlineEdit_4->setPlaceholderText("Enter the Description (3 characters at least)");


    // REMOVE the code that creates duplicate map buttons
    // We'll use the ones already defined in the UI file

    // Find the existing buttons and connect them directly
    QPushButton* addEventMapButton = ui->Add_Event->findChild<QPushButton*>("positionMapButton");
    if (addEventMapButton) {
        // Connect the button click signal to our slot
        bool connected = connect(addEventMapButton, &QPushButton::clicked, this, &MainWindow::on_positionMapButton_clicked);

        // Debug connection status
        if (!connected) {
            qDebug() << "ERROR: Failed to connect Add Event map button clicked signal!";
        } else {
            qDebug() << "Successfully connected Add Event map button clicked signal";
        }
    } else {
        qDebug() << "WARNING: Could not find positionMapButton in AddEvent tab";
    }

    // Similarly connect the update tab button
    QPushButton* updateEventMapButton = ui->Modify_Event->findChild<QPushButton*>("updatePositionMapButton");
    if (updateEventMapButton) {
        // Connect the button click signal
        bool connected = connect(updateEventMapButton, &QPushButton::clicked, this, &MainWindow::on_updatePositionMapButton_clicked);

        // Debug connection status
        if (!connected) {
            qDebug() << "ERROR: Failed to connect Update Event map button clicked signal!";
        } else {
            qDebug() << "Successfully connected Update Event map button clicked signal";
        }
    } else {
        qDebug() << "WARNING: Could not find updatePositionMapButton in ModifyEvent tab";
    }

    if (oldDockWidget) {
        // Create the custom AutoHideDockWidget
        AutoHideDockWidget *autoHideDockWidget = new AutoHideDockWidget(this);

        // Preserve the dock widget features (closable, movable, etc.)
        autoHideDockWidget->setFeatures(oldDockWidget->features());

        // Set the original widget inside the new dock widget
        autoHideDockWidget->setWidget(oldDockWidget->widget());

        // Remove the old dock widget from the UI
        removeDockWidget(oldDockWidget);
        oldDockWidget->setParent(nullptr);
        delete oldDockWidget; // Clean up the old dock widget

        // Add the new AutoHideDockWidget to the correct area
        addDockWidget(Qt::LeftDockWidgetArea, autoHideDockWidget);

        // Set the UI reference to the new dock widget (if needed)
        ui->dockWidget = autoHideDockWidget;
    }

    // Load QML map for main tab
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/Maps/QmlMap.qml")));
    ui->quickWidget->hide();

    // Initialize quickWidget_Add for use in the map dialog
    quickWidget_Add = new QQuickWidget();
    quickWidget_Add->setSource(QUrl(QStringLiteral("qrc:/Maps/QmlMap.qml")));
    //sendFirstEventToArduino();

    // Expose MainWindow to QML
    ui->quickWidget->rootContext()->setContextProperty("mainWindow", this);
    quickWidget_Add->rootContext()->setContextProperty("mainWindow", this);

    // Connect signals and slots
    auto rootObject = ui->quickWidget->rootObject();
    if (rootObject) {
        connect(this, &MainWindow::centerChanged, [this, rootObject](double latitude, double longitude) {
            QMetaObject::invokeMethod(rootObject, "setCenter",
                                      Q_ARG(QVariant, latitude),
                                      Q_ARG(QVariant, longitude));
        });

        connect(this, &MainWindow::locationMarkingChanged, [this, rootObject](double latitude, double longitude, const QString &name) {
            QMetaObject::invokeMethod(rootObject, "addMarker",
                                      Q_ARG(QVariant, latitude),
                                      Q_ARG(QVariant, longitude),
                                      Q_ARG(QVariant, name));
        });
    }

    // Connect signals and slots for position selection map
    auto addRootObject = quickWidget_Add->rootObject();
    if (addRootObject) {
        connect(this, &MainWindow::centerChanged, [this, addRootObject](double latitude, double longitude) {
            QMetaObject::invokeMethod(addRootObject, "setCenter",
                                      Q_ARG(QVariant, latitude),
                                      Q_ARG(QVariant, longitude));
        });

        connect(this, &MainWindow::locationMarkingChanged, [this, addRootObject](double latitude, double longitude, const QString &name) {
            QMetaObject::invokeMethod(addRootObject, "addMarker",
                                      Q_ARG(QVariant, latitude),
                                      Q_ARG(QVariant, longitude),
                                      Q_ARG(QVariant, name));
        });
    }

    // Center the map on an initial location
    setCenter(36.89814947073016, 10.18958015196325);
    setLocationMarking(36.89814947073016, 10.18958015196325, "ByteBuilders");

    // Add this to the constructor after the existing connect calls
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &MainWindow::onTabChanged);

    // Manual connections for buttons that weren't being connected automatically
    // Don't try to directly access Save_Add through ui pointer since it doesn't exist in the UI file
    QPushButton* saveAddButton = ui->Add_Event->findChild<QPushButton*>("pushButton");
    if (saveAddButton) {
        qDebug() << "Found Save button using findChild with name 'pushButton'";
        connect(saveAddButton, &QPushButton::clicked, this, &MainWindow::on_Save_Add_clicked);
    } else {
        qDebug() << "Looking for button by text...";

        // Try to find all buttons in the AddEvent tab
        QList<QPushButton*> buttons = ui->Add_Event->findChildren<QPushButton*>();
        qDebug() << "Found" << buttons.size() << "buttons in AddEvent tab";

        bool buttonFound = false;
        for (QPushButton* button : buttons) {
            qDebug() << "Button text:" << button->text();

            // Check if the button text indicates it's a save/add button
            if (button->text().contains("Save", Qt::CaseInsensitive) ||
                button->text().contains("Add", Qt::CaseInsensitive) ||
                button->text().contains("Create", Qt::CaseInsensitive) ||
                button->objectName().contains("Save", Qt::CaseInsensitive)) {

                qDebug() << "Found a likely Save button:" << button->text() << "with name:" << button->objectName();
                connect(button, &QPushButton::clicked, this, &MainWindow::on_Save_Add_clicked);
                buttonFound = true;
            }
        }

        if (!buttonFound) {
            qDebug() << "ERROR: Could not find any Save button in the AddEvent tab!";

            // Create a new save button if one doesn't exist
            QPushButton* newSaveButton = new QPushButton("Save Event", ui->Add_Event);
            newSaveButton->setObjectName("saveEventButton");
            newSaveButton->move(300, 550); // Position it somewhere visible
            newSaveButton->show();
            connect(newSaveButton, &QPushButton::clicked, this, &MainWindow::on_Save_Add_clicked);
            qDebug() << "Created a new Save button since none was found";
        }
    }


    if (ui->Cancel_Modify) {
        connect(ui->Cancel_Modify, &QPushButton::clicked, this, &MainWindow::on_Cancel_Modify_clicked);
    }

    // Add this after the other button connection code
    // Try to find and connect any map buttons
    QList<QPushButton*> allButtons = this->findChildren<QPushButton*>();
    for (QPushButton* button : allButtons) {
        if (button->objectName() == "pushButton_5" ||
            button->text().contains("Map", Qt::CaseInsensitive) ||
            button->text().contains("Show", Qt::CaseInsensitive)) {

            qDebug() << "Found potential map button:" << button->objectName() << "with text:" << button->text();
            connect(button, &QPushButton::clicked, this, &MainWindow::showMapInMainTab);
        }
    }
}

MainWindow::~MainWindow()
{
    sendFirstEventToArduino();
    if(serial->isOpen()) {
        serial->close();
    }

    if (mapDialog) {
        delete mapDialog;
        mapDialog = nullptr;
    }
    delete ui;
}
// Getters
double MainWindow::latitude() const
{
    return m_userLatitude;
}

double MainWindow::longitude() const
{
    return m_userLongitude;
}

QString MainWindow::locationName() const
{
    return m_locationName;
}

// Setters
void MainWindow::setLatitude(double latitude)
{
    if (m_userLatitude != latitude) {
        m_userLatitude = latitude;
        emit latitudeChanged();
    }
}

void MainWindow::setLongitude(double longitude)
{
    if (m_userLongitude != longitude) {
        m_userLongitude = longitude;
        emit longitudeChanged();
    }
}

void MainWindow::setLocationName(const QString &name)
{
    if (m_locationName != name) {
        m_locationName = name;
        emit locationNameChanged();
    }
}

// Méthode pour centrer la carte
void MainWindow::setCenter(double latitude, double longitude)
{
    setLatitude(latitude);
    setLongitude(longitude);
    emit centerChanged(latitude, longitude);
}

// Méthode pour ajouter un marqueur
void MainWindow::setLocationMarking(double latitude, double longitude, const QString &name)
{
    m_userLatitude = latitude;
    m_userLongitude = longitude;
    m_locationName = name;

    // Update position field in AddEvent tab
    QString plusCode = generatePlusCode(latitude, longitude);
    ui->AlineEdit_7->setText(plusCode);

    emit locationMarkingChanged(latitude, longitude, name);
}




void MainWindow::on_Button_Patient_pressed()
{
    QPushButton *button=ui->Button_Patient;
    QString normalStyle="color:rgb(30,143,83);background-color:rgb(255,255,255)";
    QString invertedStyle="color:rgb(255,255,255);background-color:rgb(30,143,83)";
    static bool isInverted=false;
    if(isInverted){
        button->setStyleSheet(normalStyle);

    }else{
        button->setStyleSheet(invertedStyle);
    }

    isInverted=!isInverted;
}


void MainWindow::on_Button_Vac_pressed()
{
    QPushButton *button=ui->Button_Vac;
    QString normalStyle="color:rgb(30,143,83);background-color:rgb(255,255,255)";
    QString invertedStyle="color:rgb(255,255,255);background-color:rgb(30,143,83)";
    static bool isInverted=false;
    if(isInverted){
        button->setStyleSheet(normalStyle);

    }else{
        button->setStyleSheet(invertedStyle);
    }

    isInverted=!isInverted;
}


void MainWindow::on_Button_Staff_pressed()
{
    QPushButton *button=ui->Button_Staff;
    QString normalStyle="color:rgb(30,143,83);background-color:rgb(255,255,255)";
    QString invertedStyle="color:rgb(255,255,255);background-color:rgb(30,143,83)";
    static bool isInverted=false;
    if(isInverted){
        button->setStyleSheet(normalStyle);

    }else{
        button->setStyleSheet(invertedStyle);
    }

    isInverted=!isInverted;
}



void MainWindow::on_Button_Inventory_pressed()
{
    QPushButton *button=ui->Button_Inventory;
    QString normalStyle="color:rgb(30,143,83);background-color:rgb(255,255,255)";
    QString invertedStyle="color:rgb(255,255,255);background-color:rgb(30,143,83)";
    static bool isInverted=false;
    if(isInverted){
        button->setStyleSheet(normalStyle);

    }else{
        button->setStyleSheet(invertedStyle);
    }

    isInverted=!isInverted;

}


void MainWindow::on_Button_Events_pressed()
{
    QPushButton *button=ui->Button_Events;
    QString normalStyle="color:rgb(30,143,83);background-color:rgb(255,255,255)";
    QString invertedStyle="color:rgb(255,255,255);background-color:rgb(30,143,83)";
    static bool isInverted=false;
    if(isInverted){
        button->setStyleSheet(normalStyle);

    }else{
        button->setStyleSheet(invertedStyle);
    }

    isInverted=!isInverted;

}


void MainWindow::on_Button_Appoitment_pressed()
{
    QPushButton *button=ui->Button_Appoitment;
    QString normalStyle="color:rgb(30,143,83);background-color:rgb(255,255,255)";
    QString invertedStyle="color:rgb(255,255,255);background-color:rgb(30,143,83)";
    static bool isInverted=false;
    if(isInverted){
        button->setStyleSheet(normalStyle);

    }else{
        button->setStyleSheet(invertedStyle);
    }

    isInverted=!isInverted;

}


void MainWindow::on_Button_Analytics_pressed()
{
    QPushButton *button=ui->Button_Analytics;
    QString normalStyle="color:rgb(30,143,83);background-color:rgb(255,255,255)";
    QString invertedStyle="color:rgb(255,255,255);background-color:rgb(30,143,83)";
    static bool isInverted=false;
    if(isInverted){
        button->setStyleSheet(normalStyle);

    }else{
        button->setStyleSheet(invertedStyle);
    }

    isInverted=!isInverted;
}







void MainWindow::on_pushButton_5_clicked()
{
    // This method shows the map in the main tab
    showMapInMainTab();
    showNearbyEvents(m_userLatitude, m_userLongitude, 0.0); // Appel sans rayon
}


// Add this new method to handle showing the map without depending on specific button names
void MainWindow::showMapInMainTab()
{
    if (ui->quickWidget) {
        ui->quickWidget->setVisible(true);
    }
}




/*void MainWindow::on_pushButton_7_clicked()
{
    QString Title=ui->lineEdit->text();
    QString Sponsor=ui->lineEdit_2->text();
    if (Title.isEmpty() || Sponsor.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields.");
        return;
    }
    QSqlQuery query;
    query.prepare("INSERT INTO patient (email, password) VALUES (:email, :password)");
    query.bindValue(":email", Title);
    query.bindValue(":password", Sponsor);

    // Execute the query
    if (query.exec()) {
        QMessageBox::information(this, "Success", "Data inserted successfully!");
    } else {
        QMessageBox::critical(this, "Error", "Failed to insert data: ");
    }
}*/



void MainWindow::on_Add_Event_clicked()
{
    int id = ui->AlineEdit->text().toInt();
    QString title = ui->AlineEdit_2->text();
    QString sponsor = ui->AlineEdit_3->text();
    QString description = ui->AlineEdit_4->toPlainText();
    QString date = ui->AlineEdit_5->date().toString("dd/MM/yyyy");
    QString type = ui->AlineEdit_6->currentText();
    QString position = ui->AlineEdit_7->text();
    if (!Control(title, sponsor, description, ui->AlineEdit_5->date(), type, position)) {
        return;
    }
    Evenement event(id,title.toStdString(),sponsor.toStdString(),description.toStdString(),type.toStdString(),position.toStdString(),ui->AlineEdit_5->date());
    bool success=event.addEvent();
    if(success){
        QMessageBox::information(this, "Success", "Event Added successfully!");
        refresh_table();
    }else{
        QMessageBox::warning(this, "Failed", "Failed to Add the event! Please check the data and try again.");
    }
}



void MainWindow::on_Delete_Event_clicked()
{
    int id=ui->AlineEdit->text().toInt();
    bool test=Etmp.DeleteEvent(id);
    if(test){
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);
        refresh_table();
        ui->tabWidget->setCurrentIndex(0);
        QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Deleted Succesfully\n""Click Cancel to exit"),QMessageBox::Cancel);

    }else{

        QMessageBox::critical(nullptr, QObject::tr("Not OK"), QObject::tr("Failed !\n""Click Cancel to exit."),QMessageBox::Cancel);
    }
}



void MainWindow::on_Modify_Event_clicked()
{
    int id = ui->AlineEdit->text().toInt();
    QString title = ui->AlineEdit_2->text();
    QString sponsor = ui->AlineEdit_3->text();
    QString description = ui->AlineEdit_4->toPlainText();
    QString date = ui->AlineEdit_5->date().toString("dd/MM/yyyy");
    QString type = ui->AlineEdit_6->currentText();
    QString position = ui->AlineEdit_7->text();

    // Validate the data
    if (!Control(title, sponsor, description, ui->AlineEdit_5->date(), type, position)) {
        return;
    }

    // Create event object with std::string conversions
    Evenement event(id,
                    title.toStdString(),
                    sponsor.toStdString(),
                    description.toStdString(),
                    type.toStdString(),
                    position.toStdString(),
                    ui->AlineEdit_5->date());

    // Try to modify the event
    bool success = event.modifyEvent(id);

    if (success) {
        QMessageBox::information(this, "Success", "Event updated successfully!");
        ui->tabWidget->setCurrentIndex(0);
        refresh_table();
    } else {
        QMessageBox::warning(this, "Failed", "Failed to update the event! Please check the data and try again.");
    }
}


void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    QTableWidgetItem* clickedItem = ui->tableWidget->item(row, column);
    if (!clickedItem || clickedItem->text().isEmpty()) {
        return;
    }

    // Récupération des données
    QString id = ui->tableWidget->item(row, 0)->text();
    QString titre = ui->tableWidget->item(row, 1)->text();
    QString sponsor = ui->tableWidget->item(row, 2)->text();
    QString description = ui->tableWidget->item(row, 3)->text();
    QString dateStr = ui->tableWidget->item(row, 4)->text();
    QString type = ui->tableWidget->item(row, 5)->text();
    QString pos = ui->tableWidget->item(row, 6)->text();

    // Conversion de la date
    QDate eventDate = QDate::fromString(dateStr, "dd/MM/yyyy");

    // Utilisation de votre fonction Control pour valider
    if (!Control(titre, sponsor, description, eventDate, type, pos)) {
        QMessageBox::warning(this, "Erreur", "La date de l'événement est invalide");
        return;
    }

    // Mise à jour de l'interface
    ui->AlineEdit->setText(id);
    ui->AlineEdit_2->setText(titre);
    ui->AlineEdit_3->setText(sponsor);
    ui->AlineEdit_4->setPlainText(description);
    ui->AlineEdit_5->setDate(eventDate);
    ui->AlineEdit_6->setEditText(type);
    ui->AlineEdit_7->setText(pos);

    selectedIdEv = id;

    // Mise à jour du calendrier avec votre validation
    if (eventDate.isValid()) {  // Double vérification pour la sécurité
        ui->calendarWidget->setSelectedDate(eventDate);
        ui->calendarWidget->setCurrentPage(eventDate.year(), eventDate.month());

        // Mise en surbrillance avec votre style
        QTextCharFormat highlightFormat;
        highlightFormat.setBackground(Qt::yellow);
        highlightFormat.setFontWeight(QFont::Bold);
        ui->calendarWidget->setDateTextFormat(eventDate, highlightFormat);
    }
}
void MainWindow::refresh_table() {
    // Clear the table first
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    // Get all events from database
    QList<QStringList> data = Etmp.ListEvent();

    // Set the row count to match the data
    ui->tableWidget->setRowCount(data.size());

    // Fill the table with event data
    for (int r = 0; r < data.size(); r++) {
        const QStringList& rowData = data[r];
        for (int c = 0; c < rowData.size() && c < ui->tableWidget->columnCount(); c++) {
            QTableWidgetItem* item = new QTableWidgetItem(rowData[c]);
            item->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->setItem(r, c, item);
        }
    }

    // Make sure we're showing the events tab
    ui->tabWidget->setCurrentIndex(0);
    if(arduino_is_available) {
        sendFirstEventToArduino();
    }
}
bool MainWindow::Control(const QString& titre, const QString& sponsor, const QString& description, const QDate& date, const QString& type, const QString& pos) {
    QRegularExpression alphanum(QRegularExpression("[A-Za-z0-9]{3,}"));
    if (titre.isEmpty() || !alphanum.match(titre).hasMatch() || titre.length() < 3) {
        QMessageBox::warning(this, "Input Error", "Title must at least contain 3 caracters, and no spaces or special caracters!");
        return false;
    }
    if (sponsor.isEmpty() || !alphanum.match(sponsor).hasMatch() || sponsor.length() < 3) {
        QMessageBox::warning(this, "Input Error", "Sponsor must at least contain 3 caracters, and no spaces or special caracters.");
        return false;
    }
    if (description.isEmpty() || !alphanum.match(description).hasMatch() || description.length() < 3) {
        QMessageBox::warning(this, "Input Error", "Description must at least contain 3 caracters, and no spaces or special caracters.");
        return false;
    }
    if (date.isNull() || !date.isValid()) {
        QMessageBox::warning(this, "Input Error", "Date is Invalid.");
        return false;
    }
    // Vérifie que la date est supérieure à la date actuelle
    if (date <= QDate::currentDate()) {
        QMessageBox::warning(this, "Input Error", "Date must be greater than the current date.");
        return false;
    }
    if (type.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Le Type can't be Empty.");
        return false;
    }
    QRegularExpression plusCode(QRegularExpression("[A-Za-z0-9]{4,6}\\+[A-Za-z0-9]{2,4}"));
    if (!pos.isEmpty() && !plusCode.match(pos).hasMatch()) {
        QMessageBox::warning(this, "Input Error", "Position format(PlusCode) is Invalid. valid format example : 9C4X+J5.");
        return false;
    }
    return true;
}

void MainWindow::clearInputFields(){
    ui->AlineEdit->clear();
    ui->AlineEdit_2->clear();
    ui->AlineEdit_3->clear();
    ui->AlineEdit_4->clear();
    ui->AlineEdit_5->setDateTime(QDateTime::currentDateTime());
    ui->AlineEdit_6->clear();
    ui->AlineEdit_7->clear();
}

void MainWindow::on_Cancel_Modify_clicked()
{
    clearInputFields();
}



void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    QList<QStringList> data=Etmp.ListEvent();
    if(arg1=="Date_Asc"){
        sort(data.begin(),data.end(),[](const QStringList &a, const QStringList &b){
            return a[4]<b[4];
        });
    }
    else if(arg1=="Date_Desc"){
        sort(data.begin(),data.end(),[](const QStringList &a, const QStringList &b){
            return a[4]>b[4];
        });
    }
    else if(arg1=="Type_Asc"){
        sort(data.begin(),data.end(),[](const QStringList &a, const QStringList &b){
            return a[5]<b[5];
        });
    }
    else if(arg1=="Type_Desc"){
        sort(data.begin(),data.end(),[](const QStringList &a, const QStringList &b){
            return a[5]>b[5];
        });
    }   else if(arg1=="Title_Asc"){
        sort(data.begin(),data.end(),[](const QStringList &a, const QStringList &b){
            return a[1]<b[1];
        });
    }
    else if(arg1=="Title_Desc"){
        sort(data.begin(),data.end(),[](const QStringList &a, const QStringList &b){
            return a[1]>b[1];
        });
    }
    else if(arg1=="Sponsor_Asc"){
        sort(data.begin(),data.end(),[](const QStringList &a, const QStringList &b){
            return a[2]<b[2];
        });
    }
    else if(arg1=="Sponsor_Desc"){
        sort(data.begin(),data.end(),[](const QStringList &a, const QStringList &b){
            return a[2]>b[2];
        });
    }
    update_table(data);
}
void MainWindow::update_table(const QList<QStringList>& data) {
    ui->tableWidget->clearContents(); // Effacer le contenu actuel du tableau
    ui->tableWidget->setRowCount(data.size()); // Définir le nombre de lignes

    for (int r = 0; r < data.size(); r++) {
        const QStringList& rowData = data[r];
        for (int c = 0; c < rowData.size(); c++) {
            QTableWidgetItem* item = new QTableWidgetItem(rowData[c]);
            item->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->setItem(r, c, item);
        }
    }
    ui->tabWidget->setCurrentIndex(0); // Assurez-vous que l'onglet correct est affiché
}

void MainWindow::on_Search_Button_clicked()
{
    Dialogue dial(this);
    connect(&dial, &QDialog::finished, this, &MainWindow::onDialogueFinished);
    dial.exec();
}
void MainWindow::onDialogueFinished(int result)
{

    if (result == QDialog::Accepted) {
        Dialogue *dialog = qobject_cast<Dialogue *>(sender());
        if (dialog) {
            QString searchText = dialog->getSearchText();
            QString searchCriteria = dialog->getSearchCriteria();
            QList<QStringList> data= Etmp.ListEvent();


            QList<QStringList> filteredData;
            for (int i = 0; i < data.size(); ++i) {
                const QStringList &row = data[i];
                if (searchCriteria == "Type" && row[5].contains(searchText, Qt::CaseInsensitive)) {
                    filteredData.append(row);
                } else if (searchCriteria == "Sponsor" && row[2].contains(searchText, Qt::CaseInsensitive)) {
                    filteredData.append(row);
                } else if (searchCriteria == "Title" && row[1].contains(searchText, Qt::CaseInsensitive)) {
                    filteredData.append(row);
                }
            }

            ui->tableWidget->setRowCount(0);
            for (int r = 0; r < filteredData.size(); ++r) {
                const QStringList &rowData = filteredData[r];
                ui->tableWidget->insertRow(r);
                for (int c = 0; c < rowData.size(); ++c) {
                    QTableWidgetItem *item = new QTableWidgetItem(rowData[c]);
                    ui->tableWidget->setItem(r, c, item);
                    item->setTextAlignment(Qt::AlignCenter);
                }
            }
        }
    } else {
        refresh_table();
    }
}


void MainWindow::on_pdf_Button_clicked()
{
    QString defaultPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/pdf/report.pdf";

    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "PDF Files (*.pdf)");
    if (fileName.isEmpty()) return;

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageOrientation(QPageLayout::Portrait);
    printer.setPageSize(QPageSize::A4);

    QPainter painter;
    if (!painter.begin(&printer)) {
        QMessageBox::critical(this, "Error", "Failed to initialize PDF writer");
        return;
    }

    // Layout parameters
    const int margin = 40;
    int currentY = margin;
    const int pageWidth = printer.pageRect(QPrinter::DevicePixel).width();
    const int availableWidth = pageWidth - 2 * margin;

    // Load and resize logo
    QPixmap logo(":/res/Logo.png");
    if (!logo.isNull()) {
        logo = logo.scaledToHeight(25, Qt::SmoothTransformation);
        painter.drawPixmap(margin, currentY, logo);
        currentY += logo.height() + 15;
    }

    // Main title
    painter.setPen(QColor(30, 143, 83));
    painter.setFont(QFont("Arial", 18, QFont::Bold));
    painter.drawText(margin, currentY, availableWidth, 40, Qt::AlignCenter, "Event Management Report");
    currentY += 50;

    // Events table
    const int columnCount = ui->tableWidget->columnCount()-1;
    const int columnWidth = availableWidth / columnCount;

    // Events table header
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 10, QFont::Bold));
    int currentX = margin;
    for (int col = 0; col < columnCount; ++col) {
        QString header = ui->tableWidget->horizontalHeaderItem(col)->text();
        painter.fillRect(currentX, currentY, columnWidth, 30, QColor(240, 240, 240));
        painter.drawRect(currentX, currentY, columnWidth, 30);
        painter.drawText(currentX, currentY, columnWidth, 30, Qt::AlignCenter, header);
        currentX += columnWidth;
    }
    currentY += 30;

    // Events table data
    painter.setFont(QFont("Arial", 9));
    const int rowHeight = 25;
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        if (currentY + rowHeight > printer.pageRect(QPrinter::DevicePixel).height() - margin) {
            printer.newPage();
            currentY = margin;
        }

        currentX = margin;
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem* item = ui->tableWidget->item(row, col);
            QString text = item ? item->text() : "";
            painter.drawRect(currentX, currentY, columnWidth, rowHeight);
            painter.drawText(currentX, currentY, columnWidth, rowHeight, Qt::AlignCenter, text);
            currentX += columnWidth;
        }
        currentY += rowHeight;
    }

    currentY += 40;

    // Statistics section
    painter.setPen(QColor(30, 143, 83));
    painter.setFont(QFont("Arial", 14, QFont::Bold));
    painter.drawText(margin, currentY, availableWidth, 25, Qt::AlignLeft, "Event Statistics");
    currentY += 30;

    // Calculate statistics (same as in )
    QList<QStringList> data = Etmp.ListEvent();
    QMap<QString, int> eventCountByType;
    for (const QStringList& rowData : data) {
        if (rowData.size() > 5) {
            QString eventType = rowData[5];
            eventCountByType[eventType]++;
        }
    }

    // Statistics table header
    const int statColWidth = availableWidth / 2;
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 10, QFont::Bold));

    painter.fillRect(margin, currentY, statColWidth, 30, QColor(240, 240, 240));
    painter.drawRect(margin, currentY, statColWidth, 30);
    painter.drawText(margin, currentY, statColWidth, 30, Qt::AlignCenter, "Event Type");

    painter.fillRect(margin + statColWidth, currentY, statColWidth, 30, QColor(240, 240, 240));
    painter.drawRect(margin + statColWidth, currentY, statColWidth, 30);
    painter.drawText(margin + statColWidth, currentY, statColWidth, 30, Qt::AlignCenter, "Count");

    currentY += 30;

    // Statistics table data
    painter.setFont(QFont("Arial", 9));
    for (auto it = eventCountByType.begin(); it != eventCountByType.end(); ++it) {
        if (currentY + rowHeight > printer.pageRect(QPrinter::DevicePixel).height() - margin) {
            printer.newPage();
            currentY = margin;
        }

        painter.drawRect(margin, currentY, statColWidth, rowHeight);
        painter.drawText(margin, currentY, statColWidth, rowHeight, Qt::AlignCenter, it.key());

        painter.drawRect(margin + statColWidth, currentY, statColWidth, rowHeight);
        painter.drawText(margin + statColWidth, currentY, statColWidth, rowHeight, Qt::AlignCenter, QString::number(it.value()));

        currentY += rowHeight;
    }

    // Total events row
    currentY += 10;
    painter.setFont(QFont("Arial", 10, QFont::Bold));
    painter.drawText(margin, currentY, statColWidth, rowHeight, Qt::AlignRight, "Total Events:");
    painter.drawText(margin + statColWidth, currentY, statColWidth, rowHeight, Qt::AlignCenter, QString::number(data.size()));
    currentY += rowHeight;

    painter.end();
    QMessageBox::information(this, "Success", "PDF generated successfully!");
}
void MainWindow::on_Button_Analytics_clicked()
{
    // Vérifier l'onglet
    if (ui->tabWidget->count() <= 4) {
        qCritical() << "Analytics tab not available!";
        return;
    }
    ui->tabWidget->setCurrentIndex(1);

    // Récupérer les données
    QList<QStringList> data = Etmp.ListEvent();
    if (data.isEmpty()) {
        qWarning() << "No data available!";
        return;
    }

    // Calculer les stats
    QMap<QString, int> eventCountByType;
    for (const QStringList& rowData : data) {
        if (rowData.size() > 5) {  // Vérification index
            QString eventType = rowData[5];
            eventCountByType[eventType]++;
        }
    }

    // Nettoyer l'onglet
    QWidget *tab = ui->tabWidget->widget(4);
    QLayout *oldLayout = tab->layout();
    if (oldLayout) {
        // Nettoyage sécurisé
        QLayoutItem *item;
        while ((item = oldLayout->takeAt(0))) {
            if (item->widget()) {
                delete item->widget();
            }
            delete item;
        }
        delete oldLayout;
    }

    // Créer le layout
    QHBoxLayout *layout = new QHBoxLayout(tab);
    layout->setContentsMargins(5, 5, 5, 5);

    // Graphique camembert
    QChart *pieChart = new QChart();
    QPieSeries *pieSeries = new QPieSeries(pieChart);
    for (auto it = eventCountByType.begin(); it != eventCountByType.end(); ++it) {
        pieSeries->append(it.key(), it.value());
    }
    pieChart->addSeries(pieSeries);
    pieChart->legend()->setAlignment(Qt::AlignRight);

    QChartView *pieChartView = new QChartView(pieChart, tab); // Parent explicite
    pieChartView->setRenderHint(QPainter::Antialiasing);

    // Graphique barres
    QChart *barChart = new QChart();
    QBarSeries *barSeries = new QBarSeries(barChart);
    for (auto it = eventCountByType.begin(); it != eventCountByType.end(); ++it) {
        QBarSet *set = new QBarSet(it.key(), barSeries);
        *set << it.value();
        barSeries->append(set);
    }
    barChart->addSeries(barSeries);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(eventCountByType.keys());
    barChart->addAxis(axisX, Qt::AlignBottom);
    barSeries->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setLabelFormat("%d");
    barChart->addAxis(axisY, Qt::AlignLeft);
    barSeries->attachAxis(axisY);

    QChartView *barChartView = new QChartView(barChart, tab); // Parent explicite
    barChartView->setRenderHint(QPainter::Antialiasing);

    // Ajouter au layout
    layout->addWidget(pieChartView);
    layout->addWidget(barChartView);
    pieChartView->setObjectName("pieChartView");
    barChartView->setObjectName("barChartView");

    // Ajuster les tailles
    int w = tab->width() / 2 - 10;
    pieChartView->setMinimumSize(w, 400);
    barChartView->setMinimumSize(w, 400);
}
// Handle map clicks from QML
void MainWindow::handleMapClick(double latitude, double longitude) {
    setLatitude(latitude);
    setLongitude(longitude);

    QString plusCode = generatePlusCode(latitude, longitude);
    qDebug() << "Map clicked - Lat:" << latitude << " Lng:" << longitude << " PlusCode:" << plusCode;

    // Update the position display in the dialog if it's open
    if (mapDialog && mapDialog->isVisible()) {
        QLineEdit *posDisplay = mapDialog->findChild<QLineEdit*>("positionDisplay");
        if (posDisplay) {
            posDisplay->setText(plusCode);
            qDebug() << "Updated dialog position display:" << plusCode;
        }
    } else if (mapForAddEvent) {
        // If in the Add Event tab
        if (ui->tabWidget->currentWidget() == ui->Add_Event) {
            ui->AlineEdit_7->setText(plusCode);
            qDebug() << "Updated AddEvent position:" << plusCode;
        }
        // If in the Modify Event tab
        else if (ui->tabWidget->currentWidget() == ui->Modify_Event) {
            ui->AlineEdit_7->setText(plusCode);
            qDebug() << "Updated ModifyEvent position:" << plusCode;
        }
    }

    // Update the visual marker
    emit locationMarkingChanged(latitude, longitude, "Selected Location");

    // Call showNearbyEvents to display events at the selected location
    double radius = 1000; // Define a radius for nearby events, adjust as needed
    showNearbyEvents(latitude, longitude, radius);
}

// Generate PlusCode from coordinates
QString MainWindow::generatePlusCode(double latitude, double longitude) {
    openlocationcode::LatLng loc;
    loc.latitude = latitude;
    loc.longitude = longitude;
    std::string code = openlocationcode::Encode(loc, 10); // Full precision code
    return QString::fromStdString(code);
}

// Method to get user's location for suggestions
void MainWindow::getUserLocation() {
    // Vérifier si une localisation a déjà été sélectionnée
    static bool locationAlreadySelected = false;
    if (locationAlreadySelected) {
        qDebug() << "Location already selected, not opening dialog";
        return;
    }

    // Check if the dialog is already open
    if (locationDialog && locationDialog->isVisible()) {
        qDebug() << "Location dialog is already active, bringing it to the front";
        locationDialog->raise();
        locationDialog->activateWindow();
        return;
    }

    qDebug() << "Opening location selection dialog";

    // Create a custom dialog with both options
    locationDialog = new QDialog(this);
    locationDialog->setWindowTitle(tr("Location Selection"));
    locationDialog->setMinimumWidth(400);

    QVBoxLayout *layout = new QVBoxLayout(locationDialog);

    // Create radio buttons for selection method
    QLabel *methodLabel = new QLabel(tr("Select how you want to provide your location:"), locationDialog);
    QRadioButton *mapRadio = new QRadioButton(tr("Select from map"), locationDialog);
    QRadioButton *codeRadio = new QRadioButton(tr("Enter PlusCode manually"), locationDialog);
    mapRadio->setChecked(true); // Default option

    // PlusCode input field (initially hidden)
    QLineEdit *plusCodeEdit = new QLineEdit(locationDialog);
    plusCodeEdit->setPlaceholderText(tr("Enter PlusCode (e.g., 9C4X+J5)"));
    plusCodeEdit->setVisible(false);

    // Create a map for selection (initially visible)
    QQuickWidget *mapWidget = new QQuickWidget(locationDialog);
    mapWidget->setSource(QUrl(QStringLiteral("qrc:/Maps/QmlMap.qml")));
    mapWidget->setMinimumSize(380, 300);
    mapWidget->rootContext()->setContextProperty("mainWindow", this);

    // Connect the map click signals
    auto mapRootObject = mapWidget->rootObject();
    if (mapRootObject) {
        // Center the map at a default location
        QMetaObject::invokeMethod(mapRootObject, "setCenter",
                                  Q_ARG(QVariant, 36.8065),
                                  Q_ARG(QVariant, 10.1815));

        // Clear any existing markers
        QMetaObject::invokeMethod(mapRootObject, "clearMarkers");
    }

    // Connect radio button signals
    connect(mapRadio, &QRadioButton::toggled, [mapWidget, plusCodeEdit](bool checked) {
        mapWidget->setVisible(checked);
        plusCodeEdit->setVisible(!checked);
    });

    connect(codeRadio, &QRadioButton::toggled, [mapWidget, plusCodeEdit](bool checked) {
        plusCodeEdit->setVisible(checked);
        mapWidget->setVisible(!checked);
    });

    // Add buttons
    QDialogButtonBox *buttonBox = new QDialogButtonBox(
        QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
        locationDialog);

    buttonBox->setStyleSheet("QPushButton { padding: 6px 12px; font-weight: bold; }"
                             "QPushButton[text=\"OK\"] { background-color: #4CAF50; color: white; }"
                             "QPushButton[text=\"Cancel\"] { background-color: #f44336; color: white; }");

    connect(buttonBox, &QDialogButtonBox::accepted, locationDialog, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, locationDialog, &QDialog::reject);

    layout->addWidget(methodLabel);
    layout->addWidget(mapRadio);
    layout->addWidget(codeRadio);
    layout->addWidget(plusCodeEdit);
    layout->addWidget(mapWidget);
    layout->addWidget(buttonBox);

    // Temporary storage for selected location
    double selectedLat = 0.0;
    double selectedLng = 0.0;
    bool locationSelected = false;

    // Create a scoped connection that will be automatically disconnected when it goes out of scope
    QMetaObject::Connection tempConnection;
    tempConnection = QObject::connect(
        this, &MainWindow::locationMarkingChanged,
        [this, &mapRootObject, &selectedLat, &selectedLng, &locationSelected, &plusCodeEdit](double lat, double lng, const QString &name) {
            Q_UNUSED(name);
            selectedLat = lat;
            selectedLng = lng;
            locationSelected = true;

            // Update the PlusCode field with the selected location
            QString plusCode = generatePlusCode(lat, lng);
            plusCodeEdit->setText(plusCode);

            // Show the marker on the map
            if (mapRootObject) {
                QMetaObject::invokeMethod(mapRootObject, "clearMarkers");
                QMetaObject::invokeMethod(mapRootObject, "addMarker",
                                          Q_ARG(QVariant, lat),
                                          Q_ARG(QVariant, lng),
                                          Q_ARG(QVariant, "Your Location"),
                                          Q_ARG(QVariant, ""));
            }
        });

    // Execute dialog
    int result = locationDialog->exec();

    // Disconnect the temporary connection
    QObject::disconnect(tempConnection);

    // Process the result
    if (result == QDialog::Accepted) {
        if (mapRadio->isChecked() && locationSelected) {
            // User selected a location on the map
            setCenter(selectedLat, selectedLng);
            setLocationMarking(selectedLat, selectedLng, "Your Location");
            showNearbyEvents(selectedLat, selectedLng, 10.0);
            locationAlreadySelected = true; // Marquer comme sélectionné
        }
        else if (codeRadio->isChecked() && !plusCodeEdit->text().isEmpty()) {
            // User entered a PlusCode manually
            QString plusCode = plusCodeEdit->text();
            try {
                openlocationcode::CodeArea area = openlocationcode::Decode(plusCode.toStdString());
                double lat = area.GetCenter().latitude;
                double lng = area.GetCenter().longitude;

                setCenter(lat, lng);
                setLocationMarking(lat, lng, "Your Location");
                showNearbyEvents(lat, lng, 10.0);
                locationAlreadySelected = true; // Marquer comme sélectionné
            } catch (...) {
                QMessageBox::warning(this, tr("Invalid PlusCode"),
                                     tr("Please enter a valid PlusCode format."));
            }
        } else {
            QMessageBox::information(this, tr("No Location Selected"),
                                     tr("Please select a location on the map or enter a valid PlusCode."));
        }
    }

    // Clean up the dialog
    locationDialog->deleteLater();
    locationDialog = nullptr;
}

// Method to find and display nearby events
void MainWindow::showNearbyEvents(double latitude, double longitude, double radius) {
    // Static flag to track if the dialog has been shown
    static bool dialogShown = false;

    // Clear previous markers
    if (ui->quickWidget->rootObject()) {
        QMetaObject::invokeMethod(ui->quickWidget->rootObject(), "clearMarkers");
        // Add user's location marker
        QMetaObject::invokeMethod(ui->quickWidget->rootObject(), "addMarker",
                                  Q_ARG(QVariant, latitude),
                                  Q_ARG(QVariant, longitude),
                                  Q_ARG(QVariant, "Your Location"),
                                  Q_ARG(QVariant, ""));
    }

    // Get all events
    QList<QStringList> allEvents = Etmp.ListEvent();
    int nearbyCount = 0;

    // Create a list to store nearby event details
    QStringList nearbyEventDetails;

    // Iterate through events
    for (const QStringList& event : allEvents) {
        if (event.size() >= 7) { // Ensure event has position info
            QString positionStr = event[6];
            try {
                // Decode the PlusCode to get coordinates
                openlocationcode::CodeArea area = openlocationcode::Decode(positionStr.toStdString());
                double eventLat = area.GetCenter().latitude;
                double eventLng = area.GetCenter().longitude;

                // Calculate distance (more accurate haversine formula)
                double dLat = qDegreesToRadians(eventLat - latitude);
                double dLon = qDegreesToRadians(eventLng - longitude);
                double a = qSin(dLat/2) * qSin(dLat/2) +
                           qCos(qDegreesToRadians(latitude)) *
                               qCos(qDegreesToRadians(eventLat)) *
                               qSin(dLon/2) * qSin(dLon/2);
                double c = 2 * qAtan2(qSqrt(a), qSqrt(1-a));
                double distance = 6371 * c; // Earth radius in km

                // Log event details including type
                qDebug() << "Event:" << event[1]
                         << "| Type:" << event[5]
                         << "| Distance:" << QString::number(distance, 'f', 2) << "km"
                         << "| Date:" << event[4];

                // If within radius, add marker to map and collect details
                if (distance <= radius) {
                    QString eventTitle = event[1];
                    QString eventType = event[5];
                    QString eventDate = event[4];

                    // Add marker to map with event name (title)
                    if (ui->quickWidget->rootObject()) {
                        QMetaObject::invokeMethod(ui->quickWidget->rootObject(), "addMarker",
                                                  Q_ARG(QVariant, eventLat),
                                                  Q_ARG(QVariant, eventLng),
                                                  Q_ARG(QVariant, QString("%1\n%2").arg(eventTitle).arg(eventType)),
                                                  Q_ARG(QVariant, eventType));
                    }

                    // Add formatted event details to our list
                    nearbyEventDetails.append(QString("• %1\n  Type: %2\n  Distance: %3 km\n  Date: %4\n")
                                                  .arg(eventTitle)
                                                  .arg(eventType)
                                                  .arg(distance, 0, 'f', 2)
                                                  .arg(eventDate));
                    nearbyCount++;
                }
            } catch (...) {
                qDebug() << "Skipped invalid PlusCode for event:" << event[1];
                continue;
            }
        }
    }

    // Show message with count and details of nearby events only if not shown before
    if (nearbyCount > 0 && !dialogShown) {
        QString message = tr("Found %1 events within %2 km radius:\n\n").arg(nearbyCount).arg(radius);
        message += nearbyEventDetails.join("\n");

        QMessageBox msgBox(this);
        msgBox.setWindowTitle(tr("Nearby Events"));
        msgBox.setText(message);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setIcon(QMessageBox::Information);

        // Make message box wider and scrollable
        QTextEdit *textEdit = new QTextEdit();
        textEdit->setReadOnly(true);
        textEdit->setText(message);
        textEdit->setMinimumWidth(500);
        textEdit->setMinimumHeight(300);

        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(textEdit);
        msgBox.setLayout(layout);

        msgBox.exec();
        dialogShown = true;
    }
    else if (nearbyCount == 0 && !dialogShown) {
        QMessageBox::information(this, tr("Nearby Events"),
                                 tr("No events found within %1 km radius.").arg(radius));
        dialogShown = true;
    }

    // Show and center the map
    ui->quickWidget->show();
    if (ui->quickWidget->rootObject()) {
        QMetaObject::invokeMethod(ui->quickWidget->rootObject(), "setCenter",
                                  Q_ARG(QVariant, latitude),
                                  Q_ARG(QVariant, longitude));
    }
    showRouteToNearestEvent(latitude, longitude, allEvents);
}
// Slot for suggestions button
void MainWindow::on_Suggestions_Button_clicked() {
    // Set state for map handling
    mapForAddEvent = false;

    // Use a static flag to prevent multiple calls
    static bool isProcessing = false;

    if (!isProcessing) {
        isProcessing = true;

        // Disconnect any existing connections to prevent multiple handlers
        disconnect(this, &MainWindow::locationMarkingChanged, nullptr, nullptr);

        // Call getUserLocation (which has its own static flag to prevent multiple dialogs)
        getUserLocation();

        // Reset processing flag after a short delay to prevent multiple rapid clicks
        QTimer::singleShot(500, [this]() {
            isProcessing = false;
        });
    } else {
        qDebug() << "Already processing nearby events request, ignoring";
    }
    double userLat = m_userLatitude;
    double userLng = m_userLongitude;

    // Optionally use a default radius if needed
    double searchRadius = 10.0; // 10 km

    showNearbyEvents(userLat, userLng, searchRadius);

}

// Slot for map click in Add Event tab
void MainWindow::on_positionMapButton_clicked() {
    qDebug() << "Add Event map button clicked";

    // Use current position if available, or default
    QString currentPos = ui->AlineEdit_7->text();
    double lat = m_userLatitude;
    double lng = m_userLongitude;

    if (!currentPos.isEmpty()) {
        try {
            openlocationcode::CodeArea area = openlocationcode::Decode(currentPos.toStdString());
            lat = area.GetCenter().latitude;
            lng = area.GetCenter().longitude;
            qDebug() << "Using existing position:" << lat << lng << "from" << currentPos;
        } catch (...) {
            qDebug() << "Invalid position code, using default location";
        }
    }

    // Center the map before opening dialog
    setCenter(lat, lng);

    // Open dialog for adding new event
    showPositionMapDialog(false);
}

// Slot for map button click in UpdateEvent tab
void MainWindow::on_updatePositionMapButton_clicked() {
    qDebug() << "Update Event map button clicked";

    // Use current position if available, or default
    QString currentPos = ui->AlineEdit_7->text();
    double lat = m_userLatitude;
    double lng = m_userLongitude;

    if (!currentPos.isEmpty()) {
        try {
            openlocationcode::CodeArea area = openlocationcode::Decode(currentPos.toStdString());
            lat = area.GetCenter().latitude;
            lng = area.GetCenter().longitude;
            qDebug() << "Using existing position:" << lat << lng << "from" << currentPos;
        } catch (...) {
            qDebug() << "Invalid position code, using default location";
        }
    }

    // Center the map before opening dialog
    setCenter(lat, lng);

    // Open dialog for updating existing event
    showPositionMapDialog(true);
}

// Add this as a new private slot implementation
void MainWindow::onTabChanged(int index) {
    // Get the current tab widget
    QWidget* currentTab = ui->tabWidget->widget(index);

    // If we're switching to the AddEvent tab
    if (currentTab == ui->Add_Event) {
        // Hide the main map in TabEvent
        ui->quickWidget->hide();

        // Don't automatically show the map dialog, let user click the button
        mapForAddEvent = true;

        // Try to ensure the Save_Add button is connected
        // Look for a button with multiple possible names/texts
        QPushButton* saveAddButton = nullptr;

        // Try different object names
        QList<QString> possibleNames = {"pushButton", "saveButton", "Save_Add", "addButton", "saveEventButton"};
        for (const QString& name : possibleNames) {
            saveAddButton = currentTab->findChild<QPushButton*>(name);
            if (saveAddButton) {
                qDebug() << "Found button with name:" << name;
                break;
            }
        }

        // If not found by name, try by text
        if (!saveAddButton) {
            QList<QPushButton*> buttons = currentTab->findChildren<QPushButton*>();
            for (QPushButton* button : buttons) {
                if (button->text().contains("Save", Qt::CaseInsensitive) ||
                    button->text().contains("Add", Qt::CaseInsensitive)) {
                    saveAddButton = button;
                    qDebug() << "Found button with text:" << button->text();
                    break;
                }
            }
        }

        if (saveAddButton) {
            // Disconnect any existing connections to avoid duplicates
            disconnect(saveAddButton, &QPushButton::clicked, this, &MainWindow::on_Save_Add_clicked);

            // Reconnect
            bool connected = connect(saveAddButton, &QPushButton::clicked, this, &MainWindow::on_Save_Add_clicked);
            if (connected) {
                qDebug() << "Successfully connected Save button in onTabChanged";
            } else {
                qDebug() << "Failed to connect Save button in onTabChanged";
            }
        } else {
            qDebug() << "Could not find Save button in onTabChanged, creating one...";

            // Create a new save button if one doesn't exist
            QPushButton* newSaveButton = new QPushButton("Save Event", currentTab);
            newSaveButton->setObjectName("saveEventButton");
            newSaveButton->setGeometry(300, 550, 100, 30); // Position it somewhere visible
            newSaveButton->show();
            connect(newSaveButton, &QPushButton::clicked, this, &MainWindow::on_Save_Add_clicked);
        }
    }
    // If we're switching back to TabEvent
    else if (currentTab == ui->TabEvent) {
        // Don't change the state of the map dialog

        // Don't automatically show the main map, it will be shown when needed
        mapForAddEvent = false;
    }
    else {
        // Hide the main map in other tabs
        if (ui->quickWidget->isVisible()) {
            ui->quickWidget->hide();
        }

        // Don't change the state of the map dialog

        mapForAddEvent = false;
    }
}

void MainWindow::on_Save_Add_clicked()
{
    qDebug() << "on_Save_Add_clicked - function entered";

    // Check if all required UI elements exist
    if (!ui->AlineEdit) {
        qDebug() << "ERROR: AlineEdit is null!";
        QMessageBox::critical(this, "Error", "UI element AlineEdit not found!");
        return;
    }

    if (!ui->AlineEdit_2) {
        qDebug() << "ERROR: AlineEdit_2 is null!";
        QMessageBox::critical(this, "Error", "UI element AlineEdit_2 (Title) not found!");
        return;
    }

    if (!ui->AlineEdit_3) {
        qDebug() << "ERROR: AlineEdit_3 is null!";
        QMessageBox::critical(this, "Error", "UI element AlineEdit_3 (Sponsor) not found!");
        return;
    }

    if (!ui->AlineEdit_4) {
        qDebug() << "ERROR: AlineEdit_4 is null!";
        QMessageBox::critical(this, "Error", "UI element AlineEdit_4 (Description) not found!");
        return;
    }

    if (!ui->AlineEdit_5) {
        qDebug() << "ERROR: AlineEdit_5 is null!";
        QMessageBox::critical(this, "Error", "UI element AlineEdit_5 (Date) not found!");
        return;
    }

    if (!ui->AlineEdit_6) {
        qDebug() << "ERROR: AlineEdit_6 is null!";
        QMessageBox::critical(this, "Error", "UI element AlineEdit_6 (Type) not found!");
        return;
    }

    if (!ui->AlineEdit_7) {
        qDebug() << "ERROR: AlineEdit_7 is null!";
        QMessageBox::critical(this, "Error", "UI element AlineEdit_7 (Position) not found!");
        return;
    }

    qDebug() << "All UI elements found, proceeding with event addition";

    // Increment the ID for new event
    lastIdUsed++;
    ui->AlineEdit->setText(QString::number(lastIdUsed));

    // Get event details from form
    int id = ui->AlineEdit->text().toInt();
    QString title = ui->AlineEdit_2->text();
    QString sponsor = ui->AlineEdit_3->text();
    QString description = ui->AlineEdit_4->toPlainText();
    QString date = ui->AlineEdit_5->date().toString("dd/MM/yyyy");
    QString type = ui->AlineEdit_6->currentText();
    QString position = ui->AlineEdit_7->text();

    qDebug() << "Event details:";
    qDebug() << "ID:" << id;
    qDebug() << "Title:" << title;
    qDebug() << "Sponsor:" << sponsor;
    qDebug() << "Description:" << description;
    qDebug() << "Date:" << date;
    qDebug() << "Type:" << type;
    qDebug() << "Position:" << position;

    // Validate data using our Control method with the correct parameters
    if (!Control(title, sponsor, description, ui->AlineEdit_5->date(), type, position)) {
        qDebug() << "Validation failed";
        return;
    }

    qDebug() << "Validation passed, creating event object";

    // Create event object with std::string conversions
    Evenement event(id,
                    title.toStdString(),
                    sponsor.toStdString(),
                    description.toStdString(),
                    type.toStdString(),
                    position.toStdString(),
                    ui->AlineEdit_5->date());

    qDebug() << "Trying to add event to database...";

    // Try to add the event to the database
    bool success = event.addEvent();

    qDebug() << "Event addition result:" << (success ? "SUCCESS" : "FAILURE");

    if (success) {
        QMessageBox::information(this, "Success", "Event added successfully!");

        // Clear form fields after successful addition
        ui->AlineEdit_2->clear();
        ui->AlineEdit_3->clear();
        ui->AlineEdit_4->clear();
        ui->AlineEdit_5->setDate(QDate::currentDate());
        ui->AlineEdit_6->setCurrentIndex(0);
        ui->AlineEdit_7->clear();

        // Switch back to the Events tab and refresh the table
        ui->tabWidget->setCurrentIndex(0);
        refresh_table();
    } else {
        // Get the last error from the database if possible
        QString errorMsg = "Failed to add event. Please check the data and try again.";

        // Try to get database error info
        QSqlDatabase db = QSqlDatabase::database();
        if (db.isValid() && db.isOpen()) {
            QSqlError error = db.lastError();
            if (error.isValid()) {
                errorMsg += "\n\nDatabase error: " + error.text();
                qDebug() << "Database error:" << error.text();
            } else {
                qDebug() << "No valid database error found";
            }
        } else {
            qDebug() << "Database is not valid or not open";
        }

        QMessageBox::critical(this, "Error", errorMsg);
    }
}

// Validate event data before saving
bool MainWindow::Control() {
    if (ui->AlineEdit_2->text().isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter a title for the event");
        return false;
    }

    if (ui->AlineEdit_6->currentText().isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter a type for the event");
        return false;
    }

    if (ui->AlineEdit_5->date().isNull() || !ui->AlineEdit_5->date().isValid()) {
        QMessageBox::warning(this, "Warning", "Please enter a date for the event");
        return false;
    }

    // Check if we have a valid position selected
    if (ui->AlineEdit_7->text().isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please select a position for the event using the map");
        return false;
    }

    return true;
}

// Center map on an event's location based on its PlusCode
void MainWindow::centerMapOnEventLocation(const QString &plusCode) {
    if (plusCode.isEmpty()) return;

    try {
        openlocationcode::CodeArea area = openlocationcode::Decode(plusCode.toStdString());
        double lat = area.GetCenter().latitude;
        double lng = area.GetCenter().longitude;

        if (quickWidget_Add && quickWidget_Add->rootObject()) {
            QMetaObject::invokeMethod(quickWidget_Add->rootObject(), "setCenter",
                                      Q_ARG(QVariant, lat),
                                      Q_ARG(QVariant, lng));

            QMetaObject::invokeMethod(quickWidget_Add->rootObject(), "clearMarkers");
            QMetaObject::invokeMethod(quickWidget_Add->rootObject(), "addMarker",
                                      Q_ARG(QVariant, lat),
                                      Q_ARG(QVariant, lng),
                                      Q_ARG(QVariant, "Event Location"));
        }
    } catch (...) {
        // Invalid PlusCode
        QMessageBox::warning(this, tr("Invalid PlusCode"),
                             tr("Could not center map: invalid PlusCode format."));
    }
}

// Get the current user latitude
double MainWindow::getUserLatitude() const {
    // Get from map if available, otherwise use default
    return m_userLatitude;
}

// Get the current user longitude
double MainWindow::getUserLongitude() const {
    // Get from map if available, otherwise use default
    return m_userLongitude;
}

// Show map dialog for position selection
void MainWindow::showPositionMapDialog(bool forUpdate) {
    qDebug() << "Opening map dialog, forUpdate=" << forUpdate;

    // If dialog already exists, just show it
    if (mapDialog) {
        mapDialog->raise();
        mapDialog->activateWindow();
        qDebug() << "Reusing existing map dialog";
    } else {
        // If we need to create a new dialog
        qDebug() << "Creating new map dialog";
        mapDialog = new QDialog(this);
        mapDialog->setWindowTitle("Select Position on Map");
        mapDialog->setMinimumSize(700, 600);
        mapDialog->setAttribute(Qt::WA_DeleteOnClose, false); // Don't delete on close
        mapDialog->setStyleSheet("QDialog { background-color: white; }"); // Ensure the dialog is visible

        // Create layout
        QVBoxLayout *layout = new QVBoxLayout(mapDialog);
        layout->setSpacing(10);
        layout->setContentsMargins(10, 10, 10, 10);

        // Add title label with larger, bold text
        QLabel *titleLabel = new QLabel("📍 Event Location Selection", mapDialog);
        titleLabel->setStyleSheet("QLabel { font-size: 16pt; font-weight: bold; color: #2962FF; margin-bottom: 10px; }");
        layout->addWidget(titleLabel);

        // Add instructions
        QLabel *instructionsLabel = new QLabel("Click on the map to select a position for your event. The selected position will be used as the event location.", mapDialog);
        instructionsLabel->setWordWrap(true);
        instructionsLabel->setStyleSheet("QLabel { font-size: 11pt; color: #555; margin-bottom: 15px; }");
        layout->addWidget(instructionsLabel);

        // Set up the map widget
        quickWidget_Add->setMinimumSize(680, 400);
        layout->addWidget(quickWidget_Add);

        // Current position display
        QHBoxLayout *positionLayout = new QHBoxLayout();
        QLabel *positionLabel = new QLabel("Selected Position:", mapDialog);
        positionLabel->setStyleSheet("QLabel { font-weight: bold; }");
        QLineEdit *positionDisplay = new QLineEdit(mapDialog);
        positionDisplay->setReadOnly(true);
        positionDisplay->setObjectName("positionDisplay");
        positionDisplay->setStyleSheet(
            "QLineEdit { "
            "   background-color: #f5f5f5; "
            "   padding: 8px; "
            "   border: 1px solid #ddd; "
            "   border-radius: 4px; "
            "   font-size: 11pt; "
            "}"
            );
        positionLayout->addWidget(positionLabel);
        positionLayout->addWidget(positionDisplay, 1); // Give the text field more space
        layout->addLayout(positionLayout);

        // Add buttons with improved styling
        QDialogButtonBox *buttonBox = new QDialogButtonBox(
            QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
            mapDialog);

        buttonBox->setStyleSheet(
            "QPushButton { "
            "   padding: 8px 16px; "
            "   font-weight: bold; "
            "   border-radius: 4px; "
            "   font-size: 11pt; "
            "   margin-top: 10px; "
            "}"
            "QPushButton[text=\"OK\"] { "
            "   background-color: #4CAF50; "
            "   color: white; "
            "}"
            "QPushButton[text=\"Cancel\"] { "
            "   background-color: #f44336; "
            "   color: white; "
            "}"
            "QPushButton[text=\"OK\"]:hover { "
            "   background-color: #45a049; "
            "}"
            "QPushButton[text=\"Cancel\"]:hover { "
            "   background-color: #d32f2f; "
            "}"
            );

        connect(buttonBox, &QDialogButtonBox::accepted, [this, forUpdate]() {
            QLineEdit *posDisplay = mapDialog->findChild<QLineEdit*>("positionDisplay");
            if (posDisplay && !posDisplay->text().isEmpty()) {
                QString plusCode = posDisplay->text();
                qDebug() << "Saving position from map dialog:" << plusCode;

                // Set position in appropriate field based on which tab we're on
                if (forUpdate) {
                    ui->AlineEdit_7->setText(plusCode);
                    qDebug() << "Updated position in update tab to:" << plusCode;
                } else {
                    ui->AlineEdit_7->setText(plusCode);
                    qDebug() << "Updated position in add tab to:" << plusCode;
                }

                // Also try to use the position to update the display in the main UI
                try {
                    CodeArea area =  Decode(plusCode.toStdString());
                    double lat = area.GetCenter().latitude;
                    double lng = area.GetCenter().longitude;

                    // Update the main position coordinates
                    setLatitude(lat);
                    setLongitude(lng);
                    qDebug() << "Updated main coordinates to:" << lat << lng;
                } catch (...) {
                    qDebug() << "Failed to decode plus code:" << plusCode;
                }
            }
            mapDialog->hide(); // Don't close, just hide
        });

        connect(buttonBox, &QDialogButtonBox::rejected, [this]() {
            mapDialog->hide(); // Don't close, just hide
        });

        layout->addWidget(buttonBox);

        // Connect our locationMarkingChanged signal to update the position display
        QObject::connect(this, &MainWindow::locationMarkingChanged,
                         [this](double lat, double lng, const QString &name) {
                             Q_UNUSED(name);
                             if (mapDialog) {
                                 QLineEdit *posDisplay = mapDialog->findChild<QLineEdit*>("positionDisplay");
                                 if (posDisplay) {
                                     QString plusCode = generatePlusCode(lat, lng);
                                     posDisplay->setText(plusCode);
                                     qDebug() << "Map click detected, updated position display to:" << plusCode;
                                 }
                             }
                         });
    }

    // Clear any existing markers
    if (quickWidget_Add->rootObject()) {
        QMetaObject::invokeMethod(quickWidget_Add->rootObject(), "clearMarkers");
    }

    // Center the map on current selection if available, or default location
    QString currentPos;
    if (forUpdate) {
        currentPos = ui->AlineEdit_7->text();
    } else {
        currentPos = ui->AlineEdit_7->text();
    }

    if (!currentPos.isEmpty()) {
        try {
            CodeArea area = Decode(currentPos.toStdString());
            double lat = area.GetCenter().latitude;
            double lng = area.GetCenter().longitude;

            setCenter(lat, lng);

            // Add a marker for the current position
            if (quickWidget_Add->rootObject()) {
                QMetaObject::invokeMethod(quickWidget_Add->rootObject(), "addMarker",
                                          Q_ARG(QVariant, lat),
                                          Q_ARG(QVariant, lng),
                                          Q_ARG(QVariant, "Event Location"));
            }

            // Update the position display
            QLineEdit *posDisplay = mapDialog->findChild<QLineEdit*>("positionDisplay");
            if (posDisplay) {
                posDisplay->setText(currentPos);
            }
        } catch (...) {
            // Use default location if position is invalid
            setCenter(m_userLatitude, m_userLongitude);
        }
    } else {
        // Use default location
        setCenter(m_userLatitude, m_userLongitude);
    }

    // Set flag for map click handler
    mapForAddEvent = true;

    // Show the dialog and bring it to front
    mapDialog->setModal(true);  // Make it modal for better focus
    mapDialog->show();
    mapDialog->raise();
    mapDialog->activateWindow();

    // Debug output
    qDebug() << "Map dialog shown, forUpdate=" << forUpdate
             << "at position" << (currentPos.isEmpty() ? "default" : currentPos);
}

// Slot for map click in Add Event tab
void MainWindow::on_mapClicked_Add() {
    // The coordinates are already set in handleMapClick
    double lat = latitude();
    double lng = longitude();

    // Update the PlusCode field in the UI
    QString plusCode = generatePlusCode(lat, lng);
    ui->AlineEdit_7->setText(plusCode);

    qDebug() << "on_mapClicked_Add called, updating position to:" << plusCode;
}

// Slot for map click in Suggest tab
void MainWindow::on_mapClicked_Suggest() {
    // Already handled in handleMapClick and showNearbyEvents
    qDebug() << "on_mapClicked_Suggest called";
}

void MainWindow::addCustomMarker(double latitude, double longitude, const QString &name, const QString &type) {
    // Appel à la méthode QML pour ajouter un marqueur
    QMetaObject::invokeMethod(ui->quickWidget->rootObject(), "addMarker",
                              Q_ARG(QVariant, latitude),
                              Q_ARG(QVariant, longitude),
                              Q_ARG(QVariant, name),
                              Q_ARG(QVariant, type)); // Passer le type ici
}
void MainWindow::setLMarking(double latitude, double longitude, const QString &name) {
    m_userLatitude = latitude;
    m_userLongitude = longitude;
    m_locationName = name;
    mainLocationSet = true; // Marquer l'emplacement principal comme défini

    // Émettre le signal pour mettre à jour l'interface utilisateur
    emit locationMarkingChanged(latitude, longitude, name);
}
// In MainWindow.cpp
void MainWindow::addMarker(double latitude, double longitude, const QString &name) {
    if (ui->quickWidget->rootObject()) {
        QMetaObject::invokeMethod(ui->quickWidget->rootObject(), "addMarker",
                                  Q_ARG(QVariant, latitude),
                                  Q_ARG(QVariant, longitude),
                                  Q_ARG(QVariant, name));
    }
}
void MainWindow::resetLocationSelection() {
    locationAlreadySelected = false;
    getUserLocation(); // Optionnel: rouvrir directement le dialogue
}
void MainWindow::resetEventsDialog() {
    // This will allow the events dialog to be shown again
    static bool dialogShown = false;
    dialogShown = false;
}
void MainWindow::resetEventsNotification() {
    static bool dialogShown = false;
    dialogShown = false;
    qDebug() << "Events notification reset - next search will show dialog";
}
void MainWindow::showRouteToNearestEvent(double userLat, double userLng, const QList<QStringList>& allEvents) {
    if (!ui->quickWidget->rootObject()) return;

    double minDistance = std::numeric_limits<double>::max();
    double nearestLat = 0;
    double nearestLng = 0;
    QString nearestTitle;

    // Trouver l'événement le plus proche
    for (const QStringList& event : allEvents) {
        if (event.size() >= 7) {
            QString positionStr = event[6];
            try {
                openlocationcode::CodeArea area = openlocationcode::Decode(positionStr.toStdString());
                double eventLat = area.GetCenter().latitude;
                double eventLng = area.GetCenter().longitude;

                // Calcul de distance
                double dLat = qDegreesToRadians(eventLat - userLat);
                double dLon = qDegreesToRadians(eventLng - userLng);
                double a = qSin(dLat/2) * qSin(dLat/2) +
                           qCos(qDegreesToRadians(userLat)) *
                               qCos(qDegreesToRadians(eventLat)) *
                               qSin(dLon/2) * qSin(dLon/2);
                double c = 2 * qAtan2(qSqrt(a), qSqrt(1-a));
                double distance = 6371 * c;

                if (distance < minDistance) {
                    minDistance = distance;
                    nearestLat = eventLat;
                    nearestLng = eventLng;
                    nearestTitle = event[1];
                }
            } catch (...) {
                continue;
            }
        }
    }

    if (minDistance != std::numeric_limits<double>::max()) {
        QMetaObject::invokeMethod(ui->quickWidget->rootObject(), "showRoute",
                                  Q_ARG(QVariant, userLat),
                                  Q_ARG(QVariant, userLng),
                                  Q_ARG(QVariant, nearestLat),
                                  Q_ARG(QVariant, nearestLng),
                                  Q_ARG(QVariant, nearestTitle));
    }
}
void MainWindow::readSerial()
{
    // Lire toutes les données disponibles dans le port série
    QByteArray data = serial->readAll();
    QString receivedData = QString::fromUtf8(data); // Convertir en QString

    // Afficher les données dans le QTextEdit
    ui->arduinoOut->append(receivedData);

    // Extraire les IDs séparés par des virgules
    if (!receivedData.isEmpty()) {
        QStringList ids = receivedData.split(","); // Séparer par virgule

        // Parcourir chaque ID et appeler decreaseEventQuantity
        for (const QString &idStr : ids) {
            bool ok;
            int eventId = idStr.trimmed().toInt(&ok); // Convertir en entier
            if (ok) { // Vérifier si la conversion a réussi
                decreaseEventQuantity(eventId); // Appeler la fonction pour diminuer la quantité
            } else {
                qDebug() << "Invalid ID received:" << idStr; // Gérer les IDs invalides
            }
        }
    }
}
void MainWindow::sendFirstEventToArduino()
{
    if (ui->tableWidget->rowCount() > 0) {
        if (serial->isOpen()) {
            for (int i = 0; i < 2; i++) {
                // Récupérer l'élément de la table
                QTableWidgetItem *item = ui->tableWidget->item(0, i);
                if (item) { // Vérifier si l'élément existe
                    QString id = item->text(); // Récupérer le texte en tant que QString
                    QByteArray utf8Id = id.toUtf8(); // Convertir en UTF-8

                    // Envoyer les données au port série
                    if (utf8Id == "2") {
                        serial->write("2,");
                    } else {
                        serial->write("3,");
                    }
                }
            }
        } else {
            qDebug() << "Le port série n'est pas ouvert!";
        }
    }
}

void MainWindow::initializeSerialPortWrite()
{
    serial->setPortName("COM14");
    serial->setBaudRate(QSerialPort::Baud9600); // Assurez-vous que cela correspond à votre configuration
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    if (serial->open(QIODevice::WriteOnly)) { // Ouvrir en mode écriture
        QMessageBox::information(this, "Success", "Serial port opened for writing successfully.");
    } else {
        QMessageBox::warning(this, "Error", "Failed to open serial port for writing.");
    }
}
void MainWindow::initializeSerialPortRead(QString port)
{
    // Configurer le port série
    serial->setPortName(port); // Remplacez par le port correct
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    // Ouvrir le port série en mode lecture
    if (serial->open(QIODevice::ReadWrite)) {
        qDebug() << "Serial port opened for reading successfully.";
        // Connecter le signal readyRead à la méthode readSerial
        connect(serial, &QSerialPort::readyRead, this, &MainWindow::readSerial);
    } else {
        qDebug() << "Failed to open serial port for reading.";
        QMessageBox::warning(this, "Error", "Failed to open serial port for reading.");
    }
}

void MainWindow::on_Search_Button_2_clicked()
{
    if(!serial->isOpen()){
    initializeSerialPortRead("COM14");
    }
    sendFirstEventToArduino();
}
void MainWindow::processSerialData(const QString &data)
{
    // Séparer les valeurs reçues par une virgule
    QStringList values = data.split(",");
    if (values.size() > 0) {
        // Convertir le premier élément en entier pour l'ID de l'événement
        int eventId = values[0].toInt();
        // Appeler la fonction pour diminuer la quantité de l'événement dans la base de données
        decreaseEventQuantity(eventId);
    }
}
void MainWindow::decreaseEventQuantity(int id)
{
    // Préparer la requête SQL pour diminuer la quantité de l'événement
    QSqlQuery query;
    query.prepare("UPDATE Evenement SET quantite = quantite - 1 WHERE id = :id");
    query.bindValue(":id", id);

    // Exécuter la requête et vérifier les erreurs
    if (!query.exec()) {
        qDebug() << "Error updating quantity:" << query.lastError();
        QMessageBox::critical(this, "Database Error", "Failed to update event quantity.");
    } else {
        qDebug() << "Quantity decreased for event ID:" << id;
    }
}
void MainWindow::displayLcd() {
    if (ui->tableWidget->rowCount() > 0) {
        if (serial->isOpen()) {
            for (int i = 0; i < ui->tableWidget->rowCount(); i++) { // Loop through all rows
                // Récupérer l'élément de la table pour l'ID
                QTableWidgetItem *item = ui->tableWidget->item(i, 0); // Assuming ID is in the first column
                // Récupérer l'élément de la table pour le titre
                QTableWidgetItem *item2 = ui->tableWidget->item(i, 1); // Assuming title is in the second column

                if (item) { // Vérifier si l'élément existe
                    QString id = item->text(); // Récupérer le texte en tant que QString
                    QByteArray utf8Id = id.toUtf8(); // Convertir en UTF-8

                    // Envoyer l'ID au port série
                    serial->write(utf8Id + ",");

                    if (item2) { // Vérifier si le titre existe
                        QString name = item2->text(); // Récupérer le titre
                        QByteArray utf8Name = name.toUtf8(); // Convertir en UTF-8

                        // Envoyer le titre au port série
                        serial->write(utf8Name + "\n"); // Ajouter une nouvelle ligne après le titre
                    }
                }
            }
        } else {
            qDebug() << "Le port série n'est pas ouvert!";
        }
    }
}





void MainWindow::on_LCD_clicked()
{
    if(!serial->isOpen()){
        initializeSerialPortRead("COM9");
    }
    displayLcd();
}


void MainWindow::on_Stat_Event_clicked()
{
    // Vérifier l'onglet
    // Vérifier l'onglet
    if (ui->tabWidget->count() <= 1) {
        qCritical() << "Analytics tab not available!";
        return;
    }
    ui->tabWidget->setCurrentIndex(1);

    // Récupérer les données
    QList<QStringList> data = Etmp.ListEvent();
    if (data.isEmpty()) {
        qWarning() << "No data available!";
        return;
    }

    // Calculer les stats
    QMap<QString, int> eventCountByType;
    for (const QStringList& rowData : data) {
        if (rowData.size() > 5) {  // Vérification index
            QString eventType = rowData[5];
            eventCountByType[eventType]++;
        }
    }

    // Nettoyer l'onglet
    QWidget *tab = ui->tabWidget->widget(1);
    QLayout *oldLayout = tab->layout();
    if (oldLayout) {
        // Nettoyage sécurisé
        QLayoutItem *item;
        while ((item = oldLayout->takeAt(0))) {
            if (item->widget()) {
                delete item->widget();
            }
            delete item;
        }
        delete oldLayout;
    }

    // Créer le layout
    QHBoxLayout *layout = new QHBoxLayout(tab);
    layout->setContentsMargins(5, 5, 5, 5);

    // Définir les couleurs pour chaque type d'événement
    QMap<QString, QColor> eventColors;
    eventColors["Charity"] = QColor(Qt::red);
    eventColors["Summit"] = QColor(65,105,225); // Bleu roi
    eventColors["Q&A"] = QColor(75, 0, 130); // Violet
    eventColors["Vaccination"] = QColor(30, 143, 83); // Vert spécifique

    // Graphique camembert
    QChart *pieChart = new QChart();
    QPieSeries *pieSeries = new QPieSeries(pieChart);
    for (auto it = eventCountByType.begin(); it != eventCountByType.end(); ++it) {
        QPieSlice *slice = pieSeries->append(it.key(), it.value());
        if (eventColors.contains(it.key())) {
            slice->setColor(eventColors[it.key()]);
            slice->setLabelColor(eventColors[it.key()]);
        }
        slice->setLabelVisible(true);
    }
    pieChart->addSeries(pieSeries);
    pieChart->legend()->setAlignment(Qt::AlignRight);

    QChartView *pieChartView = new QChartView(pieChart, tab);
    pieChartView->setRenderHint(QPainter::Antialiasing);

    // Graphique barres
    QChart *barChart = new QChart();
    QBarSeries *barSeries = new QBarSeries(barChart);
    for (auto it = eventCountByType.begin(); it != eventCountByType.end(); ++it) {
        QBarSet *set = new QBarSet(it.key(), barSeries);
        *set << it.value();
        if (eventColors.contains(it.key())) {
            set->setColor(eventColors[it.key()]);
        }
        barSeries->append(set);
    }
    barChart->addSeries(barSeries);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(eventCountByType.keys());
    barChart->addAxis(axisX, Qt::AlignBottom);
    barSeries->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setLabelFormat("%d");
    barChart->addAxis(axisY, Qt::AlignLeft);
    barSeries->attachAxis(axisY);

    QChartView *barChartView = new QChartView(barChart, tab);
    barChartView->setRenderHint(QPainter::Antialiasing);

    // Ajouter au layout
    layout->addWidget(pieChartView);
    layout->addWidget(barChartView);
    pieChartView->setObjectName("pieChartView");
    barChartView->setObjectName("barChartView");

    // Ajuster les tailles
    int w = tab->width() / 2 - 10;
    pieChartView->setMinimumSize(w, 400);
    barChartView->setMinimumSize(w, 400);
}

