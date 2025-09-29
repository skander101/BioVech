#ifndef MICRO_LAYOUT_H
#define MICRO_LAYOUT_H

//#include <poppler-qt6.h>  // ou qt5 selon ta version
#include <QMainWindow>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QTableWidget>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QComboBox>
#include "Microorganisme.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_12_clicked(); // Ajouter
    void on_pushButton_13_clicked(); // Supprimer
    void on_pushButton_14_clicked(); // Modifier
    void on_tableWidget_itemSelectionChanged();
    void on_searchButtonClicked(); // Recherche
    void on_pushButton_9_clicked(); // Exporter en PDF
    int drawPieChart(QPainter &painter, int x, int y, int width,
                     const QVector<QPair<QString, int>> &data,
                     const QVector<QColor> &colors,
                     const QString &title);
    void populateTable(QTableWidget* tableWidget);
    void on_pushButton_11_clicked(); // Trier
    void trierMicroorganismes();
    void afficherStatistiques();
    void on_pushButton_10_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_18_clicked();

    void readSerialData();
    /*void on_pushButton_19_clicked();
    void on_pushButton_20_clicked();
    void on_pushButton_21_clicked();
    void on_pushButton_22_clicked();
    void on_lineEdit_5_returnPressed();*/
    void sendZ();
    void sendC();
    void sendA();
    void sendE();
    void sendNumberInput();
    void sendG();
    void sendH();
    void on_lineEdit_8_returnPressed();
    void envoyerTypeVersArduino();

private:
    Ui::MainWindow *ui;
    QComboBox *typeComboBox;
    QSerialPort *serial;
    // In MainWindow.h, inside private:
    QTimer *timer_Z;
    QTimer *timer_C;
    QTimer *timer_A;
    QTimer *timer_E;
    QTimer *timer_G;
    QTimer *timer_H;


};

#endif
