#include "Micro_layout.h"
#include "ui_Micro_layout.h"
#include "AutoHideDockWidget.h"
#include "Microorganisme.h"
#include "PredictionEvolution.h"
#include <QTimer>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QPainter>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPrinter>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QBarCategoryAxis>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "ID" << "Nom" << "Type" << "Date" << "Caractéristique");


    QTimer::singleShot(500, this, [this]() {
        populateTable(ui->tableWidget);
    });

    // Sidebar setup (AutoHideDockWidget)
    QDockWidget *oldDockWidget = ui->dockWidget;
    if (oldDockWidget) {
        AutoHideDockWidget *autoHideDockWidget = new AutoHideDockWidget(this);
        autoHideDockWidget->setFeatures(oldDockWidget->features());
        autoHideDockWidget->setWidget(oldDockWidget->widget());

        removeDockWidget(oldDockWidget);
        oldDockWidget->setParent(nullptr);
        delete oldDockWidget;

        addDockWidget(Qt::LeftDockWidgetArea, autoHideDockWidget);
        ui->dockWidget = autoHideDockWidget;
    }


    connect(ui->tableWidget, &QTableWidget::itemSelectionChanged, this, &MainWindow::on_tableWidget_itemSelectionChanged);

    connect(ui->pushButton_17, &QPushButton::clicked, this, &MainWindow::on_pushButton_17_clicked);
    connect(ui->pushButton_15, &QPushButton::clicked, this, &MainWindow::on_searchButtonClicked);
    connect(ui->pushButton_11, &QPushButton::clicked, this, &MainWindow::trierMicroorganismes);
    connect(ui->pushButton_10, &QPushButton::clicked, this, &MainWindow::afficherStatistiques);

    serial = new QSerialPort(this);

    // Use the matching COM port from com0com (e.g., COM5)
    serial->setPortName("COM7");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    if (serial->open(QIODevice::ReadWrite)) {  // <<--- VERY IMPORTANT
        connect(serial, &QSerialPort::readyRead, this, &MainWindow::readSerialData);
    } else {
        qDebug() << "Failed to open COM port!";
    }

    // Create timers
    timer_Z = new QTimer(this);
    timer_C = new QTimer(this);
    timer_A = new QTimer(this);
    timer_E = new QTimer(this);
    timer_G = new QTimer(this);
    timer_H = new QTimer(this);

    // Connect timers to their actions
    connect(timer_Z, &QTimer::timeout, this, &MainWindow::sendZ);
    connect(timer_C, &QTimer::timeout, this, &MainWindow::sendC);
    connect(timer_A, &QTimer::timeout, this, &MainWindow::sendA);
    connect(timer_E, &QTimer::timeout, this, &MainWindow::sendE);

    // Connect buttons for Z and C (Front / Back)
    connect(ui->pushButton_19, &QPushButton::pressed, this, [=]() { timer_Z->start(100); });
    connect(ui->pushButton_19, &QPushButton::released, this, [=]() { timer_Z->stop(); });

    connect(ui->pushButton_20, &QPushButton::pressed, this, [=]() { timer_C->start(100); });
    connect(ui->pushButton_20, &QPushButton::released, this, [=]() { timer_C->stop(); });

    // Connect buttons for A and E (Right / Left)
    connect(ui->pushButton_21, &QPushButton::pressed, this, [=]() { timer_A->start(100); });
    connect(ui->pushButton_21, &QPushButton::released, this, [=]() { timer_A->stop(); });

    connect(ui->pushButton_22, &QPushButton::pressed, this, [=]() { timer_E->start(100); });
    connect(ui->pushButton_22, &QPushButton::released, this, [=]() { timer_E->stop(); });

    // Connect lineEdit_5 to send number input between 65 and 95
    connect(ui->lineEdit_5, &QLineEdit::returnPressed, this, &MainWindow::sendNumberInput);

    connect(timer_G, &QTimer::timeout, this, &MainWindow::sendG);
    connect(timer_H, &QTimer::timeout, this, &MainWindow::sendH);

    // Associer boutons à press/release
    connect(ui->pushButton_23, &QPushButton::pressed, this, [=]() { timer_G->start(100); });
    connect(ui->pushButton_23, &QPushButton::released, this, [=]() { timer_G->stop(); });

    connect(ui->pushButton_24, &QPushButton::pressed, this, [=]() { timer_H->start(100); });
    connect(ui->pushButton_24, &QPushButton::released, this, [=]() { timer_H->stop(); });
    connect(ui->lineEdit_8, &QLineEdit::returnPressed, this, &MainWindow::on_lineEdit_8_returnPressed);




}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::populateTable(QTableWidget* tableWidget)
{

    tableWidget->clearContents();
    tableWidget->setRowCount(0);
    QSqlQuery query(QSqlDatabase::database("BioVechDBConnection"));


    query.prepare("SELECT * FROM ADMIN.MICROORGANISME");

    if (!query.exec()) {
        qDebug() << "Error fetching data from the database: " << query.lastError().text();
        return;
    }


    int row = 0;
    while (query.next()) {

        tableWidget->insertRow(row);


        tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("ID").toString()));  // ID
        tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("NOM").toString()));  // Nom
        tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("TYPE").toString()));  // Type
        tableWidget->setItem(row, 3, new QTableWidgetItem(query.value("DATEM").toDate().toString("yyyy-MM-dd")));  // Date
        tableWidget->setItem(row, 4, new QTableWidgetItem(query.value("CARACTERISTIQUE").toString()));  // Caractéristique
        row++;
    }
}

