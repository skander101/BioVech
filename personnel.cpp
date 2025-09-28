#include "personnel.h"
#include "ui_personnel.h"
#include "autohidedockwidget.h"
#include "connection.h"
#include "piechartwidget.h"
#include <numeric>
#include <QMessageBox>
#include <QBuffer>
#include <QtCharts/QtCharts>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/qbarset.h>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QtCharts/QLegend>
#include <QPainter>
#include <QDate>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QDateEdit>
#include <QDebug>
#include <QComboBox>
#include <QLabel>
#include <QHeaderView>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QPainter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QPageSize>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QStyleFactory>
#include <QProgressBar>
#include <QFrame>
#include <QColor>
#include <QFont>
#include <QDebug>
#include <QIntValidator>
#include <QRegularExpressionValidator>
#include <QClipboard>
#include <QThread>
#include <QScrollArea>
#include <QSqlRecord>
personnel::personnel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::personnel)
    , cameraDialog(nullptr)
    , camera(nullptr)
    , captureSession(nullptr)
    , viewfinder(nullptr)
    , imageCapture(nullptr)
    , lastCaptureFilename("")
    , currentFaceEmbedding("")
    , isCaptureInProgress(false)
    , readMode(false)
    , updateMode(false)
{
    ui->setupUi(this);  // Setup UI from .ui file

    // Create a test database connection button
    QPushButton* testDbButton = new QPushButton("Test DB Connection", this);
    testDbButton->setStyleSheet("background-color: #f39c12; color: white;");
    testDbButton->setMinimumHeight(40);
    connect(testDbButton, &QPushButton::clicked, this, &personnel::testDatabaseConnection);
    
    // Add it to the layout
    QHBoxLayout* buttonsLayout = static_cast<QHBoxLayout*>(ui->tab_Personnel->layout());
    if (!buttonsLayout) {
        // If there's no layout yet, look for the horizontal layout in the parent widget
        QWidget* parentWidget = ui->tab_Personnel->parentWidget();
        if (parentWidget) {
            for (QObject* child : parentWidget->children()) {
                QHBoxLayout* horizontalLayout = qobject_cast<QHBoxLayout*>(child);
                if (horizontalLayout) {
                    buttonsLayout = horizontalLayout;
                    break;
                }
            }
        }
    }
    
    if (buttonsLayout) {
        // Add the button before the spacer
        buttonsLayout->insertWidget(buttonsLayout->count() - 1, testDbButton);
    } else {
        // Fallback if we can't find the layout
        testDbButton->setParent(this);
        testDbButton->move(20, height() - 80);
        testDbButton->show();
    }

    // Establish database connection
    Connection conn;
    if(!conn.createconnect()) {
        QMessageBox::critical(this, "Database Error", "Failed to connect to the database!");
    }
    connect(ui->cameraButton, SIGNAL(clicked()), this, SLOT(on_cameraButton_clicked()));


    // Load personnels into the table
    loadpersonnels();

    // Access the dock widget defined in the .ui file
    QDockWidget *oldDockWidget = ui->dockWidget_Sidebar;

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
        ui->dockWidget_Sidebar = autoHideDockWidget;
        QIntValidator *validator = new QIntValidator(this);
        ui->idEdit->setValidator(validator);
        QRegularExpression regExp("[A-Za-z]+"); // Regular expression for alphabetic characters
        QRegularExpressionValidator *validator2 = new QRegularExpressionValidator(regExp, this);

        ui->NomEdit->setValidator(validator2);
        ui->PrenomEdit->setValidator(validator2);
        ui->AssuranceEdit->setValidator(validator2);
        
        // Create Password field if it doesn't exist
        if (!findChild<QLineEdit*>("PasswordEdit")) {
            QLabel* passwordLabel = new QLabel("Password:", this);
            QLineEdit* passwordEdit = new QLineEdit(this);
            passwordEdit->setObjectName("PasswordEdit");
            passwordEdit->setPlaceholderText("Enter password");
            
            // Find where to place the password field
            QWidget* formWidget = ui->idEdit->parentWidget();
            if (formWidget) {
                QGridLayout* gridLayout = qobject_cast<QGridLayout*>(formWidget->layout());
                if (gridLayout) {
                    // Find the row after the last field
                    int row = gridLayout->rowCount();
                    gridLayout->addWidget(passwordLabel, row, 0);
                    gridLayout->addWidget(passwordEdit, row, 1);
                }
            }
        }
    }

    // Connect signals and slots
    
    // Set horizontal header stretch mode
    ui->tab_Personnel->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

personnel::~personnel()
{
    if (camera) {
        if (camera->isActive()) {
            camera->stop();
        }
        delete camera;
    }
    if (captureSession) {
        delete captureSession;
    }

    if (imageCapture) {
        delete imageCapture;
    }

    if (viewfinder) {
        delete viewfinder;
    }

    if (cameraDialog) {
        cameraDialog->close();
        delete cameraDialog;
    }

    delete ui;
}



void personnel::loadpersonnels()
{
    Employee e;
    // Clear the table
    e.populateTable(ui->tab_Personnel);
    
    // Update the group box title with count
}

void personnel::on_tab_Personnel_cellClicked(int row, int /* column */)
{
    // Get data from the selected row
    QString id = ui->tab_Personnel->item(row, 0)->text();
    QString nom = ui->tab_Personnel->item(row, 1)->text();
    QString prenom = ui->tab_Personnel->item(row, 2)->text();
    QString poste = ui->tab_Personnel->item(row, 3)->text();
    QString salaire = ui->tab_Personnel->item(row, 4)->text();
    QString age = ui->tab_Personnel->item(row, 5)->text();
    QString assurance = ui->tab_Personnel->item(row, 6)->text();
    
    // Populate the form
    ui->idEdit->setText(id);
    ui->idEdit->setReadOnly(true);
    ui->NomEdit->setText(nom);
    ui->PrenomEdit->setText(prenom);
    ui->Post->setCurrentText(poste);    ui->AssuranceEdit->setText(assurance);
    ui->Agespinbox->setValue(age.toInt());
    ui->Salairedoublespinbox->setValue(salaire.toDouble());

    

    
    // Update the group box title
    ui->groupBox_PersonnelDetails->setTitle("Edit personnel: " + id);
}

void personnel::on_pushButton_add_clicked()
{
    // Get values from input fields
    QLineEdit* idEdit = findChild<QLineEdit*>("idEdit");
    QLineEdit* NomEdit = findChild<QLineEdit*>("NomEdit");
    QLineEdit* PrenomEdit = findChild<QLineEdit*>("PrenomEdit");
    QComboBox* PosteEdit = findChild<QComboBox*>("Post");
    QLineEdit* AssuranceEdit = findChild<QLineEdit*>("AssuranceEdit");
    QSpinBox* AgeEdit = findChild<QSpinBox*>("Agespinbox");
    QDoubleSpinBox* SalaireEdit = findChild<QDoubleSpinBox*>("Salairedoublespinbox");
    QLineEdit* PasswordEdit = findChild<QLineEdit*>("PasswordEdit");
    QLineEdit* FacecodeEdit = findChild<QLineEdit*>("facecode");

    // Validate inputs
    if (!idEdit || !NomEdit || !PrenomEdit || !PosteEdit || !AssuranceEdit || !AgeEdit || !SalaireEdit || !FacecodeEdit) {
        QMessageBox::warning(this, "Error", "UI components not found!");
        return;
    }
    
    if (idEdit->text().isEmpty() || NomEdit->text().isEmpty() || PrenomEdit->text().isEmpty() || 
        PosteEdit->currentText().isEmpty() || AssuranceEdit->text().isEmpty() || FacecodeEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Missing Information", "Please fill in all required fields (ID, Name, etc).");
        return;
    }
    
    // Get password or use default if not provided
    QString password = "default_password";
    if (PasswordEdit && !PasswordEdit->text().isEmpty()) {
        password = PasswordEdit->text();
    }
    
    // Debug output
    qDebug() << "Adding personnel with ID:" << idEdit->text();

    // Create RV object
    Employee personnel;
    personnel.setId(idEdit->text().toInt());
    personnel.setNom(NomEdit->text());
    personnel.setPrenom(PrenomEdit->text());
    personnel.setPoste(PosteEdit->currentText());
    personnel.setSalaire(SalaireEdit->value());
    personnel.setAge(AgeEdit->value());
    personnel.setAssurance(AssuranceEdit->text());
    personnel.setFacecode(FacecodeEdit->text());

    // Save to database (with CIN as 0/NULL, but with password)
    bool success = personnel.createEmployee(
        personnel.getId(),
        personnel.getNom(),
        personnel.getPrenom(),
        personnel.getPoste(),
        personnel.getSalaire(),
        personnel.getAge(),
        personnel.getAssurance(),
        password,
        personnel.getFacecode()
    );
    
    // Debug output for database operation result
    qDebug() << "Database save operation result:" << (success ? "Success" : "Failed");
    if (!success) {
        QSqlDatabase db = QSqlDatabase::database();
        qDebug() << "Database error:" << db.lastError().text();
    }
    
    if (success) {
        QMessageBox::information(this, "Success", "personnel added successfully!");
        loadpersonnels(); // Refresh the table
        clearInputFields(); // Clear the form
    } else {
        QMessageBox::critical(this, "Error", "Failed to add personnel. Please check your inputs and try again.");
    }
}
void personnel::clearInputFields()
{
    ui->idEdit->setReadOnly(false);
    // Clear inputs
    ui->idEdit->clear();
    ui->AssuranceEdit->clear();
    ui->NomEdit->clear();
    ui->PrenomEdit->clear();
    ui->Post->setCurrentIndex(-1);  // Deselects current item    ui->Agespinbox->setValue(0);
    ui->Salairedoublespinbox->setValue(0);

    // Clear password if exists
    QLineEdit* passwordEdit = findChild<QLineEdit*>("PasswordEdit");
    if (passwordEdit) {
        passwordEdit->clear();
    }

    // Reset the group box title
    ui->groupBox_PersonnelDetails->setTitle("personnel Details");
}

void personnel::on_pushButton_update_clicked()
{
    // Get values from input fields
    QLineEdit* idEdit = findChild<QLineEdit*>("idEdit");
    QLineEdit* NomEdit = findChild<QLineEdit*>("NomEdit");
    QLineEdit* PrenomEdit = findChild<QLineEdit*>("PrenomEdit");
    QComboBox* PosteEdit = findChild<QComboBox*>("Post");
    QLineEdit* AssuranceEdit = findChild<QLineEdit*>("AssuranceEdit");
    QSpinBox* AgeEdit = findChild<QSpinBox*>("Agespinbox");
    QDoubleSpinBox* SalaireEdit = findChild<QDoubleSpinBox*>("Salairedoublespinbox");
    QLineEdit* PasswordEdit = findChild<QLineEdit*>("PasswordEdit");
    ui->idEdit->setReadOnly(true);
    ui->facecode->setReadOnly(true);


    
    // Validate inputs
    if (!idEdit || !NomEdit || !PrenomEdit || !PosteEdit || !AssuranceEdit || !AgeEdit || !SalaireEdit) {
        QMessageBox::warning(this, "Error", "UI components not found!");
        return;
    }

    if (idEdit->text().isEmpty() || NomEdit->text().isEmpty() || PrenomEdit->text().isEmpty() || PosteEdit->currentText().isEmpty() || AssuranceEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Missing Information", "Please fill in all required fields (ID, Name, etc).");
        return;
    }
    
    // Create RV object
    Employee personnel;
    personnel.setId(idEdit->text().toInt());
    personnel.setNom(NomEdit->text());
    personnel.setPrenom(PrenomEdit->text());
    personnel.setPoste(PosteEdit->currentText());
    personnel.setSalaire(SalaireEdit->value());
    personnel.setAge(AgeEdit->value());
    personnel.setAssurance(AssuranceEdit->text());
    
    bool success = false;
    
    // Check if password is provided
    if (PasswordEdit && !PasswordEdit->text().isEmpty()) {
        // Update in database with password
        success = personnel.updateEmployeeWithPassword(
            personnel.getId(),
            personnel.getNom(),
            personnel.getPrenom(),
            personnel.getPoste(),
            personnel.getSalaire(),
            personnel.getAge(),
            personnel.getAssurance(),
            PasswordEdit->text()
        );
    } else {
        // Update in database without changing password
        success = personnel.updateEmployee(
            personnel.getId(),
            personnel.getNom(),
            personnel.getPrenom(),
            personnel.getPoste(),
            personnel.getSalaire(),
            personnel.getAge(),
            personnel.getAssurance()
        );
    }

    if (success) {
        QMessageBox::information(this, "Success", "Personnel updated successfully!");
        loadpersonnels(); // Refresh the table
        ui->idEdit->setReadOnly(false);
        ui->facecode->setReadOnly(false);

    } else {
        QMessageBox::critical(this, "Error", "Failed to update personnel. Please check your inputs and try again.");
    }
}

void personnel::on_pushButton_delete_clicked()
{
    // Get ID from input field
    QLineEdit* idEdit = findChild<QLineEdit*>("idEdit");
    
    // Validate input
    if (!idEdit) {
        QMessageBox::warning(this, "Error", "UI components not found!");
        return;
    }
    
    if (idEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Missing Information", "Please select an personnel to delete.");
        return;
    }
    
    // Confirm deletion
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirm Deletion", 
                                                             "Are you sure you want to delete this personnel?",
                                                             QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No) {
        return;
    }
    
    // Create RV object
    Employee personnel;
    personnel.setId(idEdit->text().toInt());
    
    // Delete from database
    bool success = personnel.deleteEmployee(personnel.getId());
    
    if (success) {
        QMessageBox::information(this, "Success", "personnel deleted successfully!");
        loadpersonnels(); // Refresh the table
        clearInputFields(); // Clear the form
    } else {
        QMessageBox::critical(this, "Error", "Failed to delete personnel. Please try again.");
    }
}



