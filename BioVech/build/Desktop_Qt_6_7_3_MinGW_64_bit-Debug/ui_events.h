/********************************************************************************
** Form generated from reading UI file 'events.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTS_H
#define UI_EVENTS_H

#include <QtCore/QVariant>
#include <QtQuickWidgets/QQuickWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDockWidget>
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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_events
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QTabWidget *tabWidget;
    QWidget *TabEvent;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_EventDetails;
    QGridLayout *gridLayout_3;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_10;
    QComboBox *AlineEdit_6;
    QLabel *label_9;
    QLineEdit *AlineEdit_7;
    QPlainTextEdit *AlineEdit_4;
    QLabel *label_11;
    QLabel *label_8;
    QLineEdit *AlineEdit_2;
    QLineEdit *AlineEdit_3;
    QLineEdit *AlineEdit;
    QLabel *label_5;
    QDateEdit *AlineEdit_5;
    QVBoxLayout *verticalLayout_2;
    QPushButton *Add_Event;
    QPushButton *Modify_Event;
    QPushButton *Cancel_Modify;
    QPushButton *Delete_Event;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Suggestions_Button;
    QPushButton *Stat_Event;
    QPushButton *pdf_Button;
    QPushButton *Search_Button;
    QWidget *tab_3;
    QGridLayout *gridLayout_4;
    QPushButton *positionMapButton;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *verticalSpacer;
    QQuickWidget *quickWidget;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QCalendarWidget *calendarWidget;
    QWidget *tab;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QDockWidget *dockWidget;
    QWidget *dockWidget_Sidebar;
    QVBoxLayout *verticalLayout_SidebarContainer;
    QLabel *sidebar_top_logo;
    QVBoxLayout *verticalLayout_SidebarButtons;
    QHBoxLayout *hLayout_PatientBtn;
    QLabel *label_31;
    QPushButton *Button_Patient;
    QHBoxLayout *hLayout_MicroVacBtn;
    QLabel *label_41;
    QPushButton *Button_Vac;
    QHBoxLayout *hLayout_PersonnelBtn;
    QLabel *label_51;
    QPushButton *Button_Staff;
    QHBoxLayout *hLayout_InventoryBtn;
    QLabel *label_6;
    QPushButton *Button_Inventory;
    QHBoxLayout *hLayout_AppointmentBtn;
    QLabel *label_81;
    QPushButton *Button_Appoitment;
    QHBoxLayout *hLayout_EventBtn;
    QLabel *label_71;
    QPushButton *Button_Events;
    QHBoxLayout *hLayout_AnalyticsBtn;
    QLabel *label_AnalyticsIcon;
    QPushButton *Button_Analytics;
    QHBoxLayout *hLayout_HelpBtn;
    QLabel *label_91;
    QPushButton *Button_help;

    void setupUi(QMainWindow *events)
    {
        if (events->objectName().isEmpty())
            events->setObjectName("events");
        events->resize(1574, 845);
        events->setStyleSheet(QString::fromUtf8("/* Global Window Style */\n"
"QMainWindow {\n"
" border-image: url(\":/Static/Static/white_bg.jpg\");\n"
" background-size: contain;\n"
"}\n"
"\n"
"/* Header Logo */\n"
"QLabel#biovec_logo {\n"
"margin-left: 25px;\n"
"min-width: 50px;\n"
"max-width: 250px;\n"
"min-height: 80px;\n"
"max-height: 80px;\n"
"qproperty-alignment: AlignCenter;\n"
"background-color: transparent;\n"
"}\n"
"\n"
"/* Sidebar Dock Widget */\n"
"QDockWidget {\n"
"border: none;\n"
"background-color: #ffffff;\n"
"}\n"
"\n"
"QDockWidget::title {\n"
"background-color: #208c54;\n"
"color: white;\n"
"padding: 10px;\n"
"font-weight: bold;\n"
"border-radius: 5px;\n"
"text-align: left;\n"
"}\n"
"\n"
"/* Sidebar Header Logo */\n"
"QLabel#sidebar_top_logo {\n"
"min-width: 50px;\n"
"max-width: 250px;\n"
"min-height:100px;\n"
"max-height: 150px;\n"
"qproperty-alignment: 'AlignCenter';\n"
"image: url(:/Static/Static/dashboard.png);\n"
"}\n"
"\n"
"/* Sidebar Button Styles */\n"
"QDockWidget QPushButton {\n"
"background-color: #208c54;\n"
"color: #f6f8fa;\n"
""
                        "padding: 18px 32px 18px 25px;\n"