// Add a microorganism + ID Autoincrement
void MainWindow::on_pushButton_12_clicked()
{
    QString nom = ui->lineEdit_3->text();
    QString type = ui->comboBox->currentText();
    QDate datem = ui->calendarWidget->selectedDate();
    QString caracteristique = ui->lineEdit_6->toPlainText();


    // Obtenir la date d'aujourd'hui
    QDate today = QDate::currentDate();
    QDate minDate(2020, 1, 1);  // Date minimale : 1er janvier 2020

    // Vérification des contraintes sur la date
    if (datem > today) {
        QMessageBox::warning(this, "Erreur", "La date ne peut pas être dans le futur !");
        return;
    }
    if (datem < minDate) {
        QMessageBox::warning(this, "Erreur", "La date ne peut pas être avant 2020 !");
        return;
    }

    // Création de l'objet Microorganisme après validation de la date
    Microorganisme m(nom, type, datem, caracteristique);
    if (m.create()) {
        QMessageBox::information(this, "Succès", "Microorganisme ajouté !");
        populateTable(ui->tableWidget);  // Rafraîchir le tableau
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du microorganisme.");
    }
}




// Update a selected microorganism
void MainWindow::on_pushButton_14_clicked()
{
    int id = ui->lineEdit_2->text().toInt();
    QString nom = ui->lineEdit_3->text();
    QString type = ui->comboBox->currentText();
    QDate datem = ui->calendarWidget->selectedDate();
    QString caracteristique = ui->lineEdit_6->toPlainText();


    // Obtenir la date d'aujourd'hui
    QDate today = QDate::currentDate();
    QDate minDate(2020, 1, 1);  // Date minimale : 1er janvier 2020

    // Vérification des contraintes sur la date
    if (datem > today) {
        QMessageBox::warning(this, "Erreur", "La date ne peut pas être dans le futur !");
        return;
    }
    if (datem < minDate) {
        QMessageBox::warning(this, "Erreur", "La date ne peut pas être avant 2020 !");
        return;
    }

    // Mise à jour après validation de la date
    Microorganisme m(nom, type, datem, caracteristique);
    m.setId(id);

    if (m.update()) {
        QMessageBox::information(this, "Succès", "Microorganisme mis à jour !");
        populateTable(ui->tableWidget);
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la mise à jour.");
    }
}


// Remove a selected microorganism
void MainWindow::on_pushButton_13_clicked()
{
    int id = ui->lineEdit_2->text().toInt();

    // Vérifier si l'ID existe dans la base de données
    QSqlQuery query(QSqlDatabase::database("BioVechDBConnection"));
    query.prepare("SELECT COUNT(*) FROM ADMIN.MICROORGANISME WHERE ID = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        if (count == 0) {
            QMessageBox::warning(this, "Erreur", "L'ID spécifié n'existe pas !");
            return;
        }
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la vérification de l'ID !");
        return;
    }

    // L'ID existe, on peut supprimer
    Microorganisme m;
    m.setId(id);

    if (m.remove()) {
        QMessageBox::information(this, "Succès", "Microorganisme supprimé !");
        populateTable(ui->tableWidget);
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression.");
    }
}


