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
#include <QtQuickWidgets/QQuickWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_3;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QCalendarWidget *calendarWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *TabEvent;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Search_Button;
    QComboBox *comboBox;
    QPushButton *pdf_Button;
    QPushButton *Suggestions_Button;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *tableWidget;
    QWidget *AddEvent;
    QGroupBox *groupBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_5;
    QLineEdit *AlineEdit;
    QLabel *label_7;
    QLineEdit *AlineEdit_2;
    QLabel *label_8;
    QLineEdit *AlineEdit_3;
    QLabel *label_9;
    QPlainTextEdit *AlineEdit_4;
    QLabel *label_10;
    QDateEdit *AlineEdit_5;
    QLabel *label_11;
    QComboBox *AlineEdit_6;
    QLineEdit *AlineEdit_7;
    QLabel *label_4;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *Add_Event;
    QPushButton *Cancel_Add;
    QPushButton *positionMapButton;
    QWidget *ModifyEvent;
    QGroupBox *groupBox_2;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *label_12;
    QLineEdit *MlineEdit_1;
    QLabel *label_13;
    QLineEdit *MlineEdit_2;
    QLabel *label_14;
    QLineEdit *MlineEdit_3;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QDateEdit *MlineEdit_5;
    QComboBox *MlineEdit_6;
    QPlainTextEdit *MlineEdit_4;
    QLineEdit *MlineEdit_7;
    QLabel *label_18;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *Modify_Event;
    QPushButton *Cancel_Modify;
    QPushButton *updatePositionMapButton;
    QWidget *DeleteTabWidget;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget;
    QFormLayout *formLayout_4;
    QLabel *label_2;
    QLineEdit *DlineEdit;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *Delete_Event;
    QPushButton *Cancel_Delete;
    QWidget *tab;
    QQuickWidget *quickWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_6;
    QPushButton *Button_Patient;
    QPushButton *Button_Vac;
    QPushButton *Button_Staff;
    QPushButton *Button_Events;
    QPushButton *Button_Inventory;
    QPushButton *Button_Appoitment;
    QPushButton *Button_Analytics;
    QPushButton *Button_help;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1280, 720);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 100, 158, 78));
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(30, 143, 83);"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(350, 0, 206, 101));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(204, 99));
        label->setStyleSheet(QString::fromUtf8("image: url(:/res/Logo.png);"));
        label->setScaledContents(true);

        horizontalLayout->addWidget(label);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(760, 120, 298, 197));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        calendarWidget = new QCalendarWidget(horizontalLayoutWidget_2);
        calendarWidget->setObjectName("calendarWidget");
        sizePolicy.setHeightForWidth(calendarWidget->sizePolicy().hasHeightForWidth());
        calendarWidget->setSizePolicy(sizePolicy);
        calendarWidget->setStyleSheet(QString::fromUtf8("color: rgb(30, 143, 83);"));

        horizontalLayout_2->addWidget(calendarWidget);

        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(40, 160, 693, 463));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(gridLayoutWidget);
        tabWidget->setObjectName("tabWidget");
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMinimumSize(QSize(691, 461));
        tabWidget->setMaximumSize(QSize(691, 461));
        TabEvent = new QWidget();
        TabEvent->setObjectName("TabEvent");
        layoutWidget1 = new QWidget(TabEvent);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(90, 40, 526, 31));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        Search_Button = new QPushButton(layoutWidget1);
        Search_Button->setObjectName("Search_Button");
        Search_Button->setStyleSheet(QString::fromUtf8("color: rgb(30, 143, 83);"));

        horizontalLayout_3->addWidget(Search_Button);

        comboBox = new QComboBox(layoutWidget1);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setStyleSheet(QString::fromUtf8("color: rgb(30, 143, 83);\n"
"background-color: rgb(28, 28, 28);"));

        horizontalLayout_3->addWidget(comboBox);

        pdf_Button = new QPushButton(layoutWidget1);
        pdf_Button->setObjectName("pdf_Button");
        pdf_Button->setStyleSheet(QString::fromUtf8("color: rgb(30, 143, 83);"));

        horizontalLayout_3->addWidget(pdf_Button);

        Suggestions_Button = new QPushButton(layoutWidget1);
        Suggestions_Button->setObjectName("Suggestions_Button");
        Suggestions_Button->setStyleSheet(QString::fromUtf8("color: rgb(30, 143, 83);"));

        horizontalLayout_3->addWidget(Suggestions_Button);

        horizontalLayoutWidget_3 = new QWidget(TabEvent);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(0, 90, 782, 302));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(horizontalLayoutWidget_3);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
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
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        if (tableWidget->rowCount() < 4)
            tableWidget->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem11);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setMinimumSize(QSize(691, 300));
        tableWidget->setMaximumSize(QSize(16777215, 300));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(false);
        tableWidget->setFont(font1);
        tableWidget->setStyleSheet(QString::fromUtf8("color: rgb(30, 143, 83);\n"
"background-color: rgb(255, 255, 255);\n"
"gridline-color: rgb(30, 143, 83);"));

        horizontalLayout_4->addWidget(tableWidget);

        tabWidget->addTab(TabEvent, QString());
        AddEvent = new QWidget();
        AddEvent->setObjectName("AddEvent");
        groupBox = new QGroupBox(AddEvent);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(40, 20, 601, 361));
        QFont font2;
        font2.setBold(true);
        groupBox->setFont(font2);
        groupBox->setStyleSheet(QString::fromUtf8("color: rgb(30, 143, 83);"));
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(20, 30, 541, 297));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName("label_5");
        QFont font3;
        font3.setPointSize(9);
        font3.setBold(true);
        label_5->setFont(font3);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(30, 143, 83);"));
        label_5->setScaledContents(true);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_5);

        AlineEdit = new QLineEdit(formLayoutWidget);
        AlineEdit->setObjectName("AlineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, AlineEdit);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName("label_7");
        label_7->setFont(font2);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb( 30, 143, 83);"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_7);

        AlineEdit_2 = new QLineEdit(formLayoutWidget);
        AlineEdit_2->setObjectName("AlineEdit_2");

        formLayout->setWidget(1, QFormLayout::FieldRole, AlineEdit_2);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName("label_8");
        label_8->setFont(font2);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb( 30, 143, 83);"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_8);

        AlineEdit_3 = new QLineEdit(formLayoutWidget);
        AlineEdit_3->setObjectName("AlineEdit_3");

        formLayout->setWidget(2, QFormLayout::FieldRole, AlineEdit_3);

        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName("label_9");
        label_9->setFont(font2);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(30, 143, 83\n"
");"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_9);

        AlineEdit_4 = new QPlainTextEdit(formLayoutWidget);
        AlineEdit_4->setObjectName("AlineEdit_4");

        formLayout->setWidget(3, QFormLayout::FieldRole, AlineEdit_4);

        label_10 = new QLabel(formLayoutWidget);
        label_10->setObjectName("label_10");
        label_10->setFont(font2);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(30, 143, 83);"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_10);

        AlineEdit_5 = new QDateEdit(formLayoutWidget);
        AlineEdit_5->setObjectName("AlineEdit_5");

        formLayout->setWidget(4, QFormLayout::FieldRole, AlineEdit_5);

        label_11 = new QLabel(formLayoutWidget);
        label_11->setObjectName("label_11");
        label_11->setFont(font2);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(30, 143, 83);\n"
""));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_11);

        AlineEdit_6 = new QComboBox(formLayoutWidget);
        AlineEdit_6->addItem(QString());
        AlineEdit_6->addItem(QString());
        AlineEdit_6->addItem(QString());
        AlineEdit_6->addItem(QString());
        AlineEdit_6->setObjectName("AlineEdit_6");

        formLayout->setWidget(5, QFormLayout::FieldRole, AlineEdit_6);

        AlineEdit_7 = new QLineEdit(formLayoutWidget);
        AlineEdit_7->setObjectName("AlineEdit_7");

        formLayout->setWidget(6, QFormLayout::FieldRole, AlineEdit_7);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName("label_4");
        label_4->setFont(font2);

        formLayout->setWidget(6, QFormLayout::LabelRole, label_4);

        horizontalLayoutWidget_4 = new QWidget(groupBox);
        horizontalLayoutWidget_4->setObjectName("horizontalLayoutWidget_4");
        horizontalLayoutWidget_4->setGeometry(QRect(60, 330, 452, 31));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        Add_Event = new QPushButton(horizontalLayoutWidget_4);
        Add_Event->setObjectName("Add_Event");
        Add_Event->setMaximumSize(QSize(150, 16777215));
        Add_Event->setFont(font2);
        Add_Event->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 143, 83);\n"