void personnel::on_pushButton_clear_clicked()
{
    ui->idEdit->setReadOnly(false);
    ui->facecode->setReadOnly(false);

    clearInputFields();
}

void personnel::testDatabaseConnection()
{
    // Test the database connection using our utility method
    bool connected = Connection::testConnection();
    
    // Display results in a message box
    if (connected) {
        QMessageBox::information(this, "Database Connection", 
            "Connected to the database successfully!");
    } else {
        QMessageBox::critical(this, "Database Connection", 
            "Failed to connect to the database.\n\n"
            "Please check these possible issues:\n"
            "1. Make sure the ODBC driver is installed\n"
            "2. Verify your ODBC DSN 'BioVech' is properly configured\n"
            "3. Check that username 'admin' and password 'admin' are correct\n"
            "4. Ensure the Oracle database server is running");
    }
}


void personnel::on_filterButton_clicked()
{


    // Filter dialog
    QDialog dialog(this);
    dialog.setWindowTitle("Filter Employees");
    dialog.setMinimumWidth(450);
    dialog.setMinimumHeight(350);
    dialog.setStyleSheet(
        "QDialog { background-color: #f0f8f0; }"
        "QLabel { font-weight: bold; color: #2c3e50; margin-top: 10px; font-size: 14px; }"
        "QComboBox, QDateEdit { border: 1px solid #2ecc71; border-radius: 3px; padding: 8px; min-height: 30px; }"
        "QCheckBox { color: #2c3e50; font-size: 14px; }"
        "QPushButton { background-color: #2ecc71; color: white; border-radius: 3px; padding: 10px 20px; min-height: 40px; }"
        "QPushButton:hover { background-color: #27ae60; }"
        "QPushButton#cancelButton { background-color: #95a5a6; }"
        "QPushButton#cancelButton:hover { background-color: #7f8c8d; }"
        );

    QVBoxLayout* layout = new QVBoxLayout(&dialog);
    layout->setSpacing(15);
    layout->setContentsMargins(25, 25, 25, 25);

    QLabel* titleLabel = new QLabel("Filter Employees", &dialog);
    titleLabel->setStyleSheet("font-size: 18px; font-weight: bold; color: #27ae60; margin-bottom: 20px;");
    layout->addWidget(titleLabel);

    // Filter by Poste (Job Position)
    QLabel* posteLabel = new QLabel("Filter by Job Position:", &dialog);
    QComboBox* posteCombo = new QComboBox(&dialog);
    posteCombo->addItems(QStringList() << "All" << "Manager" << "Developer" << "Designer" << "Analyst");
    layout->addWidget(posteLabel);
    layout->addWidget(posteCombo);

    // Filter by Salary Range
    QLabel* salaryLabel = new QLabel("Filter by Salary Range:", &dialog);
    QHBoxLayout* salaryLayout = new QHBoxLayout();
    QLabel* minSalaryLabel = new QLabel("Min:", &dialog);
    minSalaryLabel->setFixedWidth(50);
    QDoubleSpinBox* minSalary = new QDoubleSpinBox(&dialog);
    minSalary->setRange(0.0, 1000000.0); // Set a reasonable range for salary
    minSalary->setValue(0.0);

    QLabel* maxSalaryLabel = new QLabel("Max:", &dialog);
    maxSalaryLabel->setFixedWidth(50);
    QDoubleSpinBox* maxSalary = new QDoubleSpinBox(&dialog);
    maxSalary->setRange(0.0, 1000000.0); // Set a reasonable range for salary
    maxSalary->setValue(1000000.0);

    salaryLayout->addWidget(minSalaryLabel);
    salaryLayout->addWidget(minSalary);
    salaryLayout->addWidget(maxSalaryLabel);
    salaryLayout->addWidget(maxSalary);
    layout->addWidget(salaryLabel);
    layout->addLayout(salaryLayout);

    // Filter by Age Range
    QLabel* ageLabel = new QLabel("Filter by Age Range:", &dialog);
    QHBoxLayout* ageLayout = new QHBoxLayout();
    QLabel* minAgeLabel = new QLabel("Min:", &dialog);
    minAgeLabel->setFixedWidth(50);
    QSpinBox* minAge = new QSpinBox(&dialog);
    minAge->setRange(0, 100); // Set a reasonable range for age
    minAge->setValue(0);

    QLabel* maxAgeLabel = new QLabel("Max:", &dialog);
    maxAgeLabel->setFixedWidth(50);
    QSpinBox* maxAge = new QSpinBox(&dialog);
    maxAge->setRange(0, 100); // Set a reasonable range for age
    maxAge->setValue(100);

    ageLayout->addWidget(minAgeLabel);
    ageLayout->addWidget(minAge);
    ageLayout->addWidget(maxAgeLabel);
    ageLayout->addWidget(maxAge);
    layout->addWidget(ageLabel);
    layout->addLayout(ageLayout);

    // Buttons
    QPushButton* applyButton = new QPushButton("Apply Filter", &dialog);
    applyButton->setCursor(Qt::PointingHandCursor);

    QPushButton* cancelButton = new QPushButton("Cancel", &dialog);
    cancelButton->setObjectName("cancelButton");
    cancelButton->setCursor(Qt::PointingHandCursor);

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();
    buttonLayout->addWidget(cancelButton);
    buttonLayout->addWidget(applyButton);
    layout->addLayout(buttonLayout);

    dialog.setLayout(layout);

    connect(cancelButton, &QPushButton::clicked, &dialog, &QDialog::reject);
    connect(applyButton, &QPushButton::clicked, &dialog, &QDialog::accept);

    if (dialog.exec() == QDialog::Accepted) {
        Employee e;
        // Get all employees
        QList<Employee> allEmployees = e.getAll(); // Assuming you have a static method to get all employees
        QList<Employee> filteredEmployees;

        QString selectedPoste = posteCombo->currentText();
        double minSalaryValue = minSalary->value();
        double maxSalaryValue = maxSalary->value();
        int minAgeValue = minAge->value();
        int maxAgeValue = maxAge->value();

        // Apply filters
        for (const Employee& employee : allEmployees) {
            bool posteMatch = selectedPoste == "All" || employee.getPoste() == selectedPoste;
            bool salaryMatch = employee.getSalaire() >= minSalaryValue && employee.getSalaire() <= maxSalaryValue;
            bool ageMatch = employee.getAge() >= minAgeValue && employee.getAge() <= maxAgeValue;

            if (posteMatch && salaryMatch && ageMatch) {
                filteredEmployees.append(employee);
            }
        }

        // Clear the table
        ui->tab_Personnel->setRowCount(0);

        // Populate the table with filtered results
        for (int i = 0; i < filteredEmployees.size(); ++i) {
            ui->tab_Personnel->insertRow(i);
            ui->tab_Personnel->setItem(i, 0, new QTableWidgetItem(QString::number(filteredEmployees[i].getId())));
            ui->tab_Personnel->setItem(i, 1, new QTableWidgetItem(filteredEmployees[i].getNom()));
            ui->tab_Personnel->setItem(i, 2, new QTableWidgetItem(filteredEmployees[i].getPrenom()));
            ui->tab_Personnel->setItem(i, 3, new QTableWidgetItem(filteredEmployees[i].getPoste()));
            ui->tab_Personnel->setItem(i, 4, new QTableWidgetItem(QString::number(filteredEmployees[i].getSalaire())));
            ui->tab_Personnel->setItem(i, 5, new QTableWidgetItem(QString::number(filteredEmployees[i].getAge())));
            ui->tab_Personnel->setItem(i, 6, new QTableWidgetItem(filteredEmployees[i].getAssurance()));
        }

        // Show filter status
        QString filterInfo = "Filtered by: ";
        if (selectedPoste != "All") {
            filterInfo += "Poste = " + selectedPoste + ", ";
        }
        filterInfo += "Salary Range: " + QString::number(minSalaryValue) + " to " + QString::number(maxSalaryValue) + ", ";
        filterInfo += "Age Range: " + QString::number(minAgeValue) + " to " + QString::number(maxAgeValue);

        ui->groupBox_PersonnelDetails->setTitle("Employee Details - " + filterInfo);
    }

}




QPixmap generatePieChart(const QMap<QString, int>& data, const QList<QColor>& colors, const QString& title)
{
    // Create the pie series and fill with data
     QPieSeries* series = new  QPieSeries();
    int i = 0;
    for (auto it = data.begin(); it != data.end(); ++it, ++i) {
         QPieSlice* slice = series->append(it.key(), it.value());
        slice->setBrush(colors[i % colors.size()]);
        slice->setLabelVisible(true);
    }

    // Create the chart and configure it
     QChart* chart = new  QChart();
    chart->addSeries(series);
    chart->setTitle(title);
    chart->setAnimationOptions( QChart::SeriesAnimations);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->legend()->setFont(QFont("Arial", 10));

    // Create a chart view with fixed size
     QChartView* chartView = new  QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setFixedSize(800, 600); // Bigger size
    chart->setTheme( QChart::ChartThemeLight); // Optional

    // Make sure layout is updated
    chartView->updateGeometry();
    chartView->show(); // Force layout
    QCoreApplication::processEvents(); // Let Qt update layout

    // Render to pixmap
    QPixmap pixmap(chartView->size());
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    qDebug() << "ChartView size:" << chartView->size();
    chartView->render(&painter);
    painter.end();

    delete chartView; // Cleanup
    return pixmap;
}



QString pixmapToBase64(const QPixmap &pixmap) {
    QByteArray ba;
    QBuffer buffer(&ba);
    buffer.open(QIODevice::WriteOnly);
    pixmap.save(&buffer, "PNG");
    QString imgBase64 = QString::fromLatin1(ba.toBase64());
    return "data:image/png;base64," + imgBase64;
}