"text-align: left;\n"
"border: none;\n"
"border-radius: 0;\n"
"font-size: 18px;\n"
"font-weight: bold;\n"
"}\n"
"\n"
"QDockWidget QPushButton:hover {\n"
"background-color: #27ae77;\n"
"}\n"
"\n"
"QDockWidget QPushButton:pressed {\n"
"background-color: #27ae80;\n"
"}\n"
"\n"
"/* Sidebar Icon Styles */\n"
"QDockWidget QLabel {\n"
"min-width: 60px;\n"
"min-height:60px;\n"
"max-width: 60px;\n"
"max-height: 60px;\n"
"qproperty-alignment: 'AlignCenter';\n"
"margin-left: 4px;\n"
"}\n"
"\n"
"/* GroupBox Styles */\n"
"QGroupBox {\n"
"border: 1px solid #2ecc71;\n"
"border-radius: 8px;\n"
"margin-top: 12px;\n"
"font-weight: bold;\n"
"background-color: #ffffff;\n"
"padding: 4px;\n"
"}\n"
"\n"
"QGroupBox QPushButton {\n"
"border-radius: 20px;\n"
"font-weight: bold;\n"
"padding: 10px 20px;\n"
"min-height: 35px;\n"
"}\n"
"\n"
"QGroupBox QLineEdit {\n"
"border-radius: 20px;\n"
"padding: 8px 12px;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"subcontrol-origin: margin;\n"
"left: 10px;\n"
"padding: 0 5p"
                        "x 0 5px;\n"
"color: #27ae60;\n"
"background-color: #ffffff;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"/* Table Widget Styles */\n"
"QTableWidget {\n"
"border: 1px solid #2ecc71;\n"
"border-radius: 8px;\n"
"alternate-background-color: #f9f9f9;\n"
"background-color: #ffffff;\n"
"font-size: 15px;\n"
"selection-behavior: SelectRows;\n"
"selection-background-color: #AFE1AF;\n"
"selection-color: #000000;\n"
"gridline-color: #e0e0e0;\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"background-color: #27ae60;\n"
"color: white;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"background-color: #27ae60;\n"
"color: white;\n"
"padding: 10px;\n"
"border: none;\n"
"border-bottom: 1px solid #208c54;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"}\n"
"\n"
"/* General Button Styles */\n"
"QPushButton {\n"
"background-color: #2ecc71;\n"
"color: white;\n"
"border-radius: 18px;\n"
"padding: 10px 20px;\n"
"font-weight: bold;\n"
"font-size: 15px;\n"
"min-height: 35px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"background-color: #27ae60;\n"
"}\n"
""
                        "\n"
"QPushButton:pressed {\n"
"background-color: #1e8449;\n"
"}\n"
"\n"
"/* Input Field Styles */\n"
"QLineEdit, QDateEdit, QComboBox, QDateTimeEdit, QPlainTextEdit {\n"
"border: 1px solid #2ecc71;\n"
"border-radius: 18px;\n"
"padding: 8px 12px;\n"
"background-color: #ffffff;\n"
"font-size: 15px;\n"
"min-height: 35px;\n"
"}\n"
"\n"
"QPlainTextEdit {\n"
"qproperty-alignment: 'AlignLeft | AlignTop';\n"
"}\n"
"\n"
"/* Label Styles */\n"
"QLabel {\n"
"color: #2c3e50;\n"
"font-size: 15px;\n"
"background-color: transparent;\n"
"padding: 2px;\n"
"}\n"
"\n"
"/* Main Tab Widget */\n"
"QTabWidget::pane {\n"
"border:1px solid #2ecc71;\n"
"border-radius: 20px 20px 20px;\n"
"border-top: none;\n"
"background: white;\n"
"padding: 10px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"background: #208c54;\n"
"color: white;\n"
"border: 0px solid #208c54;\n"
"border-bottom: none;\n"
"border-radius: 23px 23px 0 0;\n"
"padding: 10px 20px;\n"
"margin-right: 4px;\n"
"font: bold 14pt \"Segoe UI\";\n"
"min-width: 10px;\n"
"}\n"
"\n"
"QTabBar::tab:s"
                        "elected {\n"