"color: rgb(255, 255, 255);\n"
""));

        horizontalLayout_5->addWidget(Add_Event);

        Cancel_Add = new QPushButton(horizontalLayoutWidget_4);
        Cancel_Add->setObjectName("Cancel_Add");
        Cancel_Add->setMaximumSize(QSize(150, 16777215));
        Cancel_Add->setFont(font2);
        Cancel_Add->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 143, 83);\n"
"color: rgb(255, 255, 255);\n"
""));

        horizontalLayout_5->addWidget(Cancel_Add);

        positionMapButton = new QPushButton(AddEvent);
        positionMapButton->setObjectName("positionMapButton");
        positionMapButton->setGeometry(QRect(530, 390, 130, 30));
        positionMapButton->setStyleSheet(QString::fromUtf8("\n"
"            QPushButton {\n"
"              background-color: #4CAF50;\n"
"              color: white;\n"
"              font-weight: bold;\n"
"              padding: 5px;\n"
"              border-radius: 4px;\n"
"            }\n"
"            QPushButton:hover {\n"
"              background-color: #45a049;\n"
"            }\n"
"           "));
        tabWidget->addTab(AddEvent, QString());
        ModifyEvent = new QWidget();
        ModifyEvent->setObjectName("ModifyEvent");
        groupBox_2 = new QGroupBox(ModifyEvent);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(20, 0, 631, 401));
        groupBox_2->setFont(font2);
        groupBox_2->setStyleSheet(QString::fromUtf8("color: rgb(30, 143, 83);"));
        formLayoutWidget_2 = new QWidget(groupBox_2);
        formLayoutWidget_2->setObjectName("formLayoutWidget_2");
        formLayoutWidget_2->setGeometry(QRect(20, 40, 541, 294));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(formLayoutWidget_2);
        label_12->setObjectName("label_12");
        label_12->setFont(font3);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(30, 143, 83);"));
        label_12->setScaledContents(true);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_12);

        MlineEdit_1 = new QLineEdit(formLayoutWidget_2);
        MlineEdit_1->setObjectName("MlineEdit_1");
        MlineEdit_1->setReadOnly(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, MlineEdit_1);

        label_13 = new QLabel(formLayoutWidget_2);
        label_13->setObjectName("label_13");
        label_13->setFont(font2);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb( 30, 143, 83);"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_13);

        MlineEdit_2 = new QLineEdit(formLayoutWidget_2);
        MlineEdit_2->setObjectName("MlineEdit_2");

        formLayout_2->setWidget(1, QFormLayout::FieldRole, MlineEdit_2);

        label_14 = new QLabel(formLayoutWidget_2);
        label_14->setObjectName("label_14");
        label_14->setFont(font2);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb( 30, 143, 83);"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_14);

        MlineEdit_3 = new QLineEdit(formLayoutWidget_2);
        MlineEdit_3->setObjectName("MlineEdit_3");

        formLayout_2->setWidget(2, QFormLayout::FieldRole, MlineEdit_3);

        label_15 = new QLabel(formLayoutWidget_2);
        label_15->setObjectName("label_15");
        label_15->setFont(font2);
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(30, 143, 83\n"
");"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_15);

        label_16 = new QLabel(formLayoutWidget_2);
        label_16->setObjectName("label_16");
        label_16->setFont(font2);
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(30, 143, 83);"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_16);

        label_17 = new QLabel(formLayoutWidget_2);
        label_17->setObjectName("label_17");
        label_17->setFont(font2);
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(30, 143, 83);\n"
""));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_17);

        MlineEdit_5 = new QDateEdit(formLayoutWidget_2);
        MlineEdit_5->setObjectName("MlineEdit_5");

        formLayout_2->setWidget(4, QFormLayout::FieldRole, MlineEdit_5);

        MlineEdit_6 = new QComboBox(formLayoutWidget_2);
        MlineEdit_6->addItem(QString());
        MlineEdit_6->addItem(QString());
        MlineEdit_6->addItem(QString());
        MlineEdit_6->addItem(QString());
        MlineEdit_6->setObjectName("MlineEdit_6");

        formLayout_2->setWidget(5, QFormLayout::FieldRole, MlineEdit_6);

        MlineEdit_4 = new QPlainTextEdit(formLayoutWidget_2);
        MlineEdit_4->setObjectName("MlineEdit_4");

        formLayout_2->setWidget(3, QFormLayout::FieldRole, MlineEdit_4);

        MlineEdit_7 = new QLineEdit(formLayoutWidget_2);
        MlineEdit_7->setObjectName("MlineEdit_7");

        formLayout_2->setWidget(6, QFormLayout::FieldRole, MlineEdit_7);

        label_18 = new QLabel(formLayoutWidget_2);
        label_18->setObjectName("label_18");
        label_18->setFont(font2);

        formLayout_2->setWidget(6, QFormLayout::LabelRole, label_18);

        horizontalLayoutWidget_5 = new QWidget(groupBox_2);
        horizontalLayoutWidget_5->setObjectName("horizontalLayoutWidget_5");
        horizontalLayoutWidget_5->setGeometry(QRect(70, 340, 491, 80));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        Modify_Event = new QPushButton(horizontalLayoutWidget_5);
        Modify_Event->setObjectName("Modify_Event");
        Modify_Event->setMaximumSize(QSize(150, 16777215));
        Modify_Event->setFont(font2);
        Modify_Event->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 143, 83);\n"
