#include "mainwindow.h"
#include "ui_face_embedding.h"
#include <QScrollBar>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    pythonProcess(nullptr),
    isVerifyMode(false)
{
    ui->setupUi(this);

    // Initialize database
    if (!initializeDatabase()) {
        QMessageBox::critical(this, "Database Error", "Failed to initialize database. The application will now exit.");
        QApplication::quit();
    }

    // Initialize UI elements
    ui->registerButton->setEnabled(false);

    // Log startup message
    logMessage("Face Recognition System started");
    logMessage("Please use Register tab to add new patients or Verify tab to identify existing patients");
}

MainWindow::~MainWindow()
{
    if (pythonProcess) {
        if (pythonProcess->state() == QProcess::Running) {
            pythonProcess->terminate();
            pythonProcess->waitForFinished(3000);
        }
        delete pythonProcess;
    }
    if (db.isOpen()) {
        db.close();
    }
    delete ui;
}

bool MainWindow::initializeDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("patients.db");

    if (!db.open()) {
        logMessage("Error: " + db.lastError().text());
        return false;
    }

    QSqlQuery query;
    return query.exec("CREATE TABLE IF NOT EXISTS patient "
                      "(name TEXT NOT NULL, "
                      "facecode TEXT NOT NULL)");
}

void MainWindow::on_registerImageButton_clicked()
{
    isVerifyMode = false;
    loadImage();
}

void MainWindow::on_verifyImageButton_clicked()
{
    isVerifyMode = true;
    loadImage();
}

void MainWindow::loadImage()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Face Image"), "",
                                                    tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));

    if (fileName.isEmpty())
        return;

    QPixmap pixmap(fileName);
    if (pixmap.isNull()) {
        QMessageBox::warning(this, tr("Image Load Error"),
                             tr("Cannot load %1.").arg(fileName));
        return;
    }

    currentImagePath = fileName;
    QLabel *imageLabel = isVerifyMode ? ui->verifyImageLabel : ui->registerImageLabel;
    displayZoomableImage(imageLabel, pixmap);

    clearCurrentData();
    logMessage(QString("%1 image loaded: %2")
                   .arg(isVerifyMode ? "Verify" : "Register")
                   .arg(fileName));

    processImage(fileName);
}

void MainWindow::clearCurrentData()
{
    currentEmbedding.clear();
    if (!isVerifyMode) {
        ui->registerButton->setEnabled(false);
        ui->nameLineEdit->clear();
    }
    ui->resultLabel->clear();
}

void MainWindow::displayZoomableImage(QLabel *label, const QPixmap &pixmap)
{
    QPixmap scaledPixmap = pixmap.scaled(label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    label->setPixmap(scaledPixmap);
}

void MainWindow::processImage(const QString &imagePath)
{
    if (pythonProcess && pythonProcess->state() == QProcess::Running) {
        QMessageBox::warning(this, tr("Process Running"),
                             tr("Please wait for the current process to finish."));
        return;
    }

    if (pythonProcess) {
        delete pythonProcess;
    }

    pythonProcess = new QProcess(this);

    connect(pythonProcess, &QProcess::started, this, &MainWindow::handleProcessStarted);
    connect(pythonProcess, &QProcess::readyReadStandardOutput, this, &MainWindow::handleProcessOutput);
    connect(pythonProcess, &QProcess::readyReadStandardError, this, &MainWindow::handleProcessError);
    connect(pythonProcess, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            this, &MainWindow::handleProcessFinished);

    QStringList arguments;
    arguments << "face_embedding_processor.py" << imagePath;

    logMessage("Starting face embedding process");
    logMessage("Command: python " + arguments.join(" "));

    ui->progressBar->setValue(10);
    pythonProcess->start("python", arguments);
}

void MainWindow::handleProcessStarted()
{
    logMessage("Process started...");
    ui->progressBar->setValue(20);
}

void MainWindow::handleProcessOutput()
{
    QString output = pythonProcess->readAllStandardOutput();
    logMessage(output);

    if (output.contains("Face Embedding Unique ID:")) {
        QStringList lines = output.split("\n");
        for (int i = 0; i < lines.size(); i++) {
            if (lines[i].contains("Face Embedding Unique ID:") && i+1 < lines.size()) {
                currentEmbedding = lines[i+1].trimmed();
                if (!currentEmbedding.isEmpty()) {
                    if (isVerifyMode) {
                        QString matchedName;
                        if (findMatchingPatient(currentEmbedding, matchedName)) {
                            ui->resultLabel->setText("Welcome back : " + matchedName + "!");
                            ui->resultLabel->setStyleSheet("color: green; font-weight: bold;");
                        } else {
                            ui->resultLabel->setText("No matching patient found");
                            ui->resultLabel->setStyleSheet("color: red; font-weight: bold;");
                        }
                    } else {
                        ui->registerButton->setEnabled(true);
                        logMessage("Face embedding generated successfully");
                    }
                    ui->progressBar->setValue(80);
                    break;
                }
            }
        }
    }
}

void MainWindow::handleProcessError()
{
    QString error = pythonProcess->readAllStandardError();
    logMessage("ERROR: " + error);
}

void MainWindow::handleProcessFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    if (exitStatus == QProcess::NormalExit && exitCode == 0) {
        logMessage("Process completed successfully.");
        ui->progressBar->setValue(100);
    } else {
        logMessage("Process failed with exit code " + QString::number(exitCode));
        ui->progressBar->setValue(0);
        QMessageBox::warning(this, tr("Process Error"),
                             tr("Face embedding extraction failed. Please check the log for details."));
    }
}

