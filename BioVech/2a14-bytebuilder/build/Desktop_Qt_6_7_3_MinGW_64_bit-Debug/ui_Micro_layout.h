/********************************************************************************
** Form generated from reading UI file 'Micro_layout.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MICRO_LAYOUT_H
#define UI_MICRO_LAYOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_CentralWidget;
    QSpacerItem *horizontalSpacer_LeftOfTabs;
    QLabel *biovec_logo;
    QTabWidget *mainContentTabWidget;
    QWidget *tab_MicroDetails;
    QVBoxLayout *verticalLayout_Tab1;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_10;
    QLineEdit *lineEdit_3;
    QVBoxLayout *vLayout_Calendar;
    QLabel *label_12;
    QCalendarWidget *calendarWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_11;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *vLayout_Characteristics;
    QPushButton *pushButton_14;
    QPushButton *pushButton_13;
    QPushButton *pushButton_12;
    QHBoxLayout *hLayout_ID;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_13;
    QTextEdit *lineEdit_6;
    QPushButton *pushButton_16;
    QWidget *tab_DataPrep;
    QVBoxLayout *verticalLayout_Tab2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_GB1;
    QLineEdit *lineEdit;
    QPushButton *pushButton_15;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QPushButton *pushButton_11;
    QTableWidget *tableWidget;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_GB3;
    QHBoxLayout *hLayout_PrepPredButtons;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QSpacerItem *hSpacer_PrepPred;
    QTextEdit *lineEdit_4;
    QWidget *tab;
    QPushButton *pushButton_19;
    QPushButton *pushButton_20;
    QPushButton *pushButton_21;
    QPushButton *pushButton_22;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_23;
    QPushButton *pushButton_24;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents_7;
    QVBoxLayout *verticalLayout_SidebarContainer;
    QLabel *sidebar_top_logo;
    QVBoxLayout *verticalLayout_SidebarButtons;
    QHBoxLayout *hLayout_PatientBtn;
    QLabel *label_3;
    QPushButton *pushButton;
    QHBoxLayout *hLayout_MicroVacBtn;
    QLabel *label_4;
    QPushButton *pushButton_2;
    QHBoxLayout *hLayout_PersonnelBtn;
    QLabel *label_5;
    QPushButton *pushButton_3;
    QHBoxLayout *hLayout_InventoryBtn;
    QLabel *label_6;
    QPushButton *pushButton_4;
    QHBoxLayout *hLayout_AppointmentBtn;
    QLabel *label_8;
    QPushButton *pushButton_6;
    QHBoxLayout *hLayout_EventBtn;
    QLabel *label_7;
    QPushButton *pushButton_5;
    QHBoxLayout *hLayout_AnalyticsBtn;
    QLabel *label_AnalyticsIcon;
    QPushButton *pushButton_7;
    QHBoxLayout *hLayout_HelpBtn;
    QLabel *label_9;
    QPushButton *pushButton_8;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1450, 874);
        MainWindow->setStyleSheet(QString::fromUtf8("/* Global Window Style */\n"
"QMainWindow {\n"
" border-image: url(\":/Static/Static/white_bg.jpg\");\n"
" background-size: contain;\n"
"}\n"
"\n"
"/* Header Logo */\n"
"QLabel#biovec_logo {\n"
"    margin-left: 25px;\n"
"    min-width: 50px;\n"
"    max-width: 250px;\n"
"    min-height: 80px;\n"
"    max-height: 80px;\n"
"    qproperty-alignment: AlignCenter;\n"
"    background-color: transparent;\n"
"    image: url(:/Static/Static/logo.png);\n"
"}\n"
"\n"
"/* Sidebar Dock Widget */\n"
"QDockWidget {\n"
"    border: none;\n"
"    background-color: #ffffff;\n"
"}\n"
"\n"
"QDockWidget::title {\n"
"    background-color: #208c54;\n"
"    color: white;\n"
"    padding: 10px;\n"
"    font-weight: bold;\n"
"    border-radius: 5px;\n"
"    text-align: left;\n"
"}\n"
"\n"
"/* Sidebar Header Logo */\n"
"QLabel#sidebar_top_logo {\n"
"    min-width: 50px;\n"
"    max-width: 250px;\n"
"    min-height:100px;\n"
"    max-height: 150px;\n"
"    qproperty-alignment: 'AlignCenter';\n"
"    image: url(:/Static/Static/dashboard."
                        "png);\n"