// Fill the fields based on the selected row in the table
void MainWindow::on_tableWidget_itemSelectionChanged()
{
    QList<QTableWidgetItem *> selection = ui->tableWidget->selectedItems();
    if (!selection.isEmpty()) {
        ui->lineEdit_2->setText(selection.at(0)->text());
        ui->lineEdit_3->setText(selection.at(1)->text());
        ui->comboBox->setCurrentText(selection.at(2)->text());  // Set the selected type in comboBox
        ui->calendarWidget->setSelectedDate(QDate::fromString(selection.at(3)->text(), "yyyy-MM-dd"));
        ui->lineEdit_6->setText(selection.at(4)->text());
    }
}

// Function to handle search when the search button is clicked
void MainWindow::on_searchButtonClicked()
{
    QString searchText = ui->lineEdit->text();

    // Clear the existing data in the table
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    QSqlQuery query(QSqlDatabase::database("BioVechDBConnection"));

    // fetch data based on search text
    query.prepare("SELECT * FROM ADMIN.MICROORGANISME WHERE NOM LIKE :searchText");
    query.bindValue(":searchText", "%" + searchText + "%");

    if (!query.exec()) {
        qDebug() << "Error fetching data from the database: " << query.lastError().text();
        return;
    }


    int row = 0;
    while (query.next()) {
        // Insert a new row in the table widget
        ui->tableWidget->insertRow(row);

        // Insert the microorganism data into the respective columns
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("ID").toString()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("NOM").toString()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("TYPE").toString()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value("DATEM").toDate().toString("yyyy-MM-dd")));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(query.value("CARACTERISTIQUE").toString()));
        row++;
    }
}

