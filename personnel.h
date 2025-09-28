#ifndef PERSONNEL_H
#define PERSONNEL_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDate>
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
#include "employe.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class personnel;
}
QT_END_NAMESPACE

class personnel : public QMainWindow
{
    Q_OBJECT

public:
    explicit personnel(QWidget *parent = nullptr);
    ~personnel();

private slots:
    // CRUD operation slots
    void on_pushButton_add_clicked();
    void on_pushButton_update_clicked();
    void on_pushButton_delete_clicked();
    //void on_tableWidget_2_cellClicked(int row, int column);
    void on_pushButton_clear_clicked();
    void testDatabaseConnection(); // Test database connection
    void on_tab_Personnel_cellClicked(int row, int column);
    void on_filterButton_clicked();
    void on_exportPdfButton_clicked();
    void on_searchPersonnel_returnPressed();
    void on_statisticsButton_clicked();
    void on_cameraButton_clicked();
    int drawPieChart(QPainter &painter, int x, int y, int width,
                     const QVector<QPair<QString, int>> &data,
                     const QVector<QColor> &colors,
                     const QString &title);
    void drawPieChartWidget(QPainter &painter, const QRect &rect,
                            const QVector<QPair<QString, int>> &data,
                            const QVector<QColor> &colors);

    // Camera handlers
    void startCamera(const QByteArray &cameraId = QByteArray());
    void stopCamera();
    void captureImage();
    void handleCameraError(QCamera::Error error, const QString &errorString);

    // Face detection in viewfinder
    void detectFaceInViewfinder();

private:
    Ui::personnel *ui;
    void loadpersonnels(); // Load all appointments into the table
    void clearInputFields(); // Clear input fields
    void setupUI(); // Setup additional UI elements

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

    void setupCameraDialog();
    void processCapturedImage(const QString &filePath, QLabel *processingLabel, QLabel *statusLabel, QProgressDialog *progressDialog);
    void processLoginFace(const QString &filePath, QDialog *loginDialog, QLabel *statusLabel, QLabel *processingLabel, QProgressDialog *progressDialog);

};

#endif // PERSONNEL_H