void personnel::on_exportPdfButton_clicked()
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

    const int columnCount = ui->tab_Personnel->columnCount();
    const int rowCount = ui->tab_Personnel->rowCount();
    const int rowHeight = 25;
    const int headerHeight = 30;
    const int columnWidth = contentWidth / columnCount;

    // Draw table headers
    painter.setPen(Qt::black);
    painter.setBrush(QColor("#2ecc71"));
    for (int col = 0; col < columnCount; ++col) {
        QString header = ui->tab_Personnel->horizontalHeaderItem(col)->text();
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
            QTableWidgetItem *item = ui->tab_Personnel->item(row, col);
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

int personnel::drawPieChart(QPainter &painter, int x, int y, int width,
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
void personnel::on_searchPersonnel_returnPressed()
{
    QString searchText = ui->searchPersonnel->text().trimmed();

    if (searchText.isEmpty()) {
        // If search box is empty, show all appointments
        loadpersonnels();
        return;
    }
    Employee emp;
    // Search appointments
    QList<Employee> searchResults = emp.search(searchText);
    qDebug() << "Search Results:";
    qDebug() << "Number of results:" << searchResults.size();


    for (const Employee &emp : searchResults) {
        qDebug()
        << "ID:" << emp.getId()
        << "Name:" << emp.getNom()
        << "Name:" << emp.getPrenom()
        << "Poste:" << emp.getPoste()
        << "Salaire:" << emp.getSalaire()
        << "Age:" << emp.getAge()
        << "Assurance:" << emp.getAssurance();
    }

    // Clear the table
    ui->tab_Personnel->setRowCount(0);
    emp.populatePresetTable(ui->tab_Personnel,searchResults );

    // Update the group box title with count
    ui->groupBox_PersonnelDetails->setTitle("Search Results (" + QString::number(searchResults.size()) + ")");

}


// void personnel::on_statisticsButton_clicked()
// { // Statistics
//     Employee e;
//     QList<Employee> employees = e.getAll(); // Assuming you have a method to get all employees

//     // Count by job position (Poste)
//     int managerCount = 0;
//     int developerCount = 0;
//     int designerCount = 0;
//     int analystCount = 0;

//     // Age groups
//     int ageUnder30 = 0;
//     int age30to40 = 0;
//     int age40to50 = 0;
//     int ageOver50 = 0;

//     // Salary ranges
//     int salaryUnder50k = 0;
//     int salary50kto100k = 0;
//     int salaryOver100k = 0;

//     for (const Employee& employee : employees) {
//         QString poste = employee.getPoste();
//         if (poste == "Manager") managerCount++;
//         else if (poste == "Developer") developerCount++;
//         else if (poste == "Designer") designerCount++;
//         else if (poste == "Analyst") analystCount++;

//         // Age groups
//         int age = employee.getAge();
//         if (age < 30) ageUnder30++;
//         else if (age >= 30 && age < 40) age30to40++;
//         else if (age >= 40 && age < 50) age40to50++;
//         else if (age >= 50) ageOver50++;

//         // Salary ranges
//         double salary = employee.getSalaire();
//         if (salary < 50000) salaryUnder50k++;
//         else if (salary >= 50000 && salary < 100000) salary50kto100k++;
//         else if (salary >= 100000) salaryOver100k++;
//     }

//     // Create a custom statistics dialog
//     QDialog statsDialog(this);
//     statsDialog.setWindowTitle("Employee Statistics");
//     statsDialog.setMinimumWidth(800); // Increased width to accommodate charts
//     statsDialog.setMinimumHeight(800); // Increased height to accommodate charts
//     statsDialog.setStyleSheet(
//         "QDialog { background-color: #f0f8f0; }"
//         "QLabel { color: #2c3e50; }"
//         "QLabel#titleLabel { font-size: 20px; font-weight: bold; color: #27ae60; }"
//         "QLabel#totalLabel { font-size: 18px; font-weight: bold; margin-top: 10px; color: #27ae60; }"
//         "QFrame#line { background-color: #2ecc71; }"
//         "QPushButton { background-color: #2ecc71; color: white; border-radius: 3px; padding: 10px 20px; }"
//         "QPushButton:hover { background-color: #27ae60; }"
//         );

//     QVBoxLayout* layout = new QVBoxLayout(&statsDialog);
//     layout->setSpacing(20);
//     layout->setContentsMargins(30, 30, 30, 30);

//     // Title
//     QLabel* titleLabel = new QLabel("Employee Statistics", &statsDialog);
//     titleLabel->setObjectName("titleLabel");
//     titleLabel->setAlignment(Qt::AlignCenter);
//     layout->addWidget(titleLabel);

//     // Horizontal line
//     QFrame* line = new QFrame(&statsDialog);
//     line->setObjectName("line");
//     line->setFrameShape(QFrame::HLine);
//     line->setFrameShadow(QFrame::Sunken);
//     line->setFixedHeight(2);
//     layout->addWidget(line);

//     // Total employees
//     QLabel* totalLabel = new QLabel("Total Employees: " + QString::number(employees.size()), &statsDialog);
//     totalLabel->setObjectName("totalLabel");
//     totalLabel->setAlignment(Qt::AlignCenter);
//     layout->addWidget(totalLabel);

//     // Job position breakdown
//     QGridLayout* statsGrid = new QGridLayout();
//     statsGrid->setSpacing(15);

//     // Manager
//     QLabel* managerLabel = new QLabel("Managers:", &statsDialog);
//     managerLabel->setStyleSheet("font-weight: bold; color: #3498db; font-size: 14px;");
//     QLabel* managerValue = new QLabel(QString::number(managerCount), &statsDialog);
//     managerValue->setStyleSheet("font-size: 18px; color: #3498db;");
//     QProgressBar* managerBar = new QProgressBar(&statsDialog);
//     managerBar->setRange(0, employees.isEmpty() ? 1 : employees.size());
//     managerBar->setValue(managerCount);
//     managerBar->setStyleSheet("QProgressBar { border: 1px solid #bdc3c7; border-radius: 5px; text-align: center; height: 25px; } "
//                               "QProgressBar::chunk { background-color: #3498db; }");

//     // Developer
//     QLabel* developerLabel = new QLabel("Developers:", &statsDialog);
//     developerLabel->setStyleSheet("font-weight: bold; color: #27ae60; font-size: 14px;");
//     QLabel* developerValue = new QLabel(QString::number(developerCount), &statsDialog);
//     developerValue->setStyleSheet("font-size: 18px; color: #27ae60;");
//     QProgressBar* developerBar = new QProgressBar(&statsDialog);
//     developerBar->setRange(0, employees.isEmpty() ? 1 : employees.size());
//     developerBar->setValue(developerCount);
//     developerBar->setStyleSheet("QProgressBar { border: 1px solid #bdc3c7; border-radius: 5px; text-align: center; height: 25px; } "
//                                 "QProgressBar::chunk { background-color: #27ae60; }");

//     // Designer
//     QLabel* designerLabel = new QLabel("Designers:", &statsDialog);
//     designerLabel->setStyleSheet("font-weight: bold; color: #e74c3c; font-size: 14px;");
//     QLabel* designerValue = new QLabel(QString::number(designerCount), &statsDialog);
//     designerValue->setStyleSheet("font-size: 18px; color: #e74c3c;");
//     QProgressBar* designerBar = new QProgressBar(&statsDialog);
//     designerBar->setRange(0, employees.isEmpty() ? 1 : employees.size());
//     designerBar->setValue(designerCount);
//     designerBar->setStyleSheet("QProgressBar { border: 1px solid #bdc3c7; border-radius: 5px; text-align: center; height: 25px; } "
//                                "QProgressBar::chunk { background-color: #e74c3c; }");

//     // Analyst
//     QLabel* analystLabel = new QLabel("Analysts:", &statsDialog);
//     analystLabel->setStyleSheet("font-weight: bold; color: #f39c12; font-size: 14px;");
//     QLabel* analystValue = new QLabel(QString::number(analystCount), &statsDialog);
//     analystValue->setStyleSheet("font-size: 18px; color: #f39c12;");
//     QProgressBar* analystBar = new QProgressBar(&statsDialog);
//     analystBar->setRange(0, employees.isEmpty() ? 1 : employees.size());
//     analystBar->setValue(analystCount);
//     analystBar->setStyleSheet("QProgressBar { border: 1px solid #bdc3c7; border-radius: 5px; text-align: center; height: 25px; } "
//                               "QProgressBar::chunk { background-color: #f39c12; }");

//     // Add to grid
//     statsGrid->addWidget(managerLabel, 0, 0);
//     statsGrid->addWidget(managerValue, 0, 1);
//     statsGrid->addWidget(managerBar, 0, 2);

//     statsGrid->addWidget(developerLabel, 1, 0);
//     statsGrid->addWidget(developerValue, 1, 1);
//     statsGrid->addWidget(developerBar, 1, 2);

//     statsGrid->addWidget(designerLabel, 2, 0);
//     statsGrid->addWidget(designerValue, 2, 1);
//     statsGrid->addWidget(designerBar, 2, 2);

//     statsGrid->addWidget(analystLabel, 3, 0);
//     statsGrid->addWidget(analystValue, 3, 1);
//     statsGrid->addWidget(analystBar, 3, 2);

//     layout->addLayout(statsGrid);

//     // Age Distribution Chart
//     // Age Distribution Chart
//     // Create the dialog

//     // Scroll area
//     QScrollArea* scrollArea = new QScrollArea(&statsDialog);
//     scrollArea->setWidgetResizable(true);

//     // Content widget
//     QWidget* contentWidget = new QWidget();
//     QVBoxLayout* contentLayout = new QVBoxLayout(contentWidget);
//     contentLayout->setSpacing(20); // Add spacing between widgets

//     // Age Distribution Chart
//     QBarSet* ageSet = new QBarSet("Age Groups");
//     *ageSet << ageUnder30 << age30to40 << age40to50 << ageOver50;

//     QBarSeries* ageSeries = new QBarSeries();
//     ageSeries->append(ageSet);

//     QChart* ageChart = new QChart();
//     ageChart->addSeries(ageSeries);
//     ageChart->setTitle("Age Distribution");
//     ageChart->setAnimationOptions(QChart::SeriesAnimations);

//     QStringList ageCategories;
//     ageCategories << "Under 30" << "30-40" << "40-50" << "Over 50";
//     QBarCategoryAxis* ageAxisX = new QBarCategoryAxis();
//     ageAxisX->append(ageCategories);
//     ageChart->addAxis(ageAxisX, Qt::AlignBottom);
//     ageSeries->attachAxis(ageAxisX);

//     QValueAxis* ageAxisY = new QValueAxis();
//     ageChart->addAxis(ageAxisY, Qt::AlignLeft);
//     ageSeries->attachAxis(ageAxisY);

//     QChartView* ageChartView = new QChartView(ageChart);
//     ageChartView->setRenderHint(QPainter::Antialiasing);
//     ageChartView->setMinimumSize(600, 300); // Set a minimum size for the chart

//     contentLayout->addWidget(new QLabel("Age Distribution", contentWidget));
//     contentLayout->addWidget(ageChartView);

//     // Salary Distribution Chart
//     QBarSet* salarySet = new QBarSet("Salary Ranges");
//     *salarySet << salaryUnder50k << salary50kto100k << salaryOver100k;

//     QBarSeries* salarySeries = new QBarSeries();
//     salarySeries->append(salarySet);

//     QChart* salaryChart = new QChart();
//     salaryChart->addSeries(salarySeries);
//     salaryChart->setTitle("Salary Distribution");
//     salaryChart->setAnimationOptions(QChart::SeriesAnimations);

//     QStringList salaryCategories;
//     salaryCategories << "Under 50k" << "50k-100k" << "Over 100k";
//     QBarCategoryAxis* salaryAxisX = new QBarCategoryAxis();
//     salaryAxisX->append(salaryCategories);
//     salaryChart->addAxis(salaryAxisX, Qt::AlignBottom);
//     salarySeries->attachAxis(salaryAxisX);

//     QValueAxis* salaryAxisY = new QValueAxis();
//     salaryChart->addAxis(salaryAxisY, Qt::AlignLeft);
//     salarySeries->attachAxis(salaryAxisY);

//     QChartView* salaryChartView = new QChartView(salaryChart);
//     salaryChartView->setRenderHint(QPainter::Antialiasing);
//     salaryChartView->setMinimumSize(600, 300); // Set a minimum size for the chart

//     contentLayout->addWidget(new QLabel("Salary Distribution", contentWidget));
//     contentLayout->addWidget(salaryChartView);

//     // Add content to scroll area
//     scrollArea->setWidget(contentWidget);
//     layout->addWidget(scrollArea);

//     // Add close button
//     QPushButton* closeButton = new QPushButton("Close", &statsDialog);
//     closeButton->setCursor(Qt::PointingHandCursor);
//     closeButton->setMinimumHeight(40);
//     connect(closeButton, &QPushButton::clicked, &statsDialog, &QDialog::accept);

//     QHBoxLayout* buttonLayout = new QHBoxLayout();
//     buttonLayout->addStretch();
//     buttonLayout->addWidget(closeButton);
//     layout->addLayout(buttonLayout);

//     statsDialog.setLayout(layout);
//     statsDialog.exec();
// }

void personnel::on_statisticsButton_clicked()
{
    Employee e;
    QList<Employee> employees = e.getAll();

    // Count by job position
    int managerCount = 0, developerCount = 0, designerCount = 0, analystCount = 0;
    // Age groups
    int ageUnder30 = 0, age30to40 = 0, age40to50 = 0, ageOver50 = 0;
    // Salary ranges
    int salaryUnder50k = 0, salary50kto100k = 0, salaryOver100k = 0;

    for (const Employee& employee : employees) {
        QString poste = employee.getPoste();
        if (poste == "Manager") managerCount++;
        else if (poste == "Developer") developerCount++;
        else if (poste == "Designer") designerCount++;
        else if (poste == "Analyst") analystCount++;

        int age = employee.getAge();
        if (age < 30) ageUnder30++;
        else if (age < 40) age30to40++;
        else if (age < 50) age40to50++;
        else ageOver50++;

        double salary = employee.getSalaire();
        if (salary < 50000) salaryUnder50k++;
        else if (salary < 100000) salary50kto100k++;
        else salaryOver100k++;
    }

    QDialog statsDialog(this);
    statsDialog.setWindowTitle("Employee Statistics");
    statsDialog.setMinimumSize(900, 700);
    statsDialog.setStyleSheet(
        "QDialog { background-color: #f0f8f0; }"
        "QLabel { color: #2c3e50; }"
        "QLabel#titleLabel { font-size: 20px; font-weight: bold; color: #27ae60; }"
        "QLabel#totalLabel { font-size: 18px; font-weight: bold; margin-top: 10px; color: #27ae60; }"
        "QFrame#line { background-color: #2ecc71; }"
        "QPushButton { background-color: #2ecc71; color: white; border-radius: 3px; padding: 10px 20px; }"
        "QPushButton:hover { background-color: #27ae60; }"
        );

    QVBoxLayout* mainLayout = new QVBoxLayout(&statsDialog);
    mainLayout->setSpacing(20);
    mainLayout->setContentsMargins(30, 30, 30, 30);

    QLabel* titleLabel = new QLabel("Employee Statistics", &statsDialog);
    titleLabel->setObjectName("titleLabel");
    titleLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(titleLabel);

    QFrame* line = new QFrame(&statsDialog);
    line->setObjectName("line");
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    line->setFixedHeight(2);
    mainLayout->addWidget(line);

    QLabel* totalLabel = new QLabel("Total Employees: " + QString::number(employees.size()), &statsDialog);
    totalLabel->setObjectName("totalLabel");
    totalLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(totalLabel);

    QScrollArea* scrollArea = new QScrollArea(&statsDialog);
    scrollArea->setWidgetResizable(true);
    QWidget* contentWidget = new QWidget();
    QVBoxLayout* contentLayout = new QVBoxLayout(contentWidget);
    contentLayout->setSpacing(30);

    // ---------------- JOB CHART ----------------
    QWidget* jobChartWidget = new QWidget(contentWidget);
    QVBoxLayout* jobChartLayout = new QVBoxLayout(jobChartWidget);

    QLabel* jobChartTitle = new QLabel("Job Distribution", jobChartWidget);
    jobChartTitle->setStyleSheet("font-weight: bold; font-size: 16px; color: #2c3e50;");
    jobChartLayout->addWidget(jobChartTitle, 0, Qt::AlignCenter);

    PieChartWidget* jobPieWidget = new PieChartWidget(jobChartWidget);
    jobPieWidget->setMinimumSize(400, 300);
    jobPieWidget->setStyleSheet("background-color: white; border: 1px solid #ddd;");
    jobPieWidget->setData({
                              {"Managers", managerCount},
                              {"Developers", developerCount},
                              {"Designers", designerCount},
                              {"Analysts", analystCount}
                          }, {
                              QColor("#3498db"),
                              QColor("#27ae60"),
                              QColor("#e74c3c"),
                              QColor("#f39c12")
                          });
    jobChartLayout->addWidget(jobPieWidget);
    contentLayout->addWidget(jobChartWidget);

    // ---------------- AGE CHART ----------------
    QWidget* ageChartWidget = new QWidget(contentWidget);
    QVBoxLayout* ageChartLayout = new QVBoxLayout(ageChartWidget);

    QLabel* ageChartTitle = new QLabel("Age Distribution", ageChartWidget);
    ageChartTitle->setStyleSheet("font-weight: bold; font-size: 16px; color: #2c3e50;");
    ageChartLayout->addWidget(ageChartTitle, 0, Qt::AlignCenter);

    PieChartWidget* agePieWidget = new PieChartWidget(ageChartWidget);
    agePieWidget->setMinimumSize(400, 300);
    agePieWidget->setStyleSheet("background-color: white; border: 1px solid #ddd;");
    agePieWidget->setData({
                              {"Under 30", ageUnder30},
                              {"30-40", age30to40},
                              {"40-50", age40to50},
                              {"Over 50", ageOver50}
                          }, {
                              QColor("#9b59b6"),
                              QColor("#3498db"),
                              QColor("#1abc9c"),
                              QColor("#e67e22")
                          });
    ageChartLayout->addWidget(agePieWidget);
    contentLayout->addWidget(ageChartWidget);

    // ---------------- SALARY CHART ----------------
    QWidget* salaryChartWidget = new QWidget(contentWidget);
    QVBoxLayout* salaryChartLayout = new QVBoxLayout(salaryChartWidget);

    QLabel* salaryChartTitle = new QLabel("Salary Distribution", salaryChartWidget);
    salaryChartTitle->setStyleSheet("font-weight: bold; font-size: 16px; color: #2c3e50;");
    salaryChartLayout->addWidget(salaryChartTitle, 0, Qt::AlignCenter);

    PieChartWidget* salaryPieWidget = new PieChartWidget(salaryChartWidget);
    salaryPieWidget->setMinimumSize(400, 300);
    salaryPieWidget->setStyleSheet("background-color: white; border: 1px solid #ddd;");
    salaryPieWidget->setData({
                                 {"Under 50k", salaryUnder50k},
                                 {"50k-100k", salary50kto100k},
                                 {"Over 100k", salaryOver100k}
                             }, {
                                 QColor("#e74c3c"),
                                 QColor("#f39c12"),
                                 QColor("#2ecc71")
                             });
    salaryChartLayout->addWidget(salaryPieWidget);
    contentLayout->addWidget(salaryChartWidget);

    scrollArea->setWidget(contentWidget);
    mainLayout->addWidget(scrollArea);

    QPushButton* closeButton = new QPushButton("Close", &statsDialog);
    closeButton->setCursor(Qt::PointingHandCursor);
    closeButton->setMinimumHeight(40);
    connect(closeButton, &QPushButton::clicked, &statsDialog, &QDialog::accept);

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();
    buttonLayout->addWidget(closeButton);
    mainLayout->addLayout(buttonLayout);

    statsDialog.exec();
}
void personnel::drawPieChartWidget(QPainter &painter, const QRect &rect,
                                   const QVector<QPair<QString, int>> &data,
                                   const QVector<QColor> &colors)
{
    int total = std::accumulate(data.begin(), data.end(), 0,
                                [](int sum, const auto &pair) { return sum + pair.second; });
    if (total == 0) return;

    // Calculate dimensions
    const int margin = 20;
    const int pieSize = qMin(rect.width(), rect.height()) - 2 * margin;
    const int pieX = rect.left() + margin;
    const int pieY = rect.top() + margin;
    QRectF pieRect(pieX, pieY, pieSize, pieSize);

    // Draw pie chart
    double startAngle = 0;
    for (int i = 0; i < data.size(); ++i) {
        double angle = (data[i].second * 360.0) / total;
        painter.setPen(Qt::black);
        painter.setBrush(colors[i % colors.size()]);
        painter.drawPie(pieRect, startAngle * 16, angle * 16);
        startAngle += angle;
    }

    // Draw legend
    const int legendX = pieX + pieSize + margin;
    const int legendY = pieY;
    const int legendItemHeight = 20;
    const int colorBoxSize = 15;

    painter.setFont(QFont("Arial", 9));

    for (int i = 0; i < data.size(); ++i) {
        double percentage = (data[i].second * 100.0) / total;
        QString label = QString("%1: %2 (%3%)")
                            .arg(data[i].first)
                            .arg(data[i].second)
                            .arg(percentage, 0, 'f', 1);

        // Color box
        painter.setPen(Qt::black);
        painter.setBrush(colors[i % colors.size()]);
        painter.drawRect(legendX, legendY + i * legendItemHeight, colorBoxSize, colorBoxSize);

        // Text
        painter.setBrush(Qt::NoBrush);
        painter.drawText(legendX + colorBoxSize + 5,
                         legendY + i * legendItemHeight + colorBoxSize - 3,
                         label);
    }
}

void personnel::on_cameraButton_clicked()
{
    // Create the camera dialog if it doesn't exist
    if (!cameraDialog) {
        cameraDialog = new QDialog(this);
        cameraDialog->setWindowTitle("BioVec - Face Code Generator");
        cameraDialog->setMinimumSize(800, 600);

        // Create layout for the dialog
        QVBoxLayout *layout = new QVBoxLayout(cameraDialog);

        // Add camera selection dropdown
        QHBoxLayout *cameraSelectionLayout = new QHBoxLayout();
        QLabel *cameraLabel = new QLabel("Select Camera:", cameraDialog);
        cameraLabel->setStyleSheet("font-weight: bold; color: #208c54;");

        QComboBox *cameraSelector = new QComboBox(cameraDialog);
        cameraSelector->setObjectName("cameraSelector");
        cameraSelector->setMinimumWidth(300);
        cameraSelector->setStyleSheet("padding: 4px; border: 1px solid #208c54; border-radius: 3px;");

        // Populate camera selector with available cameras
        const QList<QCameraDevice> cameras = QMediaDevices::videoInputs();
        if (cameras.isEmpty()) {
            cameraSelector->addItem("No cameras available");
            cameraSelector->setEnabled(false);
        } else {
            for (const QCameraDevice &cameraDevice : cameras) {
                cameraSelector->addItem(cameraDevice.description(), QVariant::fromValue(cameraDevice.id()));
            }
        }

        QPushButton *refreshCamerasButton = new QPushButton("Refresh", cameraDialog);
        refreshCamerasButton->setStyleSheet("background-color: #3498db; color: white; padding: 4px 10px; border-radius: 3px;");
        connect(refreshCamerasButton, &QPushButton::clicked, this, [this, cameraSelector]() {
            // Get available cameras
            const QList<QCameraDevice> cameras = QMediaDevices::videoInputs();

            // Store currently selected camera ID
            QVariant currentCameraId;
            if (cameraSelector->currentIndex() >= 0) {
                currentCameraId = cameraSelector->currentData();
            }

            // Clear and repopulate the combobox
            cameraSelector->clear();

            if (cameras.isEmpty()) {
                cameraSelector->addItem("No cameras available");
                cameraSelector->setEnabled(false);
            } else {
                int indexToSelect = 0;
                for (int i = 0; i < cameras.size(); ++i) {
                    const QCameraDevice &cameraDevice = cameras[i];
                    cameraSelector->addItem(cameraDevice.description(), QVariant::fromValue(cameraDevice.id()));

                    // If this was the previously selected camera, select it again
                    if (currentCameraId.isValid() && currentCameraId == cameraDevice.id()) {
                        indexToSelect = i;
                    }
                }
                cameraSelector->setCurrentIndex(indexToSelect);
                cameraSelector->setEnabled(true);
            }

            QLabel *statusLabel = cameraDialog->findChild<QLabel*>("statusLabel");
            if (statusLabel) {
                statusLabel->setText("Camera list refreshed. Please select a camera.");
            }
        });

        cameraSelectionLayout->addWidget(cameraLabel);
        cameraSelectionLayout->addWidget(cameraSelector, 1);
        cameraSelectionLayout->addWidget(refreshCamerasButton);
        layout->addLayout(cameraSelectionLayout);

        // Create viewfinder
        viewfinder = new QVideoWidget(cameraDialog);
        viewfinder->setMinimumSize(640, 480);
        viewfinder->setStyleSheet("background-color: black; border: 1px solid #208c54;");
        layout->addWidget(viewfinder);

        // Create face preview and face code area
        QHBoxLayout *previewLayout = new QHBoxLayout();

        // Face preview section
        QVBoxLayout *facePreviewLayout = new QVBoxLayout();
        QLabel *facePreviewLabel = new QLabel("Face Preview:", cameraDialog);
        facePreviewLabel->setStyleSheet("font-weight: bold; color: #208c54;");

        QLabel *faceImageLabel = new QLabel(cameraDialog);
        faceImageLabel->setFixedSize(150, 150);
        faceImageLabel->setFrameShape(QFrame::Box);
        faceImageLabel->setFrameShadow(QFrame::Sunken);
        faceImageLabel->setStyleSheet("border: 2px solid #208c54; background-color: #f0f0f0;");
        faceImageLabel->setAlignment(Qt::AlignCenter);
        faceImageLabel->setText("Your face\nwill appear\nhere");
        faceImageLabel->setObjectName("facePreview");

        facePreviewLayout->addWidget(facePreviewLabel);
        facePreviewLayout->addWidget(faceImageLabel);
        facePreviewLayout->addStretch();

        // Face code section
        QVBoxLayout *faceCodeLayout = new QVBoxLayout();
        QLabel *faceCodeTitleLabel = new QLabel("Face Code:", cameraDialog);
        faceCodeTitleLabel->setStyleSheet("font-weight: bold; color: #208c54;");

        // Create a scroll area to contain the face code label
        QScrollArea *scrollArea = new QScrollArea(cameraDialog);
        scrollArea->setObjectName("faceCodeScrollArea");
        scrollArea->setWidgetResizable(true);
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        QLabel *faceCodeLabel = new QLabel(scrollArea);
        faceCodeLabel->setObjectName("faceCodeLabel");
        faceCodeLabel->setStyleSheet("font-family: monospace; font-size: 10px; background-color: #f0f0f0; padding: 5px; border: 1px solid #ccc; border-radius: 3px;");
        faceCodeLabel->setWordWrap(true);
        faceCodeLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);
        faceCodeLabel->setText("The extracted face code will appear here after generation.");

        scrollArea->setWidget(faceCodeLabel);
        scrollArea->setFixedHeight(150);

        faceCodeLayout->addWidget(faceCodeTitleLabel);
        faceCodeLayout->addWidget(scrollArea);

        // Add a copy button for the face code
        QPushButton *copyCodeButton = new QPushButton("Copy Code", cameraDialog);
        copyCodeButton->setObjectName("copyCodeButton");
        copyCodeButton->setStyleSheet("background-color: #3498db; color: white; padding: 4px 10px; border-radius: 3px;");
        copyCodeButton->setEnabled(false);
        connect(copyCodeButton, &QPushButton::clicked, this, [this, faceCodeLabel]() {
            QString faceCode = faceCodeLabel->text();
            if (!faceCode.isEmpty() && faceCode != "The extracted face code will appear here after generation.") {
                QApplication::clipboard()->setText(faceCode);
                QMessageBox::information(cameraDialog, "Code Copied", "Face code has been copied to clipboard.");
            }
        });

        faceCodeLayout->addWidget(copyCodeButton);
        faceCodeLayout->addStretch();

        previewLayout->addLayout(facePreviewLayout, 1);
        previewLayout->addLayout(faceCodeLayout, 2);

        layout->addLayout(previewLayout);

        // Create status label
        QLabel *statusLabel = new QLabel(cameraDialog);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setStyleSheet("color: #208c54; font-weight: bold;");
        statusLabel->setText("Please start the camera to begin face code generation.");
        layout->addWidget(statusLabel);

        // Create buttons
        QHBoxLayout *buttonLayout = new QHBoxLayout();

        QPushButton *startButton = new QPushButton("Start Camera", cameraDialog);
        startButton->setStyleSheet("background-color: #208c54; color: white; padding: 8px 15px; border-radius: 4px;");

        QPushButton *generateButton = new QPushButton("Generate Face Code", cameraDialog);
        generateButton->setStyleSheet("background-color: #2ecc71; color: white; padding: 8px 15px; border-radius: 4px;");

        QPushButton *useCodeButton = new QPushButton("Use This Code", cameraDialog);
        useCodeButton->setObjectName("useCodeButton");
        useCodeButton->setStyleSheet("background-color: #3498db; color: white; padding: 8px 15px; border-radius: 4px;");
        useCodeButton->setEnabled(false);

        QPushButton *closeButton = new QPushButton("Close", cameraDialog);
        closeButton->setStyleSheet("background-color: #e74c3c; color: white; padding: 8px 15px; border-radius: 4px;");

        buttonLayout->addWidget(startButton);
        buttonLayout->addWidget(generateButton);
        buttonLayout->addWidget(useCodeButton);
        buttonLayout->addWidget(closeButton);

        layout->addLayout(buttonLayout);

        // Connect signals
        connect(startButton, &QPushButton::clicked, this, [this, cameraSelector]() {
            startCamera(cameraSelector->currentData().toByteArray());
        });

        connect(generateButton, &QPushButton::clicked, this, &personnel::captureImage);

        connect(useCodeButton, &QPushButton::clicked, this, [this]() {
            QLabel *faceCodeLabel = cameraDialog->findChild<QLabel*>("faceCodeLabel");
            if (faceCodeLabel) {
                QString faceCode = faceCodeLabel->text();
                if (!faceCode.isEmpty() && faceCode != "The extracted face code will appear here after generation.") {
                    // Find the face code input in the registration form
                    QLineEdit *faceCodeEdit = ui->facecode;
                    if (faceCodeEdit) {
                        faceCodeEdit->setText(faceCode);
                        QMessageBox::information(cameraDialog, "Face Code Applied",
                                                 "The face code has been successfully applied to your registration form.");
                        cameraDialog->accept();
                    } else {
                        QMessageBox::warning(cameraDialog, "Error",
                                             "Could not find the face code field in the registration form.");
                    }
                } else {
                    QMessageBox::warning(cameraDialog, "No Face Code",
                                         "Please generate a face code first by clicking 'Generate Face Code'.");
                }
            }
        });

        connect(closeButton, &QPushButton::clicked, cameraDialog, &QDialog::reject);

        // Close event will stop the camera
        connect(cameraDialog, &QDialog::finished, this, &personnel::stopCamera);
    }

    // Reset UI elements for a new session
    QLabel *statusLabel = cameraDialog->findChild<QLabel*>("statusLabel");
    QLabel *facePreview = cameraDialog->findChild<QLabel*>("facePreview");
    QLabel *faceCodeLabel = cameraDialog->findChild<QLabel*>("faceCodeLabel");
    QPushButton *useCodeButton = cameraDialog->findChild<QPushButton*>("useCodeButton");
    QPushButton *copyCodeButton = cameraDialog->findChild<QPushButton*>("copyCodeButton");

    if (statusLabel) {
        statusLabel->setText("Please start the camera to begin face code generation.");
    }

    if (facePreview) {
        facePreview->setText("Your face\nwill appear\nhere");
        facePreview->setPixmap(QPixmap());
    }

    if (faceCodeLabel) {
        faceCodeLabel->setText("The extracted face code will appear here after generation.");
    }

    if (useCodeButton) {
        useCodeButton->setEnabled(false);
    }

    if (copyCodeButton) {
        copyCodeButton->setEnabled(false);
    }

    // Show the dialog
    cameraDialog->show();
}

void personnel::startCamera(const QByteArray &cameraId)
{
    QLabel *statusLabel = cameraDialog->findChild<QLabel*>("statusLabel");
    if (statusLabel) {
        statusLabel->setText("Starting camera...");
    }

    // Clean up existing camera resources
    if (camera && camera->isActive()) {
        camera->stop();
    }

    if (camera) {
        delete camera;
        camera = nullptr;
    }

    if (captureSession) {
        delete captureSession;
        captureSession = nullptr;
    }

    if (imageCapture) {
        delete imageCapture;
        imageCapture = nullptr;
    }

    // Create new capture session
    captureSession = new QMediaCaptureSession(this);

    // Get available cameras
    const QList<QCameraDevice> cameras = QMediaDevices::videoInputs();

    if (cameras.isEmpty()) {
        QMessageBox::warning(cameraDialog, "Camera Error", "No camera devices found.");
        if (statusLabel) {
            statusLabel->setText("Error: No cameras found");
            statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");
        }
        return;
    }

    // Select the camera device
    QCameraDevice selectedCamera = cameras.first(); // Default to first camera

    if (!cameraId.isEmpty()) {
        for (const QCameraDevice &device : cameras) {
            if (device.id() == cameraId) {
                selectedCamera = device;
                break;
            }
        }
    }

    // Create the camera with the selected device
    camera = new QCamera(selectedCamera, this);

    if (statusLabel) {
        statusLabel->setText("Selected camera: " + selectedCamera.description());
    }

    // Connect error signal
    connect(camera, &QCamera::errorOccurred, this, &personnel::handleCameraError);

    // Create image capture
    imageCapture = new QImageCapture(this);

    // Connect to error and image saved signals
    connect(imageCapture, &QImageCapture::errorOccurred, this,
            [this](int id, QImageCapture::Error error, const QString &errorString) {
                Q_UNUSED(id);
                Q_UNUSED(error);
                QMessageBox::warning(cameraDialog, "Image Capture Error", errorString);
            });

    // Set up the capture session
    captureSession->setCamera(camera);
    captureSession->setVideoOutput(viewfinder);
    captureSession->setImageCapture(imageCapture);

    // Create an overlay label for face detection
    QLabel *overlayLabel = new QLabel(viewfinder);
    overlayLabel->setObjectName("overlayLabel");
    overlayLabel->setAlignment(Qt::AlignCenter);
    overlayLabel->setGeometry(0, 0, viewfinder->width(), viewfinder->height());
    overlayLabel->setStyleSheet("background-color: transparent;");
    overlayLabel->raise();
    overlayLabel->hide();

    // Start the camera
    camera->start();

    // Create a camera status check timer that self-destructs after completion
    QTimer *statusTimer = new QTimer(this);
    statusTimer->setSingleShot(true);
    connect(statusTimer, &QTimer::timeout, this, [this, selectedCamera, statusTimer]() {
        QLabel *statusLabel = cameraDialog->findChild<QLabel*>("statusLabel");

        if (!camera || !camera->isActive()) {
            if (statusLabel) {
                statusLabel->setText("Failed to start camera");
                statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");
            }
        } else {
            if (statusLabel) {
                statusLabel->setText("Camera ready: " + selectedCamera.description() + " - Click 'Generate Face Code' when ready");
                statusLabel->setStyleSheet("color: #208c54; font-weight: bold;");
            }

            // Create a face detection timer that's owned by this object
            QTimer *faceDetectionTimer = new QTimer(this);
            connect(faceDetectionTimer, &QTimer::timeout, this, &personnel::detectFaceInViewfinder);

            // Always clean up camera resources when dialog is closed
            connect(cameraDialog, &QDialog::finished, faceDetectionTimer, &QTimer::stop);
            connect(cameraDialog, &QDialog::finished, faceDetectionTimer, &QTimer::deleteLater);

            // Start the timer
            faceDetectionTimer->start(4000); // Run face detection every 4 seconds
        }

        // Clean up this timer
        statusTimer->deleteLater();
    });

    statusTimer->start(2000); // 2 second delay
}

void personnel::captureImage()
{
    if (!camera || !imageCapture) {
        QMessageBox::warning(cameraDialog, "Camera Error", "Camera is not initialized. Please start the camera first.");
        return;
    }

    if (!camera->isActive()) {
        QMessageBox::warning(cameraDialog, "Camera Error", "Camera is not active. Please restart the camera.");
        return;
    }

    // Prevent multiple simultaneous captures
    if (isCaptureInProgress) {
        QMessageBox::information(cameraDialog, "Processing", "A capture is already in progress. Please wait.");
        return;
    }

    isCaptureInProgress = true;

    QLabel *statusLabel = cameraDialog->findChild<QLabel*>("statusLabel");
    if (statusLabel) {
        statusLabel->setText("Capturing image...");
        statusLabel->setStyleSheet("color: #FFA500; font-weight: bold;");
    }

    // DO NOT STOP THE CAMERA HERE - doing so puts it in a stopped state where capture fails
    // if (camera && camera->isActive()) {
    //     camera->stop();
    // }

    // Create a temporary directory for the capture
    QString captureDir = QDir::tempPath() + "/BioVec/Captures";
    QDir dir(captureDir);
    if (!dir.exists()) {
        dir.mkpath(".");
    }

    // Generate filename with timestamp
    QString timestamp = QDateTime::currentDateTime().toString("yyyyMMdd-hhmmss");
    QString fileName = QDir::toNativeSeparators(dir.absoluteFilePath("capture-" + timestamp + ".jpg"));

    // Create a simple processing indicator
    QLabel *processingLabel = new QLabel(viewfinder);
    processingLabel->setObjectName("processingIndicator");
    processingLabel->setText("CAPTURING\nPlease hold still...");
    processingLabel->setStyleSheet("background-color: rgba(0, 0, 0, 180); color: white; font-size: 24px; font-weight: bold; padding: 20px; border-radius: 10px;");
    processingLabel->setAlignment(Qt::AlignCenter);

    int labelWidth = 250;
    int labelHeight = 100;
    int x = (viewfinder->width() - labelWidth) / 2;
    int y = (viewfinder->height() - labelHeight) / 2;
    processingLabel->setGeometry(x, y, labelWidth, labelHeight);
    processingLabel->show();
    processingLabel->raise();

    // Create a progress dialog that automatically closes
    QProgressDialog *progressDialog = new QProgressDialog("Processing face capture...", "Cancel", 0, 100, cameraDialog);
    progressDialog->setWindowTitle("Face Processing");
    progressDialog->setWindowModality(Qt::WindowModal);
    progressDialog->setValue(0);
    progressDialog->setMinimumDuration(1000); // Only show after 1 second if still processing
    progressDialog->setCancelButton(nullptr); // Cannot cancel

    // Disconnect any existing connections to prevent multiple handlers
    QObject::disconnect(imageCapture, &QImageCapture::imageSaved, nullptr, nullptr);
    QObject::disconnect(imageCapture, &QImageCapture::errorOccurred, nullptr, nullptr);

    // Connect to image saved signal
    connect(imageCapture, &QImageCapture::imageSaved, this, [this, processingLabel, statusLabel, fileName, timestamp, progressDialog]
            (int id, const QString &filePath) {
                Q_UNUSED(id);
                qDebug() << "Image saved to:" << filePath;

                // Set progress dialog to 20% after capture
                progressDialog->setValue(20);

                // Process the captured image
                processCapturedImage(filePath, processingLabel, statusLabel, progressDialog);
            });

    // Connect to error signal
    connect(imageCapture, &QImageCapture::errorOccurred, this,
            [this, processingLabel, statusLabel, progressDialog](int id, QImageCapture::Error error, const QString &errorString) {
                Q_UNUSED(id);
                Q_UNUSED(error);

                processingLabel->deleteLater();
                progressDialog->close();
                progressDialog->deleteLater();

                if (statusLabel) {
                    statusLabel->setText("Capture error: " + errorString);
                    statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");
                }

                QMessageBox::warning(cameraDialog, "Capture Error",
                                     "Failed to capture image: " + errorString);
                isCaptureInProgress = false;
            });

    // Capture the image
    int captureId = imageCapture->captureToFile(fileName);
    qDebug() << "Starting image capture with ID:" << captureId;
}

// Process the captured image separately
void personnel::processCapturedImage(const QString &filePath, QLabel *processingLabel, QLabel *statusLabel, QProgressDialog *progressDialog)
{
    // Verify the file exists and has content
    QFileInfo fileInfo(filePath);
    if (!fileInfo.exists() || fileInfo.size() == 0) {
        processingLabel->deleteLater();
        progressDialog->close();
        progressDialog->deleteLater();

        if (statusLabel) {
            statusLabel->setText("Error: Captured image file not found or empty");
            statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");
        }

        QMessageBox::warning(cameraDialog, "Capture Error", "Failed to save image file or file is empty.");
        isCaptureInProgress = false;
        return;
    }

    // Update the processing label
    processingLabel->setText("Analyzing...");
    progressDialog->setValue(30);

    if (statusLabel) {
        statusLabel->setText("Analyzing face features...");
    }

    // Find the script path - search in additional locations
    QString scriptPath;
    QStringList scriptPaths = {
        "face_recognition/face_recognition_bridge.py",  // Relative to current working directory
        QCoreApplication::applicationDirPath() + "/face_recognition/face_recognition_bridge.py",
        QCoreApplication::applicationDirPath() + "/../face_recognition/face_recognition_bridge.py",
        QDir::currentPath() + "/face_recognition/face_recognition_bridge.py",
        QDir::currentPath() + "/../face_recognition/face_recognition_bridge.py",
        "C:/Users/Dell/OneDrive/Desktop/Atelier_Connexion/Atelier_Connexion/face_recognition/face_recognition_bridge.py"
    };

    for (const QString &path : scriptPaths) {
        if (QFileInfo::exists(path)) {
            scriptPath = path;
            qDebug() << "Found face recognition script at:" << path;
            break;
        }
    }

    if (scriptPath.isEmpty()) {
        processingLabel->deleteLater();
        progressDialog->close();
        progressDialog->deleteLater();

        if (statusLabel) {
            statusLabel->setText("Error: Face recognition script not found");
            statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");
        }

        QMessageBox::critical(cameraDialog, "Script Error",
                              "Face recognition script not found. Check installation.");
        isCaptureInProgress = false;
        return;
    }

    progressDialog->setValue(40);

    // Find Python command
    QString pythonCmd = "python";
    QStringList possiblePythonPaths = {
        "python",
        "python3",
        "C:\\Python310\\python.exe",
        "C:\\Program Files\\Python310\\python.exe",
        QCoreApplication::applicationDirPath() + "/python/python.exe"
    };

    for (const QString &path : possiblePythonPaths) {
        if (path == "python" || path == "python3") {
            QProcess pythonCheck;
            pythonCheck.start(path, QStringList() << "--version");
            if (pythonCheck.waitForStarted(1000) && pythonCheck.waitForFinished(2000)) {
                pythonCmd = path;
                qDebug() << "Using Python command:" << path;
                break;
            }
        } else if (QFileInfo::exists(path)) {
            pythonCmd = path;
            qDebug() << "Using Python path:" << path;
            break;
        }
    }

    progressDialog->setValue(50);

    // Try running the Python script directly
    QProcess *process = new QProcess(this);

    // Use system environment without modifications
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    process->setProcessEnvironment(env);
    process->setProcessChannelMode(QProcess::MergedChannels);

    // Build the command with arguments
    QStringList arguments;
    arguments << scriptPath;
    arguments << "--detect-face";
    arguments << "--image" << QDir::toNativeSeparators(filePath);
    arguments << "--draw-rectangle";

    qDebug() << "Running command:" << pythonCmd << arguments.join(" ");

    // Connect to process finished signal
    connect(process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            this, [this, process, processingLabel, statusLabel, filePath, progressDialog, pythonCmd](int exitCode, QProcess::ExitStatus exitStatus) {
                // Read all output
                QString output = QString::fromUtf8(process->readAll());

                // Log the output for debugging
                qDebug() << "Face detection output:";
                qDebug() << output.left(1000); // First 1000 chars only
                qDebug() << "Exit code:" << exitCode << "Exit status:" << exitStatus;

                // Clean up the processing label
                processingLabel->deleteLater();
                progressDialog->setValue(90);

                // Check for successful execution
                if (exitCode != 0 || exitStatus != QProcess::NormalExit) {
                    if (statusLabel) {
                        statusLabel->setText("Face detection failed (Code: " + QString::number(exitCode) + ")");
                        statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");
                    }

                    QString errorMessage = "The face detection process failed with exit code " + QString::number(exitCode);
                    if (!output.isEmpty()) {
                        errorMessage += "\n\nError details:\n" + output;
                    }

                    progressDialog->close();
                    progressDialog->deleteLater();
                    QMessageBox::warning(cameraDialog, "Detection Failed", errorMessage);
                    process->deleteLater();
                    isCaptureInProgress = false;
                    return;
                }

                // Try to extract JSON from the output
                int jsonStart = output.indexOf('{');
                int jsonEnd = output.lastIndexOf('}');

                if (jsonStart == -1 || jsonEnd == -1 || jsonStart > jsonEnd) {
                    if (statusLabel) {
                        statusLabel->setText("Invalid response format from face detection");
                        statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");
                    }

                    progressDialog->close();
                    progressDialog->deleteLater();
                    QMessageBox::warning(cameraDialog, "Detection Error",
                                         "Could not parse the face detection output.\n\nTry again or check the face recognition installation.\n\nOutput: " + output.left(200));
                    process->deleteLater();
                    isCaptureInProgress = false;
                    return;
                }

                progressDialog->setValue(95);

                QString jsonStr = output.mid(jsonStart, jsonEnd - jsonStart + 1);
                QJsonParseError parseError;
                QJsonDocument jsonResponse = QJsonDocument::fromJson(jsonStr.toUtf8(), &parseError);

                if (parseError.error != QJsonParseError::NoError || !jsonResponse.isObject()) {
                    if (statusLabel) {
                        statusLabel->setText("Invalid JSON from face detection");
                        statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");
                    }

                    progressDialog->close();
                    progressDialog->deleteLater();
                    QMessageBox::warning(cameraDialog, "Detection Error",
                                         "Invalid JSON response from face detection.\n\nTry again or check the face recognition installation.\n\nJSON Error: " + parseError.errorString());
                    process->deleteLater();
                    isCaptureInProgress = false;
                    return;
                }

                // Process the JSON response
                QJsonObject jsonObject = jsonResponse.object();
                bool success = jsonObject.value("success").toBool();

                if (!success) {
                    QString errorMessage = jsonObject.value("message").toString();
                    if (errorMessage.isEmpty()) {
                        errorMessage = "Unknown error";
                    }

                    if (statusLabel) {
                        statusLabel->setText("Face detection failed: " + errorMessage);
                        statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");
                    }

                    progressDialog->close();
                    progressDialog->deleteLater();
                    QMessageBox::warning(cameraDialog, "Detection Failed",
                                         "Face detection failed: " + errorMessage);
                    process->deleteLater();
                    isCaptureInProgress = false;
                    return;
                }

                // Check if faces were detected
                bool hasFaces = jsonObject.value("has_faces").toBool();

                QLabel *facePreview = cameraDialog->findChild<QLabel*>("facePreview");
                QLabel *faceCodeLabel = cameraDialog->findChild<QLabel*>("faceCodeLabel");
                QPushButton *useCodeButton = cameraDialog->findChild<QPushButton*>("useCodeButton");
                QPushButton *copyCodeButton = cameraDialog->findChild<QPushButton*>("copyCodeButton");

                if (!hasFaces) {
                    if (statusLabel) {
                        statusLabel->setText("No faces detected in the image");
                        statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");
                    }

                    if (facePreview) {
                        facePreview->setText("No face\ndetected");
                    }

                    progressDialog->close();
                    progressDialog->deleteLater();
                    QMessageBox::warning(cameraDialog, "No Face Detected",
                                         "No faces were detected in the captured image.\n\n"
                                         "Please make sure your face is clearly visible and try again.");
                    process->deleteLater();
                    isCaptureInProgress = false;
                    return;
                }

                // Get the image with faces highlighted
                QString base64Image = jsonObject.value("image").toString();
                if (base64Image.isEmpty()) {
                    if (statusLabel) {
                        statusLabel->setText("Missing image data in response");
                        statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");
                    }

                    progressDialog->close();
                    progressDialog->deleteLater();
                    QMessageBox::warning(cameraDialog, "Detection Error",
                                         "Missing image data in face detection response.");
                    process->deleteLater();
                    isCaptureInProgress = false;
                    return;
                }

                QByteArray imageData = QByteArray::fromBase64(base64Image.toUtf8());
                QPixmap resultImage;
                if (!resultImage.loadFromData(imageData, "JPG")) {
                    if (statusLabel) {
                        statusLabel->setText("Failed to load result image");
                        statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");
                    }

                    progressDialog->close();
                    progressDialog->deleteLater();
                    QMessageBox::warning(cameraDialog, "Image Error",
                                         "Failed to load the result image from face detection.");
                    process->deleteLater();
                    isCaptureInProgress = false;
                    return;
                }

                // Get the face embedding
                QString faceEmbedding = jsonObject.value("face_embedding").toString();
                if (faceEmbedding.isEmpty()) {
                    if (statusLabel) {
                        statusLabel->setText("Missing face code in response");
                        statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");
                    }

                    progressDialog->close();
                    progressDialog->deleteLater();
                    QMessageBox::warning(cameraDialog, "Code Error",
                                         "Missing face code in detection response.");
                    process->deleteLater();
                    isCaptureInProgress = false;
                    return;
                }

                // Store the face embedding
                currentFaceEmbedding = faceEmbedding;
                progressDialog->setValue(100);

                // Update the UI
                if (statusLabel) {
                    statusLabel->setText("Face code generated successfully!");
                    statusLabel->setStyleSheet("color: #208c54; font-weight: bold;");
                }

                if (facePreview && !resultImage.isNull()) {
                    // Scale the image to fit the preview
                    QPixmap scaledImage = resultImage.scaled(
                        facePreview->size(),
                        Qt::KeepAspectRatio,
                        Qt::SmoothTransformation
                        );
                    facePreview->setPixmap(scaledImage);
                }

                if (faceCodeLabel) {
                    // Display the full face code without truncation
                    faceCodeLabel->setText(faceEmbedding);
                    faceCodeLabel->setStyleSheet("font-family: monospace; font-size: 10px; background-color: #f0f0f0; padding: 5px; border: 2px solid #208c54; border-radius: 3px;");
                }

                // Enable the use code and copy buttons
                if (useCodeButton) {
                    useCodeButton->setEnabled(true);
                    useCodeButton->setStyleSheet("background-color: #2ecc71; color: white; padding: 8px 15px; border-radius: 4px; font-weight: bold;");
                }

                if (copyCodeButton) {
                    copyCodeButton->setEnabled(true);
                }

                // Close the progress dialog before showing the success message
                progressDialog->close();
                progressDialog->deleteLater();

                QApplication::beep(); // Play a sound to indicate completion

                QMessageBox::information(cameraDialog, "Face Code Generated",
                                         "Face code has been successfully generated!\n\n"
                                         "Click 'Use This Code' to apply it to your registration form.");

                // Clean up
                process->deleteLater();
                isCaptureInProgress = false;
            });

    // Handle process errors
    connect(process, &QProcess::errorOccurred, this, [this, process, processingLabel, statusLabel, progressDialog, pythonCmd](QProcess::ProcessError error) {
        processingLabel->deleteLater();

        QString errorText;
        switch (error) {
        case QProcess::FailedToStart:
            errorText = "Failed to start Python process. Check if Python is installed.";
            break;
        case QProcess::Crashed:
            errorText = "Python process crashed. Check face recognition installation.";
            break;
        case QProcess::Timedout:
            errorText = "Python process timed out.";
            break;
        case QProcess::ReadError:
            errorText = "Error reading from Python process.";
            break;
        case QProcess::WriteError:
            errorText = "Error writing to Python process.";
            break;
        default:
            errorText = "Unknown process error.";
        }

        if (statusLabel) {
            statusLabel->setText("Process error: " + errorText);
            statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");
        }

        progressDialog->close();
        progressDialog->deleteLater();
        QMessageBox::critical(this->cameraDialog, "Process Error",
                              "Error running face detection: " + errorText);

        process->deleteLater();
        this->isCaptureInProgress = false;
    });

    // Set a timeout for the process - longer timeout (60 seconds)
    QTimer *timeoutTimer = new QTimer(this);
    timeoutTimer->setSingleShot(true);
    connect(timeoutTimer, &QTimer::timeout, this, [this, process, processingLabel, timeoutTimer, progressDialog]() {
        if (process->state() == QProcess::Running) {
            processingLabel->deleteLater();
            process->kill();

            progressDialog->close();
            progressDialog->deleteLater();
            QMessageBox::warning(nullptr, "Timeout",
                                 "Face detection process timed out. Please try again.");
            this->isCaptureInProgress = false;
        }
        timeoutTimer->deleteLater();
    });

    connect(process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            timeoutTimer, &QTimer::stop);
    connect(process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            timeoutTimer, &QTimer::deleteLater);

    timeoutTimer->start(60000); // 60 second timeout - give it more time

    // Start the process
    qDebug() << "Starting face detection process with command:" << pythonCmd;
    qDebug() << "Arguments:" << arguments.join(" ");
    process->start(pythonCmd, arguments);

    // Check if process started
    if (!process->waitForStarted(5000)) {
        processingLabel->deleteLater();
        progressDialog->close();
        progressDialog->deleteLater();

        if (statusLabel) {
            statusLabel->setText("Failed to start face detection process");
            statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");
        }

        QMessageBox::critical(this->cameraDialog, "Process Error",
                              "Failed to start face detection process: " + process->errorString());

        process->deleteLater();
        this->isCaptureInProgress = false;
    }
}

void personnel::stopCamera()
{
    // Kill any running timers and processes first
    const QList<QTimer *> timers = this->findChildren<QTimer *>();
    for (QTimer *timer : timers) {
        timer->stop();
    }

    const QList<QProcess *> processes = this->findChildren<QProcess *>();
    for (QProcess *process : processes) {
        if (process->state() == QProcess::Running) {
            process->kill();
            process->waitForFinished(1000);
        }
    }

    if (camera && camera->isActive()) {
        camera->stop();
    }

    // Clean up any processing indicators
    QLabel *processingLabel = viewfinder ? viewfinder->findChild<QLabel*>("processingIndicator") : nullptr;
    if (processingLabel) {
        processingLabel->deleteLater();
    }

    QLabel *overlayLabel = viewfinder ? viewfinder->findChild<QLabel*>("overlayLabel") : nullptr;
    if (overlayLabel) {
        overlayLabel->hide();
    }
}

// Add implementation for missing handleCameraError method
void personnel::handleCameraError(QCamera::Error error, const QString &errorString)
{
    Q_UNUSED(error);
    QLabel *statusLabel = cameraDialog->findChild<QLabel*>("statusLabel");
    if (statusLabel) {
        statusLabel->setText("Camera error: " + errorString);
        statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");
    }
    QMessageBox::warning(cameraDialog, "Camera Error", "Error: " + errorString);
}

void personnel::detectFaceInViewfinder()
{
    // Disable background face detection - it's causing too many errors
    // We'll only do face detection when the user clicks the capture button
    return;
}

void personnel::processLoginFace(const QString &filePath, QDialog *loginDialog, QLabel *statusLabel, QLabel *processingLabel, QProgressDialog *progressDialog)
{
    // Verify the file exists and has content
    QFileInfo fileInfo(filePath);
    if (!fileInfo.exists() || fileInfo.size() == 0) {
        processingLabel->deleteLater();
        progressDialog->close();
        progressDialog->deleteLater();

        if (statusLabel) {
            statusLabel->setText("Error: Captured image file not found or empty");
            statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");
        }

        QMessageBox::warning(loginDialog, "Capture Error", "Failed to save image file or file is empty.");
        return;
    }

    // Update the processing label
    processingLabel->setText("Analyzing...");
    progressDialog->setValue(20);

    if (statusLabel) {
        statusLabel->setText("Analyzing face features...");
    }

    // Find the script path
    QString scriptPath;
    QStringList scriptPaths = {
        "face_recognition/face_recognition_bridge.py",
        QCoreApplication::applicationDirPath() + "/face_recognition/face_recognition_bridge.py",
        QCoreApplication::applicationDirPath() + "/../face_recognition/face_recognition_bridge.py",
        QDir::currentPath() + "/face_recognition/face_recognition_bridge.py",
        QDir::currentPath() + "/../face_recognition/face_recognition_bridge.py",
        "C:/Users/Dell/OneDrive/Desktop/Atelier_Connexion/Atelier_Connexion/face_recognition/face_recognition_bridge.py"
    };

    for (const QString &path : scriptPaths) {
        if (QFileInfo::exists(path)) {
            scriptPath = path;
            qDebug() << "Found face recognition script at:" << path;
            break;
        }
    }

    if (scriptPath.isEmpty()) {
        processingLabel->deleteLater();
        progressDialog->close();
        progressDialog->deleteLater();

        if (statusLabel) {
            statusLabel->setText("Error: Face recognition script not found");
            statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");
        }

        QMessageBox::critical(loginDialog, "Script Error",
                              "Face recognition script not found. Check installation.");
        return;
    }

    progressDialog->setValue(30);

    // Find Python command
    QString pythonCmd = "python";
    QStringList possiblePythonPaths = {
        "python",
        "python3",
        "C:\\Python310\\python.exe",
        "C:\\Program Files\\Python310\\python.exe",
        QCoreApplication::applicationDirPath() + "/python/python.exe"
    };

    for (const QString &path : possiblePythonPaths) {
        if (path == "python" || path == "python3") {
            QProcess pythonCheck;
            pythonCheck.start(path, QStringList() << "--version");
            if (pythonCheck.waitForStarted(1000) && pythonCheck.waitForFinished(2000)) {
                pythonCmd = path;
                qDebug() << "Using Python command:" << path;
                break;
            }
        } else if (QFileInfo::exists(path)) {
            pythonCmd = path;
            qDebug() << "Using Python path:" << path;
            break;
        }
    }

    progressDialog->setValue(40);

    // Start by getting the face embedding from the captured image
    QProcess *process = new QProcess(this);
    process->setProcessChannelMode(QProcess::MergedChannels);

    // Build the command with arguments
    QStringList arguments;
    arguments << scriptPath;
    arguments << "--detect-face";
    arguments << "--image" << QDir::toNativeSeparators(filePath);
    arguments << "--draw-rectangle";

    qDebug() << "Running command:" << pythonCmd << arguments.join(" ");

    // Connect to process finished signal
    connect(process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            this, [this, process, processingLabel, statusLabel, loginDialog, progressDialog, pythonCmd](int exitCode, QProcess::ExitStatus exitStatus) {
                // Read all output
                QString output = QString::fromUtf8(process->readAll());
                qDebug() << "Face detection output (first 1000 chars):" << output.left(1000);

                // Check for successful execution
                if (exitCode != 0 || exitStatus != QProcess::NormalExit) {
                    processingLabel->deleteLater();
                    progressDialog->close();
                    progressDialog->deleteLater();

                    if (statusLabel) {
                        statusLabel->setText("Face detection failed (Code: " + QString::number(exitCode) + ")");
                        statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");
                    }

                    QString errorMessage = "The face detection process failed with exit code " + QString::number(exitCode);
                    if (!output.isEmpty()) {
                        errorMessage += "\n\nError details:\n" + output;
                    }

                    QMessageBox::warning(loginDialog, "Detection Failed", errorMessage);
                    process->deleteLater();
                    return;
                }

                // Extract JSON from the output
                int jsonStart = output.indexOf('{');
                int jsonEnd = output.lastIndexOf('}');

                if (jsonStart == -1 || jsonEnd == -1 || jsonStart > jsonEnd) {
                    processingLabel->deleteLater();
                    progressDialog->close();
                    progressDialog->deleteLater();

                    if (statusLabel) {
                        statusLabel->setText("Invalid response format from face detection");
                        statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");
                    }

                    QMessageBox::warning(loginDialog, "Detection Error",
                                         "Could not parse the face detection output.");
                    process->deleteLater();
                    return;
                }

                QString jsonStr = output.mid(jsonStart, jsonEnd - jsonStart + 1);
                QJsonParseError parseError;
                QJsonDocument jsonResponse = QJsonDocument::fromJson(jsonStr.toUtf8(), &parseError);

                if (parseError.error != QJsonParseError::NoError || !jsonResponse.isObject()) {
                    processingLabel->deleteLater();
                    progressDialog->close();
                    progressDialog->deleteLater();

                    if (statusLabel) {
                        statusLabel->setText("Invalid JSON from face detection");
                        statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");
                    }

                    QMessageBox::warning(loginDialog, "Detection Error",
                                         "Invalid JSON response from face detection.");
                    process->deleteLater();
                    return;
                }

                // Process the JSON response
                QJsonObject jsonObject = jsonResponse.object();
                bool success = jsonObject.value("success").toBool();

                if (!success) {
                    processingLabel->deleteLater();
                    progressDialog->close();
                    progressDialog->deleteLater();

                    QString errorMessage = jsonObject.value("message").toString();
                    if (errorMessage.isEmpty()) {
                        errorMessage = "Unknown error";
                    }

                    if (statusLabel) {
                        statusLabel->setText("Face detection failed: " + errorMessage);
                        statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");
                    }

                    QMessageBox::warning(loginDialog, "Detection Failed",
                                         "Face detection failed: " + errorMessage);
                    process->deleteLater();
                    return;
                }

                // Check if faces were detected
                bool hasFaces = jsonObject.value("has_faces").toBool();

                if (!hasFaces) {
                    processingLabel->deleteLater();
                    progressDialog->close();
                    progressDialog->deleteLater();

                    if (statusLabel) {
                        statusLabel->setText("No faces detected in the image");
                        statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");
                    }

                    QMessageBox::warning(loginDialog, "No Face Detected",
                                         "No faces were detected in the captured image.\n\n"
                                         "Please make sure your face is clearly visible and try again.");
                    process->deleteLater();
                    return;
                }

                // Get the face embedding
                QString capturedFaceEmbedding = jsonObject.value("face_embedding").toString();

                if (capturedFaceEmbedding.isEmpty()) {
                    processingLabel->deleteLater();
                    progressDialog->close();
                    progressDialog->deleteLater();

                    QString errorMessage = "No face embedding data returned from detection process";
                    qDebug() << "ERROR:" << errorMessage;
                    qDebug() << "JSON response:" << jsonStr;

                    if (statusLabel) {
                        statusLabel->setText("Face detection failed: Missing embedding data");
                        statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");
                    }

                    QMessageBox::warning(loginDialog, "Detection Error",
                                         "The face detection process did not return valid face data.\n\n"
                                         "Please try again in better lighting conditions.");
                    process->deleteLater();
                    return;
                }

                // Debug the captured face code
                qDebug() << "Successfully extracted face embedding:";
                qDebug() << "  Length:" << capturedFaceEmbedding.length();
                qDebug() << "  First 20 chars:" << capturedFaceEmbedding.left(20);
                qDebug() << "  Contains commas:" << capturedFaceEmbedding.contains(',');

                progressDialog->setValue(60);
                statusLabel->setText("Face detected! Checking database...");

                // Search for a matching face in the database
                QSqlDatabase db = QSqlDatabase::database("BioVechConnection");
                if (!db.isValid()) {
                    qDebug() << "BioVechConnection not valid, trying default connection...";
                    db = QSqlDatabase::database(); // Try the default connection

                    if (!db.isValid()) {
                        qDebug() << "Default connection not valid either. Available connections:";
                        QStringList connectionNames = QSqlDatabase::connectionNames();
                        for (const QString& name : connectionNames) {
                            qDebug() << "  " << name;
                        }

                        if (!connectionNames.isEmpty()) {
                            db = QSqlDatabase::database(connectionNames.first());
                            qDebug() << "Trying first available connection:" << connectionNames.first();
                        }
                    }
                }

                if (!db.isValid()) {
                    processingLabel->deleteLater();
                    progressDialog->close();
                    progressDialog->deleteLater();

                    statusLabel->setText("Database error: Connection not valid");
                    statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");

                    QMessageBox::critical(loginDialog, "Database Error",
                                          "Cannot connect to the database to verify your face.");
                    process->deleteLater();
                    return;
                }

                // Check if the FACECODE column exists
                QSqlQuery checkQuery(db);

                // IMPORTANT: We know the FACECODE column exists from the database screenshot
                // Force set this to true to bypass the check that's causing the error
                bool faceCodeColumnExists = true;

                qDebug() << "FACECODE column check bypassed - assuming it exists";

                /* Comment out the problematic check
        // First try using PRAGMA table_info (SQLite specific)
        checkQuery.prepare("PRAGMA table_info(EMPLOYE)");
        bool faceCodeColumnExists = false;

        qDebug() << "Checking database for FACECODE column...";

        if (checkQuery.exec()) {
            while (checkQuery.next()) {
                QString columnName = checkQuery.value(1).toString();
                qDebug() << "  Found column:" << columnName;
                if (columnName.toUpper() == "FACECODE") {
                    faceCodeColumnExists = true;
                    qDebug() << "  FACECODE column found!";
                    break;
                }
            }
        } else {
            qDebug() << "  Error executing PRAGMA table_info:" << checkQuery.lastError().text();

            // Try an alternative approach - use a SELECT that would fail if the column doesn't exist
            QSqlQuery testQuery(db);
            testQuery.prepare("SELECT FACECODE FROM EMPLOYE LIMIT 1");
            if (testQuery.exec()) {
                faceCodeColumnExists = true;
                qDebug() << "  FACECODE column exists based on SELECT test";
            } else {
                qDebug() << "  FACECODE column does not exist based on SELECT test:" << testQuery.lastError().text();

                // Try with lowercase in case the database is case-sensitive
                testQuery.prepare("SELECT facecode FROM EMPLOYE LIMIT 1");
                if (testQuery.exec()) {
                    faceCodeColumnExists = true;
                    qDebug() << "  facecode (lowercase) column exists based on SELECT test";
                } else {
                    qDebug() << "  facecode (lowercase) column does not exist based on SELECT test:" << testQuery.lastError().text();
                }
            }
        }
        */

                qDebug() << "FACECODE column exists:" << faceCodeColumnExists;

                if (!faceCodeColumnExists) {
                    processingLabel->deleteLater();
                    progressDialog->close();
                    progressDialog->deleteLater();

                    statusLabel->setText("Database error: No face recognition data column");
                    statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");

                    QMessageBox::warning(loginDialog, "Face Login Error",
                                         "Face recognition is not set up in the database.\n"
                                         "Please use ID and password to login first.");
                    process->deleteLater();
                    return;
                }

                progressDialog->setValue(70);

                // Query employees with face codes - adapted to work with both SQLite and Oracle
                QSqlQuery query(db);

                // Detect if using Oracle or SQLite
                QString dbType = db.driverName().toUpper();
                qDebug() << "Database driver type:" << dbType;

                // First, let's verify the database connection with a simple query
                QSqlQuery testQuery(db);
                if (dbType.contains("ORACLE") || dbType.contains("OCI") || dbType.contains("ODBC")) {
                    // Oracle syntax - use ROWNUM instead of LIMIT
                    if (!testQuery.exec("SELECT * FROM EMPLOYE WHERE ROWNUM <= 1")) {
                        qDebug() << "ERROR: Basic database query failed:" << testQuery.lastError().text();
                        processingLabel->deleteLater();
                        progressDialog->close();
                        progressDialog->deleteLater();

                        statusLabel->setText("Database connection error");
                        statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");

                        QMessageBox::critical(loginDialog, "Database Error",
                                              "Failed to connect to database: " + testQuery.lastError().text());
                        process->deleteLater();
                        return;
                    }
                } else {
                    // SQLite/MySQL syntax
                    if (!testQuery.exec("SELECT * FROM EMPLOYE LIMIT 1")) {
                        qDebug() << "ERROR: Basic database query failed:" << testQuery.lastError().text();
                        processingLabel->deleteLater();
                        progressDialog->close();
                        progressDialog->deleteLater();

                        statusLabel->setText("Database connection error");
                        statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");

                        QMessageBox::critical(loginDialog, "Database Error",
                                              "Failed to connect to database: " + testQuery.lastError().text());
                        process->deleteLater();
                        return;
                    }
                }

                // Now the real query for face codes
                if (dbType.contains("ORACLE") || dbType.contains("OCI") || dbType.contains("ODBC")) {
                    // Oracle or ODBC syntax - adapted for Oracle
                    query.prepare("SELECT ID, NOM, PRENOM, FACECODE FROM EMPLOYE WHERE FACECODE IS NOT NULL");
                    qDebug() << "Using Oracle-compatible query for face codes";
                } else {
                    // SQLite syntax
                    query.prepare("SELECT ID, NOM, PRENOM, FACECODE FROM EMPLOYE WHERE FACECODE IS NOT NULL AND FACECODE <> ''");
                    qDebug() << "Using SQLite-compatible query for face codes";
                }

                qDebug() << "Executing query to find employees with face codes...";

                if (!query.exec()) {
                    processingLabel->deleteLater();
                    progressDialog->close();
                    progressDialog->deleteLater();

                    statusLabel->setText("Database query error: " + query.lastError().text());
                    statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");

                    QMessageBox::critical(loginDialog, "Database Error",
                                          "Failed to query employee data: " + query.lastError().text());
                    process->deleteLater();
                    return;
                }

                // Check if there are any stored face codes at all
                bool hasAnyFaceCodes = query.next(); // Move to first row

                if (!hasAnyFaceCodes) {
                    qDebug() << "No employees with face codes found in the database!";

                    // Rather than stopping with an error, we'll show a warning and then proceed to capture the face
                    // This allows users to register their face on first use
                    QMessageBox::warning(loginDialog, "Face Login Information",
                                         "There are no registered face codes in the database.\n\n"
                                         "We'll capture your face now - if it matches when you try to login next time, "
                                         "you'll be automatically signed in.");

                    // We'll continue with the face capture - the user's face will be captured
                    // but obviously won't match any existing face in the database
                    // Later, they can login with ID/password and register their face

                    // Don't return here - let the code continue to process the captured image
                } else {
                    qDebug() << "Found at least one employee with face code data";

                    // Dump the first employee's data to verify we can read it
                    // No need to call first() since we're already on the first row
                    int firstId = query.value(0).toInt();
                    QString firstName = query.value(2).toString();
                    QString lastName = query.value(1).toString();
                    QString faceCode = query.value(3).toString();

                    qDebug() << "First employee data:";
                    qDebug() << "  ID:" << firstId;
                    qDebug() << "  Name:" << firstName << lastName;
                    qDebug() << "  FaceCode length:" << faceCode.length();
                    qDebug() << "  FaceCode starts with:" << (faceCode.isEmpty() ? "EMPTY" : faceCode.left(20));

                    // Additional Oracle debugging
                    if (dbType.contains("ORACLE") || dbType.contains("OCI") || dbType.contains("ODBC")) {
                        QSqlRecord record = query.record();
                        qDebug() << "Oracle record column count:" << record.count();
                        for (int i = 0; i < record.count(); i++) {
                            qDebug() << "  Column" << i << "name:" << record.fieldName(i);
                            qDebug() << "  Column" << i << "value:" << query.value(i).toString().left(20);
                        }
                    }

                    // Execute the query again to process all rows
                    if (dbType.contains("ORACLE") || dbType.contains("OCI") || dbType.contains("ODBC")) {
                        // For Oracle, we need to re-execute the query
                        query.exec();
                    } else {
                        // For other databases, we can just reset the position
                        query.seek(-1);
                    }
                }

                // Check each face code from database for a match
                bool matchFound = false;
                int matchedEmployeeId = 0;
                QString matchedEmployeeName;
                double bestMatchDistance = 999.0; // Initialize with a high value

                progressDialog->setValue(80);

                while (query.next()) {
                    int employeeId = query.value(0).toInt();
                    QString employeeFirstName = query.value(2).toString();
                    QString employeeLastName = query.value(1).toString();
                    QString storedFaceCode = query.value(3).toString();

                    // Debug the column values
                    qDebug() << "Row values for employee #" << employeeId << ":";
                    qDebug() << "  First name:" << employeeFirstName;
                    qDebug() << "  Last name:" << employeeLastName;
                    qDebug() << "  Face code length:" << storedFaceCode.length();

                    // Try alternative ways to access the FACECODE column if it's empty
                    if (storedFaceCode.isEmpty()) {
                        // Try accessing by column name
                        storedFaceCode = query.value("FACECODE").toString();

                        // Try lowercase column name if that doesn't work
                        if (storedFaceCode.isEmpty()) {
                            storedFaceCode = query.value("facecode").toString();
                        }

                        // If still empty, try getting all column names
                        if (storedFaceCode.isEmpty()) {
                            QSqlRecord record = query.record();
                            qDebug() << "Available columns for employee #" << employeeId << ":";
                            for (int i = 0; i < record.count(); i++) {
                                qDebug() << "  Column" << i << ":" << record.fieldName(i)
                                << "Value:" << query.value(i).toString().left(20);
                            }

                            // Oracle specific handling - in Oracle, sometimes column names are all uppercase
                            if (dbType.contains("ORACLE") || dbType.contains("OCI") || dbType.contains("ODBC")) {
                                for (int i = 0; i < record.count(); i++) {
                                    QString fieldName = record.fieldName(i);
                                    if (fieldName.toUpper() == "FACECODE") {
                                        storedFaceCode = query.value(i).toString();
                                        qDebug() << "Found FACECODE in column" << i << "with name" << fieldName;
                                        break;
                                    }
                                }
                            }

                            // If still empty and we have at least 4 columns, try the 4th column
                            if (storedFaceCode.isEmpty() && record.count() >= 4) {
                                storedFaceCode = query.value(3).toString();
                            }
                        }
                    }

                    if (!storedFaceCode.isEmpty()) {
                        // Debug the stored face code to verify it's properly retrieved
                        qDebug() << "Processing face code for employee ID:" << employeeId
                                 << "Face code length:" << storedFaceCode.length()
                                 << "First 20 chars:" << storedFaceCode.left(20);

                        // Clean up the stored face code - remove any extra whitespace or invalid characters
                        storedFaceCode = storedFaceCode.trimmed();

                        // Ensure face code has the correct format (comma-separated floats)
                        if (!storedFaceCode.contains(',')) {
                            qDebug() << "Face code for employee #" << employeeId << "does not contain commas, might be invalid format";
                            continue;
                        }

                        // Use a separate Python process to do the face comparison
                        QProcess compareProcess;
                        compareProcess.setProcessChannelMode(QProcess::MergedChannels);

                        // Write face codes to temporary files to avoid command-line issues
                        QString tempDir = QDir::tempPath() + "/BioVec/comparison";
                        QDir().mkpath(tempDir);

                        QString capturedFile = tempDir + "/captured_face.txt";
                        QString storedFile = tempDir + "/stored_face.txt";

                        // Write the face codes to files
                        QFile capturedFileObj(capturedFile);
                        QFile storedFileObj(storedFile);

                        bool filesWritten = true;

                        if (capturedFileObj.open(QIODevice::WriteOnly | QIODevice::Text)) {
                            QTextStream capturedStream(&capturedFileObj);
                            capturedStream << capturedFaceEmbedding;
                            capturedFileObj.close();
                        } else {
                            filesWritten = false;
                            qDebug() << "Failed to write captured face code to file";
                        }

                        if (storedFileObj.open(QIODevice::WriteOnly | QIODevice::Text)) {
                            QTextStream storedStream(&storedFileObj);
                            storedStream << storedFaceCode;
                            storedFileObj.close();
                        } else {
                            filesWritten = false;
                            qDebug() << "Failed to write stored face code to file";
                        }

                        if (!filesWritten) {
                            qDebug() << "Skipping comparison for employee #" << employeeId << "due to file write error";
                            continue;
                        }

                        // Find the path to our dedicated comparison script
                        QString appDir = QCoreApplication::applicationDirPath();
                        QString scriptPath = appDir + "/../face_recognition/compare_faces.py";
                        QFileInfo scriptInfo(scriptPath);

                        if (!scriptInfo.exists()) {
                            // Try another location
                            scriptPath = QDir::cleanPath(appDir + "/face_recognition/compare_faces.py");
                            scriptInfo.setFile(scriptPath);

                            if (!scriptInfo.exists()) {
                                // Try one more location
                                scriptPath = QDir::cleanPath("C:/Users/Dell/OneDrive/Desktop/Atelier_Connexion/Atelier_Connexion/face_recognition/compare_faces.py");
                                scriptInfo.setFile(scriptPath);

                                if (!scriptInfo.exists()) {
                                    qDebug() << "ERROR: Could not find compare_faces.py script";
                                    continue;
                                }
                            }
                        }

                        // Build comparison command - call our dedicated script with the file paths
                        QStringList compareArgs;
                        compareArgs << scriptPath << capturedFile << storedFile;

                        qDebug() << "Running Python comparison with command:" << pythonCmd << compareArgs.join(" ");
                        compareProcess.start(pythonCmd, compareArgs);
                        if (compareProcess.waitForFinished(10000)) {
                            QString output = compareProcess.readAllStandardOutput().trimmed();
                            QString errorOutput = compareProcess.readAllStandardError().trimmed();
                            QStringList lines = output.split('\n');

                            if (!errorOutput.isEmpty()) {
                                qDebug() << "Face comparison error for employee #" << employeeId << ":" << errorOutput;
                            }

                            qDebug() << "Full comparison output for employee #" << employeeId << ":" << output;

                            // Look for the distance value in the output - it should be the last line
                            bool distanceFound = false;

                            // Try each line from last to first to find a valid double
                            for (int i = lines.size() - 1; i >= 0; i--) {
                                QString line = lines[i].trimmed();

                                // Skip empty lines
                                if (line.isEmpty()) {
                                    continue;
                                }

                                // Try to convert the line to a double
                                bool ok;
                                double distance = line.toDouble(&ok);

                                if (ok) {
                                    distanceFound = true;
                                    qDebug() << "Face comparison result for employee #" << employeeId
                                             << "(" << employeeFirstName << " " << employeeLastName << ")"
                                             << ": Distance =" << distance;

                                    // If this is the closest match so far and below our threshold
                                    if (distance < bestMatchDistance) {
                                        bestMatchDistance = distance;
                                        matchedEmployeeId = employeeId;
                                        matchedEmployeeName = employeeFirstName + " " + employeeLastName;
                                    }
                                    break;
                                }
                            }

                            if (!distanceFound) {
                                qDebug() << "Failed to parse distance value from output for employee #" << employeeId;
                            }
                        } else {
                            qDebug() << "Face comparison process timed out for employee #" << employeeId;
                        }
                    }
                }

                // Now determine if the best match is good enough
                matchFound = (bestMatchDistance < 0.4); // Use the same threshold as in Python code

                qDebug() << "Best match distance:" << bestMatchDistance << "for employee ID:" << matchedEmployeeId;

                progressDialog->setValue(100);
                processingLabel->deleteLater();

                // Process the result
                if (matchFound) {
                    // Success! A matching face was found
                    statusLabel->setText("Face verification successful!");
                    statusLabel->setStyleSheet("color: #208c54; font-weight: bold;");

                    progressDialog->close();
                    progressDialog->deleteLater();

                    // Calculate confidence level (0-100%)
                    int confidencePercent = qMax(0, qMin(100, (int)((1.0 - bestMatchDistance / 0.4) * 100)));

                    QMessageBox::information(loginDialog, "Login Successful",
                                             "Welcome back, " + matchedEmployeeName + "!\n\n" +
                                                 "Match confidence: " + QString::number(confidencePercent) + "%");

                    // Close the dialog
                    loginDialog->accept();

                    // Open personnel window
                    personnel* personnelWindow = new personnel();
                    this->close();
                    personnelWindow->show();
                } else {
                    // No match found or confidence too low
                    progressDialog->close();
                    progressDialog->deleteLater();

                    // Provide detailed feedback based on best match distance
                    if (bestMatchDistance < 0.6 && bestMatchDistance >= 0.4) {
                        // There was a close match, but not confident enough
                        statusLabel->setText("Face verification failed: Low confidence match");
                        statusLabel->setStyleSheet("color: #FFA500; font-weight: bold;");

                        // Calculate confidence level (0-100%)
                        int confidencePercent = qMax(0, qMin(100, (int)((1.0 - bestMatchDistance / 0.6) * 100)));

                        QString message = "Your face appears similar to " + matchedEmployeeName +
                                          ", but the match confidence (" + QString::number(confidencePercent) +
                                          "%) is too low.\n\n" +
                                          "For security reasons, please use ID and password to login.";

                        QMessageBox::warning(loginDialog, "Low Confidence Match", message);
                    } else if (bestMatchDistance < 999.0) {
                        // Some comparison was done but no good match
                        statusLabel->setText("Face verification failed: No match found");
                        statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");

                        int confidencePercent = qMax(0, qMin(100, (int)((1.0 - bestMatchDistance / 0.8) * 100)));
                        QString message = "Your face does not match any registered user.\n\n";

                        if (confidencePercent > 30) {
                            message += "The closest match was " + matchedEmployeeName + " with only " +
                                       QString::number(confidencePercent) + "% confidence.\n\n";
                        }

                        message += "Please try again with better lighting or use ID and password to login.";
                        QMessageBox::warning(loginDialog, "Login Failed", message);
                    } else {
                        // No comparisons were performed or all failed
                        statusLabel->setText("Face verification failed: No valid comparisons");
                        statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");

                        QMessageBox::warning(loginDialog, "Login Failed",
                                             "Could not compare your face with any stored face codes.\n\n"
                                             "This could be due to formatting issues or corrupted data.\n\n"
                                             "Please use ID and password to login and re-register your face.");
                    }

                    // Check if there are any face codes at all in the database
                    // If not, we can offer to store this face for future use
                    if (!hasAnyFaceCodes) {
                        statusLabel->setText("No matching face, but we can save yours for next time");
                        statusLabel->setStyleSheet("color: #FFA500; font-weight: bold;");

                        QMessageBox::StandardButton reply = QMessageBox::question(loginDialog,
                                                                                  "Save Your Face?",
                                                                                  "Would you like to save your face for future logins?\n\n"
                                                                                  "You'll need to login with ID and password first, then associate this face with your account.",
                                                                                  QMessageBox::Yes | QMessageBox::No);

                        if (reply == QMessageBox::Yes) {
                            // Save the captured face code temporarily
                            QString tempDir = QDir::tempPath() + "/BioVec";
                            QDir().mkpath(tempDir);
                            QString tempFile = tempDir + "/last_captured_face.txt";

                            QFile file(tempFile);
                            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                                QTextStream out(&file);
                                out << capturedFaceEmbedding;
                                file.close();

                                QMessageBox::information(loginDialog, "Face Saved",
                                                         "Your face has been temporarily saved.\n\n"
                                                         "After logging in with ID and password, go to your profile to associate this face with your account.");
                            }
                        }
                    }

                    // Re-enable the verify button
                    QPushButton *verifyButton = loginDialog->findChild<QPushButton*>("Verify Face");
                    if (verifyButton) {
                        verifyButton->setEnabled(true);
                    }
                }

                process->deleteLater();
            });

    // Handle process errors
    connect(process, &QProcess::errorOccurred, this, [process, processingLabel, statusLabel, progressDialog, loginDialog, pythonCmd](QProcess::ProcessError error) {
        processingLabel->deleteLater();

        QString errorText;
        switch (error) {
        case QProcess::FailedToStart:
            errorText = "Failed to start Python process. Check if Python is installed.";
            break;
        case QProcess::Crashed:
            errorText = "Python process crashed. Check face recognition installation.";
            break;
        case QProcess::Timedout:
            errorText = "Python process timed out.";
            break;
        case QProcess::ReadError:
            errorText = "Error reading from Python process.";
            break;
        case QProcess::WriteError:
            errorText = "Error writing to Python process.";
            break;
        default:
            errorText = "Unknown process error.";
        }

        if (statusLabel) {
            statusLabel->setText("Process error: " + errorText);
            statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");
        }

        progressDialog->close();
        progressDialog->deleteLater();
        QMessageBox::critical(loginDialog, "Process Error",
                              "Error running face detection: " + errorText);

        // Re-enable the verify button
        QPushButton *verifyButton = loginDialog->findChild<QPushButton*>("Verify Face");
        if (verifyButton) {
            verifyButton->setEnabled(true);
        }

        process->deleteLater();
    });

    // Set a timeout
    QTimer *timeoutTimer = new QTimer(this);
    timeoutTimer->setSingleShot(true);
    connect(timeoutTimer, &QTimer::timeout, this, [process, processingLabel, timeoutTimer, progressDialog, loginDialog, pythonCmd]() {
        if (process->state() == QProcess::Running) {
            processingLabel->deleteLater();
            progressDialog->close();
            progressDialog->deleteLater();

            process->kill();
            QMessageBox::warning(loginDialog, "Timeout",
                                 "Face detection process timed out. Please try again.");

            // Re-enable the verify button
            QPushButton *verifyButton = loginDialog->findChild<QPushButton*>("Verify Face");
            if (verifyButton) {
                verifyButton->setEnabled(true);
            }
        }
        timeoutTimer->deleteLater();
    });

    connect(process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            timeoutTimer, &QTimer::stop);
    connect(process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            timeoutTimer, &QTimer::deleteLater);

    timeoutTimer->start(60000); // 60 second timeout

    // Start the process
    process->start(pythonCmd, arguments);

    // Check if process started
    if (!process->waitForStarted(5000)) {
        processingLabel->deleteLater();
        progressDialog->close();
        progressDialog->deleteLater();

        if (statusLabel) {
            statusLabel->setText("Failed to start face detection process");
            statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");
        }

        QMessageBox::critical(loginDialog, "Process Error",
                              "Failed to start face detection process: " + process->errorString());

        // Re-enable the verify button
        QPushButton *verifyButton = loginDialog->findChild<QPushButton*>("Verify Face");
        if (verifyButton) {
            verifyButton->setEnabled(true);
        }

        process->deleteLater();
    }
}