"background: #ffffff;\n"
"color: #208c54;\n"
"border-color: #2ecc71;\n"
"}\n"
"\n"
"QTabBar::tab:!selected:hover {\n"
"background: #1E8F53;\n"
"color: white;\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"alignment: left;\n"
"left: 5px;\n"
"}\n"
"\n"
"/* Calendar Widget */\n"
"QCalendarWidget {\n"
"background-color: #29aa63;\n"
"color: #ffffff;\n"
"font-family: \"Segoe UI\", \"Arial\", sans-serif;\n"
"font-size: 16px;\n"
"border: none;\n"
"border-radius: 15px;\n"
"}\n"
"\n"
"QCalendarWidget QWidget#qt_calendar_navigationbar {\n"
"background-color: #29aa63;\n"
"border: none;\n"
"border-top-left-radius: 15px;\n"
"border-top-right-radius: 15px;\n"
"}\n"
"\n"
"QCalendarWidget QToolButton {\n"
"color: #ffffff;\n"
"background-color: transparent;\n"
"border: none;\n"
"padding: 8px 12px;\n"
"border-radius: 8px;\n"
"font-size: 18px;\n"
"}\n"
"\n"
"QCalendarWidget QToolButton:hover {\n"
"background-color:#36d67e;\n"
"}\n"
"\n"
"QCalendarWidget QLabel {\n"
"font-size: 18px;\n"
"font-weight: bold;\n"
"color: #fffff"
                        "f;\n"
"border: none;\n"
"}\n"
"\n"
"QCalendarWidget QTableView {\n"
"background-color: #1e8c54;\n"
"border: none;\n"
"border-radius: 0px;\n"
"selection-background-color: rgba(255, 255, 255, 0.3);\n"
"selection-color: #2c3e50;\n"
"gridline-color: rgba(255, 255, 255, 50);\n"
"font-weight: bold;\n"
"}\n"
"\n"
"QCalendarWidget QTableView::item {\n"
"border: none;\n"
"color: white;\n"
"border-radius: 18px;\n"
"padding: 5px;\n"
"qproperty-alignment: AlignCenter;\n"
"}\n"
"\n"
"QCalendarWidget QTableView::item:selected {\n"
"background-color: #81C784;\n"
"color: white;\n"
"border-radius: 18px;\n"
"font-weight: bold;\n"
"}\n"
"\n"
"QCalendarWidget QTableView QHeaderView::section {\n"
"background-color: transparent;\n"
"color: #B2DFDB;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"border: none;\n"
"padding: 5px;\n"
"qproperty-alignment: AlignCenter;\n"
"}\n"
"\n"
"QCalendarWidget QTableView::item[dayOfWeek=\"6\"],\n"
"QCalendarWidget QTableView::item[dayOfWeek=\"7\"] {\n"
"color: #000000;\n"
"font-weight: bold;\n"
"}"
                        "\n"
