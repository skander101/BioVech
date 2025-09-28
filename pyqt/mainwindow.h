#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QProcess>
#include <QTemporaryFile>
#include <QDir>
#include <QDebug>
#include <QThread>
#include <QScrollBar>
#include <cmath>
#include <QString>
#include <QVBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_registerImageButton_clicked();
    void on_verifyImageButton_clicked();
    void on_registerButton_clicked();
    void on_actionExit_triggered();
    void on_actionAbout_triggered();

    void handleProcessStarted();
    void handleProcessOutput();
    void handleProcessError();
    void handleProcessFinished(int exitCode, QProcess::ExitStatus exitStatus);

private:
    Ui::MainWindow *ui;
    QString currentImagePath;
    QString currentEmbedding;
    QProcess *pythonProcess;
    QSqlDatabase db;
    bool isVerifyMode;

    void loadImage();
    void processImage(const QString &imagePath);
    double calculateSimilarity(const QString &embedding1, const QString &embedding2);
    void logMessage(const QString &message);
    void displayZoomableImage(QLabel *label, const QPixmap &pixmap);
    bool initializeDatabase();
    bool findMatchingPatient(const QString &faceCode, QString &matchedName);
    void clearCurrentData();
};

#endif // MAINWINDOW_H
