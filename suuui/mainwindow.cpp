#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QPixmap>
#include <QMessageBox>
#include <QDebug>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Load the pre-trained face detection model
    QString protoPath = "C:/Users/Mega-Pc/3D Objects/OpenCV-Image-Tracking-on-Qt-master/models/deploy.prototxt";
    QString modelPath = "C:/Users/Mega-Pc/3D Objects/OpenCV-Image-Tracking-on-Qt-master/models/res10_300x300_ssd_iter_140000_fp16.caffemodel";

    if (!QFile::exists(protoPath)) {
        QMessageBox::critical(this, "Error", "Prototxt file not found: " + protoPath);
        return;
    }
    if (!QFile::exists(modelPath)) {
        QMessageBox::critical(this, "Error", "Model file not found: " + modelPath);
        return;
    }

    net = cv::dnn::readNetFromCaffe(protoPath.toStdString(), modelPath.toStdString());
    if (net.empty()) {
        QMessageBox::critical(this, "Error", "Could not load face detection model.");
        return;
    }

    // Initialize the camera
    capture.open(0); // Open the default camera (index 0)
    if (!capture.isOpened()) {
        QMessageBox::critical(this, "Error", "Could not open camera.");
        return;
    }

    // Set up a timer to update the frame
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateFrame);
    timer->start(30); // Update every 30ms (~33 FPS)
}

MainWindow::~MainWindow() {
    delete ui;
    capture.release(); // Release the camera
}

void MainWindow::updateFrame() {
    qDebug() << "Capturing frame...";
    cv::Mat frame;
    if (!capture.read(frame)) { // Capture a frame
        qDebug() << "Error: No frame captured.";
        statusBar()->showMessage("Error: No frame captured.");
        return;
    }

    if (frame.empty()) {
        qDebug() << "Error: Empty frame.";
        statusBar()->showMessage("Error: Empty frame.");
        return;
    }

    qDebug() << "Frame captured. Processing...";

    // Flip the frame horizontally (optional)
    cv::flip(frame, frame, 1);

    // Prepare the frame for face detection
    cv::Mat blob = cv::dnn::blobFromImage(frame, 1.0, cv::Size(300, 300), cv::Scalar(104, 117, 123), false, false);

    // Pass the blob through the network
    net.setInput(blob);
    cv::Mat detections = net.forward();

    // Process the detections
    cv::Mat detectionMat(detections.size[2], detections.size[3], CV_32F, detections.ptr<float>());

    for (int i = 0; i < detectionMat.rows; i++) {
        float confidence = detectionMat.at<float>(i, 2);

        // Filter out weak detections
        if (confidence > 0.7) {
            int x1 = static_cast<int>(detectionMat.at<float>(i, 3) * frame.cols);
            int y1 = static_cast<int>(detectionMat.at<float>(i, 4) * frame.rows);
            int x2 = static_cast<int>(detectionMat.at<float>(i, 5) * frame.cols);
            int y2 = static_cast<int>(detectionMat.at<float>(i, 6) * frame.rows);

            // Draw a rectangle around the detected face
            cv::rectangle(frame, cv::Point(x1, y1), cv::Point(x2, y2), cv::Scalar(0, 255, 0), 2);

            // Display confidence
            std::string label = "Confidence: " + std::to_string(confidence);
            cv::putText(frame, label, cv::Point(x1, y1 - 10), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 255, 0), 1);
        }
    }

    // Convert the frame to QImage
    QImage img(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_BGR888);

    // Display the frame in a QLabel
    ui->videoLabel->setPixmap(QPixmap::fromImage(img));
}
