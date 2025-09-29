/********************************************************************************
** Form generated from reading UI file 'appointment.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPOINTMENT_H
#define UI_APPOINTMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_appointment
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_CentralWidget;
    QLabel *biovec_logo;
    QSpacerItem *horizontalSpacer_LeftOfTabs;
    QTabWidget *mainContentTabWidget;
    QWidget *tab_Appointments;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *readTodaysAppointmentsButton;
    QPushButton *statisticButton;
    QPushButton *speechSettingsButton;
    QCalendarWidget *smart_calendar;
    QWidget *dispaly_info;
    QSpacerItem *horizontalSpacer;
    QWidget *tab_Management;
    QGridLayout *gridLayout;
    QLineEdit *search;
    QGroupBox *groupBox_AppointmentDetails;
    QGridLayout *gridLayout_3;
    QLineEdit *noteEdit;
    QLineEdit *idEdit;
    QComboBox *objectifEdit;
    QLabel *Automangmentlabel;
    QLabel *manuel_managment;
    QComboBox *statusCombo;
    QLineEdit *ideEdit;
    QLabel *ideLabel;
    QLabel *statusLabel;
    QLabel *dateLabel;
    QPushButton *pushButton_clear;
    QPushButton *auto_appointment;
    QLabel *idLabel;
    QLabel *objectiveLabel;
    QHBoxLayout *horizontalLayout_Actions;
    QPushButton *pushButton_add;
    QPushButton *pushButton_update;
    QPushButton *pushButton_delete;
    QLabel *idaLabel;
    QSpacerItem *verticalSpacer;
    QLabel *noteLabel;
    QLineEdit *cinpEdit;
    QDateTimeEdit *dateEdit;
    QPushButton *exportPdfButton;
    QHBoxLayout *horizontalLayout_SearchFilter;
    QPushButton *filterButton;
    QTableWidget *tab_CRUD;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QDockWidget *dockWidget;
    QWidget *dockWidget_Sidebar;
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

    void setupUi(QMainWindow *appointment)
    {
        if (appointment->objectName().isEmpty())
            appointment->setObjectName("appointment");
        appointment->resize(1450, 874);
        appointment->setStyleSheet(QString::fromUtf8("/* Global Window Style */\n"
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
"QPushButton#pushButton_delete {\n"
"    background-color: #d8666c;\n"
"}\n"
"\n"
"QPushButton#pushButton_delete:hover {\n"
"    background-color: #d85057;\n"
"}\n"
"\n"
"QPushButton#pushButton_delete:pressed {\n"
"    background-color: #c04349;\n"
"}\n"
"\n"
"QPushButton#pushButton_clear {\n"
"    background-color: #66ffa4;\n"
"    color: #126032;\n"
"   border-radius: 18px;\n"
"    padding: 10px 20px;\n"
"    font-weight: bold;\n"
"    font-size: 15px;\n"
"    min-hei"
                        "ght: 35px;\n"
