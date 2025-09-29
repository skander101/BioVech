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

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *TabEvent;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Search_Button;
    QLineEdit *searchLineEdit;
    QComboBox *comboBox;
    QPushButton *pdf_Button;
    QPushButton *Suggestions_Button;
    QTableWidget *tableWidget;
    QWidget *AddEvent;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout;
    QLabel *label_id;
    QLineEdit *AlineEdit;
    QLabel *label_title;
    QLineEdit *AlineEdit_2;
    QLabel *label_title_2;
    QLineEdit *AlineEdit_3;
    QLabel *label_description;
    QPlainTextEdit *AlineEdit_4;
    QLabel *label_date;
    QDateEdit *AlineEdit_5;
    QLabel *label_type;
    QComboBox *AlineEdit_6;
    QLabel *label_location;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *AlineEdit_7;
    QPushButton *positionMapButton;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *Add_Event;
    QPushButton *Cancel_Add;
    QSpacerItem *horizontalSpacer_2;
    QWidget *ModifyEvent;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QFormLayout *formLayout_2;
    QLabel *label_12;
    QLineEdit *MlineEdit_1;
    QLabel *label_13;
    QLineEdit *MlineEdit_2;
    QLabel *label_14;
    QLineEdit *MlineEdit_3;
    QLabel *label_15;
    QPlainTextEdit *MlineEdit_4;
    QLabel *label_16;
    QDateEdit *MlineEdit_5;
    QLabel *label_17;
    QComboBox *MlineEdit_6;
    QLabel *label_18;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *MlineEdit_7;
    QPushButton *updatePositionMapButton;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *Modify_Event;
    QPushButton *Cancel_Modify;
    QSpacerItem *horizontalSpacer_4;
    QWidget *DeleteTabWidget;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_3;
    QFormLayout *formLayout_3;
    QLabel *label_2;
    QLineEdit *DlineEdit;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *Delete_Event;
    QPushButton *Cancel_Delete;
    QWidget *tab;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_19;
    QVBoxLayout *verticalLayout_8;
    QCalendarWidget *calendarWidget;
    QQuickWidget *quickWidget;
    QPushButton *Search_Button_2;
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

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1280, 845);
        MainWindow->setStyleSheet(QString::fromUtf8("/* Global Window Style */\n"
"   QMainWindow {\n"
"    border-image: url(\":/Static/Static/white_bg.jpg\");\n"
"    background-size: contain;\n"
"   }\n"
"\n"
"   /* Header Logo */\n"
"   QLabel#biovec_logo {\n"
"       margin-left: 25px;\n"
"       min-width: 50px;\n"
"       max-width: 250px;\n"
"       min-height: 80px;\n"
"       max-height: 80px;\n"
"       qproperty-alignment: AlignCenter;\n"
"       background-color: transparent;\n"
"       image: url(:/Static/Static/logo.png);\n"
"   }\n"
"\n"
"   /* Sidebar Dock Widget */\n"
"   QDockWidget {\n"
"       border: none;\n"
"       background-color: #ffffff;\n"
"   }\n"
"\n"
"   QDockWidget::title {\n"
"       background-color: #208c54;\n"
"       color: white;\n"
"       padding: 10px;\n"
"       font-weight: bold;\n"
"       border-radius: 5px;\n"
"       text-align: left;\n"
"   }\n"
"\n"
"   /* Sidebar Header Logo */\n"
"   QLabel#sidebar_top_logo {\n"
"       min-width: 50px;\n"
"       max-width: 250px;\n"
"       min-height:100px;\n"
"       max-he"
                        "ight: 150px;\n"
"       qproperty-alignment: 'AlignCenter';\n"
"       image: url(:/Static/Static/dashboard.png);\n"
"   }\n"
"\n"
"   /* Sidebar Button Styles - TEXT MADE LARGER */\n"
"   QDockWidget QPushButton {\n"
"       background-color: #208c54;\n"
"       color: #f6f8fa;\n"
"       padding: 18px 32px 18px 25px;\n"
"       text-align: left;\n"
"       border: none;\n"
"       border-radius: 0;\n"
"       font-size: 18px;\n"
"       font-weight: bold;\n"
"   }\n"
"\n"
"   QDockWidget QPushButton:hover {\n"
"       background-color: #27ae77;\n"
"   }\n"
"\n"
"   QDockWidget QPushButton:pressed {\n"
"       background-color: #27ae80;\n"
"   }\n"
"\n"
"   /* Sidebar Icon Styles - ICONS MADE LARGER */\n"
"   QDockWidget QLabel {\n"
"       min-width: 60px;\n"
"       min-height:60px;\n"
"       max-width: 60px;\n"
"       max-height: 60px;\n"
"       qproperty-alignment: 'AlignCenter';\n"
"       margin-left: 4px;\n"
"   }\n"
"\n"
"   /* GroupBox Styles - PADDING/MARGIN REDUCED */\n"
"   QGroupBox {\n"
"    "
                        "   border: 1px solid #2ecc71;\n"
"       border-radius: 8px;\n"
"       margin-top: 12px;\n"
"       font-weight: bold;\n"
"       background-color: #ffffff;\n"
"       padding: 4px;\n"
"   }\n"
"\n"
"   QGroupBox QPushButton {\n"
"       border-radius: 20px;\n"
"       font-weight: bold;\n"
"       padding: 10px 20px;\n"
"       min-height: 35px;\n"
"   }\n"
"\n"
"   QGroupBox QLineEdit {\n"
"       border-radius: 20px;\n"
"       padding: 8px 12px;\n"
"   }\n"
"\n"
"   QGroupBox::title {\n"
"       subcontrol-origin: margin;\n"
"       left: 10px;\n"
"       padding: 0 5px 0 5px;\n"
"       color: #27ae60;\n"
"       background-color: #ffffff;\n"
"       border-radius: 4px;\n"
"   }\n"
"\n"
"   /* Table Widget Styles */\n"
"   QTableWidget {\n"
"       border: 1px solid #2ecc71;\n"
"       border-radius: 8px;\n"
"       alternate-background-color: #f9f9f9;\n"
"       background-color: #ffffff;\n"
"       font-size: 15px;\n"
"       selection-behavior: SelectRows;\n"
"       selection-background-color: #AFE1A"
                        "F;\n"
"       selection-color: #000000;\n"
"       gridline-color: #e0e0e0;\n"
"   }\n"
"\n"
"   QTableWidget::item:selected {\n"
"       background-color: #27ae60;\n"
"       color: white;\n"
"   }\n"
"\n"
"   QHeaderView::section {\n"
"       background-color: #27ae60;\n"
"       color: white;\n"
"       padding: 10px;\n"
"       border: none;\n"
"       border-bottom: 1px solid #208c54;\n"
"       font-size: 16px;\n"
"       font-weight: bold;\n"
"   }\n"
"\n"
"   /* General Button Styles */\n"
"   QPushButton {\n"
"       background-color: #2ecc71;\n"
"       color: white;\n"
"       border-radius: 18px;\n"
"       padding: 10px 20px;\n"
"       font-weight: bold;\n"
"       font-size: 15px;\n"
"       min-height: 35px;\n"
"   }\n"
"\n"
"   QPushButton:hover {\n"
"       background-color: #27ae60;\n"
"   }\n"
"\n"
"   QPushButton:pressed {\n"
"       background-color: #1e8449;\n"
"   }\n"
"\n"
"   /* Specific Button Styles */\n"
"   QPushButton#pushButton_delete {\n"
"       background-color: #d8666c;\n"
""
                        "   }\n"
"\n"
"   QPushButton#pushButton_delete:hover {\n"
"       background-color: #d85057;\n"
"   }\n"
"\n"
"   QPushButton#pushButton_delete:pressed {\n"
"       background-color: #c04349;\n"
"   }\n"
"\n"
"   QPushButton#pushButton_clear {\n"
"       background-color: #66ffa4;\n"
"       color: #126032;\n"
"      border-radius: 18px;\n"
"       padding: 10px 20px;\n"
"       font-weight: bold;\n"
"       font-size: 15px;\n"
"       min-height: 35px;\n"
"   }\n"
"\n"
"   QPushButton#pushButton_clear:hover {\n"
"       background-color: #57dd8d;\n"
"   }\n"
"\n"
"   /* Input Field Styles */\n"
"   QLineEdit, QDateEdit, QComboBox, QDateTimeEdit {\n"
"       border: 1px solid #2ecc71;\n"
"       border-radius: 18px;\n"
"       padding: 8px 12px;\n"
"       background-color: #ffffff;\n"
"       font-size: 15px;\n"
"       min-height: 35px;\n"
"   }\n"
"\n"
"   QLineEdit#lineEdit_6,\n"
"   QLineEdit#lineEdit_4 {\n"
"       min-height: 100px;\n"
"       border-radius: 8px;\n"
"       qproperty-alignment: 'AlignLe"
                        "ft | AlignTop';\n"
"   }\n"
"\n"
"   QLineEdit#lineEdit_4 {\n"
"       background-color: #f8f9fa;\n"
"   }\n"
"\n"
"   /* Label Styles */\n"
"   QLabel {\n"
"       color: #2c3e50;\n"
"       font-size: 15px;\n"
"       background-color: transparent;\n"
"       padding: 2px;\n"
"   }\n"
"\n"
"   /* Main Tab Widget */\n"
"   QTabWidget::pane {\n"
"       border:1px solid #2ecc71;\n"
"       border-radius: 20px 20px 20px;\n"
"       border-top: none;\n"
"       background: white;\n"
"       padding: 10px;\n"
"   }\n"
"\n"
"   QTabBar::tab {\n"
"       background: #208c54;\n"
"       color: white;\n"
"       border: 0px solid #208c54;\n"
"       border-bottom: none;\n"
"       border-radius: 23px 23px 0 0;\n"
"       padding: 10px 20px;\n"
"       margin-right: 4px;\n"
"       font: bold 14pt \"Segoe UI\";\n"
"       min-width: 10px;\n"
"   }\n"
"\n"
"   QTabBar::tab:selected {\n"
"       background: #ffffff;\n"
"       color: #208c54;\n"
"       border-color: #2ecc71;\n"
"   }\n"
"\n"
"   QTabBar::tab:!selected:"
                        "hover {\n"
"       background: #1E8F53;\n"
"       color: white;\n"
"   }\n"
"\n"
"   QTabWidget::tab-bar {\n"
"       alignment: left;\n"
"       left: 5px;\n"
"   }\n"
"\n"
"   QCalendarWidget {\n"
"       background-color: #29aa63;\n"
"       color: #ffffff;\n"
"       font-family: \"Segoe UI\", \"Arial\", sans-serif;\n"
"       font-size: 16px;\n"
"       border: none;\n"
"       border-radius: 15px;\n"
"   }\n"
"\n"
"   QCalendarWidget QWidget#qt_calendar_navigationbar {\n"
"       background-color: #29aa63;\n"
"       border: none;\n"
"       border-top-left-radius: 15px;\n"
"       border-top-right-radius: 15px;\n"
"   }\n"
"\n"
"   QCalendarWidget QToolButton {\n"
"       color: #ffffff;\n"
"       background-color: transparent;\n"
"       border: none;\n"
"       padding: 8px 12px;\n"
"       border-radius: 8px;\n"
"       font-size: 18px;\n"
"   }\n"
"\n"
"   QCalendarWidget QToolButton:hover {\n"
"       background-color:#36d67e;\n"
"   }\n"
"\n"
"   QCalendarWidget QLabel {\n"
"       font-size: 18"
                        "px;\n"
"       font-weight: bold;\n"
"       color: #ffffff;\n"
"       border: none;\n"
"   }\n"
"\n"
"   QCalendarWidget QTableView {\n"
"       background-color: #1e8c54;\n"
"       border: none;\n"
"       border-radius: 0px;\n"
"       selection-background-color: rgba(255, 255, 255, 0.3);\n"
"       selection-color: #2c3e50;\n"
"       gridline-color: rgba(255, 255, 255, 50);\n"
"       font-weight: bold;\n"
"   }\n"
"\n"
"   QCalendarWidget QTableView::item {\n"
"       border: none;\n"
"       color: white;\n"
"       border-radius: 18px;\n"
"       padding: 5px;\n"
"       qproperty-alignment: AlignCenter;\n"
"   }\n"
"\n"
"   QCalendarWidget QTableView::item:selected {\n"
"       background-color: #81C784;\n"
"       color: white;\n"
"       border-radius: 18px;\n"
"       font-weight: bold;\n"
"   }\n"
"\n"
"   QCalendarWidget QTableView QHeaderView::section {\n"
"       background-color: transparent;\n"
"       color: #B2DFDB;\n"
"       font-size: 16px;\n"
"       font-weight: bold;\n"
"       bord"
                        "er: none;\n"
"       padding: 5px;\n"
"       qproperty-alignment: AlignCenter;\n"
"   }\n"
"\n"
"   QCalendarWidget QTableView::item[dayOfWeek=\"6\"],\n"
"   QCalendarWidget QTableView::item[dayOfWeek=\"7\"] {\n"
"       color: #000000;\n"
"       font-weight: bold;\n"
"   }\n"
"\n"
"   QCalendarWidget QTableView::disabled {\n"
"       color: #66BB6A;\n"
"       font-weight: normal;\n"
"   }\n"
"\n"
"   QCalendarWidget QAbstractItemView:focus {\n"
"       outline: none;\n"
"   }"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(3);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        TabEvent = new QWidget();
        TabEvent->setObjectName("TabEvent");
        verticalLayout = new QVBoxLayout(TabEvent);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        Search_Button = new QPushButton(TabEvent);
        Search_Button->setObjectName("Search_Button");

        horizontalLayout_2->addWidget(Search_Button);

        searchLineEdit = new QLineEdit(TabEvent);
        searchLineEdit->setObjectName("searchLineEdit");

        horizontalLayout_2->addWidget(searchLineEdit);

        comboBox = new QComboBox(TabEvent);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        horizontalLayout_2->addWidget(comboBox);

        pdf_Button = new QPushButton(TabEvent);
        pdf_Button->setObjectName("pdf_Button");

        horizontalLayout_2->addWidget(pdf_Button);

        Suggestions_Button = new QPushButton(TabEvent);
        Suggestions_Button->setObjectName("Suggestions_Button");

        horizontalLayout_2->addWidget(Suggestions_Button);


        verticalLayout->addLayout(horizontalLayout_2);

        tableWidget = new QTableWidget(TabEvent);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
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
        if (tableWidget->rowCount() < 10)
            tableWidget->setRowCount(10);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tableWidget->setRowCount(10);
        tableWidget->setColumnCount(6);

        verticalLayout->addWidget(tableWidget);

        tabWidget->addTab(TabEvent, QString());
        AddEvent = new QWidget();
        AddEvent->setObjectName("AddEvent");
        verticalLayout_2 = new QVBoxLayout(AddEvent);
        verticalLayout_2->setObjectName("verticalLayout_2");
        groupBox = new QGroupBox(AddEvent);
        groupBox->setObjectName("groupBox");
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName("verticalLayout_3");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_id = new QLabel(groupBox);
        label_id->setObjectName("label_id");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_id);

        AlineEdit = new QLineEdit(groupBox);
        AlineEdit->setObjectName("AlineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, AlineEdit);

        label_title = new QLabel(groupBox);
        label_title->setObjectName("label_title");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_title);

        AlineEdit_2 = new QLineEdit(groupBox);
        AlineEdit_2->setObjectName("AlineEdit_2");

        formLayout->setWidget(1, QFormLayout::FieldRole, AlineEdit_2);

        label_title_2 = new QLabel(groupBox);
        label_title_2->setObjectName("label_title_2");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_title_2);

        AlineEdit_3 = new QLineEdit(groupBox);
        AlineEdit_3->setObjectName("AlineEdit_3");

        formLayout->setWidget(2, QFormLayout::FieldRole, AlineEdit_3);

        label_description = new QLabel(groupBox);
        label_description->setObjectName("label_description");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_description);

        AlineEdit_4 = new QPlainTextEdit(groupBox);
        AlineEdit_4->setObjectName("AlineEdit_4");

        formLayout->setWidget(3, QFormLayout::FieldRole, AlineEdit_4);

        label_date = new QLabel(groupBox);
        label_date->setObjectName("label_date");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_date);

        AlineEdit_5 = new QDateEdit(groupBox);
        AlineEdit_5->setObjectName("AlineEdit_5");
        AlineEdit_5->setCalendarPopup(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, AlineEdit_5);

        label_type = new QLabel(groupBox);
        label_type->setObjectName("label_type");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_type);

        AlineEdit_6 = new QComboBox(groupBox);
        AlineEdit_6->addItem(QString());
        AlineEdit_6->addItem(QString());
        AlineEdit_6->addItem(QString());
        AlineEdit_6->addItem(QString());
        AlineEdit_6->setObjectName("AlineEdit_6");

        formLayout->setWidget(5, QFormLayout::FieldRole, AlineEdit_6);

        label_location = new QLabel(groupBox);
        label_location->setObjectName("label_location");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_location);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        AlineEdit_7 = new QLineEdit(groupBox);
        AlineEdit_7->setObjectName("AlineEdit_7");

        horizontalLayout_3->addWidget(AlineEdit_7);

        positionMapButton = new QPushButton(groupBox);
        positionMapButton->setObjectName("positionMapButton");

        horizontalLayout_3->addWidget(positionMapButton);


        formLayout->setLayout(6, QFormLayout::FieldRole, horizontalLayout_3);


        verticalLayout_3->addLayout(formLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        Add_Event = new QPushButton(groupBox);
        Add_Event->setObjectName("Add_Event");

        horizontalLayout_4->addWidget(Add_Event);

        Cancel_Add = new QPushButton(groupBox);
        Cancel_Add->setObjectName("Cancel_Add");

        horizontalLayout_4->addWidget(Cancel_Add);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout_2->addWidget(groupBox);

        tabWidget->addTab(AddEvent, QString());
        ModifyEvent = new QWidget();
        ModifyEvent->setObjectName("ModifyEvent");
        verticalLayout_4 = new QVBoxLayout(ModifyEvent);
        verticalLayout_4->setObjectName("verticalLayout_4");
        groupBox_2 = new QGroupBox(ModifyEvent);
        groupBox_2->setObjectName("groupBox_2");
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setObjectName("verticalLayout_5");
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName("label_12");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_12);

        MlineEdit_1 = new QLineEdit(groupBox_2);
        MlineEdit_1->setObjectName("MlineEdit_1");
        MlineEdit_1->setStyleSheet(QString::fromUtf8("background-color: #f0f0f0;"));
        MlineEdit_1->setReadOnly(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, MlineEdit_1);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName("label_13");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_13);

        MlineEdit_2 = new QLineEdit(groupBox_2);
        MlineEdit_2->setObjectName("MlineEdit_2");

        formLayout_2->setWidget(1, QFormLayout::FieldRole, MlineEdit_2);

        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName("label_14");

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_14);

        MlineEdit_3 = new QLineEdit(groupBox_2);
        MlineEdit_3->setObjectName("MlineEdit_3");

        formLayout_2->setWidget(2, QFormLayout::FieldRole, MlineEdit_3);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName("label_15");

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_15);

        MlineEdit_4 = new QPlainTextEdit(groupBox_2);
        MlineEdit_4->setObjectName("MlineEdit_4");

        formLayout_2->setWidget(3, QFormLayout::FieldRole, MlineEdit_4);

        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName("label_16");

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_16);

        MlineEdit_5 = new QDateEdit(groupBox_2);
        MlineEdit_5->setObjectName("MlineEdit_5");
        MlineEdit_5->setCalendarPopup(true);

        formLayout_2->setWidget(4, QFormLayout::FieldRole, MlineEdit_5);

        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName("label_17");

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_17);

        MlineEdit_6 = new QComboBox(groupBox_2);
        MlineEdit_6->addItem(QString());
        MlineEdit_6->addItem(QString());
        MlineEdit_6->addItem(QString());
        MlineEdit_6->addItem(QString());
        MlineEdit_6->setObjectName("MlineEdit_6");

        formLayout_2->setWidget(5, QFormLayout::FieldRole, MlineEdit_6);

        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName("label_18");

        formLayout_2->setWidget(6, QFormLayout::LabelRole, label_18);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        MlineEdit_7 = new QLineEdit(groupBox_2);
        MlineEdit_7->setObjectName("MlineEdit_7");

        horizontalLayout_5->addWidget(MlineEdit_7);

        updatePositionMapButton = new QPushButton(groupBox_2);
        updatePositionMapButton->setObjectName("updatePositionMapButton");

        horizontalLayout_5->addWidget(updatePositionMapButton);


        formLayout_2->setLayout(6, QFormLayout::FieldRole, horizontalLayout_5);


        verticalLayout_5->addLayout(formLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        Modify_Event = new QPushButton(groupBox_2);
        Modify_Event->setObjectName("Modify_Event");

        horizontalLayout_6->addWidget(Modify_Event);

        Cancel_Modify = new QPushButton(groupBox_2);
        Cancel_Modify->setObjectName("Cancel_Modify");

        horizontalLayout_6->addWidget(Cancel_Modify);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout_5->addLayout(horizontalLayout_6);


        verticalLayout_4->addWidget(groupBox_2);

        tabWidget->addTab(ModifyEvent, QString());
        DeleteTabWidget = new QWidget();
        DeleteTabWidget->setObjectName("DeleteTabWidget");
        verticalLayout_6 = new QVBoxLayout(DeleteTabWidget);
        verticalLayout_6->setObjectName("verticalLayout_6");
        groupBox_3 = new QGroupBox(DeleteTabWidget);
        groupBox_3->setObjectName("groupBox_3");
        formLayout_3 = new QFormLayout(groupBox_3);
        formLayout_3->setObjectName("formLayout_3");
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName("label_2");

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_2);

        DlineEdit = new QLineEdit(groupBox_3);
        DlineEdit->setObjectName("DlineEdit");

        formLayout_3->setWidget(0, QFormLayout::FieldRole, DlineEdit);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        Delete_Event = new QPushButton(groupBox_3);
        Delete_Event->setObjectName("Delete_Event");

        horizontalLayout_7->addWidget(Delete_Event);

        Cancel_Delete = new QPushButton(groupBox_3);
        Cancel_Delete->setObjectName("Cancel_Delete");

        horizontalLayout_7->addWidget(Cancel_Delete);


        formLayout_3->setLayout(1, QFormLayout::FieldRole, horizontalLayout_7);


        verticalLayout_6->addWidget(groupBox_3);

        tabWidget->addTab(DeleteTabWidget, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        verticalLayout_7 = new QVBoxLayout(tab);
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_19 = new QLabel(tab);
        label_19->setObjectName("label_19");
        label_19->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_7->addWidget(label_19);

        tabWidget->addTab(tab, QString());

        horizontalLayout->addWidget(tabWidget);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        calendarWidget = new QCalendarWidget(centralwidget);
        calendarWidget->setObjectName("calendarWidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(calendarWidget->sizePolicy().hasHeightForWidth());
        calendarWidget->setSizePolicy(sizePolicy1);
        calendarWidget->setMinimumSize(QSize(300, 200));
        calendarWidget->setMaximumSize(QSize(350, 250));

        verticalLayout_8->addWidget(calendarWidget);

        quickWidget = new QQuickWidget(centralwidget);
        quickWidget->setObjectName("quickWidget");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(quickWidget->sizePolicy().hasHeightForWidth());
        quickWidget->setSizePolicy(sizePolicy2);
        quickWidget->setMinimumSize(QSize(300, 250));
        quickWidget->setMaximumSize(QSize(350, 16777215));
        quickWidget->setResizeMode(QQuickWidget::ResizeMode::SizeRootObjectToView);

        verticalLayout_8->addWidget(quickWidget);

        Search_Button_2 = new QPushButton(centralwidget);
        Search_Button_2->setObjectName("Search_Button_2");

        verticalLayout_8->addWidget(Search_Button_2);


        horizontalLayout->addLayout(verticalLayout_8);

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
        MainWindow->addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, dockWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Event Management System", nullptr));
        Search_Button->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        searchLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search events...", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Sort: (None)", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Date (Ascending)", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Date (Descending)", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Type (A-Z)", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Type (Z-A)", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Title (A-Z)", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "Title (Z-A)", nullptr));

        pdf_Button->setText(QCoreApplication::translate("MainWindow", "Export PDF", nullptr));
        Suggestions_Button->setText(QCoreApplication::translate("MainWindow", "Nearby Events", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Title", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Sponsor", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Actions", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(TabEvent), QCoreApplication::translate("MainWindow", "Event List", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Add New Event", nullptr));
        label_id->setText(QCoreApplication::translate("MainWindow", "ID:", nullptr));
        label_title->setText(QCoreApplication::translate("MainWindow", "Title:", nullptr));
        label_title_2->setText(QCoreApplication::translate("MainWindow", "Sponsor:", nullptr));
        label_description->setText(QCoreApplication::translate("MainWindow", "Description:", nullptr));
        label_date->setText(QCoreApplication::translate("MainWindow", "Date:", nullptr));
        label_type->setText(QCoreApplication::translate("MainWindow", "Type:", nullptr));
        AlineEdit_6->setItemText(0, QCoreApplication::translate("MainWindow", "Charity", nullptr));
        AlineEdit_6->setItemText(1, QCoreApplication::translate("MainWindow", "Summit", nullptr));
        AlineEdit_6->setItemText(2, QCoreApplication::translate("MainWindow", "Q&A", nullptr));
        AlineEdit_6->setItemText(3, QCoreApplication::translate("MainWindow", "Vaccination", nullptr));

        label_location->setText(QCoreApplication::translate("MainWindow", "Location:", nullptr));
        positionMapButton->setText(QCoreApplication::translate("MainWindow", "\360\237\223\215 Select on Map", nullptr));
        Add_Event->setText(QCoreApplication::translate("MainWindow", "Add Event", nullptr));
        Cancel_Add->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(AddEvent), QCoreApplication::translate("MainWindow", "Add Event", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Modify Event", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "ID:", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Title:", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Sponsor:", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Description:", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Date:", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Type:", nullptr));
        MlineEdit_6->setItemText(0, QCoreApplication::translate("MainWindow", "Charity", nullptr));
        MlineEdit_6->setItemText(1, QCoreApplication::translate("MainWindow", "Vaccination", nullptr));
        MlineEdit_6->setItemText(2, QCoreApplication::translate("MainWindow", "Summit", nullptr));
        MlineEdit_6->setItemText(3, QCoreApplication::translate("MainWindow", "Q&A", nullptr));

        label_18->setText(QCoreApplication::translate("MainWindow", "Location:", nullptr));
        updatePositionMapButton->setText(QCoreApplication::translate("MainWindow", "\360\237\223\215 Select on Map", nullptr));
        Modify_Event->setText(QCoreApplication::translate("MainWindow", "Update Event", nullptr));
        Cancel_Modify->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ModifyEvent), QCoreApplication::translate("MainWindow", "Update Event", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Delete Event", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Event ID:", nullptr));
        Delete_Event->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        Cancel_Delete->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(DeleteTabWidget), QCoreApplication::translate("MainWindow", "Delete Event", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Event Statistics", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        Search_Button_2->setText(QCoreApplication::translate("MainWindow", "Find Events", nullptr));
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

#endif // UI_MAINWINDOW_H