"}\n"
"\n"
"/* Sidebar Button Styles - TEXT MADE LARGER */\n"
"QDockWidget QPushButton {\n"
"    background-color: #208c54;\n"
"    color: #f6f8fa;\n"
"    padding: 18px 32px 18px 25px;\n"
"    text-align: left;\n"
"    border: none;\n"
"    border-radius: 0;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QDockWidget QPushButton:hover {\n"
"    background-color: #27ae77;\n"
"}\n"
"\n"
"QDockWidget QPushButton:pressed {\n"
"    background-color: #27ae80;\n"
"}\n"
"\n"
"/* Sidebar Icon Styles - ICONS MADE LARGER */\n"
"QDockWidget QLabel {\n"
"    min-width: 60px;\n"
"    min-height:60px;\n"
"    max-width: 60px;\n"
"    max-height: 60px;\n"
"    qproperty-alignment: 'AlignCenter';\n"
"    margin-left: 4px;\n"
"}\n"
"\n"
"/* GroupBox Styles - PADDING/MARGIN REDUCED */\n"
"QGroupBox {\n"
"    border: 1px solid #2ecc71;\n"
"    border-radius: 8px;\n"
"    margin-top: 12px;\n"
"    font-weight: bold;\n"
"    background-color: #ffffff;\n"
"    padding: 4px;\n"
"}\n"
"\n"
"QGroupBox QPush"
                        "Button {\n"
"    border-radius: 20px;\n"
"    font-weight: bold;\n"
"    padding: 10px 20px;\n"
"    min-height: 35px;\n"
"}\n"
"\n"
"QGroupBox QLineEdit {\n"
"    border-radius: 20px;\n"
"    padding: 8px 12px;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    left: 10px;\n"
"    padding: 0 5px 0 5px;\n"
"    color: #27ae60;\n"
"    background-color: #ffffff;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"/* Table Widget Styles */\n"
"QTableWidget {\n"
"    border: 1px solid #2ecc71;\n"
"    border-radius: 8px;\n"
"    alternate-background-color: #f9f9f9;\n"
"    background-color: #ffffff;\n"
"    font-size: 15px;\n"
"    selection-behavior: SelectRows;\n"
"    selection-background-color: #AFE1AF;\n"
"    selection-color: #000000;\n"
"    gridline-color: #e0e0e0;\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #27ae60;\n"
"    color: white;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #27ae60;\n"
"    color: white;\n"
"    padding: 10px;\n"
"   "
                        " border: none;\n"
"    border-bottom: 1px solid #208c54;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* General Button Styles */\n"
"QPushButton {\n"
"    background-color: #2ecc71;\n"
"    color: white;\n"
"    border-radius: 18px;\n"
"    padding: 10px 20px;\n"
"    font-weight: bold;\n"
"    font-size: 15px;\n"
"    min-height: 35px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #27ae60;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1e8449;\n"
"}\n"
"\n"
"/* Specific Button Styles */\n"
"QPushButton#pushButton_13 {\n"
"    background-color: #d8666c;\n"
"}\n"
"\n"
"QPushButton#pushButton_13:hover {\n"
"    background-color: #d85057;\n"
"}\n"
"\n"
"QPushButton#pushButton_13:pressed {\n"
"    background-color: #c04349;\n"
"}\n"
"\n"
"QPushButton#pushButton_16 {\n"
"    background-color: #66ffa4;\n"
"    color: #126032;\n"
"    max-width: 40px;\n"
"    min-width: 30px;\n"
"    padding: 5px;\n"
"    font-size: 12px;\n"
"    font-weight: bold;\n"
"    min-he"
                        "ight: 28px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton#pushButton_16:hover {\n"
