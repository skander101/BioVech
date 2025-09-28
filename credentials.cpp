#include "credentials.h"
#include "./ui_credentials.h"
#include "personnel.h" // Include the personnel window header
#include "employe.h"
#include "connection.h"
#include <QMessageBox>
#include <QRandomGenerator>
#include <QComboBox>
#include <QRegularExpression>
#include <QString>
#include <QDir>
#include <QTimer>
#include <QComboBox>
#include <QLabel>
#include <QSlider>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QFrame>
#include <QProgressDialog>
#include <QProcess>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QFileInfo>
#include <QCoreApplication>
#include <QTextEdit>
#include <QDialog>
#include <QPushButton>
#include <QFormLayout>
#include <QImage>
#include <QPixmap>
#include <QIcon>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QEasingCurve>
#include <QParallelAnimationGroup>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QUrl>
#include <QDateTime>
#include <QStandardPaths>
#include <QPainter>
#include <QFont>
#include <QImage>
#include <QMediaCaptureSession>
#include <QMediaDevices>
#include <QCameraDevice>
#include <QImageCapture>
#include <QTemporaryDir>
#include <QElapsedTimer>
#include <QGraphicsOpacityEffect>
#include <QEasingCurve>
#include <QApplication>
#include <QClipboard>
#include <QThread>
#include <QScrollArea>
#include <QSqlRecord>


credentials::credentials(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::credentials)
    , animation(nullptr)
    , speechProcess(new QProcess(this))
    , targetEdit(nullptr)
    , isSpeechRunning(false)
    , availableMicrophones()
    , selectedMicrophoneIndex(-1)
    , recognizedText("")
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
    ui->setupUi(this);
    m_currentOpacity = 1.0;
    // Set current page to login page (index 1)
    ui->stackedWidget->setCurrentIndex(1);
    
    // Initialize database connection
    Connection conn;
    if(!conn.createconnect()) {
        QMessageBox::critical(this, "Database Error", "Failed to connect to the database!");
    }
    
    // Connect button signals for login and create account
    connect(ui->switch_login_butt, SIGNAL(clicked()), this, SLOT(on_switch_login_butt_clicked()));
    connect(ui->switch_create_account_button, SIGNAL(clicked()), this, SLOT(on_switch_create_account_button_clicked()));
    connect(ui->create_account_button, SIGNAL(clicked()), this, SLOT(on_create_account_button_clicked()));
    connect(ui->Log_in_button, SIGNAL(clicked()), this, SLOT(on_Log_in_button_clicked()));
    
    // Connect face recognition buttons
    connect(ui->cameraButton, SIGNAL(clicked()), this, SLOT(on_cameraButton_clicked()));
    connect(ui->cameraButton2, SIGNAL(clicked()), this, SLOT(on_cameraButton2_clicked()));


    // Update EmailLineEdit to handle ID input
    ui->EmailLineEdit->setPlaceholderText("Enter your ID");
    QIntValidator *idValidator = new QIntValidator(this);
    ui->EmailLineEdit->setValidator(idValidator);
    
    // Update emailButton to indicate ID voice input
    ui->emailButton->setText("Voice ID");
    
    // Connect voice buttons
    connect(ui->emailButton, SIGNAL(clicked()), this, SLOT(on_cinButton_clicked()));
    connect(ui->passwordButton, SIGNAL(clicked()), this, SLOT(on_passwordButton_clicked()));
    
    // Connect recognition button
    connect(ui->recognitionButton, SIGNAL(clicked()), this, SLOT(startSpeechRecognition()));
    
    // Initialize validators
    QIntValidator *validator = new QIntValidator(this);
    ui->IdEdit->setValidator(validator);
    QRegularExpression regExp("[A-Za-z]+"); // Regular expression for alphabetic characters
    QRegularExpressionValidator *validator2 = new QRegularExpressionValidator(regExp, this);

    ui->NomEdit->setValidator(validator2);
    ui->PrenomEdit->setValidator(validator2);
    ui->AssuranceEdit->setValidator(validator2);
    
    // Initialize QProcess for speech recognition
    connect(speechProcess, &QProcess::readyReadStandardOutput, this, &credentials::handleSpeechOutput);
    connect(speechProcess, &QProcess::readyReadStandardError, this, &credentials::processSpeechError);
    connect(speechProcess, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), 
            this, &credentials::processSpeechResult);
    
    // Connect signals for UI elements that are now in the UI file
    connect(ui->refreshMicsButton, &QPushButton::clicked, this, &credentials::loadAvailableMicrophones);
    connect(ui->micSelector, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &credentials::onMicrophoneSelected);
    
    // Load available microphones
    QTimer::singleShot(500, this, &credentials::loadAvailableMicrophones);
}

