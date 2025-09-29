/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QGroupBox *groupBox;
    QTableWidget *tableWidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QLabel *label_10;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents_7;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1408, 692);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: white;\n"
""));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(340, 0, 381, 111));
        label->setStyleSheet(QString::fromUtf8("image: url(:/falla7/logo.png);"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(130, 200, 631, 361));
        tableWidget = new QTableWidget(groupBox);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 130, 611, 221));
        tableWidget->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 0);"));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(120, 40, 401, 31));
        pushButton_9 = new QPushButton(groupBox);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(150, 80, 83, 29));
        pushButton_10 = new QPushButton(groupBox);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(260, 80, 83, 29));
        pushButton_11 = new QPushButton(groupBox);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(360, 80, 83, 29));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(130, 140, 321, 51));
        QFont font;
        font.setPointSize(24);
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 0);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1408, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName("dockWidget");
        dockWidget->setAutoFillBackground(true);
        dockWidget->setStyleSheet(QString::fromUtf8(""));
        dockWidget->setFloating(true);
        dockWidget->setFeatures(QDockWidget::DockWidgetFeature::DockWidgetMovable);
        dockWidgetContents_7 = new QWidget();
        dockWidgetContents_7->setObjectName("dockWidgetContents_7");
        pushButton = new QPushButton(dockWidgetContents_7);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 110, 191, 41));
        QFont font1;
        font1.setBold(true);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(30, 143, 83);\n"
""));
        pushButton_2 = new QPushButton(dockWidgetContents_7);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(0, 160, 191, 41));
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(30, 143, 83);"));
        pushButton_3 = new QPushButton(dockWidgetContents_7);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(0, 210, 191, 41));
        pushButton_3->setFont(font1);
        pushButton_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(30, 143, 83);"));
        pushButton_4 = new QPushButton(dockWidgetContents_7);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(0, 260, 191, 41));
        pushButton_4->setFont(font1);
        pushButton_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(30, 143, 83);\n"
""));
        pushButton_5 = new QPushButton(dockWidgetContents_7);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(0, 310, 191, 41));
        pushButton_5->setFont(font1);
        pushButton_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(30, 143, 83);\n"
""));
        pushButton_6 = new QPushButton(dockWidgetContents_7);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(0, 360, 191, 41));
        pushButton_6->setFont(font1);
        pushButton_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(30, 143, 83);\n"
""));
        pushButton_7 = new QPushButton(dockWidgetContents_7);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(0, 410, 191, 41));
        pushButton_7->setFont(font1);
        pushButton_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(30, 143, 83);\n"
""));
        pushButton_8 = new QPushButton(dockWidgetContents_7);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(0, 490, 191, 41));
        pushButton_8->setFont(font1);
        pushButton_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(30, 143, 83);\n"
""));
        label_2 = new QLabel(dockWidgetContents_7);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(-30, 0, 251, 101));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/falla7/sidebarupfull.png);"));
        label_3 = new QLabel(dockWidgetContents_7);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 110, 41, 41));
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/falla7/1.png);"));
        label_4 = new QLabel(dockWidgetContents_7);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 160, 41, 41));
        label_4->setStyleSheet(QString::fromUtf8("image: url(:/falla7/2.png);"));
        label_5 = new QLabel(dockWidgetContents_7);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 210, 41, 41));
        label_5->setStyleSheet(QString::fromUtf8("image: url(:/falla7/3.png);"));
        label_6 = new QLabel(dockWidgetContents_7);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, 260, 41, 41));
        label_6->setStyleSheet(QString::fromUtf8("image: url(:/falla7/4.png);"));
        label_7 = new QLabel(dockWidgetContents_7);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(0, 310, 41, 41));
        label_7->setStyleSheet(QString::fromUtf8("image: url(:/falla7/7.png);"));
        label_8 = new QLabel(dockWidgetContents_7);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(0, 410, 41, 41));
        label_8->setStyleSheet(QString::fromUtf8("image: url(:/falla7/5.png);"));
        label_9 = new QLabel(dockWidgetContents_7);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(0, 490, 41, 41));
        label_9->setStyleSheet(QString::fromUtf8("image: url(:/falla7/6.png);"));
        dockWidget->setWidget(dockWidgetContents_7);
        MainWindow->addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, dockWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Discovery Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Caracteristics", nullptr));
        lineEdit->setText(QString());
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "STAT", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "FILTRE", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Appointment", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Patient", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "MicroVac", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Personnel", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Inventory", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Event", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Appointment", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Analytics", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Help n Support", nullptr));
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
        label_9->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