"    background-color: #57dd8d;\n"
"}\n"
"\n"
"/* Input Field Styles */\n"
"QLineEdit, QDateEdit, QComboBox, QDateTimeEdit {\n"
"    border: 1px solid #2ecc71;\n"
"    border-radius: 18px;\n"
"    padding: 8px 12px;\n"
"    background-color: #ffffff;\n"
"    font-size: 15px;\n"
"    min-height: 35px;\n"
"}\n"
"\n"
"QTextEdit#lineEdit_6,\n"
"QTextEdit#lineEdit_4 {\n"
"    min-height: 100px;\n"
"    border-radius: 8px;\n"
"    qproperty-alignment: 'AlignLeft | AlignTop';\n"
"}\n"
"\n"
"QTextEdit#lineEdit_4 {\n"
"    background-color: #f8f9fa;\n"
"}\n"
"\n"
"/* Label Styles */\n"
"QLabel {\n"
"    color: #2c3e50;\n"
"    font-size: 15px;\n"
"    background-color: transparent;\n"
"    padding: 2px;\n"
"}\n"
"\n"
"/* Main Tab Widget */\n"
"QTabWidget::pane {\n"
"    border:1px solid #2ecc71;\n"
"    border-radius: 20px 20px 20px;\n"
"    border-top: none;\n"
"    background: white;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"QTabB"
                        "ar::tab {\n"
"    background: #208c54;\n"
"    color: white;\n"
"    border: 0px solid #208c54;\n"
"    border-bottom: none;\n"
"    border-radius: 23px 23px 0 0;\n"
"    padding: 10px 20px;\n"
"    margin-right: 4px;\n"
"    font: bold 14pt \"Segoe UI\";\n"
"    min-width: 10px;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background: #ffffff;\n"
"    color: #208c54;\n"
"    border-color: #2ecc71;\n"
"}\n"
"\n"
"QTabBar::tab:!selected:hover {\n"
"    background: #1E8F53;\n"
"    color: white;\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"    alignment: left;\n"
"    left: 5px;\n"
"}\n"
"\n"
"QCalendarWidget {\n"
"    background-color: #29aa63;\n"
"    color: #ffffff;\n"
"    font-family: \"Segoe UI\", \"Arial\", sans-serif;\n"
"    font-size: 16px;\n"
"    border: none;\n"
"    border-radius: 15px;\n"
"}\n"
"\n"
"QCalendarWidget QWidget#qt_calendar_navigationbar {\n"
"    background-color: #29aa63;\n"
"    border: none;\n"
"    border-top-left-radius: 15px;\n"
"    border-top-right-radius: 15px;\n"
"}\n"
"\n"
"Q"
                        "CalendarWidget QToolButton {\n"
"    color: #ffffff;\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    padding: 8px 12px;\n"
"    border-radius: 8px;\n"
"    font-size: 18px;\n"
"}\n"
"\n"
"QCalendarWidget QToolButton:hover {\n"
"    background-color:#36d67e;\n"
"}\n"
"\n"
"QCalendarWidget QLabel {\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"}\n"
"\n"
"QCalendarWidget QTableView {\n"
"    background-color: #1e8c54;\n"
"    border: none;\n"
"    border-radius: 0px;\n"
"    selection-background-color: rgba(255, 255, 255, 0.3);\n"
"    selection-color: #2c3e50;\n"
"    gridStyle: none;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QCalendarWidget QTableView::item {\n"
"    border: none;\n"
"    color: white;\n"
"    border-radius: 18px;\n"
"    padding: 5px;\n"
"    qproperty-alignment: AlignCenter;\n"
"}\n"
"\n"
"QCalendarWidget QTableView::item:selected {\n"
"    background-color: #81C784;\n"
"    color: white;\n"
"    border-radius: 18px;"
                        "\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QCalendarWidget QTableView QHeaderView::section {\n"
