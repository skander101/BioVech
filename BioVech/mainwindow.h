#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    void populateTable(QTableWidget* tableWidget);
    void on_pushButton_11_clicked(); // Trier
    void trierMicroorganismes();
    void afficherStatistiques();
    void on_pushButton_10_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_18_clicked();

private:
    Ui::MainWindow *ui;
    QComboBox *typeComboBox;
};

#endif