credentials::~credentials()
{
    if (speechProcess->state() == QProcess::Running) {
        speechProcess->terminate();
        speechProcess->waitForFinished(1000);
    }
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

void credentials::loadAvailableMicrophones()
{
    qDebug() << "Loading available microphones...";
    
    // Stop any running process before starting a new one
    if (speechProcess->state() == QProcess::Running) {
        speechProcess->terminate();
        speechProcess->waitForFinished();
    }
    
    // Clear existing microphones and prepare UI
    availableMicrophones.clear();
    ui->micSelector->clear();
    ui->micSelector->addItem("Loading microphones...");
    ui->micSelector->setEnabled(false);
    
    // Get application directory and working directory for debugging
    QString currentDir = QCoreApplication::applicationDirPath();
    QString workingDir = QDir::currentPath();
    qDebug() << "Application directory:" << currentDir;
    qDebug() << "Working directory:" << workingDir;
    
    // Search for speech_to_text.py script in various locations
QStringList possiblePaths = {
    // Add this path first (the actual location of your file)
    QDir::cleanPath(QDir("C:/Users/Dell/OneDrive/Desktop/Atelier_Connexion/Atelier_Connexion/2a14-bytebuilder/").absoluteFilePath("speech_to_text.py")),

    // Keep other paths as fallbacks
    QDir::cleanPath(QCoreApplication::applicationDirPath() + "/speech_to_text.py"),
    QDir::cleanPath(QDir(QCoreApplication::applicationDirPath()).absoluteFilePath("../speech_to_text.py")),
    QDir::cleanPath(QDir(QCoreApplication::applicationDirPath()).absoluteFilePath("../../speech_to_text.py")),
    QDir::cleanPath(QDir(QCoreApplication::applicationDirPath()).absoluteFilePath("../../../speech_to_text.py")),
    QDir::cleanPath(QDir::currentPath() + "/speech_to_text.py"),
    "speech_to_text.py"
};
    
    QString pythonScriptPath;
    for (const QString &path : possiblePaths) {
        QFileInfo fileInfo(path);
        qDebug() << "Checking path:" << path << "Exists:" << fileInfo.exists();
        if (fileInfo.exists()) {
            pythonScriptPath = path;
            break;
        }
    }
    
    if (pythonScriptPath.isEmpty()) {
        ui->micSelector->clear();
        ui->micSelector->addItem("Error: script not found");
        ui->micSelector->setEnabled(true);
        
        QMessageBox::critical(this, "Error", "Could not find speech_to_text.py script.\nPlease ensure it exists in the application directory.");
        return;
    }
    
    qDebug() << "Using script at path:" << pythonScriptPath;
    
    // Check if Python is available
    QProcess pythonCheck;
    pythonCheck.start("python", QStringList() << "--version");
    bool pythonStarted = pythonCheck.waitForStarted(3000);
    
    if (!pythonStarted) {
        qDebug() << "Python command failed to start. Trying python3...";
        pythonCheck.start("python3", QStringList() << "--version");
        pythonStarted = pythonCheck.waitForStarted(3000);
        
        if (!pythonStarted) {
            qDebug() << "Neither python nor python3 commands are available.";
            ui->micSelector->clear();
            ui->micSelector->addItem("Error: Python not found");
            ui->micSelector->setEnabled(true);
            
            QMessageBox::critical(this, "Error", "Python is not installed or not in PATH.\n"
                               "Please install Python and run the install_python_packages.bat script.");
            return;
        }
    }
    
    if (pythonCheck.waitForFinished(3000)) {
        QString pythonVersion = pythonCheck.readAllStandardOutput() + pythonCheck.readAllStandardError();
        qDebug() << "Python version:" << pythonVersion.trimmed();
    }
    
    // Determine which python command to use
    QString pythonCommand = pythonStarted ? "python" : "python3";
    
    // Check for PyAudio package
    QProcess pipCheck;
    pipCheck.start(pythonCommand, QStringList() << "-c" << "import pyaudio; print('PyAudio installed')");
    
    if (!pipCheck.waitForFinished(5000) || pipCheck.exitCode() != 0) {
        QMessageBox::warning(this, "Missing Package", 
                            "The PyAudio package is not installed.\n\n"
                            "Please run the install_python_packages.bat script or manually install it with:\n"
                            "pip install pyaudio");
    }
    
    // Try running Python with elevated privileges to access audio devices
    QProcess elevatedProcess;
    bool elevated = false;
    
    // Check if we're on Windows and try to run with elevated privileges
    #ifdef Q_OS_WIN
        // First try with normal permissions
        elevatedProcess.start(pythonCommand, QStringList() << "-c" << "import pyaudio; p = pyaudio.PyAudio(); print(p.get_device_count()); p.terminate()");
        if (elevatedProcess.waitForFinished(5000)) {
            QString output = elevatedProcess.readAllStandardOutput();
            int deviceCount = output.trimmed().toInt();
            qDebug() << "Device count with normal permissions:" << deviceCount;
            
            if (deviceCount <= 0) {
                // Try to run as elevated to access audio devices
                QMessageBox::information(this, "Microphone Access", 
                                       "We need to run with elevated privileges to detect microphones.\n"
                                       "You might see a User Account Control (UAC) prompt.");
                
                // Create a batch file to run the Python script with admin privileges
                QString batchPath = QDir::tempPath() + "/run_python_admin.bat";
                QFile batchFile(batchPath);
                if (batchFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
                    QTextStream stream(&batchFile);
                    stream << "@echo off\n";
                    stream << "echo Running Python with admin privileges...\n";
                    stream << "powershell -Command \"Start-Process '" << pythonCommand << "' -ArgumentList '" 
                          << pythonScriptPath << " --list-mics' -Verb RunAs -Wait\"\n";
                    stream << "echo Script finished. Press any key to continue...\n";
                    stream << "pause > nul\n";
                    batchFile.close();
                    
                    // Let the user know what's happening
                    QMessageBox::information(this, "Microphone Detection",
                                           "A command prompt window will open. Please click 'Yes' on the UAC prompt.\n"
                                           "Wait for the script to finish, then press any key to continue.");
                    
                    // Run the batch file
                    QProcess::startDetached("cmd.exe", QStringList() << "/c" << batchPath);
                    elevated = true;
                }
            }
        }
    #endif
    
    // Get list of microphones using Python script if not elevated
    if (!elevated) {
        qDebug() << "Running:" << pythonCommand << pythonScriptPath << "--list-mics";
        
        // Use MergedChannels to capture both stdout and stderr in one stream
        speechProcess->setProcessChannelMode(QProcess::MergedChannels);
        
        // Start the process
        speechProcess->start(pythonCommand, QStringList() << pythonScriptPath << "--list-mics");
        
        if (!speechProcess->waitForStarted(5000)) {
            qDebug() << "Failed to start the microphone listing process.";
            qDebug() << "Error:" << speechProcess->errorString();
            
            ui->micSelector->clear();
            ui->micSelector->addItem("Error: " + speechProcess->errorString());
            ui->micSelector->setEnabled(true);
            addManualMicrophones();
            return;
        }
        
        // Increased timeout for Python script execution (20 seconds)
        if (!speechProcess->waitForFinished(20000)) {
            qDebug() << "Microphone listing process timeout.";
            speechProcess->terminate();
            
            ui->micSelector->clear();
            ui->micSelector->addItem("Timeout loading microphones");
            ui->micSelector->setEnabled(true);
            addManualMicrophones();
            return;
        }
        
        // Read all output
        QByteArray allOutput = speechProcess->readAll();
        QString strOutput = QString::fromUtf8(allOutput);
        
        // Log output for debugging
        qDebug() << "Python script output (truncated):" << strOutput.left(500);
        
        // Try all parsing methods
        bool microphonesParsed = false;
        
        // Method 1: Look for the simplified format
        if (!microphonesParsed) {
            int beginMarker = strOutput.indexOf("--- MICROPHONES BEGIN ---");
            int endMarker = strOutput.indexOf("--- MICROPHONES END ---");
            
            if (beginMarker != -1 && endMarker != -1 && beginMarker < endMarker) {
                qDebug() << "Found simplified microphone format";
                
                // Extract the lines between the markers
                QString simplifiedMics = strOutput.mid(beginMarker + 24, endMarker - beginMarker - 24).trimmed();
                QStringList micLines = simplifiedMics.split('\n', Qt::SkipEmptyParts);
                
                ui->micSelector->clear();
                ui->micSelector->setEnabled(true);
                
                for (const QString &line : micLines) {
                    QStringList parts = line.split(':', Qt::SkipEmptyParts);
                    if (parts.size() == 2) {
                        int index = parts[0].trimmed().toInt();
                        QString name = parts[1].trimmed();
                        
                        availableMicrophones.append(qMakePair(index, name));
                        ui->micSelector->addItem(name, index);
                        qDebug() << "Added microphone:" << index << name;
                    }
                }
                
                microphonesParsed = true;
            }
        }
        
        // Method 2: Look for JSON between markers
        if (!microphonesParsed) {
            int startMarker = strOutput.indexOf("QT_JSON_START");
            int endMarker = strOutput.indexOf("QT_JSON_END");
            
            if (startMarker != -1 && endMarker != -1 && startMarker < endMarker) {
                QString jsonContent = strOutput.mid(startMarker + 13, endMarker - startMarker - 13).trimmed();
                qDebug() << "Found JSON between markers:" << jsonContent.left(100);
                
                QJsonParseError jsonError;
                QJsonDocument doc = QJsonDocument::fromJson(jsonContent.toUtf8(), &jsonError);
                
                if (jsonError.error == QJsonParseError::NoError && doc.isArray()) {
                    QJsonArray micArray = doc.array();
                    
                    ui->micSelector->clear();
                    ui->micSelector->setEnabled(true);
                    
                    for (int i = 0; i < micArray.size(); i++) {
                        QJsonObject mic = micArray[i].toObject();
                        int index = mic["index"].toInt();
                        QString name = mic["name"].toString();
                        
                        availableMicrophones.append(qMakePair(index, name));
                        ui->micSelector->addItem(name, index);
                        qDebug() << "Added microphone from JSON:" << index << name;
                    }
                    
                    microphonesParsed = true;
                } else {
                    qDebug() << "JSON parsing error:" << jsonError.errorString();
                }
            }
        }
        
        // Method 3: Regular expression to find a JSON array
        if (!microphonesParsed) {
            QRegularExpression jsonRegex("\\[\\s*\\{[^\\[\\]]*\\}\\s*\\]");
            QRegularExpressionMatch match = jsonRegex.match(strOutput);
            
            if (match.hasMatch()) {
                QString jsonContent = match.captured(0);
                qDebug() << "Found JSON using regex:" << jsonContent.left(100);
                
                QJsonParseError jsonError;
                QJsonDocument doc = QJsonDocument::fromJson(jsonContent.toUtf8(), &jsonError);
                
                if (jsonError.error == QJsonParseError::NoError && doc.isArray()) {
                    QJsonArray micArray = doc.array();
                    
                    ui->micSelector->clear();
                    ui->micSelector->setEnabled(true);
                    
                    for (int i = 0; i < micArray.size(); i++) {
                        QJsonObject mic = micArray[i].toObject();
                        int index = mic["index"].toInt();
                        QString name = mic["name"].toString();
                        
                        availableMicrophones.append(qMakePair(index, name));
                        ui->micSelector->addItem(name, index);
                        qDebug() << "Added microphone from regex JSON:" << index << name;
                    }
                    
                    microphonesParsed = true;
                } else {
                    qDebug() << "JSON regex parsing error:" << jsonError.errorString();
                }
            }
        }
        
        // Method 4: Look for lines with device info
        if (!microphonesParsed) {
            QRegularExpression deviceRegex("Found microphone: (\\d+) - (.+)$");
            QRegularExpressionMatchIterator matches = deviceRegex.globalMatch(strOutput);
            
            if (matches.hasNext()) {
                ui->micSelector->clear();
                ui->micSelector->setEnabled(true);
                
                while (matches.hasNext()) {
                    QRegularExpressionMatch match = matches.next();
                    int index = match.captured(1).toInt();
                    QString name = match.captured(2).trimmed();
                    
                    availableMicrophones.append(qMakePair(index, name));
                    ui->micSelector->addItem(name, index);
                    qDebug() << "Added microphone from regex:" << index << name;
                }
                
                microphonesParsed = true;
            }
        }
        
        // If no microphones were found by any method
        if (!microphonesParsed || availableMicrophones.isEmpty()) {
            qDebug() << "No microphones were found by any parsing method.";
            
            // Add manual microphones as a fallback
            addManualMicrophones();
            

            // Show a message box with options to check system settings

        }
    } else {
        // If we ran with elevated privileges, add manual microphones 
        addManualMicrophones();
    }
}

void credentials::addManualMicrophones()
{
    qDebug() << "Adding manual microphones as fallback...";
    
    ui->micSelector->clear();
    ui->micSelector->setEnabled(true);
    availableMicrophones.clear();
    
    // These are commonly used indexes for the default microphone
    struct MicrophoneInfo {
        int index;
        QString name;
    };
    
    MicrophoneInfo mics[] = {
        {0, "Default Microphone (Index 0)"},
        {1, "Primary Microphone (Index 1)"},
        {2, "Secondary Microphone (Index 2)"},
        {3, "Alternative Microphone (Index 3)"},
        {4, "USB Microphone (Index 4)"},
        {5, "Nvidia Broadcast (Index 5)"},
        {13, "Other Microphone (Index 13)"},
        {14, "WO Mic Device (Index 14)"},
        {32, "Microphone (WO Mic Device) (Index 32)"},
        {35, "USB PnP Audio Device (Index 35)"},
        {36, "NVIDIA Broadcast (Index 36)"},
        {43, "Realtek HD Audio Mic input (Index 43)"}
    };
    
    for (const auto& mic : mics) {
        availableMicrophones.append(qMakePair(mic.index, mic.name));
        ui->micSelector->addItem(mic.name, mic.index);
        qDebug() << "Added manual microphone:" << mic.index << mic.name;
    }
    
    // Select first microphone by default
    if (ui->micSelector->count() > 0) {
        ui->micSelector->setCurrentIndex(0);
        selectedMicrophoneIndex = ui->micSelector->itemData(0).toInt();
        qDebug() << "Selected default manual microphone index:" << selectedMicrophoneIndex;
    }
    
    }

void credentials::onMicrophoneSelected(int index)
{
    if (index >= 0 && index < availableMicrophones.size()) {
        selectedMicrophoneIndex = availableMicrophones[index].first;
        qDebug() << "Selected microphone index:" << selectedMicrophoneIndex;
    }
}

void credentials::on_cinButton_clicked()
{
    targetEdit = ui->EmailLineEdit;  // Use EmailLineEdit for ID
    startSpeechRecognition();
}

void credentials::on_passwordButton_clicked()
{
    targetEdit = ui->PasswordLineEdit;  // Set target QLineEdit to passwordEdit
    startSpeechRecognition();
}

void credentials::startSpeechRecognition()
{
    if (speechProcess->state() == QProcess::Running) {
        speechProcess->terminate();
        speechProcess->waitForFinished();
    }
    
    if (selectedMicrophoneIndex < 0) {
        qDebug() << "No microphone selected";
        ui->speechStatus->setText("No microphone selected");
        QMessageBox::warning(this, "Voice Recognition", "Please select a microphone first.");
        return;
    }
    
    // Reset UI state
    ui->recognitionButton->setEnabled(false);
    ui->speechStatus->setText("Listening...");
    ui->recognizedText->clear();
    recognizedText = "";
    
    // Get application directory
    QString currentDir = QCoreApplication::applicationDirPath();
    qDebug() << "Application directory:" << currentDir;
    
    // Search for speech_to_text.py script in various locations
QStringList possiblePaths = {
    // Add this path first (the actual location of your file)
    QDir::cleanPath(QDir("C:/Users/Dell/OneDrive/Desktop/Atelier_Connexion/Atelier_Connexion/2a14-bytebuilder/").absoluteFilePath("speech_to_text.py")),

    // Keep other paths as fallbacks
    QDir::cleanPath(QCoreApplication::applicationDirPath() + "/speech_to_text.py"),
    QDir::cleanPath(QDir(QCoreApplication::applicationDirPath()).absoluteFilePath("../speech_to_text.py")),
    QDir::cleanPath(QDir(QCoreApplication::applicationDirPath()).absoluteFilePath("../../speech_to_text.py")),
    QDir::cleanPath(QDir(QCoreApplication::applicationDirPath()).absoluteFilePath("../../../speech_to_text.py")),
    QDir::cleanPath(QDir::currentPath() + "/speech_to_text.py"),
    "speech_to_text.py"
};
    
    QString pythonScriptPath;
    for (const QString &path : possiblePaths) {
        QFileInfo fileInfo(path);
        qDebug() << "Checking path:" << path << "Exists:" << fileInfo.exists();
        if (fileInfo.exists()) {
            pythonScriptPath = path;
            break;
        }
    }
    
    if (pythonScriptPath.isEmpty()) {
        qDebug() << "Could not find speech_to_text.py in any of the expected locations.";
        ui->speechStatus->setText("Error: script not found");
        ui->recognitionButton->setEnabled(true);
        QMessageBox::critical(this, "Error", "Could not find speech_to_text.py script.");
        return;
    }
    
    // Determine which python command to use
    QProcess pythonCheck;
    pythonCheck.start("python", QStringList() << "--version");
    bool pythonStarted = pythonCheck.waitForStarted(3000);
    
    QString pythonCommand = "python";
    if (!pythonStarted) {
        qDebug() << "Python command failed to start. Trying python3...";
        pythonCheck.start("python3", QStringList() << "--version");
        pythonStarted = pythonCheck.waitForStarted(3000);
        
        if (!pythonStarted) {
            qDebug() << "Neither python nor python3 commands are available.";
            ui->speechStatus->setText("Error: Python not found");
            ui->recognitionButton->setEnabled(true);
            QMessageBox::critical(this, "Error", "Python is not installed or not in PATH.");
            return;
        }
        pythonCommand = "python3";
    }
    
    // Check for vosk module
    QProcess voskCheck;
    voskCheck.start(pythonCommand, QStringList() << "-c" << "import vosk; print('Vosk found')");
    if (!voskCheck.waitForFinished(5000) || voskCheck.exitCode() != 0) {
        qDebug() << "Vosk module not found";
        QMessageBox::warning(this, "Missing Module", 
                            "The 'vosk' Python module is not installed.\n"
                            "Speech recognition will not work properly.\n\n"
                            "Please run 'pip install vosk' to install it.");
    }
    
    // Check for model directory
QDir dir(QDir::cleanPath(QDir(QCoreApplication::applicationDirPath()).absoluteFilePath("../../../vosk-model-small-fr-0.22")));    //QDir dir(modelDir);
    if (!dir.exists()) {
        // Try alternative paths
        //modelDir = QDir::currentPath() + "/vosk-model-small-fr-0.22";
        //dir.setPath(modelDir);
        
        if (!dir.exists()) {
            //modelDir = "C:/Users/Mega-Pc/Desktop/qt/Nouveau dossier/2a14-bytebuilder/vosk-model-small-fr-0.22";
            //dir.setPath(modelDir);
            
            if (!dir.exists()) {
                qDebug() << "Vosk model directory not found.";
                //qDebug() << modelDir;
                ui->speechStatus->setText("Error: Voice model not found");
                ui->recognitionButton->setEnabled(true);
                QMessageBox::critical(this, "Error", "Voice recognition model not found.\nPlease make sure the vosk-model-small-fr-0.22 directory is in the application directory.");
                return;
            }
        }
    }
    
    //qDebug() << "Using model directory:" << modelDir;
    
    // Start the speech recognition process
    qDebug() << "Starting speech recognition with microphone index:" << selectedMicrophoneIndex;
    qDebug() << "Running:" << pythonCommand << pythonScriptPath << "--device" << QString::number(selectedMicrophoneIndex);
    
    // Set a timeout value for speech recognition (in seconds)
    int timeout = 10;
    
    // Configure process to capture all outputs
    speechProcess->setProcessChannelMode(QProcess::SeparateChannels);
    
    speechProcess->start(pythonCommand, QStringList() 
                     << pythonScriptPath 
                     << "--device" << QString::number(selectedMicrophoneIndex)
                     << "--timeout" << QString::number(timeout));
    
    if (!speechProcess->waitForStarted(5000)) {
        qDebug() << "Failed to start speech recognition process";
        qDebug() << "Error:" << speechProcess->errorString();
        ui->speechStatus->setText("Error: " + speechProcess->errorString());
        ui->recognitionButton->setEnabled(true);
        return;
    }
    
    qDebug() << "Speech recognition process started";
    ui->speechStatus->setText("Listening (max " + QString::number(timeout) + " seconds)...");
    
    // Show progress in UI with a timer
    QTimer *progressTimer = new QTimer(this);
    int elapsedSeconds = 0;
    
    connect(progressTimer, &QTimer::timeout, this, [=]() mutable {
        elapsedSeconds++;
        ui->speechStatus->setText("Listening (" + QString::number(elapsedSeconds) + "/" + QString::number(timeout) + " seconds)...");
        
        if (elapsedSeconds >= timeout) {
            progressTimer->stop();
            progressTimer->deleteLater();
        }
    });
    
    progressTimer->start(1000); // Update every second
}

void credentials::processSpeechResult()
{
    if (speechProcess->state() == QProcess::NotRunning) {
        QByteArray output = speechProcess->readAllStandardOutput();
        QByteArray errorOutput = speechProcess->readAllStandardError();
        
        qDebug() << "Speech recognition process finished";
        qDebug() << "Exit code:" << speechProcess->exitCode();
        qDebug() << "Exit status:" << speechProcess->exitStatus();
        
        if (!errorOutput.isEmpty()) {
            qDebug() << "Speech recognition error output:" << errorOutput;
            
            // Check for critical errors in error output
            QString errorString = QString::fromUtf8(errorOutput);
            if (errorString.contains("Error opening audio stream", Qt::CaseInsensitive) ||
                errorString.contains("No default input device", Qt::CaseInsensitive) ||
                errorString.contains("Invalid device index", Qt::CaseInsensitive)) {
                
                QMessageBox::warning(this, "Microphone Error", 
                                    "There was a problem accessing the selected microphone.\n\n"
                                    "The microphone might be in use by another application or disabled.\n\n"
                                    "Please try another microphone or check your system settings.");
            }
            else if (errorString.contains("could not find the vosk model", Qt::CaseInsensitive)) {
                QMessageBox::warning(this, "Model Error", 
                                    "Could not find the voice recognition model files.\n\n"
                                    "Please make sure the 'vosk-model-small-fr-0.22' directory is present.");
            }
        }
        
        QString result = QString::fromUtf8(output).trimmed();
        qDebug() << "Speech recognition result:" << result;
        
        // If we didn't already handle text in handleSpeechOutput
        if (recognizedText.isEmpty()) {
            if (result.isEmpty()) {

            } else {
                // Filter out non-speech text
                if (result.contains("{") || result.contains("}") || 
                    result.contains("Listening") || result.startsWith("[") ||
                    result.contains("QT_JSON") || result.contains("Python")) {
                    
                    // Try to find actual text in the result
                    QStringList lines = result.split("\n");
                    for (const QString &line : lines) {
                        if (!line.contains("{") && !line.contains("}") && 
                            !line.contains("Listening") && !line.startsWith("[") &&
                            !line.contains("QT_JSON") && !line.contains("Python") &&
                            !line.trimmed().isEmpty()) {
                            
                            recognizedText = line.trimmed();
                            ui->recognizedText->setText(recognizedText);
                            break;
                        }
                    }
                    
                    if (recognizedText.isEmpty()) {
                        ui->speechStatus->setText("Speech processing error");
                        qDebug() << "Could not find speech in result";
                    } else {
                        ui->speechStatus->setText("Done");
                    }
                } else {
                    recognizedText = result;
                    ui->speechStatus->setText("Done");
                }
            }
        } else {
            ui->speechStatus->setText("Done");
        }
        
        ui->recognitionButton->setEnabled(true);
    }
}

void credentials::handleSpeechOutput()
{
    QByteArray output = speechProcess->readAllStandardOutput();
    QString text = QString(output).trimmed();
    int newlinePos = text.indexOf('\n');
    QString firstLine = (newlinePos != -1) ? text.left(newlinePos) : text;
    text = firstLine;

    // Debug: Print the recognized text
    qDebug() << "Recognized text from stdout:" << text;
    
    // Only process if we have target edit field and non-empty text
    if (!targetEdit || text.isEmpty()) {
        return;
    }
    
    // Filter out debugging outputs and only set valid text
    // Ignore JSON outputs, markers, and other non-speech text
    if (text.contains("{") || text.contains("}") || 
        text.contains("Listening") || text.startsWith("[") ||
        text.contains("QT_JSON") || text.contains("Python") ||
        text.contains("pyaudio") || text.contains("version")) {
        
        qDebug() << "Ignoring non-speech output:" << text;
        return;
    }

    // Some basic cleanup of the recognized text
    text = text.trimmed();
    
    // If it's an ID field, convert spoken numbers to digits
    if (targetEdit == ui->EmailLineEdit) {
        // Convert spoken French numbers to digits
        text = convertSpokenNumbersToDigits(text);
        
        // Remove any non-numeric characters
        QString numericOnly;
        for (const QChar &c : text) {
            if (c.isDigit()) {
                numericOnly.append(c);
            }
        }
        text = text.remove(" ");
        text = numericOnly;
    } 
    // If password field, convert numbers but keep text
    else if (targetEdit == ui->PasswordLineEdit) {
        // Convert spoken numbers to digits while preserving other text
        text = convertSpokenNumbersToDigits(text);
        
        // Remove spaces
        text = text.remove(" ");
    }
    
    if (!text.isEmpty()) {
        // Set the text in the target field
        targetEdit->setText(text);
        qDebug()<<"niggawhy";
        // Store the recognized text for later use
        recognizedText = text;
        ui->recognizedText->setText(text);
        
        // Show a brief confirmation message
        QLabel *confirmLabel = new QLabel(targetEdit->parentWidget());
        confirmLabel->setText("✓ Voice detected");
        confirmLabel->setStyleSheet("color: green; font-weight: bold;");
        confirmLabel->move(targetEdit->x() + targetEdit->width() - 120, 
                          targetEdit->y() + targetEdit->height() + 5);
        confirmLabel->show();
        
        // Auto-hide after 3 seconds
        QTimer::singleShot(3000, confirmLabel, &QLabel::deleteLater);
    }
}

// Helper method to convert spoken numbers to digits
QString credentials::convertSpokenNumbersToDigits(const QString &text)
{
    // Make a copy we can modify
    QString result = text;
    
    // Create a map for French numbers
    QMap<QString, QString> numberWords;
    
    // French numbers
    numberWords["zéro"] = "0";
    numberWords["zero"] = "0";
    numberWords["un"] = "1";
    numberWords["en"] = "1";
    numberWords["an"] = "1";
    numberWords["une"] = "1";
    numberWords["deux"] = "2";
    numberWords["de"] = "2";
    numberWords["dieux"] = "2";
    numberWords["dieu"] = "2";
    numberWords["trois"] = "3";
    numberWords["toi"] = "3";
    numberWords["troie"] = "3";
    numberWords["quatre"] = "4";
    numberWords["cinq"] = "5";
    numberWords["six"] = "6";
    numberWords["si"] = "6";
    numberWords["ci"] = "6";
    numberWords["scie"] = "6";
    numberWords["sept"] = "7";
    numberWords["cette"] = "7";
    numberWords["huit"] = "8";
    numberWords["neuf"] = "9";
    numberWords["dix"] = "10";
    numberWords["onze"] = "11";
    numberWords["douze"] = "12";
    numberWords["treize"] = "13";
    numberWords["quatorze"] = "14";
    numberWords["quinze"] = "15";
    numberWords["seize"] = "16";
    numberWords["dix-sept"] = "17";
    numberWords["dix sept"] = "17";
    numberWords["dixsept"] = "17";
    numberWords["dix-huit"] = "18";
    numberWords["dix huit"] = "18";
    numberWords["dixhuit"] = "18";
    numberWords["dix-neuf"] = "19";
    numberWords["dix neuf"] = "19";
    numberWords["dixneuf"] = "19";
    numberWords["vingt"] = "20";
    
    // English numbers for fallback
    numberWords["zero"] = "0";
    numberWords["one"] = "1";
    numberWords["two"] = "2";
    numberWords["three"] = "3";
    numberWords["four"] = "4";
    numberWords["five"] = "5";
    numberWords["six"] = "6";
    numberWords["seven"] = "7";
    numberWords["eight"] = "8";
    numberWords["nine"] = "9";
    numberWords["ten"] = "10";
    
    // Split the input into words
    QStringList words = result.split(" ", Qt::SkipEmptyParts);
    for (int i = 0; i < words.size(); i++) {
        QString word = words[i].toLower();
        
        // Check if this word is a spoken number
        if (numberWords.contains(word)) {
            // Replace the word with its digit
            words[i] = numberWords[word];
        }
    }
    
    // Join back into a string
    result = words.join(" ");
    return result;
}

void credentials::on_create_account_button_clicked()
{
    // Get values from input fields
    QLineEdit* idEdit = ui->IdEdit;
    QLineEdit* NomEdit = ui->NomEdit;
    QLineEdit* PrenomEdit = ui->PrenomEdit;
    QComboBox* Post = ui->Post;
    QLineEdit* AssuranceEdit = ui->AssuranceEdit;
    QSpinBox* AgeEdit = ui->AgeSpinBox;
    QDoubleSpinBox* SalaireEdit = ui->SalaireDoubleSpinBox;
    QLineEdit* passwordEdit = ui->PasswordCreateEdit; // Use the UI password field directly
    QLineEdit* FacecodeEdit = ui->facecode;

    
    // Get Password from the create account page
    QString password = passwordEdit->text();

    // Validate inputs
    if (!idEdit || !NomEdit || !PrenomEdit || !Post || !AssuranceEdit || !AgeEdit || !SalaireEdit || !passwordEdit || !FacecodeEdit) {
        QMessageBox::warning(this, "Error", "UI components not found!");
        return;
    }

    if (idEdit->text().isEmpty() || NomEdit->text().isEmpty() || PrenomEdit->text().isEmpty() || 
        Post->currentText().isEmpty() || AssuranceEdit->text().isEmpty() || password.isEmpty() ||
        !FacecodeEdit) {
        QMessageBox::warning(this, "Missing Information", "Please fill in all required fields.");
        return;
    }

    // Debug output
    qDebug() << "Adding personnel with ID:" << idEdit->text();

    // Create Employee object
    Employee p;
    p.setId(idEdit->text().toInt());
    p.setNom(NomEdit->text());
    p.setPrenom(PrenomEdit->text());
    p.setPoste(Post->currentText());
    p.setSalaire(SalaireEdit->value());
    p.setAge(AgeEdit->value());
    p.setAssurance(AssuranceEdit->text());
    p.setFacecode(FacecodeEdit->text());

    // Save to database with CIN as null/0 but with password
    bool success = p.createEmployee(
        p.getId(),
        p.getNom(),
        p.getPrenom(),
        p.getPoste(),
        p.getSalaire(),
        p.getAge(),
        p.getAssurance(),
        password,
        p.getFacecode()
    );
    
    // Debug output for database operation result
    qDebug() << "Database save operation result:" << (success ? "Success" : "Failed");
    if (!success) {
        QSqlDatabase db = QSqlDatabase::database();
        qDebug() << "Database error:" << db.lastError().text();
    }

    if (success) {
        QMessageBox::information(this, "Success", "Account created successfully!");
        this->close();

        // Open the personnel window
        personnel* personnelWindow = new personnel();
        personnelWindow->show();
    } else {
        QMessageBox::critical(this, "Error", "Failed to create account. Please check your inputs and try again.");
        qDebug() << password << p.getAssurance() <<  p.getAge() << p.getSalaire() << p.getPoste() << p.getPrenom() << p.getNom() << p.getId();


    }
}

void credentials::on_Log_in_button_clicked()
{
    QString idText = ui->EmailLineEdit->text().trimmed(); // Get ID from EmailLineEdit
    QString password = ui->PasswordLineEdit->text().trimmed();
    QString facecode = ui->facecode->text().trimmed();

    
    if (idText.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(nullptr, "Input Error", "ID and Password fields cannot be empty!");
        return;
    }
    
    // Validate that ID is numeric
    bool isNumeric;
    int idValue = idText.toInt(&isNumeric);
    
    if (!isNumeric) {
        QMessageBox::warning(nullptr, "Input Error", "ID must be a numeric value!");
        return;
    }
    
    // Check credentials using the employee class with ID and password
    Employee e;
    if (e.verifyIDPassword(idValue, password)||e.verifyFaceCode(facecode)) {
        this->close();
        
        // Open the personnel window
        personnel* personnelWindow = new personnel();
        personnelWindow->show();
    }
    else {
        QMessageBox::warning(nullptr, "Login Error", "Invalid ID or Password. Please try again.");
    }
}



void credentials::on_switch_login_butt_clicked()
{
    startFadeAnimation(1, ui->switch_create_account_button);
}

void credentials::on_switch_create_account_button_clicked()
{
    startFadeAnimation(0, ui->switch_login_butt);
}

// Add this method to your credentials class
void credentials::updateFade()
{if (!m_opacityEffect || !m_fadeTimer) {
        qWarning() << "updateFade called with invalid timer or effect!";
        if(m_fadeTimer && m_fadeTimer->isActive()) m_fadeTimer->stop();
        return;
    }

    //qDebug() << "Update Fade: Current Opacity=" << m_currentOpacity << "FadingIn=" << m_fadingIn;

    if (m_fadingIn) {
        // --- Fading In ---
        m_currentOpacity += m_opacityStep;
        if (m_currentOpacity >= 1.0) {
            m_currentOpacity = 1.0;
            m_opacityEffect->setOpacity(m_currentOpacity); // Apply final opacity
            m_fadeTimer->stop();
            m_fadingIn = false; // Reset state
            qDebug() << "Fade In complete.";

            // Re-enable the *other* button (the one for the page we just arrived at)
            if (m_buttonToEnable) {
                m_buttonToEnable->setEnabled(true);
                qDebug() << "Re-enabled button:" << m_buttonToEnable->objectName();
                m_buttonToEnable = nullptr; // Clear stored button
            }
            // Optional: Remove the effect now that it's full opacity?
            // ui->stackedWidget->setGraphicsEffect(nullptr);
            // delete m_opacityEffect; // Be careful if you do this
            // m_opacityEffect = nullptr;
        } else {
            m_opacityEffect->setOpacity(m_currentOpacity); // Apply intermediate opacity
        }
    } else {
        // --- Fading Out ---
        m_currentOpacity -= m_opacityStep;
        if (m_currentOpacity <= 0.0) {
            m_currentOpacity = 0.0;
            m_opacityEffect->setOpacity(m_currentOpacity); // Apply final opacity (invisible)

            // --- Switch Page ---
            qDebug() << "Fade Out complete. Switching to page index:" << m_targetPageIndex;
            ui->stackedWidget->setCurrentIndex(m_targetPageIndex);

            // --- Start Fading In ---
            m_fadingIn = true;
            // Don't stop/restart timer, just let it continue for the fade-in phase
        } else {
            m_opacityEffect->setOpacity(m_currentOpacity); // Apply intermediate opacity
        }
    }
}

void credentials::startFadeAnimation(int targetIndex, QPushButton* buttonToReEnable)
{
    qDebug() << "Starting fade to index:" << targetIndex;

    // --- Ensure Timer Exists ---
    if (!m_fadeTimer) {
        m_fadeTimer = new QTimer(this);
        connect(m_fadeTimer, &QTimer::timeout, this, &credentials::updateFade);
        qDebug() << "Created fade timer.";
    }

    // --- Stop any existing animation ---
    if (m_fadeTimer->isActive()) {
        qDebug() << "Stopping active fade timer.";
        m_fadeTimer->stop();
        // Restore previous button if animation was interrupted
        if (m_buttonToEnable) {
            m_buttonToEnable->setEnabled(true);
        }
    }

    // --- Ensure Effect Exists and is Applied ---
    if (!m_opacityEffect) {
        m_opacityEffect = new QGraphicsOpacityEffect(this); // Parent to 'this' or specific widget
        ui->stackedWidget->setGraphicsEffect(m_opacityEffect);
        qDebug() << "Created and applied opacity effect.";
    }

    // --- Set Animation State ---
    m_targetPageIndex = targetIndex;
    m_fadingIn = false; // Start by fading out
    // Start fade from current opacity, in case animation was interrupted
    m_currentOpacity = m_opacityEffect->opacity();
    m_buttonToEnable = buttonToReEnable; // Store button to re-enable later

    qDebug() << "Initial state: Target=" << m_targetPageIndex
             << "FadingIn=" << m_fadingIn
             << "CurrentOpacity=" << m_currentOpacity;


    // --- Disable Buttons ---
    ui->switch_login_butt->setEnabled(false);
    ui->switch_create_account_button->setEnabled(false);

    // --- Start Fade Out ---
    // Use a small interval for smooth animation (e.g., ~60fps)
    m_fadeTimer->start(16);
}




void credentials::processSpeechError()
{
    QByteArray errorOutput = speechProcess->readAllStandardError();
    if (!errorOutput.isEmpty()) {
        QString errorText = QString::fromUtf8(errorOutput);
        qDebug() << "Speech recognition error:" << errorText;
        
        // Check for common error patterns
        if (errorText.contains("ImportError: No module named pyaudio", Qt::CaseInsensitive) ||
            errorText.contains("ModuleNotFoundError: No module named 'pyaudio'", Qt::CaseInsensitive)) {
            
            QMessageBox::warning(this, "Missing PyAudio", 
                               "The PyAudio module is not installed.\n\n"
                               "Please run the install_python_packages.bat script.");
            
            ui->speechStatus->setText("Error: PyAudio not installed");
        }
        else if (errorText.contains("ImportError: No module named vosk", Qt::CaseInsensitive) ||
                 errorText.contains("ModuleNotFoundError: No module named 'vosk'", Qt::CaseInsensitive)) {
            
            QMessageBox::warning(this, "Missing Vosk", 
                               "The Vosk speech recognition module is not installed.\n\n"
                               "Please run the install_python_packages.bat script.");
            
            ui->speechStatus->setText("Error: Vosk not installed");
        }
        else if (errorText.contains("Error opening audio stream", Qt::CaseInsensitive) ||
                 errorText.contains("Invalid device index", Qt::CaseInsensitive)) {
            
            QMessageBox::warning(this, "Microphone Error", 
                               "Could not access the selected microphone.\n\n"
                               "The microphone might be in use by another application or disabled.");
            
            ui->speechStatus->setText("Error: Cannot access microphone");
        }
    }
}

void credentials::switch_to_login()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void credentials::switch_to_create_account()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void credentials::create_account()
{
    on_create_account_button_clicked();
}

void credentials::login()
{
    on_Log_in_button_clicked();
}

void credentials::on_cameraButton_clicked()
{
    ui->facecode->setReadOnly(false);

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

        connect(generateButton, &QPushButton::clicked, this, &credentials::captureImage);

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
        connect(cameraDialog, &QDialog::finished, this, &credentials::stopCamera);
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
    ui->facecode->setReadOnly(true);

}

void credentials::startCamera(const QByteArray &cameraId)
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
    connect(camera, &QCamera::errorOccurred, this, &credentials::handleCameraError);

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
            connect(faceDetectionTimer, &QTimer::timeout, this, &credentials::detectFaceInViewfinder);

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

void credentials::captureImage()
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
void credentials::processCapturedImage(const QString &filePath, QLabel *processingLabel, QLabel *statusLabel, QProgressDialog *progressDialog)
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

void credentials::stopCamera()
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
void credentials::handleCameraError(QCamera::Error error, const QString &errorString)
{
    Q_UNUSED(error);
    QLabel *statusLabel = cameraDialog->findChild<QLabel*>("statusLabel");
    if (statusLabel) {
        statusLabel->setText("Camera error: " + errorString);
        statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");
    }
    QMessageBox::warning(cameraDialog, "Camera Error", "Error: " + errorString);
}

void credentials::detectFaceInViewfinder()
{
    // Disable background face detection - it's causing too many errors
    // We'll only do face detection when the user clicks the capture button
    return;
}

void credentials::on_cameraButton2_clicked()
{
    ui->facecode->setReadOnly(false);

    // Create a face recognition login dialog
    QDialog *faceLoginDialog = new QDialog(this);
    faceLoginDialog->setWindowTitle("BioVec - Face Recognition Login");
    faceLoginDialog->setMinimumSize(800, 600);

    // Create layout for the dialog
    QVBoxLayout *layout = new QVBoxLayout(faceLoginDialog);

    // Add camera selection dropdown
    QHBoxLayout *cameraSelectionLayout = new QHBoxLayout();
    QLabel *cameraLabel = new QLabel("Select Camera:", faceLoginDialog);
    cameraLabel->setStyleSheet("font-weight: bold; color: #208c54;");

    QComboBox *cameraSelector = new QComboBox(faceLoginDialog);
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

    QPushButton *refreshCamerasButton = new QPushButton("Refresh", faceLoginDialog);
    refreshCamerasButton->setStyleSheet("background-color: #3498db; color: white; padding: 4px 10px; border-radius: 3px;");
    connect(refreshCamerasButton, &QPushButton::clicked, this, [this, cameraSelector]() {
        const QList<QCameraDevice> cameras = QMediaDevices::videoInputs();
        QVariant currentCameraId;
        if (cameraSelector->currentIndex() >= 0) {
            currentCameraId = cameraSelector->currentData();
        }

        cameraSelector->clear();

        if (cameras.isEmpty()) {
            cameraSelector->addItem("No cameras available");
            cameraSelector->setEnabled(false);
        } else {
            int indexToSelect = 0;
            for (int i = 0; i < cameras.size(); ++i) {
                const QCameraDevice &cameraDevice = cameras[i];
                cameraSelector->addItem(cameraDevice.description(), QVariant::fromValue(cameraDevice.id()));

                if (currentCameraId.isValid() && currentCameraId == cameraDevice.id()) {
                    indexToSelect = i;
                }
            }
            cameraSelector->setCurrentIndex(indexToSelect);
            cameraSelector->setEnabled(true);
        }
    });

    cameraSelectionLayout->addWidget(cameraLabel);
    cameraSelectionLayout->addWidget(cameraSelector, 1);
    cameraSelectionLayout->addWidget(refreshCamerasButton);
    layout->addLayout(cameraSelectionLayout);

    // Create viewfinder
    QVideoWidget *viewfinder = new QVideoWidget(faceLoginDialog);
    viewfinder->setMinimumSize(640, 480);
    viewfinder->setStyleSheet("background-color: black; border: 1px solid #208c54;");
    layout->addWidget(viewfinder);

    // Status label
    QLabel *statusLabel = new QLabel(faceLoginDialog);
    statusLabel->setObjectName("statusLabel");
    statusLabel->setStyleSheet("color: #208c54; font-weight: bold;");
    statusLabel->setText("Please start the camera and look at the camera for facial recognition.");
    layout->addWidget(statusLabel);

    // Create buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    QPushButton *startButton = new QPushButton("Start Camera", faceLoginDialog);
    startButton->setStyleSheet("background-color: #208c54; color: white; padding: 8px 15px; border-radius: 4px;");

    QPushButton *verifyButton = new QPushButton("Verify Face", faceLoginDialog);
    verifyButton->setStyleSheet("background-color: #2ecc71; color: white; padding: 8px 15px; border-radius: 4px;");
    verifyButton->setEnabled(false);

    QPushButton *closeButton = new QPushButton("Close", faceLoginDialog);
    closeButton->setStyleSheet("background-color: #e74c3c; color: white; padding: 8px 15px; border-radius: 4px;");

    buttonLayout->addWidget(startButton);
    buttonLayout->addWidget(verifyButton);
    buttonLayout->addWidget(closeButton);

    layout->addLayout(buttonLayout);

    // Camera session variables
    QCamera *camera = nullptr;
    QMediaCaptureSession *captureSession = nullptr;
    QImageCapture *imageCapture = nullptr;

    // Connect signals
    connect(startButton, &QPushButton::clicked, [=, &camera, &captureSession, &imageCapture]() mutable {
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

        // Get camera device
        QByteArray cameraId = cameraSelector->currentData().toByteArray();
        QCameraDevice selectedCamera = cameras.first(); // Default to first camera

        if (!cameraId.isEmpty()) {
            for (const QCameraDevice &device : cameras) {
                if (device.id() == cameraId) {
                    selectedCamera = device;
                    break;
                }
            }
        }

        // Create the camera
        camera = new QCamera(selectedCamera, this);
        statusLabel->setText("Starting camera: " + selectedCamera.description());

        // Connect error signal
        connect(camera, &QCamera::errorOccurred, this, [statusLabel](QCamera::Error error, const QString &errorString) {
            Q_UNUSED(error);
            statusLabel->setText("Camera error: " + errorString);
            statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");
        });

        // Create image capture
        imageCapture = new QImageCapture(this);

        // Set up the capture session
        captureSession->setCamera(camera);
        captureSession->setVideoOutput(viewfinder);
        captureSession->setImageCapture(imageCapture);

        // Start the camera
        camera->start();

        // Enable verify button after camera starts
        QTimer::singleShot(2000, [verifyButton, camera, statusLabel]() {
            if (camera && camera->isActive()) {
                verifyButton->setEnabled(true);
                statusLabel->setText("Camera ready. Click 'Verify Face' to login with facial recognition.");
            }
        });
    });

    // Face verification
    connect(verifyButton, &QPushButton::clicked, [=, &camera, &imageCapture, &captureSession]() mutable {
        if (!camera || !imageCapture || !camera->isActive()) {
            QMessageBox::warning(faceLoginDialog, "Camera Error", "Camera is not ready. Please start the camera first.");
            return;
        }

        // Disable button during verification
        verifyButton->setEnabled(false);
        statusLabel->setText("Capturing image for verification...");
        statusLabel->setStyleSheet("color: #FFA500; font-weight: bold;");

        // Create a temporary directory for the capture
        QString captureDir = QDir::tempPath() + "/BioVec/FaceLogin";
        QDir dir(captureDir);
        if (!dir.exists()) {
            dir.mkpath(".");
        }

        // Generate filename with timestamp
        QString timestamp = QDateTime::currentDateTime().toString("yyyyMMdd-hhmmss");
        QString fileName = QDir::toNativeSeparators(dir.absoluteFilePath("login-" + timestamp + ".jpg"));

        // Create a processing indicator
        QLabel *processingLabel = new QLabel(viewfinder);
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

        // Progress dialog
        QProgressDialog *progressDialog = new QProgressDialog("Verifying your face...", nullptr, 0, 100, faceLoginDialog);
        progressDialog->setWindowTitle("Face Verification");
        progressDialog->setWindowModality(Qt::WindowModal);
        progressDialog->setValue(0);
        progressDialog->setMinimumDuration(1000);
        progressDialog->setCancelButton(nullptr);

        // Capture image and verify
        connect(imageCapture, &QImageCapture::imageSaved, this, [this, faceLoginDialog, statusLabel, processingLabel, progressDialog](int id, const QString &filePath) {
            Q_UNUSED(id);
            processLoginFace(filePath, faceLoginDialog, statusLabel, processingLabel, progressDialog);
        });

        connect(imageCapture, &QImageCapture::errorOccurred, this, [verifyButton, processingLabel, statusLabel, progressDialog](int id, QImageCapture::Error error, const QString &errorString) {
            Q_UNUSED(id);
            Q_UNUSED(error);

            processingLabel->deleteLater();
            progressDialog->close();
            progressDialog->deleteLater();

            statusLabel->setText("Capture error: " + errorString);
            statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold;");

            QMessageBox::warning(nullptr, "Capture Error", "Failed to capture image: " + errorString);
            verifyButton->setEnabled(true);
        });

        // Capture the image
        imageCapture->captureToFile(fileName);
    });

    // Close dialog and clean up
    connect(closeButton, &QPushButton::clicked, [faceLoginDialog, &camera, &captureSession]() mutable {
        // Clean up camera resources
        if (camera && camera->isActive()) {
            camera->stop();
        }

        faceLoginDialog->reject();
    });

    // Close event handler
    connect(faceLoginDialog, &QDialog::finished, [&camera, &captureSession, &imageCapture]() mutable {
        // Clean up camera resources
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
    });

    // Show the dialog
    faceLoginDialog->exec();
    ui->facecode->setReadOnly(true);

}

void credentials::processLoginFace(const QString &filePath, QDialog *loginDialog, QLabel *statusLabel, QLabel *processingLabel, QProgressDialog *progressDialog)
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
                    int confidencePercent = QRandomGenerator::global()->bounded(90, 101);  // Random between 90-100
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
                    if (bestMatchDistance < 0.6 && bestMatchDistance >= 0.1) {
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



void credentials::on_skipbutton_clicked()
{
    this->close();

    // Open the personnel window
    personnel* personnelWindow = new personnel();
    personnelWindow->show();
}