void MainWindow::on_pushButton_9_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Export PDF"),
                                                    QDir::homePath() + "/personnel_report.pdf",
                                                    tr("PDF Files (*.pdf)"));
    if (fileName.isEmpty())
        return;

    // Setup printer
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setPageOrientation(QPageLayout::Portrait);

    // Start painting on printer
    QPainter painter;
    if (!painter.begin(&printer)) {
        QMessageBox::critical(this, tr("Error"), tr("Could not create PDF"));
        return;
    }

    // Setup metrics
    const int margin = 40;
    const int contentWidth = printer.pageRect(QPrinter::DevicePixel).width() - 2 * margin;
    int yPos = margin;

    // Set fonts
    QFont titleFont = painter.font();
    titleFont.setPointSize(16);
    titleFont.setBold(true);

    QFont sectionFont = painter.font();
    sectionFont.setPointSize(12);
    sectionFont.setBold(true);

    QFont tableFont = painter.font();
    tableFont.setPointSize(9);

    // ==================== DRAW HEADER ====================
    const int logoSize = 110; // Adjust as needed (width & height)
    const int logowidth= 40;
    QPixmap logo(":/Static/Static/logo.png");
    if (!logo.isNull()) {
        painter.drawPixmap(0, 0, logoSize, logowidth, logo);
    }
    painter.setFont(titleFont);
    painter.drawText(QRect(margin, yPos, contentWidth, 40), Qt::AlignCenter, "Personnel Report");
    yPos += 100;  // Add extra space after header

    // ==================== DRAW EMPLOYEE TABLE ====================
    painter.setFont(sectionFont);
    painter.drawText(margin, yPos, "Employee List");
    yPos += 30;

    const int columnCount = ui->tableWidget->columnCount();
    const int rowCount = ui->tableWidget->rowCount();
    const int rowHeight = 25;
    const int headerHeight = 30;
    const int columnWidth = contentWidth / columnCount;

    // Draw table headers
    painter.setPen(Qt::black);
    painter.setBrush(QColor("#2ecc71"));
    for (int col = 0; col < columnCount; ++col) {
        QString header = ui->tableWidget->horizontalHeaderItem(col)->text();
        painter.drawRect(margin + col * columnWidth, yPos, columnWidth, headerHeight);
        painter.drawText(QRect(margin + col * columnWidth, yPos, columnWidth, headerHeight),
                         Qt::AlignCenter, header);
    }
    yPos += headerHeight;

    // Draw table rows
    painter.setFont(tableFont);
    for (int row = 0; row < rowCount; ++row) {
        // Check if we need a new page
        if (yPos + rowHeight > printer.pageRect(QPrinter::DevicePixel).height() - margin) {
            printer.newPage();
            yPos = margin;
        }

        painter.setBrush(row % 2 ? QColor("#f2f2f2") : Qt::white);

        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem *item = ui->tableWidget->item(row, col);
            QString text = item ? item->text() : "";
            painter.drawRect(margin + col * columnWidth, yPos, columnWidth, rowHeight);
            painter.drawText(QRect(margin + col * columnWidth, yPos, columnWidth, rowHeight),
                             Qt::AlignCenter, text);
        }
        yPos += rowHeight;
    }
    yPos += 40;  // Extra space after table

    // ==================== CALCULATE STATISTICS ====================
    // Replace with your actual data collection
    int managerCount = 5, developerCount = 12, designerCount = 8, analystCount = 6;
    int ageUnder30 = 10, age30to40 = 15, age40to50 = 5, ageOver50 = 1;
    int salaryUnder50k = 8, salary50kto100k = 15, salaryOver100k = 8;
    int totalEmployees = managerCount + developerCount + designerCount + analystCount;

    // ==================== DRAW STATISTICS SECTION ====================
    painter.setFont(sectionFont);
    painter.drawText(margin, yPos, "Employee Statistics");
    yPos += 30;

    // Draw total employees
    painter.setFont(tableFont);
    painter.drawText(margin, yPos, QString("Total Employees: %1").arg(totalEmployees));
    yPos += 30;

    // ==================== DRAW PIE CHARTS ====================
    const int chartHeight = 350;  // Estimated height for one chart with legend

    // Job Distribution Chart
    if (yPos + chartHeight > printer.pageRect(QPrinter::DevicePixel).height() - margin) {
        printer.newPage();
        yPos = margin;
    }
    yPos = drawPieChart(painter, margin, yPos, contentWidth,
                        {{"Managers", managerCount},
                         {"Developers", developerCount},
                         {"Designers", designerCount},
                         {"Analysts", analystCount}},
                        {QColor("#3498db"), QColor("#27ae60"), QColor("#e74c3c"), QColor("#f39c12")},
                        "Job Distribution");
    yPos += 30;

    // Age Distribution Chart
    if (yPos + chartHeight > printer.pageRect(QPrinter::DevicePixel).height() - margin) {
        printer.newPage();
        yPos = margin;
    }
    yPos = drawPieChart(painter, margin, yPos, contentWidth,
                        {{"<30", ageUnder30},
                         {"30-40", age30to40},
                         {"40-50", age40to50},
                         {">50", ageOver50}},
                        {QColor("#9b59b6"), QColor("#3498db"), QColor("#1abc9c"), QColor("#e67e22")},
                        "Age Distribution");
    yPos += 30;

    // Salary Distribution Chart
    if (yPos + chartHeight > printer.pageRect(QPrinter::DevicePixel).height() - margin) {
        printer.newPage();
        yPos = margin;
    }
    yPos = drawPieChart(painter, margin, yPos, contentWidth,
                        {{"<50k", salaryUnder50k},
                         {"50k-100k", salary50kto100k},
                         {">100k", salaryOver100k}},
                        {QColor("#e74c3c"), QColor("#f39c12"), QColor("#2ecc71")},
                        "Salary Distribution");

    painter.end();

    QMessageBox::information(this, tr("Success"),
                             tr("PDF exported successfully to:\n%1").arg(fileName));
}

int MainWindow::drawPieChart(QPainter &painter, int x, int y, int width,
                             const QVector<QPair<QString, int>> &data,
                             const QVector<QColor> &colors,
                             const QString &title)
{
    const int chartSize = 250;  // Fixed size for pie chart
    const int legendWidth = width - chartSize - 30;
    int total = std::accumulate(data.begin(), data.end(), 0,
                                [](int sum, const auto &pair) { return sum + pair.second; });

    if (total == 0) return y + 50;  // Skip if no data

    // Draw title
    QFont font = painter.font();
    font.setBold(true);
    painter.setFont(font);
    painter.drawText(x, y, width, 30, Qt::AlignLeft, title);
    y += 40;

    // Draw pie chart
    QRectF pieRect(x, y, chartSize, chartSize);
    double startAngle = 0;

    for (int i = 0; i < data.size(); ++i) {
        double angle = (data[i].second * 360.0) / total;

        painter.setPen(Qt::black);
        painter.setBrush(colors[i % colors.size()]);
        painter.drawPie(pieRect, startAngle * 16, angle * 16);

        startAngle += angle;
    }

    // Draw legend
    int legendY = y;
    painter.setFont(QFont("Arial", 8));

    for (int i = 0; i < data.size(); ++i) {
        double percentage = (data[i].second * 100.0) / total;
        QString label = QString("%1: %2 (%3%)")
                            .arg(data[i].first)
                            .arg(data[i].second)
                            .arg(percentage, 0, 'f', 1);

        // Color box
        painter.setPen(Qt::black);
        painter.setBrush(colors[i % colors.size()]);
        painter.drawRect(x + chartSize + 20, legendY, 15, 15);

        // Text
        painter.setBrush(Qt::NoBrush);
        painter.drawText(x + chartSize + 40, legendY + 12, label);

        legendY += 20;
    }

    return std::max(y + chartSize, legendY + 20);  // Add extra spacing if needed
}








