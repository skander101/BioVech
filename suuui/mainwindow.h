#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateFrame(); // Slot to update the camera feed

private:
    Ui::MainWindow *ui;
    cv::VideoCapture capture; // OpenCV video capture object
    cv::dnn::Net net; // DNN model for face detection
    QTimer *timer; // Timer to update the frame
};

#endif // MAINWINDOW_H