"\n"
"QCalendarWidget QTableView::disabled {\n"
"color: #66BB6A;\n"
"font-weight: normal;\n"
"}\n"
"\n"
"QCalendarWidget QAbstractItemView:focus {\n"
"outline: none;\n"
"}"));
        centralwidget = new QWidget(events);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        QFont font;
        font.setBold(true);
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        TabEvent = new QWidget();
        TabEvent->setObjectName("TabEvent");
        gridLayout_2 = new QGridLayout(TabEvent);
        gridLayout_2->setObjectName("gridLayout_2");
        groupBox_EventDetails = new QGroupBox(TabEvent);
        groupBox_EventDetails->setObjectName("groupBox_EventDetails");
        gridLayout_3 = new QGridLayout(groupBox_EventDetails);
        gridLayout_3->setObjectName("gridLayout_3");
        label_4 = new QLabel(groupBox_EventDetails);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        gridLayout_3->addWidget(label_4, 4, 0, 1, 1);

        label_7 = new QLabel(groupBox_EventDetails);
        label_7->setObjectName("label_7");
        label_7->setFont(font);

        gridLayout_3->addWidget(label_7, 1, 0, 1, 1);

        label_10 = new QLabel(groupBox_EventDetails);
        label_10->setObjectName("label_10");
        label_10->setFont(font);

        gridLayout_3->addWidget(label_10, 5, 0, 1, 1);

        AlineEdit_6 = new QComboBox(groupBox_EventDetails);
        AlineEdit_6->addItem(QString());
        AlineEdit_6->addItem(QString());
        AlineEdit_6->addItem(QString());
        AlineEdit_6->addItem(QString());
        AlineEdit_6->setObjectName("AlineEdit_6");

        gridLayout_3->addWidget(AlineEdit_6, 6, 1, 1, 1);

        label_9 = new QLabel(groupBox_EventDetails);
        label_9->setObjectName("label_9");
        label_9->setFont(font);

        gridLayout_3->addWidget(label_9, 3, 0, 1, 1);

        AlineEdit_7 = new QLineEdit(groupBox_EventDetails);
        AlineEdit_7->setObjectName("AlineEdit_7");

        gridLayout_3->addWidget(AlineEdit_7, 4, 1, 1, 1);

        AlineEdit_4 = new QPlainTextEdit(groupBox_EventDetails);
        AlineEdit_4->setObjectName("AlineEdit_4");

        gridLayout_3->addWidget(AlineEdit_4, 3, 1, 1, 1);

        label_11 = new QLabel(groupBox_EventDetails);
        label_11->setObjectName("label_11");
        label_11->setFont(font);

        gridLayout_3->addWidget(label_11, 6, 0, 1, 1);

        label_8 = new QLabel(groupBox_EventDetails);
        label_8->setObjectName("label_8");
        label_8->setFont(font);

        gridLayout_3->addWidget(label_8, 2, 0, 1, 1);

        AlineEdit_2 = new QLineEdit(groupBox_EventDetails);
        AlineEdit_2->setObjectName("AlineEdit_2");

        gridLayout_3->addWidget(AlineEdit_2, 1, 1, 1, 1);

        AlineEdit_3 = new QLineEdit(groupBox_EventDetails);
        AlineEdit_3->setObjectName("AlineEdit_3");

        gridLayout_3->addWidget(AlineEdit_3, 2, 1, 1, 1);

        AlineEdit = new QLineEdit(groupBox_EventDetails);
        AlineEdit->setObjectName("AlineEdit");

        gridLayout_3->addWidget(AlineEdit, 0, 1, 1, 1);

        label_5 = new QLabel(groupBox_EventDetails);
        label_5->setObjectName("label_5");
        label_5->setFont(font);

        gridLayout_3->addWidget(label_5, 0, 0, 1, 1);

        AlineEdit_5 = new QDateEdit(groupBox_EventDetails);
        AlineEdit_5->setObjectName("AlineEdit_5");

        gridLayout_3->addWidget(AlineEdit_5, 5, 1, 1, 1);


        gridLayout_2->addWidget(groupBox_EventDetails, 1, 0, 1, 3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        Add_Event = new QPushButton(TabEvent);
        Add_Event->setObjectName("Add_Event");

        verticalLayout_2->addWidget(Add_Event);

        Modify_Event = new QPushButton(TabEvent);
        Modify_Event->setObjectName("Modify_Event");

        verticalLayout_2->addWidget(Modify_Event);

        Cancel_Modify = new QPushButton(TabEvent);
        Cancel_Modify->setObjectName("Cancel_Modify");

        verticalLayout_2->addWidget(Cancel_Modify);

        Delete_Event = new QPushButton(TabEvent);
        Delete_Event->setObjectName("Delete_Event");

        verticalLayout_2->addWidget(Delete_Event);


        gridLayout_2->addLayout(verticalLayout_2, 1, 3, 1, 1);

        tableWidget = new QTableWidget(TabEvent);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
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
        if (tableWidget->rowCount() < 4)
            tableWidget->setRowCount(4);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tableWidget->setShowGrid(true);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);

        gridLayout_2->addWidget(tableWidget, 2, 0, 1, 4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        comboBox = new QComboBox(TabEvent);
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

        horizontalLayout_4->addWidget(comboBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        Suggestions_Button = new QPushButton(TabEvent);
        Suggestions_Button->setObjectName("Suggestions_Button");

        horizontalLayout_2->addWidget(Suggestions_Button);

        Stat_Event = new QPushButton(TabEvent);
        Stat_Event->setObjectName("Stat_Event");

        horizontalLayout_2->addWidget(Stat_Event);

        pdf_Button = new QPushButton(TabEvent);
        pdf_Button->setObjectName("pdf_Button");

        horizontalLayout_2->addWidget(pdf_Button);

        Search_Button = new QPushButton(TabEvent);
        Search_Button->setObjectName("Search_Button");

        horizontalLayout_2->addWidget(Search_Button);


        horizontalLayout_4->addLayout(horizontalLayout_2);


        gridLayout_2->addLayout(horizontalLayout_4, 3, 0, 1, 4);

        tabWidget->addTab(TabEvent, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        gridLayout_4 = new QGridLayout(tab_3);
        gridLayout_4->setObjectName("gridLayout_4");
        positionMapButton = new QPushButton(tab_3);
        positionMapButton->setObjectName("positionMapButton");

        gridLayout_4->addWidget(positionMapButton, 0, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        horizontalLayout_5->addItem(verticalSpacer);

        quickWidget = new QQuickWidget(tab_3);
        quickWidget->setObjectName("quickWidget");

        horizontalLayout_5->addWidget(quickWidget);


        horizontalLayout_3->addLayout(horizontalLayout_5);


        gridLayout_4->addLayout(horizontalLayout_3, 1, 1, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");

        gridLayout_4->addLayout(horizontalLayout_6, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 0, 1, 1);

        calendarWidget = new QCalendarWidget(tab_3);
        calendarWidget->setObjectName("calendarWidget");

        gridLayout_4->addWidget(calendarWidget, 1, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        tabWidget->addTab(tab, QString());

        gridLayout->addWidget(tabWidget, 1, 1, 1, 1);

        events->setCentralWidget(centralwidget);
        menubar = new QMenuBar(events);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1574, 25));
        events->setMenuBar(menubar);
        statusbar = new QStatusBar(events);
        statusbar->setObjectName("statusbar");
        events->setStatusBar(statusbar);
        dockWidget = new QDockWidget(events);
        dockWidget->setObjectName("dockWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dockWidget->sizePolicy().hasHeightForWidth());
        dockWidget->setSizePolicy(sizePolicy);
        dockWidget->setMinimumSize(QSize(264, 795));
        dockWidget->setFeatures(QDockWidget::DockWidgetFeature::NoDockWidgetFeatures);
        dockWidget->setAllowedAreas(Qt::DockWidgetArea::LeftDockWidgetArea);
        dockWidget_Sidebar = new QWidget();
        dockWidget_Sidebar->setObjectName("dockWidget_Sidebar");
        verticalLayout_SidebarContainer = new QVBoxLayout(dockWidget_Sidebar);
        verticalLayout_SidebarContainer->setSpacing(10);
        verticalLayout_SidebarContainer->setObjectName("verticalLayout_SidebarContainer");
        verticalLayout_SidebarContainer->setContentsMargins(0, 10, 0, 10);
        sidebar_top_logo = new QLabel(dockWidget_Sidebar);
        sidebar_top_logo->setObjectName("sidebar_top_logo");
        sidebar_top_logo->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/dashboard.png);"));

        verticalLayout_SidebarContainer->addWidget(sidebar_top_logo);

        verticalLayout_SidebarButtons = new QVBoxLayout();
        verticalLayout_SidebarButtons->setSpacing(5);
        verticalLayout_SidebarButtons->setObjectName("verticalLayout_SidebarButtons");
        hLayout_PatientBtn = new QHBoxLayout();
        hLayout_PatientBtn->setSpacing(0);
        hLayout_PatientBtn->setObjectName("hLayout_PatientBtn");
        label_31 = new QLabel(dockWidget_Sidebar);
        label_31->setObjectName("label_31");
        label_31->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/1.png);"));

        hLayout_PatientBtn->addWidget(label_31);

        Button_Patient = new QPushButton(dockWidget_Sidebar);
        Button_Patient->setObjectName("Button_Patient");

        hLayout_PatientBtn->addWidget(Button_Patient);


        verticalLayout_SidebarButtons->addLayout(hLayout_PatientBtn);

        hLayout_MicroVacBtn = new QHBoxLayout();
        hLayout_MicroVacBtn->setSpacing(0);
        hLayout_MicroVacBtn->setObjectName("hLayout_MicroVacBtn");
        label_41 = new QLabel(dockWidget_Sidebar);
        label_41->setObjectName("label_41");
        label_41->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/2.png);"));

        hLayout_MicroVacBtn->addWidget(label_41);

        Button_Vac = new QPushButton(dockWidget_Sidebar);
        Button_Vac->setObjectName("Button_Vac");

        hLayout_MicroVacBtn->addWidget(Button_Vac);


        verticalLayout_SidebarButtons->addLayout(hLayout_MicroVacBtn);

        hLayout_PersonnelBtn = new QHBoxLayout();
        hLayout_PersonnelBtn->setSpacing(0);
        hLayout_PersonnelBtn->setObjectName("hLayout_PersonnelBtn");
        label_51 = new QLabel(dockWidget_Sidebar);
        label_51->setObjectName("label_51");
        label_51->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/3.png);"));

        hLayout_PersonnelBtn->addWidget(label_51);

        Button_Staff = new QPushButton(dockWidget_Sidebar);
        Button_Staff->setObjectName("Button_Staff");

        hLayout_PersonnelBtn->addWidget(Button_Staff);


        verticalLayout_SidebarButtons->addLayout(hLayout_PersonnelBtn);

        hLayout_InventoryBtn = new QHBoxLayout();
        hLayout_InventoryBtn->setSpacing(0);
        hLayout_InventoryBtn->setObjectName("hLayout_InventoryBtn");
        label_6 = new QLabel(dockWidget_Sidebar);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/4.png);"));

        hLayout_InventoryBtn->addWidget(label_6);

        Button_Inventory = new QPushButton(dockWidget_Sidebar);
        Button_Inventory->setObjectName("Button_Inventory");

        hLayout_InventoryBtn->addWidget(Button_Inventory);


        verticalLayout_SidebarButtons->addLayout(hLayout_InventoryBtn);

        hLayout_AppointmentBtn = new QHBoxLayout();
        hLayout_AppointmentBtn->setSpacing(0);
        hLayout_AppointmentBtn->setObjectName("hLayout_AppointmentBtn");
        label_81 = new QLabel(dockWidget_Sidebar);
        label_81->setObjectName("label_81");
        label_81->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/5.png);"));

        hLayout_AppointmentBtn->addWidget(label_81);

        Button_Appoitment = new QPushButton(dockWidget_Sidebar);
        Button_Appoitment->setObjectName("Button_Appoitment");

        hLayout_AppointmentBtn->addWidget(Button_Appoitment);


        verticalLayout_SidebarButtons->addLayout(hLayout_AppointmentBtn);

        hLayout_EventBtn = new QHBoxLayout();
        hLayout_EventBtn->setSpacing(0);
        hLayout_EventBtn->setObjectName("hLayout_EventBtn");
        label_71 = new QLabel(dockWidget_Sidebar);
        label_71->setObjectName("label_71");
        label_71->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/6.png);"));

        hLayout_EventBtn->addWidget(label_71);

        Button_Events = new QPushButton(dockWidget_Sidebar);
        Button_Events->setObjectName("Button_Events");

        hLayout_EventBtn->addWidget(Button_Events);


        verticalLayout_SidebarButtons->addLayout(hLayout_EventBtn);

        hLayout_AnalyticsBtn = new QHBoxLayout();
        hLayout_AnalyticsBtn->setSpacing(0);
        hLayout_AnalyticsBtn->setObjectName("hLayout_AnalyticsBtn");
        label_AnalyticsIcon = new QLabel(dockWidget_Sidebar);
        label_AnalyticsIcon->setObjectName("label_AnalyticsIcon");
        label_AnalyticsIcon->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/7.png);"));

        hLayout_AnalyticsBtn->addWidget(label_AnalyticsIcon);

        Button_Analytics = new QPushButton(dockWidget_Sidebar);
        Button_Analytics->setObjectName("Button_Analytics");

        hLayout_AnalyticsBtn->addWidget(Button_Analytics);


        verticalLayout_SidebarButtons->addLayout(hLayout_AnalyticsBtn);

        hLayout_HelpBtn = new QHBoxLayout();
        hLayout_HelpBtn->setSpacing(0);
        hLayout_HelpBtn->setObjectName("hLayout_HelpBtn");
        label_91 = new QLabel(dockWidget_Sidebar);
        label_91->setObjectName("label_91");
        label_91->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/8.png);"));

        hLayout_HelpBtn->addWidget(label_91);

        Button_help = new QPushButton(dockWidget_Sidebar);
        Button_help->setObjectName("Button_help");

        hLayout_HelpBtn->addWidget(Button_help);


        verticalLayout_SidebarButtons->addLayout(hLayout_HelpBtn);


        verticalLayout_SidebarContainer->addLayout(verticalLayout_SidebarButtons);

        dockWidget->setWidget(dockWidget_Sidebar);
        events->addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, dockWidget);

        retranslateUi(events);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(events);
    } // setupUi

    void retranslateUi(QMainWindow *events)
    {
        events->setWindowTitle(QCoreApplication::translate("events", "Events Management", nullptr));
        label_3->setText(QCoreApplication::translate("events", "Events", nullptr));
        groupBox_EventDetails->setTitle(QCoreApplication::translate("events", "Event Details", nullptr));
        label_4->setText(QCoreApplication::translate("events", "Position", nullptr));
        label_7->setText(QCoreApplication::translate("events", "Title", nullptr));
        label_10->setText(QCoreApplication::translate("events", "Date", nullptr));
        AlineEdit_6->setItemText(0, QCoreApplication::translate("events", "Charity", nullptr));
        AlineEdit_6->setItemText(1, QCoreApplication::translate("events", "Summit", nullptr));
        AlineEdit_6->setItemText(2, QCoreApplication::translate("events", "Q&A", nullptr));
        AlineEdit_6->setItemText(3, QCoreApplication::translate("events", "Vaccination", nullptr));

        label_9->setText(QCoreApplication::translate("events", "Description", nullptr));
        label_11->setText(QCoreApplication::translate("events", "Type", nullptr));
        label_8->setText(QCoreApplication::translate("events", "Sponsor", nullptr));
        label_5->setText(QCoreApplication::translate("events", "Id", nullptr));
        Add_Event->setText(QCoreApplication::translate("events", "Add", nullptr));
        Modify_Event->setText(QCoreApplication::translate("events", "Update", nullptr));
        Cancel_Modify->setText(QCoreApplication::translate("events", "Cancel", nullptr));
        Delete_Event->setText(QCoreApplication::translate("events", "Delete", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("events", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("events", "Position", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("events", "Description", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("events", "Title", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("events", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("events", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("events", "Sponsor", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("events", "Sort:(None)", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("events", "Date_Asc", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("events", "Date_Desc", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("events", "Type_Asc", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("events", "Type_Desc", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("events", "Title_Asc", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("events", "Title_Desc", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("events", "Sponsor_Asc", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("events", "Sponsor_Desc", nullptr));

        Suggestions_Button->setText(QCoreApplication::translate("events", "Nearby Events", nullptr));
        Stat_Event->setText(QCoreApplication::translate("events", "Stats", nullptr));
        pdf_Button->setText(QCoreApplication::translate("events", "PDF", nullptr));
        Search_Button->setText(QCoreApplication::translate("events", "Find", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(TabEvent), QCoreApplication::translate("events", "Event Details", nullptr));
        positionMapButton->setText(QCoreApplication::translate("events", "\360\237\223\215 Select on Map", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("events", "Map", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("events", "Stats", nullptr));
        dockWidget->setWindowTitle(QCoreApplication::translate("events", "Navigation", nullptr));
        sidebar_top_logo->setText(QString());
        label_31->setText(QString());
        Button_Patient->setText(QCoreApplication::translate("events", "Patient", nullptr));
        label_41->setText(QString());
        Button_Vac->setText(QCoreApplication::translate("events", "MicroVac", nullptr));
        label_51->setText(QString());
        Button_Staff->setText(QCoreApplication::translate("events", "Personnel", nullptr));
        label_6->setText(QString());
        Button_Inventory->setText(QCoreApplication::translate("events", "Inventory", nullptr));
        label_81->setText(QString());
        Button_Appoitment->setText(QCoreApplication::translate("events", "Appointment", nullptr));
        label_71->setText(QString());
        Button_Events->setText(QCoreApplication::translate("events", "Event", nullptr));
        label_AnalyticsIcon->setText(QString());
        Button_Analytics->setText(QCoreApplication::translate("events", "Analytics", nullptr));
        label_91->setText(QString());
        Button_help->setText(QCoreApplication::translate("events", "Help/Support", nullptr));
    } // retranslateUi

};

namespace Ui {
    class events: public Ui_events {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTS_H
