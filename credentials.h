#ifndef CREDENTIALS_H
#define CREDENTIALS_H

#include <QWidget>
#include <QStackedWidget>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QProcess>
#include <QLineEdit>
#include <QComboBox>
#include <QSlider>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QTimer>
#include <QLabel>
#include <QPushButton>
#include <QList>
#include <QPair>
#include <QVariantAnimation>
#include <QAbstractAnimation>
#include <QGraphicsOpacityEffect>
#include <QMediaPlayer>
#include <QMediaDevices>
#include <QAudioDevice>
#include <QAudioOutput>
#include <QVideoWidget>
#include <QVideoSink>
#include <QMediaCaptureSession>
#include <QImageCapture>
#include <QCamera>
#include <QUrl>
#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QProgressDialog>
QT_BEGIN_NAMESPACE
namespace Ui {
class credentials;
}
QT_END_NAMESPACE

class credentials : public QWidget
{
    Q_OBJECT

public:
    credentials(QWidget *parent = nullptr);
    ~credentials();
    void animateSwitch(QWidget *whiteCard, QWidget *wordContainer, int newPageIndex);
    void animateAndSwitchPage(int targetIndex);
private slots:
    // Navigation
    void switch_to_login();
    void switch_to_create_account();
    void create_account();
    void login();
    
    // Voice recognition
    void startSpeechRecognition();
    void loadAvailableMicrophones();
    void onMicrophoneSelected(int index);
    void processSpeechResult();
    void processSpeechError();
    void handleSpeechOutput();
    
    // UI Button click handlers
    void on_cinButton_clicked();
    void on_passwordButton_clicked();
    void on_cameraButton_clicked();
    void on_cameraButton2_clicked();
    void on_create_account_button_clicked();
    void on_Log_in_button_clicked();
    void on_switch_login_butt_clicked();
    void on_switch_create_account_button_clicked();

    // Camera handlers
    void startCamera(const QByteArray &cameraId = QByteArray());
    void stopCamera();
    void captureImage();
    void handleCameraError(QCamera::Error error, const QString &errorString);

    // Face detection in viewfinder
    void detectFaceInViewfinder();

    void on_skipbutton_clicked();

private:
    Ui::credentials *ui;
    QPropertyAnimation *animation;
    QProcess *speechProcess;
    QLineEdit *targetEdit;
    bool isSpeechRunning;
    QList<QPair<int, QString>> availableMicrophones;
    int selectedMicrophoneIndex;
    QString recognizedText;
    
    // Face recognition members
    // Camera components
    QDialog *cameraDialog;
    QCamera *camera;
    QMediaCaptureSession *captureSession;
    QVideoWidget *viewfinder;
    QImageCapture *imageCapture;
    QString lastCaptureFilename;
    QString currentFaceEmbedding;
    bool isCaptureInProgress;

    bool readMode;
    bool updateMode;
    void updateFade();
    // Helper methods
    void addManualMicrophones();
    QString convertSpokenNumbersToDigits(const QString &text);
    void setupCameraDialog();
    void processCapturedImage(const QString &filePath, QLabel *processingLabel, QLabel *statusLabel, QProgressDialog *progressDialog);
    void processLoginFace(const QString &filePath, QDialog *loginDialog, QLabel *statusLabel, QLabel *processingLabel, QProgressDialog *progressDialog);

    // Animation members
    QTimer* m_fadeTimer = nullptr; // Initialize to nullptr
    QGraphicsOpacityEffect* m_opacityEffect = nullptr; // Initialize to nullptr
    double m_currentOpacity = 1.0;
    double m_opacityStep = 0.05; // Adjust for fade speed (higher = faster)
    int m_targetPageIndex = -1;
    bool m_fadingIn = false;
    QPushButton* m_buttonToEnable = nullptr; // Track which button to re-enable
    void startFadeAnimation(int targetIndex, QPushButton* buttonToReEnable); // Helper function
};
#endif // CREDENTIALS_H