"color: rgb( 255, 255, 255)"));

        horizontalLayout_6->addWidget(Modify_Event);

        Cancel_Modify = new QPushButton(horizontalLayoutWidget_5);
        Cancel_Modify->setObjectName("Cancel_Modify");
        Cancel_Modify->setMaximumSize(QSize(150, 16777215));
        Cancel_Modify->setFont(font2);
        Cancel_Modify->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 143, 83);\n"
"color: rgb(255,255,255);"));

        horizontalLayout_6->addWidget(Cancel_Modify);

        updatePositionMapButton = new QPushButton(ModifyEvent);
        updatePositionMapButton->setObjectName("updatePositionMapButton");
        updatePositionMapButton->setGeometry(QRect(540, 390, 130, 30));
        updatePositionMapButton->setStyleSheet(QString::fromUtf8("\n"
"            QPushButton {\n"
"              background-color: #2196F3;\n"
"              color: white;\n"
"              font-weight: bold;\n"
"              padding: 5px;\n"
"              border-radius: 4px;\n"
"            }\n"
"            QPushButton:hover {\n"
"              background-color: #0b7dda;\n"
"            }\n"
"           "));
        tabWidget->addTab(ModifyEvent, QString());
        DeleteTabWidget = new QWidget();
        DeleteTabWidget->setObjectName("DeleteTabWidget");
        groupBox_3 = new QGroupBox(DeleteTabWidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(40, 20, 451, 321));
        groupBox_3->setFont(font2);
        groupBox_3->setStyleSheet(QString::fromUtf8("color: rgb(30, 143, 83);"));
        layoutWidget = new QWidget(groupBox_3);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(50, 100, 331, 104));
        formLayout_4 = new QFormLayout(layoutWidget);
        formLayout_4->setObjectName("formLayout_4");
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(30, 143, 83);"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_2);

        DlineEdit = new QLineEdit(layoutWidget);
        DlineEdit->setObjectName("DlineEdit");

        formLayout_4->setWidget(0, QFormLayout::FieldRole, DlineEdit);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        Delete_Event = new QPushButton(layoutWidget);
        Delete_Event->setObjectName("Delete_Event");
        Delete_Event->setMaximumSize(QSize(150, 16777215));
        Delete_Event->setFont(font2);
        Delete_Event->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 143, 83);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_7->addWidget(Delete_Event);

        Cancel_Delete = new QPushButton(layoutWidget);
        Cancel_Delete->setObjectName("Cancel_Delete");
        Cancel_Delete->setMaximumSize(QSize(150, 16777215));
        Cancel_Delete->setFont(font2);
        Cancel_Delete->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 143, 83);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_7->addWidget(Cancel_Delete);


        formLayout_4->setLayout(1, QFormLayout::FieldRole, horizontalLayout_7);

        tabWidget->addTab(DeleteTabWidget, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        tabWidget->addTab(tab, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        quickWidget = new QQuickWidget(centralwidget);
        quickWidget->setObjectName("quickWidget");
        quickWidget->setGeometry(QRect(761, 331, 300, 331));
        sizePolicy.setHeightForWidth(quickWidget->sizePolicy().hasHeightForWidth());
        quickWidget->setSizePolicy(sizePolicy);
        quickWidget->setMinimumSize(QSize(300, 331));
        quickWidget->setMaximumSize(QSize(300, 331));
        quickWidget->setResizeMode(QQuickWidget::ResizeMode::SizeViewToRootObject);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1280, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName("dockWidget");
        dockWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 143, 83\n"
");"));
        dockWidget->setFeatures(QDockWidget::DockWidgetFeature::NoDockWidgetFeatures);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName("dockWidgetContents");
        verticalLayout_3 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_6 = new QLabel(dockWidgetContents);
        label_6->setObjectName("label_6");
        label_6->setMinimumSize(QSize(161, 124));
        label_6->setMaximumSize(QSize(100, 100));
        label_6->setStyleSheet(QString::fromUtf8("image: url(:/res/Dashbord Management.png);"));

        verticalLayout_3->addWidget(label_6);

        Button_Patient = new QPushButton(dockWidgetContents);
        Button_Patient->setObjectName("Button_Patient");
        Button_Patient->setMinimumSize(QSize(169, 51));
        Button_Patient->setMaximumSize(QSize(150, 51));
        Button_Patient->setFont(font2);
        Button_Patient->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(30, 143, 83);"));

        verticalLayout_3->addWidget(Button_Patient);

        Button_Vac = new QPushButton(dockWidgetContents);
        Button_Vac->setObjectName("Button_Vac");
        Button_Vac->setMinimumSize(QSize(171, 24));
        Button_Vac->setMaximumSize(QSize(151, 51));
        Button_Vac->setFont(font2);
        Button_Vac->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(30, 143, 83);\n"