double MainWindow::calculateSimilarity(const QString &embedding1, const QString &embedding2)
{
    if (embedding1.isEmpty() || embedding2.isEmpty() ||
        embedding1.length() != embedding2.length()) {
        return 0.0;
    }

    int matchingChars = 0;
    int totalChars = embedding1.length();

    for (int i = 0; i < totalChars; i++) {
        int val1 = embedding1[i].isDigit() ? embedding1[i].digitValue() :
                       (embedding1[i].toLower().unicode() - 'a' + 10);
        int val2 = embedding2[i].isDigit() ? embedding2[i].digitValue() :
                       (embedding2[i].toLower().unicode() - 'a' + 10);

        int diff = abs(val1 - val2);
        if (diff <= 2) {
            matchingChars++;
        }
    }

    return static_cast<double>(matchingChars) / totalChars;
}

void MainWindow::on_registerButton_clicked()
{
    QString name = ui->nameLineEdit->text().trimmed();
    if (name.isEmpty()) {
        QMessageBox::warning(this, "Registration Error", "Please enter a name");
        return;
    }

    if (currentEmbedding.isEmpty()) {
        QMessageBox::warning(this, "Registration Error", "No face embedding generated");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO patient (name, facecode) VALUES (:name, :facecode)");
    query.bindValue(":name", name);
    query.bindValue(":facecode", currentEmbedding);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Patient registered successfully");
        clearCurrentData();
        ui->registerImageLabel->clear();
    } else {
        QMessageBox::critical(this, "Error", "Failed to register patient: " + query.lastError().text());
    }
}

bool MainWindow::findMatchingPatient(const QString &faceCode, QString &matchedName)
{
    QSqlQuery query("SELECT name, facecode FROM patient");
    while (query.next()) {
        QString dbName = query.value(0).toString();
        QString dbFaceCode = query.value(1).toString();

        double similarity = calculateSimilarity(faceCode, dbFaceCode);
        if (similarity > 0.90) {
            matchedName = dbName;
            return true;
        }
    }
    return false;
}

void MainWindow::logMessage(const QString &message)
{
    ui->logTextEdit->append(message);
    QScrollBar *scrollBar = ui->logTextEdit->verticalScrollBar();
    if (scrollBar) {
        scrollBar->setValue(scrollBar->maximum());
    }
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About Face Recognition System",
                       "Face Recognition System\n\n"
                       "This application uses deep learning to register and verify patients using facial recognition.\n\n"
                       "Powered by DeepFace and TensorFlow");
}