"    background-color: transparent;\n"
"    color: #B2DFDB;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    border: none;\n"
"    padding: 5px;\n"
"    qproperty-alignment: AlignCenter;\n"
"}\n"
"\n"
"QCalendarWidget QTableView::item[dayOfWeek=\"6\"],\n"
"QCalendarWidget QTableView::item[dayOfWeek=\"7\"] {\n"
"    color: #000000;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QCalendarWidget QTableView::disabled {\n"
"    color: #66BB6A;\n"
"    font-weight: normal;\n"
"}\n"
"\n"
"QCalendarWidget QAbstractItemView:focus {\n"
"    outline: none;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_CentralWidget = new QGridLayout(centralwidget);
        gridLayout_CentralWidget->setObjectName("gridLayout_CentralWidget");
        gridLayout_CentralWidget->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_LeftOfTabs = new QSpacerItem(0, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_CentralWidget->addItem(horizontalSpacer_LeftOfTabs, 1, 0, 1, 1);

        biovec_logo = new QLabel(centralwidget);
        biovec_logo->setObjectName("biovec_logo");
        biovec_logo->setMinimumSize(QSize(79, 84));
        biovec_logo->setMaximumSize(QSize(279, 84));
        biovec_logo->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_CentralWidget->addWidget(biovec_logo, 0, 1, 1, 1);

        mainContentTabWidget = new QTabWidget(centralwidget);
        mainContentTabWidget->setObjectName("mainContentTabWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainContentTabWidget->sizePolicy().hasHeightForWidth());
        mainContentTabWidget->setSizePolicy(sizePolicy);
        tab_MicroDetails = new QWidget();
        tab_MicroDetails->setObjectName("tab_MicroDetails");
        verticalLayout_Tab1 = new QVBoxLayout(tab_MicroDetails);
        verticalLayout_Tab1->setObjectName("verticalLayout_Tab1");
        groupBox_2 = new QGroupBox(tab_MicroDetails);
        groupBox_2->setObjectName("groupBox_2");
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName("label_10");

        horizontalLayout->addWidget(label_10);

        lineEdit_3 = new QLineEdit(groupBox_2);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setClearButtonEnabled(true);

        horizontalLayout->addWidget(lineEdit_3);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        vLayout_Calendar = new QVBoxLayout();
        vLayout_Calendar->setObjectName("vLayout_Calendar");
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName("label_12");
        label_12->setAlignment(Qt::AlignmentFlag::AlignCenter);

        vLayout_Calendar->addWidget(label_12);

        calendarWidget = new QCalendarWidget(groupBox_2);
        calendarWidget->setObjectName("calendarWidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(calendarWidget->sizePolicy().hasHeightForWidth());
        calendarWidget->setSizePolicy(sizePolicy1);

        vLayout_Calendar->addWidget(calendarWidget);


        gridLayout->addLayout(vLayout_Calendar, 0, 2, 6, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName("label_11");

        horizontalLayout_2->addWidget(label_11);

        comboBox = new QComboBox(groupBox_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        horizontalLayout_2->addWidget(comboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        vLayout_Characteristics = new QVBoxLayout();
        vLayout_Characteristics->setObjectName("vLayout_Characteristics");
        pushButton_14 = new QPushButton(groupBox_2);
        pushButton_14->setObjectName("pushButton_14");

        vLayout_Characteristics->addWidget(pushButton_14);

        pushButton_13 = new QPushButton(groupBox_2);
        pushButton_13->setObjectName("pushButton_13");

        vLayout_Characteristics->addWidget(pushButton_13);

        pushButton_12 = new QPushButton(groupBox_2);
        pushButton_12->setObjectName("pushButton_12");

        vLayout_Characteristics->addWidget(pushButton_12);


        gridLayout->addLayout(vLayout_Characteristics, 5, 0, 1, 1);

        hLayout_ID = new QHBoxLayout();
        hLayout_ID->setObjectName("hLayout_ID");
        label = new QLabel(groupBox_2);
        label->setObjectName("label");

        hLayout_ID->addWidget(label);

        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setClearButtonEnabled(true);

        hLayout_ID->addWidget(lineEdit_2);


        gridLayout->addLayout(hLayout_ID, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName("label_13");

        horizontalLayout_3->addWidget(label_13);

        lineEdit_6 = new QTextEdit(groupBox_2);
        lineEdit_6->setObjectName("lineEdit_6");

        horizontalLayout_3->addWidget(lineEdit_6);


        gridLayout->addLayout(horizontalLayout_3, 4, 0, 1, 1);

        pushButton_16 = new QPushButton(groupBox_2);
        pushButton_16->setObjectName("pushButton_16");

        gridLayout->addWidget(pushButton_16, 4, 1, 1, 1);


        verticalLayout_Tab1->addWidget(groupBox_2);

        mainContentTabWidget->addTab(tab_MicroDetails, QString());
        tab_DataPrep = new QWidget();
        tab_DataPrep->setObjectName("tab_DataPrep");
        verticalLayout_Tab2 = new QVBoxLayout(tab_DataPrep);
        verticalLayout_Tab2->setObjectName("verticalLayout_Tab2");
        groupBox = new QGroupBox(tab_DataPrep);
        groupBox->setObjectName("groupBox");
        gridLayout_GB1 = new QGridLayout(groupBox);
        gridLayout_GB1->setObjectName("gridLayout_GB1");
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setClearButtonEnabled(true);

        gridLayout_GB1->addWidget(lineEdit, 0, 0, 1, 4);

        pushButton_15 = new QPushButton(groupBox);
        pushButton_15->setObjectName("pushButton_15");

        gridLayout_GB1->addWidget(pushButton_15, 0, 4, 1, 1);

        pushButton_9 = new QPushButton(groupBox);
        pushButton_9->setObjectName("pushButton_9");

        gridLayout_GB1->addWidget(pushButton_9, 1, 0, 1, 1);

        pushButton_10 = new QPushButton(groupBox);
        pushButton_10->setObjectName("pushButton_10");

        gridLayout_GB1->addWidget(pushButton_10, 1, 1, 1, 1);

        comboBox_2 = new QComboBox(groupBox);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");

        gridLayout_GB1->addWidget(comboBox_2, 1, 2, 1, 1);

        comboBox_3 = new QComboBox(groupBox);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");

        gridLayout_GB1->addWidget(comboBox_3, 1, 3, 1, 1);

        pushButton_11 = new QPushButton(groupBox);
        pushButton_11->setObjectName("pushButton_11");

        gridLayout_GB1->addWidget(pushButton_11, 1, 4, 1, 1);

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
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy2);
        tableWidget->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);

        gridLayout_GB1->addWidget(tableWidget, 2, 0, 1, 5);


        verticalLayout_Tab2->addWidget(groupBox);

        groupBox_3 = new QGroupBox(tab_DataPrep);
        groupBox_3->setObjectName("groupBox_3");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy3);
        verticalLayout_GB3 = new QVBoxLayout(groupBox_3);
        verticalLayout_GB3->setObjectName("verticalLayout_GB3");
        hLayout_PrepPredButtons = new QHBoxLayout();
        hLayout_PrepPredButtons->setObjectName("hLayout_PrepPredButtons");
        pushButton_17 = new QPushButton(groupBox_3);
        pushButton_17->setObjectName("pushButton_17");

        hLayout_PrepPredButtons->addWidget(pushButton_17);

        pushButton_18 = new QPushButton(groupBox_3);
        pushButton_18->setObjectName("pushButton_18");

        hLayout_PrepPredButtons->addWidget(pushButton_18);

        hSpacer_PrepPred = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hLayout_PrepPredButtons->addItem(hSpacer_PrepPred);


        verticalLayout_GB3->addLayout(hLayout_PrepPredButtons);

        lineEdit_4 = new QTextEdit(groupBox_3);
        lineEdit_4->setObjectName("lineEdit_4");

        verticalLayout_GB3->addWidget(lineEdit_4);


        verticalLayout_Tab2->addWidget(groupBox_3);

        mainContentTabWidget->addTab(tab_DataPrep, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        pushButton_19 = new QPushButton(tab);
        pushButton_19->setObjectName("pushButton_19");
        pushButton_19->setGeometry(QRect(310, 110, 151, 55));
        pushButton_20 = new QPushButton(tab);
        pushButton_20->setObjectName("pushButton_20");
        pushButton_20->setGeometry(QRect(310, 230, 151, 55));
        pushButton_21 = new QPushButton(tab);
        pushButton_21->setObjectName("pushButton_21");
        pushButton_21->setGeometry(QRect(460, 170, 151, 55));
        pushButton_22 = new QPushButton(tab);
        pushButton_22->setObjectName("pushButton_22");
        pushButton_22->setGeometry(QRect(150, 170, 151, 55));
        lineEdit_5 = new QLineEdit(tab);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(260, 30, 251, 53));
        pushButton_23 = new QPushButton(tab);
        pushButton_23->setObjectName("pushButton_23");
        pushButton_23->setGeometry(QRect(190, 310, 151, 55));
        pushButton_24 = new QPushButton(tab);
        pushButton_24->setObjectName("pushButton_24");
        pushButton_24->setGeometry(QRect(430, 310, 151, 55));
        lineEdit_7 = new QLineEdit(tab);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(260, 370, 181, 53));
        lineEdit_8 = new QLineEdit(tab);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(20, 370, 181, 53));
        mainContentTabWidget->addTab(tab, QString());

        gridLayout_CentralWidget->addWidget(mainContentTabWidget, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1450, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName("dockWidget");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(dockWidget->sizePolicy().hasHeightForWidth());
        dockWidget->setSizePolicy(sizePolicy4);
        dockWidget->setMinimumSize(QSize(264, 795));
        dockWidget->setFeatures(QDockWidget::DockWidgetFeature::NoDockWidgetFeatures);
        dockWidget->setAllowedAreas(Qt::DockWidgetArea::LeftDockWidgetArea);
        dockWidgetContents_7 = new QWidget();
        dockWidgetContents_7->setObjectName("dockWidgetContents_7");
        verticalLayout_SidebarContainer = new QVBoxLayout(dockWidgetContents_7);
        verticalLayout_SidebarContainer->setSpacing(10);
        verticalLayout_SidebarContainer->setObjectName("verticalLayout_SidebarContainer");
        verticalLayout_SidebarContainer->setContentsMargins(0, 10, 0, 10);
        sidebar_top_logo = new QLabel(dockWidgetContents_7);
        sidebar_top_logo->setObjectName("sidebar_top_logo");
        sidebar_top_logo->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/dashboard.png);"));

        verticalLayout_SidebarContainer->addWidget(sidebar_top_logo);

        verticalLayout_SidebarButtons = new QVBoxLayout();
        verticalLayout_SidebarButtons->setSpacing(5);
        verticalLayout_SidebarButtons->setObjectName("verticalLayout_SidebarButtons");
        hLayout_PatientBtn = new QHBoxLayout();
        hLayout_PatientBtn->setSpacing(0);
        hLayout_PatientBtn->setObjectName("hLayout_PatientBtn");
        label_3 = new QLabel(dockWidgetContents_7);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/1.png);"));

        hLayout_PatientBtn->addWidget(label_3);

        pushButton = new QPushButton(dockWidgetContents_7);
        pushButton->setObjectName("pushButton");

        hLayout_PatientBtn->addWidget(pushButton);


        verticalLayout_SidebarButtons->addLayout(hLayout_PatientBtn);

        hLayout_MicroVacBtn = new QHBoxLayout();
        hLayout_MicroVacBtn->setSpacing(0);
        hLayout_MicroVacBtn->setObjectName("hLayout_MicroVacBtn");
        label_4 = new QLabel(dockWidgetContents_7);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/2.png);"));

        hLayout_MicroVacBtn->addWidget(label_4);

        pushButton_2 = new QPushButton(dockWidgetContents_7);
        pushButton_2->setObjectName("pushButton_2");

        hLayout_MicroVacBtn->addWidget(pushButton_2);


        verticalLayout_SidebarButtons->addLayout(hLayout_MicroVacBtn);

        hLayout_PersonnelBtn = new QHBoxLayout();
        hLayout_PersonnelBtn->setSpacing(0);
        hLayout_PersonnelBtn->setObjectName("hLayout_PersonnelBtn");
        label_5 = new QLabel(dockWidgetContents_7);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/3.png);"));

        hLayout_PersonnelBtn->addWidget(label_5);

        pushButton_3 = new QPushButton(dockWidgetContents_7);
        pushButton_3->setObjectName("pushButton_3");

        hLayout_PersonnelBtn->addWidget(pushButton_3);


        verticalLayout_SidebarButtons->addLayout(hLayout_PersonnelBtn);

        hLayout_InventoryBtn = new QHBoxLayout();
        hLayout_InventoryBtn->setSpacing(0);
        hLayout_InventoryBtn->setObjectName("hLayout_InventoryBtn");
        label_6 = new QLabel(dockWidgetContents_7);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/4.png);"));

        hLayout_InventoryBtn->addWidget(label_6);

        pushButton_4 = new QPushButton(dockWidgetContents_7);
        pushButton_4->setObjectName("pushButton_4");

        hLayout_InventoryBtn->addWidget(pushButton_4);


        verticalLayout_SidebarButtons->addLayout(hLayout_InventoryBtn);

        hLayout_AppointmentBtn = new QHBoxLayout();
        hLayout_AppointmentBtn->setSpacing(0);
        hLayout_AppointmentBtn->setObjectName("hLayout_AppointmentBtn");
        label_8 = new QLabel(dockWidgetContents_7);
        label_8->setObjectName("label_8");
        label_8->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/5.png);"));

        hLayout_AppointmentBtn->addWidget(label_8);

        pushButton_6 = new QPushButton(dockWidgetContents_7);
        pushButton_6->setObjectName("pushButton_6");

        hLayout_AppointmentBtn->addWidget(pushButton_6);


        verticalLayout_SidebarButtons->addLayout(hLayout_AppointmentBtn);

        hLayout_EventBtn = new QHBoxLayout();
        hLayout_EventBtn->setSpacing(0);
        hLayout_EventBtn->setObjectName("hLayout_EventBtn");
        label_7 = new QLabel(dockWidgetContents_7);
        label_7->setObjectName("label_7");
        label_7->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/6.png);"));

        hLayout_EventBtn->addWidget(label_7);

        pushButton_5 = new QPushButton(dockWidgetContents_7);
        pushButton_5->setObjectName("pushButton_5");

        hLayout_EventBtn->addWidget(pushButton_5);


        verticalLayout_SidebarButtons->addLayout(hLayout_EventBtn);

        hLayout_AnalyticsBtn = new QHBoxLayout();
        hLayout_AnalyticsBtn->setSpacing(0);
        hLayout_AnalyticsBtn->setObjectName("hLayout_AnalyticsBtn");
        label_AnalyticsIcon = new QLabel(dockWidgetContents_7);
        label_AnalyticsIcon->setObjectName("label_AnalyticsIcon");
        label_AnalyticsIcon->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/7.png);"));

        hLayout_AnalyticsBtn->addWidget(label_AnalyticsIcon);

        pushButton_7 = new QPushButton(dockWidgetContents_7);
        pushButton_7->setObjectName("pushButton_7");

        hLayout_AnalyticsBtn->addWidget(pushButton_7);


        verticalLayout_SidebarButtons->addLayout(hLayout_AnalyticsBtn);

        hLayout_HelpBtn = new QHBoxLayout();
        hLayout_HelpBtn->setSpacing(0);
        hLayout_HelpBtn->setObjectName("hLayout_HelpBtn");
        label_9 = new QLabel(dockWidgetContents_7);
        label_9->setObjectName("label_9");
        label_9->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/8.png);"));

        hLayout_HelpBtn->addWidget(label_9);

        pushButton_8 = new QPushButton(dockWidgetContents_7);
        pushButton_8->setObjectName("pushButton_8");

        hLayout_HelpBtn->addWidget(pushButton_8);


        verticalLayout_SidebarButtons->addLayout(hLayout_HelpBtn);


        verticalLayout_SidebarContainer->addLayout(verticalLayout_SidebarButtons);

        dockWidget->setWidget(dockWidgetContents_7);
        MainWindow->addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, dockWidget);

        retranslateUi(MainWindow);

        mainContentTabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Microorganism Management", nullptr));
        biovec_logo->setText(QString());
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "MicroOrganismes", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Name:", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter Name", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Discovery Date:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Type:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Virale", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Dangereuse", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "A\303\251roport\303\251e", nullptr));

        pushButton_14->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "ID:", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter ID (for Update/Delete)", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Characteristics:", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_16->setToolTip(QCoreApplication::translate("MainWindow", "Clear ID Field", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        mainContentTabWidget->setTabText(mainContentTabWidget->indexOf(tab_MicroDetails), QCoreApplication::translate("MainWindow", "Microorganism Details", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Data View & Actions", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search Data...", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "STAT", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "Name", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "Type", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "Discovery Date", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("MainWindow", "ID", nullptr));

#if QT_CONFIG(tooltip)
        comboBox_2->setToolTip(QCoreApplication::translate("MainWindow", "Sort Column", nullptr));
#endif // QT_CONFIG(tooltip)
        comboBox_3->setItemText(0, QCoreApplication::translate("MainWindow", "Ascending", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("MainWindow", "Descending", nullptr));

#if QT_CONFIG(tooltip)
        comboBox_3->setToolTip(QCoreApplication::translate("MainWindow", "Sort Order", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        pushButton_11->setToolTip(QCoreApplication::translate("MainWindow", "Apply Sort Order", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "Sort", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Characteristics", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Prep/Prediction", nullptr));
        pushButton_17->setText(QCoreApplication::translate("MainWindow", "Predict", nullptr));
        pushButton_18->setText(QCoreApplication::translate("MainWindow", "Prepare", nullptr));
        mainContentTabWidget->setTabText(mainContentTabWidget->indexOf(tab_DataPrep), QCoreApplication::translate("MainWindow", "Data & Preparation", nullptr));
        pushButton_19->setText(QCoreApplication::translate("MainWindow", "Front", nullptr));
        pushButton_20->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        pushButton_21->setText(QCoreApplication::translate("MainWindow", "Right", nullptr));
        pushButton_22->setText(QCoreApplication::translate("MainWindow", "Left", nullptr));
        pushButton_23->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        pushButton_24->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        mainContentTabWidget->setTabText(mainContentTabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Arm Controller", nullptr));
        dockWidget->setWindowTitle(QCoreApplication::translate("MainWindow", "Navigation", nullptr));
        sidebar_top_logo->setText(QString());
        label_3->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "Patient", nullptr));
        label_4->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "MicroVac", nullptr));
        label_5->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Personnel", nullptr));
        label_6->setText(QString());
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Inventory", nullptr));
        label_8->setText(QString());
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Appointment", nullptr));
        label_7->setText(QString());
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Event", nullptr));
        label_AnalyticsIcon->setText(QString());
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Analytics", nullptr));
        label_9->setText(QString());
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Help/Support", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MICRO_LAYOUT_H
