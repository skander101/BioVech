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
    void on_loadImage1Button_clicked();
    void on_loadImage2Button_clicked();
    void on_compareButton_clicked();
    void on_actionLoad_Image_1_triggered();
    void on_actionLoad_Image_2_triggered();
    void on_actionExit_triggered();
    void on_actionAbout_triggered();

    void handleProcessStarted();
    void handleProcessOutput();
    void handleProcessError();
    void handleProcessFinished(int exitCode, QProcess::ExitStatus exitStatus);

private:
    Ui::MainWindow *ui;

    QString image1Path;
    QString image2Path;
    QString embedding1;
    QString embedding2;
    QProcess *pythonProcess;

    void loadImage(int imageNum);
    void processImage(const QString &imagePath, int imageNum);
    double calculateSimilarity(const QString &embedding1, const QString &embedding2);
    void updateCompareButtonState();
    void logMessage(const QString &message);
    void displayZoomableImage(QLabel *label, const QPixmap &pixmap);
};

#endif // MAINWINDOW_H