"alternate-background-color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(Button_Vac);

        Button_Staff = new QPushButton(dockWidgetContents);
        Button_Staff->setObjectName("Button_Staff");
        Button_Staff->setMinimumSize(QSize(171, 13));
        Button_Staff->setMaximumSize(QSize(150, 51));
        Button_Staff->setFont(font2);
        Button_Staff->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(30, 143, 83);\n"
"alternate-background-color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(Button_Staff);

        Button_Events = new QPushButton(dockWidgetContents);
        Button_Events->setObjectName("Button_Events");
        Button_Events->setMinimumSize(QSize(152, 23));
        Button_Events->setMaximumSize(QSize(171, 51));
        Button_Events->setFont(font2);
        Button_Events->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(30, 143, 83);\n"
""));

        verticalLayout_3->addWidget(Button_Events);

        Button_Inventory = new QPushButton(dockWidgetContents);
        Button_Inventory->setObjectName("Button_Inventory");
        Button_Inventory->setMinimumSize(QSize(171, 51));
        Button_Inventory->setMaximumSize(QSize(142, 51));
        Button_Inventory->setFont(font2);
        Button_Inventory->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 143, 83);\n"
"color: rgb(255, 255, 255);\n"
"alternate-background-color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(Button_Inventory);

        Button_Appoitment = new QPushButton(dockWidgetContents);
        Button_Appoitment->setObjectName("Button_Appoitment");
        Button_Appoitment->setMinimumSize(QSize(171, 12));
        Button_Appoitment->setMaximumSize(QSize(150, 51));
        Button_Appoitment->setFont(font2);
        Button_Appoitment->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 143, 83);\n"