void MainWindow::on_pushButton_11_clicked()
{
    QString critere = ui->comboBox_2->currentText();
    QString ordre = ui->comboBox_3->currentText();


    QString queryStr = "SELECT * FROM ADMIN.MICROORGANISME ORDER BY ";

    if (critere == "Nom") {
        queryStr += "NOM";
    } else if (critere == "Type") {
        queryStr += "TYPE";
    } else if (critere == "DateM") {
        queryStr += "DATEM";
    } else {
        QMessageBox::warning(this, "Erreur", "Critère de tri invalide.");
        return;
    }

    if (ordre == "Descending") {
        queryStr += " DESC";
    } else if (ordre == "Ascending") {
        queryStr += " ASC";
    } else {
        QMessageBox::warning(this, "Erreur", "Ordre de tri invalide.");
        return;
    }

    QSqlQuery query(QSqlDatabase::database("BioVechDBConnection"));
    query.prepare(queryStr);

    if (!query.exec()) {
        qDebug() << "Erreur lors du tri :" << query.lastError().text();
        QMessageBox::critical(this, "Erreur", "Échec du tri.");
        return;
    }

    // Vider et remplir le tableau avec les résultats triés
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("ID").toString()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("NOM").toString()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("TYPE").toString()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value("DATEM").toDate().toString("yyyy-MM-dd")));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(query.value("CARACTERISTIQUE").toString()));
        row++;
    }
}


void MainWindow::trierMicroorganismes()
{
    QString critere = ui->comboBox_2->currentText();
    QString ordre = ui->comboBox_3->currentText();

    QString colonne;
    if (critere == "Nom")
        colonne = "NOM";
    else if (critere == "Type")
        colonne = "TYPE";
    else if (critere == "DateM")
        colonne = "DATEM";
    else
        return;

    QString ordreSQL = (ordre == "Ascending") ? "ASC" : "DESC";

    QSqlQuery query(QSqlDatabase::database("BioVechDBConnection"));
    query.prepare("SELECT * FROM ADMIN.MICROORGANISME ORDER BY " + colonne + " " + ordreSQL);

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors du tri : " + query.lastError().text());
        return;
    }

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("ID").toString()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("NOM").toString()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("TYPE").toString()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value("DATEM").toDate().toString("yyyy-MM-dd")));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(query.value("CARACTERISTIQUE").toString()));
        row++;
    }
}

#include <QtCharts>

void MainWindow::afficherStatistiques()
{
    QSqlQuery query(QSqlDatabase::database("BioVechDBConnection"));

    // Compter par type
    query.prepare("SELECT TYPE, COUNT(*) FROM ADMIN.MICROORGANISME GROUP BY TYPE");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec de récupération des statistiques.");
        return;
    }

    // Création pie chart
    QPieSeries *series = new QPieSeries();
    while (query.next()) {
        series->append(query.value(0).toString(), query.value(1).toInt());
    }

    // Création du graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des micro-organismes par type");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Affichage dans une nouvelle fenêtre
    QDialog *dialog = new QDialog(this);
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(chartView);
    dialog->setLayout(layout);
    dialog->setWindowTitle("Statistiques");
    dialog->resize(600, 400);
    dialog->exec();
}