"}\n"
"\n"
"QPushButton#pushButton_clear:hover {\n"
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
"QLineEdit#lineEdit_6,\n"
"QLineEdit#lineEdit_4 {\n"
"    min-height: 100px;\n"
"    border-radius: 8px;\n"
"    qproperty-alignment: 'AlignLeft | AlignTop';\n"
"}\n"
"\n"
"QLineEdit#lineEdit_4 {\n"
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
"QTabBar::tab {\n"
"    backgrou"
                        "nd: #208c54;\n"
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
"QCalendarWidget QToolButton"
                        " {\n"
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
"    gridline-color: rgba(255, 255, 255, 50);\n"
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
"    border-radius: 18px;\n"
""
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
        centralwidget = new QWidget(appointment);
        centralwidget->setObjectName("centralwidget");
        gridLayout_CentralWidget = new QGridLayout(centralwidget);
        gridLayout_CentralWidget->setObjectName("gridLayout_CentralWidget");
        gridLayout_CentralWidget->setContentsMargins(0, 0, 0, 0);
        biovec_logo = new QLabel(centralwidget);
        biovec_logo->setObjectName("biovec_logo");
        biovec_logo->setMinimumSize(QSize(79, 84));
        biovec_logo->setMaximumSize(QSize(279, 84));
        biovec_logo->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_CentralWidget->addWidget(biovec_logo, 0, 1, 1, 1);

        horizontalSpacer_LeftOfTabs = new QSpacerItem(0, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_CentralWidget->addItem(horizontalSpacer_LeftOfTabs, 1, 0, 1, 1);

        mainContentTabWidget = new QTabWidget(centralwidget);
        mainContentTabWidget->setObjectName("mainContentTabWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainContentTabWidget->sizePolicy().hasHeightForWidth());
        mainContentTabWidget->setSizePolicy(sizePolicy);
        tab_Appointments = new QWidget();
        tab_Appointments->setObjectName("tab_Appointments");
        gridLayout_2 = new QGridLayout(tab_Appointments);
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        readTodaysAppointmentsButton = new QPushButton(tab_Appointments);
        readTodaysAppointmentsButton->setObjectName("readTodaysAppointmentsButton");
        readTodaysAppointmentsButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout->addWidget(readTodaysAppointmentsButton);

        statisticButton = new QPushButton(tab_Appointments);
        statisticButton->setObjectName("statisticButton");
        statisticButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout->addWidget(statisticButton);

        speechSettingsButton = new QPushButton(tab_Appointments);
        speechSettingsButton->setObjectName("speechSettingsButton");
        speechSettingsButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout->addWidget(speechSettingsButton);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        smart_calendar = new QCalendarWidget(tab_Appointments);
        smart_calendar->setObjectName("smart_calendar");

        gridLayout_2->addWidget(smart_calendar, 2, 0, 1, 1);

        dispaly_info = new QWidget(tab_Appointments);
        dispaly_info->setObjectName("dispaly_info");

        gridLayout_2->addWidget(dispaly_info, 2, 2, 2, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 2, 1, 1);

        mainContentTabWidget->addTab(tab_Appointments, QString());
        tab_Management = new QWidget();
        tab_Management->setObjectName("tab_Management");
        gridLayout = new QGridLayout(tab_Management);
        gridLayout->setObjectName("gridLayout");
        search = new QLineEdit(tab_Management);
        search->setObjectName("search");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(search->sizePolicy().hasHeightForWidth());
        search->setSizePolicy(sizePolicy1);
        search->setClearButtonEnabled(true);

        gridLayout->addWidget(search, 3, 0, 1, 1);

        groupBox_AppointmentDetails = new QGroupBox(tab_Management);
        groupBox_AppointmentDetails->setObjectName("groupBox_AppointmentDetails");
        gridLayout_3 = new QGridLayout(groupBox_AppointmentDetails);
        gridLayout_3->setObjectName("gridLayout_3");
        noteEdit = new QLineEdit(groupBox_AppointmentDetails);
        noteEdit->setObjectName("noteEdit");
        noteEdit->setClearButtonEnabled(true);

        gridLayout_3->addWidget(noteEdit, 4, 1, 2, 1);

        idEdit = new QLineEdit(groupBox_AppointmentDetails);
        idEdit->setObjectName("idEdit");
        idEdit->setClearButtonEnabled(true);

        gridLayout_3->addWidget(idEdit, 4, 4, 1, 1);

        objectifEdit = new QComboBox(groupBox_AppointmentDetails);
        objectifEdit->addItem(QString());
        objectifEdit->addItem(QString());
        objectifEdit->addItem(QString());
        objectifEdit->setObjectName("objectifEdit");

        gridLayout_3->addWidget(objectifEdit, 3, 1, 1, 1);

        Automangmentlabel = new QLabel(groupBox_AppointmentDetails);
        Automangmentlabel->setObjectName("Automangmentlabel");
        Automangmentlabel->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";\n"
""));

        gridLayout_3->addWidget(Automangmentlabel, 1, 0, 1, 1);

        manuel_managment = new QLabel(groupBox_AppointmentDetails);
        manuel_managment->setObjectName("manuel_managment");
        manuel_managment->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";"));

        gridLayout_3->addWidget(manuel_managment, 1, 3, 1, 2);

        statusCombo = new QComboBox(groupBox_AppointmentDetails);
        statusCombo->addItem(QString());
        statusCombo->addItem(QString());
        statusCombo->addItem(QString());
        statusCombo->addItem(QString());
        statusCombo->setObjectName("statusCombo");

        gridLayout_3->addWidget(statusCombo, 3, 4, 1, 1);

        ideEdit = new QLineEdit(groupBox_AppointmentDetails);
        ideEdit->setObjectName("ideEdit");
        ideEdit->setClearButtonEnabled(true);

        gridLayout_3->addWidget(ideEdit, 6, 4, 1, 1);

        ideLabel = new QLabel(groupBox_AppointmentDetails);
        ideLabel->setObjectName("ideLabel");

        gridLayout_3->addWidget(ideLabel, 6, 3, 1, 1);

        statusLabel = new QLabel(groupBox_AppointmentDetails);
        statusLabel->setObjectName("statusLabel");

        gridLayout_3->addWidget(statusLabel, 3, 3, 1, 1);

        dateLabel = new QLabel(groupBox_AppointmentDetails);
        dateLabel->setObjectName("dateLabel");

        gridLayout_3->addWidget(dateLabel, 2, 3, 1, 1);

        pushButton_clear = new QPushButton(groupBox_AppointmentDetails);
        pushButton_clear->setObjectName("pushButton_clear");
        pushButton_clear->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        gridLayout_3->addWidget(pushButton_clear, 7, 0, 1, 2);

        auto_appointment = new QPushButton(groupBox_AppointmentDetails);
        auto_appointment->setObjectName("auto_appointment");

        gridLayout_3->addWidget(auto_appointment, 6, 0, 1, 2);

        idLabel = new QLabel(groupBox_AppointmentDetails);
        idLabel->setObjectName("idLabel");

        gridLayout_3->addWidget(idLabel, 2, 0, 1, 1);

        objectiveLabel = new QLabel(groupBox_AppointmentDetails);
        objectiveLabel->setObjectName("objectiveLabel");

        gridLayout_3->addWidget(objectiveLabel, 3, 0, 1, 1);

        horizontalLayout_Actions = new QHBoxLayout();
        horizontalLayout_Actions->setObjectName("horizontalLayout_Actions");
        pushButton_add = new QPushButton(groupBox_AppointmentDetails);
        pushButton_add->setObjectName("pushButton_add");
        pushButton_add->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_Actions->addWidget(pushButton_add);

        pushButton_update = new QPushButton(groupBox_AppointmentDetails);
        pushButton_update->setObjectName("pushButton_update");
        pushButton_update->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_Actions->addWidget(pushButton_update);

        pushButton_delete = new QPushButton(groupBox_AppointmentDetails);
        pushButton_delete->setObjectName("pushButton_delete");
        pushButton_delete->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_Actions->addWidget(pushButton_delete);


        gridLayout_3->addLayout(horizontalLayout_Actions, 7, 3, 1, 2);

        idaLabel = new QLabel(groupBox_AppointmentDetails);
        idaLabel->setObjectName("idaLabel");

        gridLayout_3->addWidget(idaLabel, 4, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 1, 2, 6, 1);

        noteLabel = new QLabel(groupBox_AppointmentDetails);
        noteLabel->setObjectName("noteLabel");

        gridLayout_3->addWidget(noteLabel, 4, 0, 1, 1);

        cinpEdit = new QLineEdit(groupBox_AppointmentDetails);
        cinpEdit->setObjectName("cinpEdit");
        cinpEdit->setClearButtonEnabled(true);

        gridLayout_3->addWidget(cinpEdit, 2, 1, 1, 1);

        dateEdit = new QDateTimeEdit(groupBox_AppointmentDetails);
        dateEdit->setObjectName("dateEdit");

        gridLayout_3->addWidget(dateEdit, 2, 4, 1, 1);


        gridLayout->addWidget(groupBox_AppointmentDetails, 0, 0, 1, 3);

        exportPdfButton = new QPushButton(tab_Management);
        exportPdfButton->setObjectName("exportPdfButton");
        exportPdfButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        gridLayout->addWidget(exportPdfButton, 3, 1, 1, 1);

        horizontalLayout_SearchFilter = new QHBoxLayout();
        horizontalLayout_SearchFilter->setObjectName("horizontalLayout_SearchFilter");

        gridLayout->addLayout(horizontalLayout_SearchFilter, 1, 0, 1, 1);

        filterButton = new QPushButton(tab_Management);
        filterButton->setObjectName("filterButton");
        filterButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        gridLayout->addWidget(filterButton, 3, 2, 1, 1);

        tab_CRUD = new QTableWidget(tab_Management);
        if (tab_CRUD->columnCount() < 7)
            tab_CRUD->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tab_CRUD->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tab_CRUD->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tab_CRUD->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tab_CRUD->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tab_CRUD->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tab_CRUD->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tab_CRUD->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tab_CRUD->setObjectName("tab_CRUD");
        tab_CRUD->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(2);
        sizePolicy2.setHeightForWidth(tab_CRUD->sizePolicy().hasHeightForWidth());
        tab_CRUD->setSizePolicy(sizePolicy2);
        tab_CRUD->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tab_CRUD->setAlternatingRowColors(true);
        tab_CRUD->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        tab_CRUD->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tab_CRUD->setShowGrid(true);
        tab_CRUD->horizontalHeader()->setStretchLastSection(true);
        tab_CRUD->verticalHeader()->setVisible(false);

        gridLayout->addWidget(tab_CRUD, 2, 0, 1, 3);

        mainContentTabWidget->addTab(tab_Management, QString());

        gridLayout_CentralWidget->addWidget(mainContentTabWidget, 1, 1, 1, 1);

        appointment->setCentralWidget(centralwidget);
        menubar = new QMenuBar(appointment);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1450, 25));
        appointment->setMenuBar(menubar);
        statusbar = new QStatusBar(appointment);
        statusbar->setObjectName("statusbar");
        appointment->setStatusBar(statusbar);
        dockWidget = new QDockWidget(appointment);
        dockWidget->setObjectName("dockWidget");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(dockWidget->sizePolicy().hasHeightForWidth());
        dockWidget->setSizePolicy(sizePolicy3);
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
        label_3 = new QLabel(dockWidget_Sidebar);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/1.png);"));

        hLayout_PatientBtn->addWidget(label_3);

        pushButton = new QPushButton(dockWidget_Sidebar);
        pushButton->setObjectName("pushButton");

        hLayout_PatientBtn->addWidget(pushButton);


        verticalLayout_SidebarButtons->addLayout(hLayout_PatientBtn);

        hLayout_MicroVacBtn = new QHBoxLayout();
        hLayout_MicroVacBtn->setSpacing(0);
        hLayout_MicroVacBtn->setObjectName("hLayout_MicroVacBtn");
        label_4 = new QLabel(dockWidget_Sidebar);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/2.png);"));

        hLayout_MicroVacBtn->addWidget(label_4);

        pushButton_2 = new QPushButton(dockWidget_Sidebar);
        pushButton_2->setObjectName("pushButton_2");

        hLayout_MicroVacBtn->addWidget(pushButton_2);


        verticalLayout_SidebarButtons->addLayout(hLayout_MicroVacBtn);

        hLayout_PersonnelBtn = new QHBoxLayout();
        hLayout_PersonnelBtn->setSpacing(0);
        hLayout_PersonnelBtn->setObjectName("hLayout_PersonnelBtn");
        label_5 = new QLabel(dockWidget_Sidebar);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/3.png);"));

        hLayout_PersonnelBtn->addWidget(label_5);

        pushButton_3 = new QPushButton(dockWidget_Sidebar);
        pushButton_3->setObjectName("pushButton_3");

        hLayout_PersonnelBtn->addWidget(pushButton_3);


        verticalLayout_SidebarButtons->addLayout(hLayout_PersonnelBtn);

        hLayout_InventoryBtn = new QHBoxLayout();
        hLayout_InventoryBtn->setSpacing(0);
        hLayout_InventoryBtn->setObjectName("hLayout_InventoryBtn");
        label_6 = new QLabel(dockWidget_Sidebar);
        label_6->setObjectName("label_6");
        label_6->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/4.png);"));

        hLayout_InventoryBtn->addWidget(label_6);

        pushButton_4 = new QPushButton(dockWidget_Sidebar);
        pushButton_4->setObjectName("pushButton_4");

        hLayout_InventoryBtn->addWidget(pushButton_4);


        verticalLayout_SidebarButtons->addLayout(hLayout_InventoryBtn);

        hLayout_AppointmentBtn = new QHBoxLayout();
        hLayout_AppointmentBtn->setSpacing(0);
        hLayout_AppointmentBtn->setObjectName("hLayout_AppointmentBtn");
        label_8 = new QLabel(dockWidget_Sidebar);
        label_8->setObjectName("label_8");
        label_8->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/5.png);"));

        hLayout_AppointmentBtn->addWidget(label_8);

        pushButton_6 = new QPushButton(dockWidget_Sidebar);
        pushButton_6->setObjectName("pushButton_6");

        hLayout_AppointmentBtn->addWidget(pushButton_6);


        verticalLayout_SidebarButtons->addLayout(hLayout_AppointmentBtn);

        hLayout_EventBtn = new QHBoxLayout();
        hLayout_EventBtn->setSpacing(0);
        hLayout_EventBtn->setObjectName("hLayout_EventBtn");
        label_7 = new QLabel(dockWidget_Sidebar);
        label_7->setObjectName("label_7");
        label_7->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/6.png);"));

        hLayout_EventBtn->addWidget(label_7);

        pushButton_5 = new QPushButton(dockWidget_Sidebar);
        pushButton_5->setObjectName("pushButton_5");

        hLayout_EventBtn->addWidget(pushButton_5);


        verticalLayout_SidebarButtons->addLayout(hLayout_EventBtn);

        hLayout_AnalyticsBtn = new QHBoxLayout();
        hLayout_AnalyticsBtn->setSpacing(0);
        hLayout_AnalyticsBtn->setObjectName("hLayout_AnalyticsBtn");
        label_AnalyticsIcon = new QLabel(dockWidget_Sidebar);
        label_AnalyticsIcon->setObjectName("label_AnalyticsIcon");
        label_AnalyticsIcon->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/7.png);"));

        hLayout_AnalyticsBtn->addWidget(label_AnalyticsIcon);

        pushButton_7 = new QPushButton(dockWidget_Sidebar);
        pushButton_7->setObjectName("pushButton_7");

        hLayout_AnalyticsBtn->addWidget(pushButton_7);


        verticalLayout_SidebarButtons->addLayout(hLayout_AnalyticsBtn);

        hLayout_HelpBtn = new QHBoxLayout();
        hLayout_HelpBtn->setSpacing(0);
        hLayout_HelpBtn->setObjectName("hLayout_HelpBtn");
        label_9 = new QLabel(dockWidget_Sidebar);
        label_9->setObjectName("label_9");
        label_9->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/8.png);"));

        hLayout_HelpBtn->addWidget(label_9);

        pushButton_8 = new QPushButton(dockWidget_Sidebar);
        pushButton_8->setObjectName("pushButton_8");

        hLayout_HelpBtn->addWidget(pushButton_8);


        verticalLayout_SidebarButtons->addLayout(hLayout_HelpBtn);


        verticalLayout_SidebarContainer->addLayout(verticalLayout_SidebarButtons);

        dockWidget->setWidget(dockWidget_Sidebar);
        appointment->addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, dockWidget);

        retranslateUi(appointment);

        mainContentTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(appointment);
    } // setupUi

    void retranslateUi(QMainWindow *appointment)
    {
        appointment->setWindowTitle(QCoreApplication::translate("appointment", "Appointment Management", nullptr));
        biovec_logo->setText(QString());
#if QT_CONFIG(tooltip)
        readTodaysAppointmentsButton->setToolTip(QCoreApplication::translate("appointment", "Use text-to-speech to read today's appointments", nullptr));
#endif // QT_CONFIG(tooltip)
        readTodaysAppointmentsButton->setText(QCoreApplication::translate("appointment", "Read Today's Appointments", nullptr));
#if QT_CONFIG(tooltip)
        statisticButton->setToolTip(QCoreApplication::translate("appointment", "View appointment statistics", nullptr));
#endif // QT_CONFIG(tooltip)
        statisticButton->setText(QCoreApplication::translate("appointment", "Statistics", nullptr));
#if QT_CONFIG(tooltip)
        speechSettingsButton->setToolTip(QCoreApplication::translate("appointment", "Configure text-to-speech settings", nullptr));
#endif // QT_CONFIG(tooltip)
        speechSettingsButton->setText(QCoreApplication::translate("appointment", "Speech Settings", nullptr));
        mainContentTabWidget->setTabText(mainContentTabWidget->indexOf(tab_Appointments), QCoreApplication::translate("appointment", "Appointments", nullptr));
        search->setPlaceholderText(QCoreApplication::translate("appointment", "Search appointments (e.g., by Patient CIN, Objective, Notes)...", nullptr));
        groupBox_AppointmentDetails->setTitle(QCoreApplication::translate("appointment", "Appointment Details", nullptr));
        noteEdit->setPlaceholderText(QCoreApplication::translate("appointment", "Enter additional notes (optional)", nullptr));
        idEdit->setPlaceholderText(QCoreApplication::translate("appointment", "Enter Appointment ID (if updating)", nullptr));
        objectifEdit->setItemText(0, QCoreApplication::translate("appointment", "Treatment", nullptr));
        objectifEdit->setItemText(1, QCoreApplication::translate("appointment", "Vaccination ", nullptr));
        objectifEdit->setItemText(2, QCoreApplication::translate("appointment", "Consultation ", nullptr));

        Automangmentlabel->setText(QCoreApplication::translate("appointment", "Auto Appointment Managment", nullptr));
        manuel_managment->setText(QCoreApplication::translate("appointment", "Manuel Appointment Managment", nullptr));
        statusCombo->setItemText(0, QCoreApplication::translate("appointment", "Scheduled", nullptr));
        statusCombo->setItemText(1, QCoreApplication::translate("appointment", "Completed", nullptr));
        statusCombo->setItemText(2, QCoreApplication::translate("appointment", "Cancelled", nullptr));
        statusCombo->setItemText(3, QCoreApplication::translate("appointment", "Postponed", nullptr));

        ideEdit->setPlaceholderText(QCoreApplication::translate("appointment", "Enter Employee ID", nullptr));
        ideLabel->setText(QCoreApplication::translate("appointment", "Employee ID:", nullptr));
        statusLabel->setText(QCoreApplication::translate("appointment", "Status:", nullptr));
        dateLabel->setText(QCoreApplication::translate("appointment", "Date:", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_clear->setToolTip(QCoreApplication::translate("appointment", "Update the selected appointment using the Appointment ID", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_clear->setText(QCoreApplication::translate("appointment", "CLEAR", nullptr));
        auto_appointment->setText(QCoreApplication::translate("appointment", "ADD APPOINTMENT AUTOMATICALLY", nullptr));
        idLabel->setText(QCoreApplication::translate("appointment", "Patient CIN:", nullptr));
        objectiveLabel->setText(QCoreApplication::translate("appointment", "Objective:", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_add->setToolTip(QCoreApplication::translate("appointment", "Add a new appointment with the details above", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_add->setText(QCoreApplication::translate("appointment", "ADD", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_update->setToolTip(QCoreApplication::translate("appointment", "Update the selected appointment using the Appointment ID", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_update->setText(QCoreApplication::translate("appointment", "UPDATE", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_delete->setToolTip(QCoreApplication::translate("appointment", "Delete the selected appointment", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_delete->setText(QCoreApplication::translate("appointment", "DELETE", nullptr));
        idaLabel->setText(QCoreApplication::translate("appointment", "Appointment ID:", nullptr));
        noteLabel->setText(QCoreApplication::translate("appointment", "Note:", nullptr));
        cinpEdit->setPlaceholderText(QCoreApplication::translate("appointment", "Enter Patient CIN", nullptr));
#if QT_CONFIG(tooltip)
        exportPdfButton->setToolTip(QCoreApplication::translate("appointment", "Export current view to PDF", nullptr));
#endif // QT_CONFIG(tooltip)
        exportPdfButton->setText(QCoreApplication::translate("appointment", "Export PDF", nullptr));
#if QT_CONFIG(tooltip)
        filterButton->setToolTip(QCoreApplication::translate("appointment", "Apply filters (e.g., date range, status)", nullptr));
#endif // QT_CONFIG(tooltip)
        filterButton->setText(QCoreApplication::translate("appointment", "Filter", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tab_CRUD->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("appointment", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tab_CRUD->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("appointment", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tab_CRUD->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("appointment", "Objective", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tab_CRUD->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("appointment", "Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tab_CRUD->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("appointment", "Note", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tab_CRUD->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("appointment", "Patient CIN", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tab_CRUD->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("appointment", "Employee ID", nullptr));
        mainContentTabWidget->setTabText(mainContentTabWidget->indexOf(tab_Management), QCoreApplication::translate("appointment", "Management", nullptr));
        dockWidget->setWindowTitle(QCoreApplication::translate("appointment", "Navigation", nullptr));
        sidebar_top_logo->setText(QString());
        label_3->setText(QString());
        pushButton->setText(QCoreApplication::translate("appointment", "Patient", nullptr));
        label_4->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("appointment", "MicroVac", nullptr));
        label_5->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("appointment", "Personnel", nullptr));
        label_6->setText(QString());
        pushButton_4->setText(QCoreApplication::translate("appointment", "Inventory", nullptr));
        label_8->setText(QString());
        pushButton_6->setText(QCoreApplication::translate("appointment", "Appointment", nullptr));
        label_7->setText(QString());
        pushButton_5->setText(QCoreApplication::translate("appointment", "Event", nullptr));
        label_AnalyticsIcon->setText(QString());
        pushButton_7->setText(QCoreApplication::translate("appointment", "Analytics", nullptr));
        label_9->setText(QString());
        pushButton_8->setText(QCoreApplication::translate("appointment", "Help/Support", nullptr));
    } // retranslateUi

};

namespace Ui {
    class appointment: public Ui_appointment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPOINTMENT_H