"color: rgb(255, 255, 255);\n"
"alternate-background-color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(Button_Appoitment);

        Button_Analytics = new QPushButton(dockWidgetContents);
        Button_Analytics->setObjectName("Button_Analytics");
        Button_Analytics->setMinimumSize(QSize(171, 19));
        Button_Analytics->setMaximumSize(QSize(153, 51));
        Button_Analytics->setFont(font2);
        Button_Analytics->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 143, 83);\n"
"color: rgb(255, 255, 255);\n"
"alternate-background-color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(Button_Analytics);

        Button_help = new QPushButton(dockWidgetContents);
        Button_help->setObjectName("Button_help");
        Button_help->setMinimumSize(QSize(171, 4));
        Button_help->setMaximumSize(QSize(0, 31));
        Button_help->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(30, 143, 83);"));

        verticalLayout_3->addWidget(Button_help);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, dockWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Events", nullptr));
        label->setText(QString());
        Search_Button->setText(QCoreApplication::translate("MainWindow", "Find", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Sort:(None)", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Date_Asc", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Date_Desc", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Type_Asc", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Type_Desc", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Title_Asc", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "Title_Desc", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("MainWindow", "Sponsor_Asc", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("MainWindow", "Sponsor_Desc", nullptr));

        pdf_Button->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        Suggestions_Button->setText(QCoreApplication::translate("MainWindow", "Nearby Events", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Nouvelle colonne", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Nouvelle colonne", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Nouvelle colonne", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Nouvelle colonne", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Nouvelle colonne", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Nouvelle colonne", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Nouvelle colonne", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Nouvelle ligne", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Nouvelle ligne", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Nouvelle ligne", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Nouvelle ligne", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(TabEvent), QCoreApplication::translate("MainWindow", "Event List", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Add New Event", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Id", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Title", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Sponsor", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        AlineEdit_6->setItemText(0, QCoreApplication::translate("MainWindow", "Charity", nullptr));
        AlineEdit_6->setItemText(1, QCoreApplication::translate("MainWindow", "Summit", nullptr));
        AlineEdit_6->setItemText(2, QCoreApplication::translate("MainWindow", "Q&A", nullptr));
        AlineEdit_6->setItemText(3, QCoreApplication::translate("MainWindow", "Vaccination", nullptr));

        label_4->setText(QCoreApplication::translate("MainWindow", "Position", nullptr));
        Add_Event->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        Cancel_Add->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        positionMapButton->setText(QCoreApplication::translate("MainWindow", "\360\237\223\215 Select on Map", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(AddEvent), QCoreApplication::translate("MainWindow", "Add Event", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Modify Event", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Id", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Title", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Sponsor", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        MlineEdit_6->setItemText(0, QCoreApplication::translate("MainWindow", "Charity", nullptr));
        MlineEdit_6->setItemText(1, QCoreApplication::translate("MainWindow", "Vaccination", nullptr));
        MlineEdit_6->setItemText(2, QCoreApplication::translate("MainWindow", "Summit", nullptr));
        MlineEdit_6->setItemText(3, QCoreApplication::translate("MainWindow", "Q&A", nullptr));

        label_18->setText(QCoreApplication::translate("MainWindow", "Position", nullptr));
        Modify_Event->setText(QCoreApplication::translate("MainWindow", "Modify", nullptr));
        Cancel_Modify->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        updatePositionMapButton->setText(QCoreApplication::translate("MainWindow", "\360\237\223\215 Select on Map", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ModifyEvent), QCoreApplication::translate("MainWindow", "Update Event", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Delete Event", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Id", nullptr));
        Delete_Event->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        Cancel_Delete->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(DeleteTabWidget), QCoreApplication::translate("MainWindow", "DeleteEvent", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Stats", nullptr));
        label_6->setText(QString());
        Button_Patient->setText(QCoreApplication::translate("MainWindow", "PATIENT", nullptr));
        Button_Vac->setText(QCoreApplication::translate("MainWindow", "VAC", nullptr));
        Button_Staff->setText(QCoreApplication::translate("MainWindow", "STAFF", nullptr));
        Button_Events->setText(QCoreApplication::translate("MainWindow", "EVENTS", nullptr));
        Button_Inventory->setText(QCoreApplication::translate("MainWindow", "INVENTORY", nullptr));
        Button_Appoitment->setText(QCoreApplication::translate("MainWindow", "APPOINTMENT", nullptr));
        Button_Analytics->setText(QCoreApplication::translate("MainWindow", "ANALYTICS", nullptr));
        Button_help->setText(QCoreApplication::translate("MainWindow", "HELP AND SUPPORT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