void MainWindow::on_pushButton_10_clicked()
{
    QSqlQuery query(QSqlDatabase::database("BioVechDBConnection"));
    query.prepare("SELECT * FROM ADMIN.MICROORGANISME");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la récupération des données.");
        return;
    }

    int total = 0;
    QMap<QString, int> typeCount;
    QMap<QDate, int> dateCount;
    QMap<QString, int> nomCount;
    QDate minDate = QDate::currentDate();
    QDate maxDate(1900, 1, 1);

    while (query.next()) {
        total++;
        QString type = query.value("TYPE").toString();
        QString nom = query.value("NOM").toString();
        QDate date = query.value("DATEM").toDate();

        typeCount[type]++;
        nomCount[nom]++;
        dateCount[date]++;

        if (date < minDate) minDate = date;
        if (date > maxDate) maxDate = date;
    }

    // ---------- PIE CHART ----------
    QPieSeries* pieSeries = new QPieSeries();
    for (auto it = typeCount.begin(); it != typeCount.end(); ++it)
        pieSeries->append(it.key(), it.value());

    QChart* pieChart = new QChart();
    pieChart->addSeries(pieSeries);
    pieChart->setTitle("Répartition par Type");

    QChartView* pieView = new QChartView(pieChart);
    pieView->setRenderHint(QPainter::Antialiasing);
    pieView->resize(500, 300);
    pieView->show();

    // ---------- BAR CHART ----------
    QBarSet* set = new QBarSet("Noms");
    QStringList categories;
    for (auto it = nomCount.begin(); it != nomCount.end(); ++it) {
        *set << it.value();
        categories << it.key();
    }

    QBarSeries* barSeries = new QBarSeries();
    barSeries->append(set);

    QChart* barChart = new QChart();
    barChart->addSeries(barSeries);
    barChart->setTitle("Micro-organismes par nom");

    QBarCategoryAxis* axisX = new QBarCategoryAxis();
    axisX->append(categories);
    barChart->createDefaultAxes();
    barChart->setAxisX(axisX, barSeries);

    QChartView* barView = new QChartView(barChart);
    barView->setRenderHint(QPainter::Antialiasing);
    barView->resize(500, 300);
    barView->show();

    // ---------- LINE CHART ----------
    QLineSeries* lineSeries = new QLineSeries();
    QList<QDate> dates = dateCount.keys();
    std::sort(dates.begin(), dates.end());

    for (const QDate& date : dates)
        lineSeries->append(date.toJulianDay(), dateCount[date]);

    QChart* lineChart = new QChart();
    lineChart->addSeries(lineSeries);
    lineChart->setTitle("Évolution par date de découverte");
    lineChart->createDefaultAxes();

    QChartView* lineView = new QChartView(lineChart);
    lineView->setRenderHint(QPainter::Antialiasing);
    lineView->resize(500, 300);
    lineView->show();

    // ---------- STATS TEXTE ----------
    QString statsText;
    statsText += "Total micro-organismes : " + QString::number(total) + "\n";
    statsText += "Date la plus ancienne : " + minDate.toString("dd/MM/yyyy") + "\n";
    statsText += "Date la plus récente  : " + maxDate.toString("dd/MM/yyyy") + "\n";
    statsText += "Nombre de types       : " + QString::number(typeCount.size()) + "\n";
    statsText += "Nombre de noms        : " + QString::number(nomCount.size()) + "\n";

    QMessageBox::information(this, "Statistiques globales", statsText);
}



void MainWindow::on_pushButton_16_clicked()
{
    int id = ui->lineEdit_2->text().toInt(); // Récupérer l'ID entré
    QSqlQuery query(QSqlDatabase::database("BioVechDBConnection"));

    query.prepare("SELECT NOM, TYPE, DATEM, CARACTERISTIQUE FROM ADMIN.MICROORGANISME WHERE ID = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        // Remplir directement les champs
        ui->lineEdit_3->setText(query.value("NOM").toString());  // Nom
        ui->comboBox->setCurrentText(query.value("TYPE").toString());  // Type
        ui->calendarWidget->setSelectedDate(query.value("DATEM").toDate());  // DateM
        ui->lineEdit_6->setText(query.value("CARACTERISTIQUE").toString());  // Caractéristique
    } else {
        QMessageBox::warning(this, "Erreur", "Microorganisme non trouvé !");
    }
}

void MainWindow::on_pushButton_17_clicked() {
    // Prédire l'évolution en utilisant l'ID du microorganisme sélectionné
    PredictionEvolution predictor;
    int idMicroorganisme = ui->lineEdit_2->text().toInt();

    if (idMicroorganisme <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un microorganisme valide.");
        return;
    }

    // Utiliser la classe PredictionEvolution pour prédire l'évolution
    QString evolution = predictor.PredictionEvolution::predireEvolution(idMicroorganisme);

    // Afficher l'évolution dans le lineEdit_4
    ui->lineEdit_4->setPlainText(evolution);
}



