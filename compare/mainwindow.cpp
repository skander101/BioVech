#include "mainwindow.h"
#include "ui_face_embedding.h"
#include <QScrollBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    pythonProcess(nullptr)
{
    ui->setupUi(this);

    // Initialize ui elements
    ui->resultLabel->setText("Upload two face images to compare");
    ui->compareButton->setEnabled(false);

    // Setup connections
    connect(ui->actionLoad_Image_1, &QAction::triggered, this, &MainWindow::on_loadImage1Button_clicked);
    connect(ui->actionLoad_Image_2, &QAction::triggered, this, &MainWindow::on_loadImage2Button_clicked);

    // Log startup message
    logMessage("Face Embedding Comparison Tool started");
    logMessage("Please load two face images to compare");
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
    delete ui;
}

void MainWindow::on_loadImage1Button_clicked()
{
    loadImage(1);
}

void MainWindow::on_loadImage2Button_clicked()
{
    loadImage(2);
}

void MainWindow::on_actionLoad_Image_1_triggered()
{
    loadImage(1);
}

void MainWindow::on_actionLoad_Image_2_triggered()
{
    loadImage(2);
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About Face Embedding Comparison",
                       "Face Embedding Comparison Tool\n\n"
                       "This application uses deep learning to compare faces and determine if they belong to the same person.\n\n"
                       "Powered by DeepFace and TensorFlow");
}

void MainWindow::loadImage(int imageNum)
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

    if (imageNum == 1) {
        image1Path = fileName;
        displayZoomableImage(ui->image1Label, pixmap);
        ui->embedding1LineEdit->clear();
        embedding1.clear();
        logMessage("Image 1 loaded: " + fileName);
        processImage(fileName, 1);
    } else {
        image2Path = fileName;
        displayZoomableImage(ui->image2Label, pixmap);
        ui->embedding2LineEdit->clear();
        embedding2.clear();
        logMessage("Image 2 loaded: " + fileName);
        processImage(fileName, 2);
    }

    updateCompareButtonState();
}

void MainWindow::displayZoomableImage(QLabel *label, const QPixmap &pixmap)
{
    QPixmap scaledPixmap = pixmap.scaled(label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    label->setPixmap(scaledPixmap);
}

void MainWindow::processImage(const QString &imagePath, int imageNum)
{
    if (pythonProcess && pythonProcess->state() == QProcess::Running) {
        QMessageBox::warning(this, tr("Process Running"),
                             tr("Please wait for the current process to finish."));
        return;
    }

    // Delete previous process if exists
    if (pythonProcess) {
        delete pythonProcess;
    }

    pythonProcess = new QProcess(this);

    // Connect signals
    connect(pythonProcess, &QProcess::started, this, &MainWindow::handleProcessStarted);
    connect(pythonProcess, &QProcess::readyReadStandardOutput, this, &MainWindow::handleProcessOutput);
    connect(pythonProcess, &QProcess::readyReadStandardError, this, &MainWindow::handleProcessError);
    connect(pythonProcess, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            this, &MainWindow::handleProcessFinished);

    // Prepare and start process
    QStringList arguments;
    arguments << "face_embedding_processor.py" << imagePath;

    logMessage("Starting face embedding process for image " + QString::number(imageNum));
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

    // Extract embedding code from output
    if (output.contains("Face Embedding Unique ID:")) {
        QStringList lines = output.split("\n");
        for (int i = 0; i < lines.size(); i++) {
            if (lines[i].contains("Face Embedding Unique ID:") && i+1 < lines.size()) {
                QString embedding = lines[i+1].trimmed();
                if (!embedding.isEmpty()) {
                    if (!image1Path.isEmpty() && !embedding1.isEmpty()) {
                        // This must be for image 2
                        embedding2 = embedding;
                        ui->embedding2LineEdit->setText(embedding);
                        logMessage("Embedding for Image 2 generated successfully");
                    } else {
                        // This must be for image 1
                        embedding1 = embedding;
                        ui->embedding1LineEdit->setText(embedding);
                        logMessage("Embedding for Image 1 generated successfully");
                    }

                    ui->progressBar->setValue(80);
                    updateCompareButtonState();
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
    // For hexadecimal encoded embeddings, we need to decode and calculate cosine similarity
    if (embedding1.isEmpty() || embedding2.isEmpty() ||
        embedding1.length() != embedding2.length()) {
        return 0.0;
    }

    // Simple similarity calculation for demonstration
    // In a real implementation, you would decode hex to vector and calculate proper cosine similarity

    int matchingChars = 0;
    int totalChars = embedding1.length();

    for (int i = 0; i < totalChars; i++) {
        // Calculate hex value distance
        int val1 = embedding1[i].isDigit() ? embedding1[i].digitValue() :
                       (embedding1[i].toLower().unicode() - 'a' + 10);
        int val2 = embedding2[i].isDigit() ? embedding2[i].digitValue() :
                       (embedding2[i].toLower().unicode() - 'a' + 10);

        int diff = abs(val1 - val2);
        if (diff <= 2) { // Consider similar if values are close
            matchingChars++;
        }
    }

    return static_cast<double>(matchingChars) / totalChars;
}

void MainWindow::updateCompareButtonState()
{
    bool canCompare = !embedding1.isEmpty() && !embedding2.isEmpty();
    ui->compareButton->setEnabled(canCompare);

    if (canCompare) {
        logMessage("Both embeddings are ready. You can now compare the faces.");
    }
}

void MainWindow::on_compareButton_clicked()
{
    if (embedding1.isEmpty() || embedding2.isEmpty()) {
        QMessageBox::warning(this, tr("Comparison Error"),
                             tr("Please generate embeddings for both images first."));
        return;
    }

    // Calculate similarity
    double similarity = calculateSimilarity(embedding1, embedding2);
    double similarityPercentage = similarity * 100.0;

    // Determine if same person (threshold can be adjusted)
    bool isSamePerson = similarity > 0.75;

    QString resultText;
    if (isSamePerson) {
        resultText = QString("MATCH: These appear to be the same person (%.1f%% similarity)").arg(similarityPercentage);
        ui->resultLabel->setStyleSheet("color: green; font-weight: bold;");
    } else {
        resultText = QString("NO MATCH: These appear to be different people (%.1f%% similarity)").arg(similarityPercentage);
        ui->resultLabel->setStyleSheet("color: red; font-weight: bold;");
    }

    ui->resultLabel->setText(resultText);
    logMessage("Comparison result: " + resultText);
}

void MainWindow::logMessage(const QString &message)
{
    ui->logTextEdit->append(message);
    // Auto-scroll to bottom
    QScrollBar *scrollBar = ui->logTextEdit->verticalScrollBar();
    if (scrollBar) {
        scrollBar->setValue(scrollBar->maximum());
    }
}