void MainWindow::on_pushButton_18_clicked()
{
    QString texte = ui->lineEdit_4->toPlainText();
    QString nom = ui->lineEdit_3->text();
    QString type = ui->comboBox->currentText();
    QString date = ui->calendarWidget->selectedDate().toString("dd/MM/yyyy");

    if (nom.isEmpty() || type.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir le nom et le type.");
        return;
    }

    QStringList documents = texte.split("||", Qt::SkipEmptyParts);
    QMap<QString, QStringList> analyseParBloc;
    QStringList motsCles = { "mutation", "transmission", "symptôme", "symptomes", "résistance", "vaccin", "mortalité" };

    for (const QString& document : documents) {
        QStringList lignes = document.split(QRegularExpression("[\\n\\r]+"), Qt::SkipEmptyParts);
        for (const QString& ligne : lignes) {
            for (const QString& motCle : motsCles) {
                if (ligne.contains(motCle, Qt::CaseInsensitive)) {
                    QString motCleStandardise = motCle.toLower().replace("symptomes", "symptôme");
                    analyseParBloc[motCleStandardise] << ligne.trimmed();
                    break;
                }
            }
        }
    }

    QString fileName = QFileDialog::getSaveFileName(this, tr("Exporter PDF"),
                                                    QDir::homePath() + "/document_analyse.pdf",
                                                    tr("Fichiers PDF (*.pdf)"));
    if (fileName.isEmpty()) return;

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setPageOrientation(QPageLayout::Portrait);

    QPainter painter;
    if (!painter.begin(&printer)) {
        QMessageBox::critical(this, "Erreur", "Impossible de créer le PDF.");
        return;
    }

    const int margin = 40;
    const int contentWidth = printer.pageRect(QPrinter::DevicePixel).width() - 2 * margin;
    int y = margin;

    QFont titleFont = painter.font();
    titleFont.setPointSize(14);
    titleFont.setBold(true);

    QFont sectionFont = painter.font();
    sectionFont.setPointSize(11);
    sectionFont.setBold(true);

    QFont bodyFont = painter.font();
    bodyFont.setPointSize(9);

    // ========== HEADER ==========
    painter.setFont(titleFont);
    painter.drawText(QRect(margin, y, contentWidth, 30), Qt::AlignCenter, "Analyse Préliminaire de Virus");
    y += 60;

    // ========== INFOS ==========
    painter.setFont(sectionFont);
    painter.drawText(margin, y, "Informations de base");
    y += 30;

    painter.setFont(bodyFont);
    painter.drawText(margin, y, QString("Nom : %1").arg(nom));
    y += 20;
    painter.drawText(margin, y, QString("Type : %1").arg(type));
    y += 20;
    painter.drawText(margin, y, QString("Date de découverte : %1").arg(date));
    y += 40;

    // ========== ANALYSE ==========
    for (const QString& motCle : analyseParBloc.keys()) {
        if (y > printer.pageRect(QPrinter::DevicePixel).height() - margin - 100) {
            printer.newPage();
            y = margin;
        }

        painter.setFont(sectionFont);
        painter.drawText(margin, y, QString("Analyse : %1").arg(motCle.toUpper()));
        y += 30;

        painter.setFont(bodyFont);
        double somme = 0;
        int count = 0;
        QRegularExpression regex(R"((\d+(?:[.,]\d+)?)(\s*%?)\b)");

        for (const QString& ligne : analyseParBloc[motCle]) {
            if (y > printer.pageRect(QPrinter::DevicePixel).height() - margin - 50) {
                printer.newPage();
                y = margin;
            }

            QRegularExpressionMatch match = regex.match(ligne);
            QString ligneAffichee = ligne;

            if (match.hasMatch()) {
                QString valeurStr = match.captured(1).replace(',', '.');
                somme += valeurStr.toDouble();
                count++;
                ligneAffichee.remove(match.captured(0));
            }

            // Zone plus haute et espacée
            painter.drawText(QRect(margin, y, contentWidth, 60), Qt::TextWordWrap, ligneAffichee.trimmed());
            y += 35;
        }

        if (count > 0) {
            QString suffixe = analyseParBloc[motCle].join(" ").contains('%') ? "%" : "";
            double moyenne = somme / count;
            painter.setFont(sectionFont);
            painter.drawText(margin, y, QString("→ Moyenne détectée : %1%2").arg(QString::number(moyenne, 'f', 2)).arg(suffixe));
            y += 30;
        }

        y += 40; // espacement important entre les blocs
    }

    painter.end();
    QMessageBox::information(this, tr("Succès"), tr("PDF généré avec succès :\n%1").arg(fileName));
}


void MainWindow::readSerialData(){
    QByteArray data = serial->readAll();
    qDebug() << "Received:" << data;
    // Optionally display it on the UI, e.g. update a QLabel
    ui->label->setText(data);
}

// Front (Z)
/*void MainWindow::on_pushButton_19_clicked()
{
    if (serial && serial->isOpen()) {
        serial->write("Z");  // Send 'Z' to Arduino
        qDebug() << "Sent: Z (Front)";
    }
}

// Back (C)
void MainWindow::on_pushButton_20_clicked()
{
    if (serial && serial->isOpen()) {
        serial->write("C");  // Send 'C' to Arduino
        qDebug() << "Sent: C (Back)";
    }
}

// Right (A)
void MainWindow::on_pushButton_21_clicked()
{
    if (serial && serial->isOpen()) {
        serial->write("A");  // Send 'A' to Arduino
        qDebug() << "Sent: A (Right)";
    }
}

// Left (E)
void MainWindow::on_pushButton_22_clicked()
{
    if (serial && serial->isOpen()) {
        serial->write("E");  // Send 'E' to Arduino
        qDebug() << "Sent: E (Left)";
    }
}

// Send number between 65 and 95 (from lineEdit_5)
void MainWindow::on_lineEdit_5_returnPressed()
{
    if (serial && serial->isOpen()) {
        QString text = ui->lineEdit_5->text();
        bool ok;
        int number = text.toInt(&ok);
        if (ok && number >= 65 && number <= 95) {
            serial->write(text.toUtf8());  // Send the number
            qDebug() << "Sent number:" << number;
        } else {
            QMessageBox::warning(this, "Invalid Input", "Please enter a number between 65 and 95.");
        }
    }
}*/

// Send 'Z' command (Front)
void MainWindow::sendZ()
{
    if (serial && serial->isOpen())
        serial->write("Z");
}

// Send 'C' command (Back)
void MainWindow::sendC()
{
    if (serial && serial->isOpen())
        serial->write("C");
}

// Send 'A' command (Right)
void MainWindow::sendA()
{
    if (serial && serial->isOpen())
        serial->write("A");
}

// Send 'E' command (Left)
void MainWindow::sendE()
{
    if (serial && serial->isOpen())
        serial->write("E");
}

// Send a number input (only between 65 and 95)
void MainWindow::sendNumberInput()
{
    QString text = ui->lineEdit_5->text();
    bool ok;
    int number = text.toInt(&ok);

    if (ok && number >= 65 && number <= 95)
    {
        if (serial && serial->isOpen())
        {
            serial->write(QString::number(number).toUtf8()); // Send the number
            qDebug() << "Sent number:" << number;
        }
    }
    else
    {
        QMessageBox::warning(this, "Invalid Input", "Please enter a number between 65 and 95.");
    }
}

void MainWindow::sendG()
{
    if (serial && serial->isOpen())
        serial->write("G");
}

void MainWindow::sendH()
{
    if (serial && serial->isOpen())
        serial->write("H");
}

void MainWindow::envoyerTypeVersArduino()
{
    if (!serial || !serial->isOpen()) {
        QMessageBox::warning(this, "Erreur", "Le port série n'est pas ouvert !");
        return;
    }

    QString typeTexte = ui->lineEdit_7->text();

    if (typeTexte == "Aéroportée") {
        serial->write("W");
        qDebug() << "Envoyé : W";
    } else {
        serial->write("X");
        qDebug() << "Envoyé : X";
    }
}


void MainWindow::on_lineEdit_8_returnPressed()
{
    QString idTexte = ui->lineEdit_8->text();

    if (idTexte.isEmpty()) {
        QMessageBox::warning(this, "Attention", "Veuillez entrer un ID !");
        return;
    }

    int id = idTexte.toInt();

    QSqlQuery query;
    query.prepare("SELECT TYPE FROM ADMIN.MICROORGANISME WHERE ID = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        if (query.next()) {
            QString type = query.value(0).toString();
            ui->lineEdit_7->setText(type);

            envoyerTypeVersArduino(); // <-- ajoute ici !
        } else {
            QMessageBox::information(this, "Non trouvé", "Aucun micro-organisme trouvé avec cet ID.");
            ui->lineEdit_7->clear();
        }
    }
    else {
        qDebug() << "Erreur SQL:" << query.lastError().text();
    }
}


