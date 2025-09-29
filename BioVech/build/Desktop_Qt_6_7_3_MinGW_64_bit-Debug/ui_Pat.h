/********************************************************************************
** Form generated from reading UI file 'Pat.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAT_H
#define UI_PAT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Pat
{
public:
    QAction *actionNouveau_Patient;
    QAction *actionExporter;
    QAction *actionQuitter;
    QAction *actionAide;
    QAction *actionA_propos;
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QLabel *biovec_logo;
    QDockWidget *dockWidget_Sidebar;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *sidebarVerticalLayout;
    QLabel *sidebar_top_logo;
    QVBoxLayout *buttonsVerticalLayout;
    QHBoxLayout *patientLayout;
    QLabel *patient_icon;
    QPushButton *patientButton;
    QHBoxLayout *microvacLayout;
    QLabel *microvac_icon;
    QPushButton *microvacButton;
    QHBoxLayout *personnelLayout;
    QLabel *personnel_icon;
    QPushButton *personnelButton;
    QHBoxLayout *inventoryLayout;
    QLabel *inventory_icon;
    QPushButton *inventoryButton;
    QHBoxLayout *appointmentLayout;
    QLabel *appointment_icon;
    QPushButton *appointmentButton;
    QHBoxLayout *eventLayout;
    QLabel *event_icon;
    QPushButton *eventButton;
    QHBoxLayout *analyticsLayout;
    QLabel *analytics_icon;
    QPushButton *analyticsButton;
    QHBoxLayout *helpLayout;
    QLabel *help_icon;
    QPushButton *helpButton;
    QTabWidget *tabWidget;
    QWidget *tab_registration;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_patient;
    QGridLayout *gridLayout;
    QLabel *label_cin;
    QLineEdit *lineEdit_cin;
    QLabel *label_dob;
    QDateEdit *dateEdit_dob;
    QLabel *label_nom;
    QLineEdit *lineEdit_nom;
    QLabel *label_registration;
    QDateEdit *dateEdit_inscription;
    QLabel *label_prenom;
    QLineEdit *lineEdit_prenom;
    QLabel *label_sexe;
    QComboBox *comboBox_sexe;
    QLabel *label_tel;
    QHBoxLayout *horizontalLayout_tel;
    QComboBox *comboBox_country_code;
    QLineEdit *lineEdit_tel;
    QLabel *label_email;
    QLineEdit *lineEdit_email;
    QLabel *label_medical_history;
    QLineEdit *lineEdit_medical_file;
    QPushButton *pushButton_browse;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_save;
    QPushButton *pushButton_clear;
    QSpacerItem *verticalSpacer;
    QWidget *tab_list;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_search;
    QPushButton *pushButton_search;
    QLabel *label_sort;
    QComboBox *comboBox_sort;
    QPushButton *pushButton_sort;
    QTableWidget *tableWidget_patients;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_add;
    QPushButton *pushButton_edit;
    QPushButton *pushButton_delete;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_export;
    QWidget *tab_medical_history;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEdit_search_medical;
    QPushButton *pushButton_search_medical;
    QSplitter *splitter;
    QTableWidget *tableWidget_medical_patients;
    QWidget *widget;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_medical_details;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_patient_name;
    QTextEdit *textEdit_json_viewer;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_update_medical;
    QPushButton *pushButton_import_medical;
    QPushButton *pushButton_export_medical;
    QWidget *tab_statistics_new;
    QVBoxLayout *verticalLayout_statistics_new;
    QLabel *label_placeholder_stats;
    QWidget *tab_prediction_new;
    QVBoxLayout *verticalLayout_pred_new;
    QLabel *label_pred_title_new;
    QPushButton *pushButton_predict_new;
    QSpacerItem *verticalSpacer_pred_new;
    QWidget *tab_assistant_new;
    QVBoxLayout *verticalLayout_assistant_new;
    QLabel *label_placeholder_assistant;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Pat)
    {
        if (Pat->objectName().isEmpty())
            Pat->setObjectName("Pat");
        Pat->resize(1185, 908);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Pat->sizePolicy().hasHeightForWidth());
        Pat->setSizePolicy(sizePolicy);
        Pat->setStyleSheet(QString::fromUtf8("/* Global Window Style */\n"
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
        actionNouveau_Patient = new QAction(Pat);
        actionNouveau_Patient->setObjectName("actionNouveau_Patient");
        actionExporter = new QAction(Pat);
        actionExporter->setObjectName("actionExporter");
        actionQuitter = new QAction(Pat);
        actionQuitter->setObjectName("actionQuitter");
        actionAide = new QAction(Pat);
        actionAide->setObjectName("actionAide");
        actionA_propos = new QAction(Pat);
        actionA_propos->setObjectName("actionA_propos");
        centralwidget = new QWidget(Pat);
        centralwidget->setObjectName("centralwidget");
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName("gridLayout_3");
        biovec_logo = new QLabel(centralwidget);
        biovec_logo->setObjectName("biovec_logo");

        gridLayout_3->addWidget(biovec_logo, 1, 2, 1, 1);

        dockWidget_Sidebar = new QDockWidget(centralwidget);
        dockWidget_Sidebar->setObjectName("dockWidget_Sidebar");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dockWidget_Sidebar->sizePolicy().hasHeightForWidth());
        dockWidget_Sidebar->setSizePolicy(sizePolicy1);
        dockWidget_Sidebar->setFeatures(QDockWidget::DockWidgetFeature::NoDockWidgetFeatures);
        dockWidget_Sidebar->setAllowedAreas(Qt::DockWidgetArea::LeftDockWidgetArea);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName("dockWidgetContents_2");
        sidebarVerticalLayout = new QVBoxLayout(dockWidgetContents_2);
        sidebarVerticalLayout->setSpacing(15);
        sidebarVerticalLayout->setObjectName("sidebarVerticalLayout");
        sidebarVerticalLayout->setContentsMargins(0, 10, 0, 10);
        sidebar_top_logo = new QLabel(dockWidgetContents_2);
        sidebar_top_logo->setObjectName("sidebar_top_logo");
        sidebar_top_logo->setStyleSheet(QString::fromUtf8("image:url(:/Static/Static/dashboard.png);"));

        sidebarVerticalLayout->addWidget(sidebar_top_logo);

        buttonsVerticalLayout = new QVBoxLayout();
        buttonsVerticalLayout->setSpacing(5);
        buttonsVerticalLayout->setObjectName("buttonsVerticalLayout");
        patientLayout = new QHBoxLayout();
        patientLayout->setObjectName("patientLayout");
        patient_icon = new QLabel(dockWidgetContents_2);
        patient_icon->setObjectName("patient_icon");
        patient_icon->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/1.png);"));

        patientLayout->addWidget(patient_icon);

        patientButton = new QPushButton(dockWidgetContents_2);
        patientButton->setObjectName("patientButton");

        patientLayout->addWidget(patientButton);


        buttonsVerticalLayout->addLayout(patientLayout);

        microvacLayout = new QHBoxLayout();
        microvacLayout->setObjectName("microvacLayout");
        microvac_icon = new QLabel(dockWidgetContents_2);
        microvac_icon->setObjectName("microvac_icon");
        microvac_icon->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/2.png);"));

        microvacLayout->addWidget(microvac_icon);

        microvacButton = new QPushButton(dockWidgetContents_2);
        microvacButton->setObjectName("microvacButton");

        microvacLayout->addWidget(microvacButton);


        buttonsVerticalLayout->addLayout(microvacLayout);

        personnelLayout = new QHBoxLayout();
        personnelLayout->setObjectName("personnelLayout");
        personnel_icon = new QLabel(dockWidgetContents_2);
        personnel_icon->setObjectName("personnel_icon");
        personnel_icon->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/3.png);"));

        personnelLayout->addWidget(personnel_icon);

        personnelButton = new QPushButton(dockWidgetContents_2);
        personnelButton->setObjectName("personnelButton");

        personnelLayout->addWidget(personnelButton);


        buttonsVerticalLayout->addLayout(personnelLayout);

        inventoryLayout = new QHBoxLayout();
        inventoryLayout->setObjectName("inventoryLayout");
        inventory_icon = new QLabel(dockWidgetContents_2);
        inventory_icon->setObjectName("inventory_icon");
        inventory_icon->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/4.png);"));

        inventoryLayout->addWidget(inventory_icon);

        inventoryButton = new QPushButton(dockWidgetContents_2);
        inventoryButton->setObjectName("inventoryButton");

        inventoryLayout->addWidget(inventoryButton);


        buttonsVerticalLayout->addLayout(inventoryLayout);

        appointmentLayout = new QHBoxLayout();
        appointmentLayout->setObjectName("appointmentLayout");
        appointment_icon = new QLabel(dockWidgetContents_2);
        appointment_icon->setObjectName("appointment_icon");
        appointment_icon->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/5.png);"));

        appointmentLayout->addWidget(appointment_icon);

        appointmentButton = new QPushButton(dockWidgetContents_2);
        appointmentButton->setObjectName("appointmentButton");

        appointmentLayout->addWidget(appointmentButton);


        buttonsVerticalLayout->addLayout(appointmentLayout);

        eventLayout = new QHBoxLayout();
        eventLayout->setObjectName("eventLayout");
        event_icon = new QLabel(dockWidgetContents_2);
        event_icon->setObjectName("event_icon");
        event_icon->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/6.png);"));

        eventLayout->addWidget(event_icon);

        eventButton = new QPushButton(dockWidgetContents_2);
        eventButton->setObjectName("eventButton");

        eventLayout->addWidget(eventButton);


        buttonsVerticalLayout->addLayout(eventLayout);

        analyticsLayout = new QHBoxLayout();
        analyticsLayout->setObjectName("analyticsLayout");
        analytics_icon = new QLabel(dockWidgetContents_2);
        analytics_icon->setObjectName("analytics_icon");
        analytics_icon->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/7.png);"));

        analyticsLayout->addWidget(analytics_icon);

        analyticsButton = new QPushButton(dockWidgetContents_2);
        analyticsButton->setObjectName("analyticsButton");

        analyticsLayout->addWidget(analyticsButton);


        buttonsVerticalLayout->addLayout(analyticsLayout);

        helpLayout = new QHBoxLayout();
        helpLayout->setObjectName("helpLayout");
        help_icon = new QLabel(dockWidgetContents_2);
        help_icon->setObjectName("help_icon");
        help_icon->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/8.png);"));

        helpLayout->addWidget(help_icon);

        helpButton = new QPushButton(dockWidgetContents_2);
        helpButton->setObjectName("helpButton");

        helpLayout->addWidget(helpButton);


        buttonsVerticalLayout->addLayout(helpLayout);


        sidebarVerticalLayout->addLayout(buttonsVerticalLayout);

        dockWidget_Sidebar->setWidget(dockWidgetContents_2);

        gridLayout_3->addWidget(dockWidget_Sidebar, 1, 1, 2, 1);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        tab_registration = new QWidget();
        tab_registration->setObjectName("tab_registration");
        verticalLayout_2 = new QVBoxLayout(tab_registration);
        verticalLayout_2->setObjectName("verticalLayout_2");
        groupBox_patient = new QGroupBox(tab_registration);
        groupBox_patient->setObjectName("groupBox_patient");
        gridLayout = new QGridLayout(groupBox_patient);
        gridLayout->setObjectName("gridLayout");
        label_cin = new QLabel(groupBox_patient);
        label_cin->setObjectName("label_cin");

        gridLayout->addWidget(label_cin, 0, 0, 1, 1);

        lineEdit_cin = new QLineEdit(groupBox_patient);
        lineEdit_cin->setObjectName("lineEdit_cin");

        gridLayout->addWidget(lineEdit_cin, 0, 1, 1, 1);

        label_dob = new QLabel(groupBox_patient);
        label_dob->setObjectName("label_dob");

        gridLayout->addWidget(label_dob, 0, 2, 1, 1);

        dateEdit_dob = new QDateEdit(groupBox_patient);
        dateEdit_dob->setObjectName("dateEdit_dob");
        dateEdit_dob->setCalendarPopup(true);

        gridLayout->addWidget(dateEdit_dob, 0, 3, 1, 1);

        label_nom = new QLabel(groupBox_patient);
        label_nom->setObjectName("label_nom");

        gridLayout->addWidget(label_nom, 1, 0, 1, 1);

        lineEdit_nom = new QLineEdit(groupBox_patient);
        lineEdit_nom->setObjectName("lineEdit_nom");

        gridLayout->addWidget(lineEdit_nom, 1, 1, 1, 1);

        label_registration = new QLabel(groupBox_patient);
        label_registration->setObjectName("label_registration");

        gridLayout->addWidget(label_registration, 1, 2, 1, 1);

        dateEdit_inscription = new QDateEdit(groupBox_patient);
        dateEdit_inscription->setObjectName("dateEdit_inscription");
        dateEdit_inscription->setCalendarPopup(true);

        gridLayout->addWidget(dateEdit_inscription, 1, 3, 1, 1);

        label_prenom = new QLabel(groupBox_patient);
        label_prenom->setObjectName("label_prenom");

        gridLayout->addWidget(label_prenom, 2, 0, 1, 1);

        lineEdit_prenom = new QLineEdit(groupBox_patient);
        lineEdit_prenom->setObjectName("lineEdit_prenom");

        gridLayout->addWidget(lineEdit_prenom, 2, 1, 1, 1);

        label_sexe = new QLabel(groupBox_patient);
        label_sexe->setObjectName("label_sexe");

        gridLayout->addWidget(label_sexe, 2, 2, 1, 1);

        comboBox_sexe = new QComboBox(groupBox_patient);
        comboBox_sexe->addItem(QString());
        comboBox_sexe->addItem(QString());
        comboBox_sexe->setObjectName("comboBox_sexe");

        gridLayout->addWidget(comboBox_sexe, 2, 3, 1, 1);

        label_tel = new QLabel(groupBox_patient);
        label_tel->setObjectName("label_tel");

        gridLayout->addWidget(label_tel, 3, 0, 1, 1);

        horizontalLayout_tel = new QHBoxLayout();
        horizontalLayout_tel->setObjectName("horizontalLayout_tel");
        comboBox_country_code = new QComboBox(groupBox_patient);
        comboBox_country_code->addItem(QString());
        comboBox_country_code->addItem(QString());
        comboBox_country_code->addItem(QString());
        comboBox_country_code->addItem(QString());
        comboBox_country_code->addItem(QString());
        comboBox_country_code->addItem(QString());
        comboBox_country_code->setObjectName("comboBox_country_code");
        comboBox_country_code->setMaximumSize(QSize(110, 16777215));

        horizontalLayout_tel->addWidget(comboBox_country_code);

        lineEdit_tel = new QLineEdit(groupBox_patient);
        lineEdit_tel->setObjectName("lineEdit_tel");

        horizontalLayout_tel->addWidget(lineEdit_tel);


        gridLayout->addLayout(horizontalLayout_tel, 3, 1, 1, 3);

        label_email = new QLabel(groupBox_patient);
        label_email->setObjectName("label_email");

        gridLayout->addWidget(label_email, 4, 0, 1, 1);

        lineEdit_email = new QLineEdit(groupBox_patient);
        lineEdit_email->setObjectName("lineEdit_email");

        gridLayout->addWidget(lineEdit_email, 4, 1, 1, 3);

        label_medical_history = new QLabel(groupBox_patient);
        label_medical_history->setObjectName("label_medical_history");

        gridLayout->addWidget(label_medical_history, 5, 0, 1, 1);

        lineEdit_medical_file = new QLineEdit(groupBox_patient);
        lineEdit_medical_file->setObjectName("lineEdit_medical_file");
        lineEdit_medical_file->setReadOnly(true);

        gridLayout->addWidget(lineEdit_medical_file, 5, 1, 1, 1);

        pushButton_browse = new QPushButton(groupBox_patient);
        pushButton_browse->setObjectName("pushButton_browse");

        gridLayout->addWidget(pushButton_browse, 5, 2, 1, 2);


        verticalLayout_2->addWidget(groupBox_patient);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_save = new QPushButton(tab_registration);
        pushButton_save->setObjectName("pushButton_save");
        pushButton_save->setMinimumSize(QSize(120, 55));

        horizontalLayout_2->addWidget(pushButton_save);

        pushButton_clear = new QPushButton(tab_registration);
        pushButton_clear->setObjectName("pushButton_clear");
        pushButton_clear->setMinimumSize(QSize(120, 55));

        horizontalLayout_2->addWidget(pushButton_clear);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        tabWidget->addTab(tab_registration, QString());
        tab_list = new QWidget();
        tab_list->setObjectName("tab_list");
        verticalLayout_4 = new QVBoxLayout(tab_list);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        lineEdit_search = new QLineEdit(tab_list);
        lineEdit_search->setObjectName("lineEdit_search");

        horizontalLayout_3->addWidget(lineEdit_search);

        pushButton_search = new QPushButton(tab_list);
        pushButton_search->setObjectName("pushButton_search");

        horizontalLayout_3->addWidget(pushButton_search);

        label_sort = new QLabel(tab_list);
        label_sort->setObjectName("label_sort");

        horizontalLayout_3->addWidget(label_sort);

        comboBox_sort = new QComboBox(tab_list);
        comboBox_sort->addItem(QString());
        comboBox_sort->addItem(QString());
        comboBox_sort->addItem(QString());
        comboBox_sort->setObjectName("comboBox_sort");

        horizontalLayout_3->addWidget(comboBox_sort);

        pushButton_sort = new QPushButton(tab_list);
        pushButton_sort->setObjectName("pushButton_sort");

        horizontalLayout_3->addWidget(pushButton_sort);


        verticalLayout_4->addLayout(horizontalLayout_3);

        tableWidget_patients = new QTableWidget(tab_list);
        if (tableWidget_patients->columnCount() < 9)
            tableWidget_patients->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_patients->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_patients->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_patients->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_patients->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_patients->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_patients->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_patients->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_patients->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_patients->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        tableWidget_patients->setObjectName("tableWidget_patients");
        tableWidget_patients->setSortingEnabled(true);

        verticalLayout_4->addWidget(tableWidget_patients);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        pushButton_add = new QPushButton(tab_list);
        pushButton_add->setObjectName("pushButton_add");

        horizontalLayout_4->addWidget(pushButton_add);

        pushButton_edit = new QPushButton(tab_list);
        pushButton_edit->setObjectName("pushButton_edit");

        horizontalLayout_4->addWidget(pushButton_edit);

        pushButton_delete = new QPushButton(tab_list);
        pushButton_delete->setObjectName("pushButton_delete");

        horizontalLayout_4->addWidget(pushButton_delete);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        pushButton_export = new QPushButton(tab_list);
        pushButton_export->setObjectName("pushButton_export");

        horizontalLayout_4->addWidget(pushButton_export);


        verticalLayout_4->addLayout(horizontalLayout_4);

        tabWidget->addTab(tab_list, QString());
        tab_medical_history = new QWidget();
        tab_medical_history->setObjectName("tab_medical_history");
        verticalLayout_5 = new QVBoxLayout(tab_medical_history);
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        lineEdit_search_medical = new QLineEdit(tab_medical_history);
        lineEdit_search_medical->setObjectName("lineEdit_search_medical");

        horizontalLayout_5->addWidget(lineEdit_search_medical);

        pushButton_search_medical = new QPushButton(tab_medical_history);
        pushButton_search_medical->setObjectName("pushButton_search_medical");

        horizontalLayout_5->addWidget(pushButton_search_medical);


        verticalLayout_5->addLayout(horizontalLayout_5);

        splitter = new QSplitter(tab_medical_history);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Orientation::Horizontal);
        tableWidget_medical_patients = new QTableWidget(splitter);
        if (tableWidget_medical_patients->columnCount() < 4)
            tableWidget_medical_patients->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_medical_patients->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_medical_patients->setHorizontalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_medical_patients->setHorizontalHeaderItem(2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_medical_patients->setHorizontalHeaderItem(3, __qtablewidgetitem12);
        tableWidget_medical_patients->setObjectName("tableWidget_medical_patients");
        tableWidget_medical_patients->setSortingEnabled(true);
        splitter->addWidget(tableWidget_medical_patients);
        widget = new QWidget(splitter);
        widget->setObjectName("widget");
        verticalLayout_6 = new QVBoxLayout(widget);
        verticalLayout_6->setObjectName("verticalLayout_6");
        groupBox_medical_details = new QGroupBox(widget);
        groupBox_medical_details->setObjectName("groupBox_medical_details");
        verticalLayout_7 = new QVBoxLayout(groupBox_medical_details);
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_patient_name = new QLabel(groupBox_medical_details);
        label_patient_name->setObjectName("label_patient_name");
        QFont font;
        font.setBold(true);
        label_patient_name->setFont(font);

        verticalLayout_7->addWidget(label_patient_name);

        textEdit_json_viewer = new QTextEdit(groupBox_medical_details);
        textEdit_json_viewer->setObjectName("textEdit_json_viewer");
        textEdit_json_viewer->setReadOnly(true);

        verticalLayout_7->addWidget(textEdit_json_viewer);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        pushButton_update_medical = new QPushButton(groupBox_medical_details);
        pushButton_update_medical->setObjectName("pushButton_update_medical");

        horizontalLayout_6->addWidget(pushButton_update_medical);

        pushButton_import_medical = new QPushButton(groupBox_medical_details);
        pushButton_import_medical->setObjectName("pushButton_import_medical");

        horizontalLayout_6->addWidget(pushButton_import_medical);

        pushButton_export_medical = new QPushButton(groupBox_medical_details);
        pushButton_export_medical->setObjectName("pushButton_export_medical");

        horizontalLayout_6->addWidget(pushButton_export_medical);


        verticalLayout_7->addLayout(horizontalLayout_6);


        verticalLayout_6->addWidget(groupBox_medical_details);

        splitter->addWidget(widget);

        verticalLayout_5->addWidget(splitter);

        tabWidget->addTab(tab_medical_history, QString());
        tab_statistics_new = new QWidget();
        tab_statistics_new->setObjectName("tab_statistics_new");
        verticalLayout_statistics_new = new QVBoxLayout(tab_statistics_new);
        verticalLayout_statistics_new->setObjectName("verticalLayout_statistics_new");
        label_placeholder_stats = new QLabel(tab_statistics_new);
        label_placeholder_stats->setObjectName("label_placeholder_stats");
        label_placeholder_stats->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_statistics_new->addWidget(label_placeholder_stats);

        tabWidget->addTab(tab_statistics_new, QString());
        tab_prediction_new = new QWidget();
        tab_prediction_new->setObjectName("tab_prediction_new");
        verticalLayout_pred_new = new QVBoxLayout(tab_prediction_new);
        verticalLayout_pred_new->setObjectName("verticalLayout_pred_new");
        label_pred_title_new = new QLabel(tab_prediction_new);
        label_pred_title_new->setObjectName("label_pred_title_new");
        label_pred_title_new->setFont(font);
        label_pred_title_new->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_pred_new->addWidget(label_pred_title_new);

        pushButton_predict_new = new QPushButton(tab_prediction_new);
        pushButton_predict_new->setObjectName("pushButton_predict_new");

        verticalLayout_pred_new->addWidget(pushButton_predict_new);

        verticalSpacer_pred_new = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_pred_new->addItem(verticalSpacer_pred_new);

        tabWidget->addTab(tab_prediction_new, QString());
        tab_assistant_new = new QWidget();
        tab_assistant_new->setObjectName("tab_assistant_new");
        verticalLayout_assistant_new = new QVBoxLayout(tab_assistant_new);
        verticalLayout_assistant_new->setObjectName("verticalLayout_assistant_new");
        label_placeholder_assistant = new QLabel(tab_assistant_new);
        label_placeholder_assistant->setObjectName("label_placeholder_assistant");
        label_placeholder_assistant->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_assistant_new->addWidget(label_placeholder_assistant);

        tabWidget->addTab(tab_assistant_new, QString());

        gridLayout_3->addWidget(tabWidget, 2, 2, 1, 1);

        Pat->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Pat);
        statusbar->setObjectName("statusbar");
        Pat->setStatusBar(statusbar);
        QWidget::setTabOrder(patientButton, microvacButton);
        QWidget::setTabOrder(microvacButton, personnelButton);
        QWidget::setTabOrder(personnelButton, inventoryButton);
        QWidget::setTabOrder(inventoryButton, appointmentButton);
        QWidget::setTabOrder(appointmentButton, eventButton);
        QWidget::setTabOrder(eventButton, analyticsButton);
        QWidget::setTabOrder(analyticsButton, helpButton);
        QWidget::setTabOrder(helpButton, tabWidget);
        QWidget::setTabOrder(tabWidget, lineEdit_cin);
        QWidget::setTabOrder(lineEdit_cin, dateEdit_dob);
        QWidget::setTabOrder(dateEdit_dob, lineEdit_nom);
        QWidget::setTabOrder(lineEdit_nom, dateEdit_inscription);
        QWidget::setTabOrder(dateEdit_inscription, lineEdit_prenom);
        QWidget::setTabOrder(lineEdit_prenom, comboBox_sexe);
        QWidget::setTabOrder(comboBox_sexe, comboBox_country_code);
        QWidget::setTabOrder(comboBox_country_code, lineEdit_tel);
        QWidget::setTabOrder(lineEdit_tel, lineEdit_email);
        QWidget::setTabOrder(lineEdit_email, lineEdit_medical_file);
        QWidget::setTabOrder(lineEdit_medical_file, pushButton_browse);
        QWidget::setTabOrder(pushButton_browse, pushButton_save);
        QWidget::setTabOrder(pushButton_save, pushButton_clear);
        QWidget::setTabOrder(pushButton_clear, lineEdit_search);
        QWidget::setTabOrder(lineEdit_search, pushButton_search);
        QWidget::setTabOrder(pushButton_search, comboBox_sort);
        QWidget::setTabOrder(comboBox_sort, pushButton_sort);
        QWidget::setTabOrder(pushButton_sort, tableWidget_patients);
        QWidget::setTabOrder(tableWidget_patients, pushButton_add);
        QWidget::setTabOrder(pushButton_add, pushButton_edit);
        QWidget::setTabOrder(pushButton_edit, pushButton_delete);
        QWidget::setTabOrder(pushButton_delete, pushButton_export);
        QWidget::setTabOrder(pushButton_export, lineEdit_search_medical);
        QWidget::setTabOrder(lineEdit_search_medical, pushButton_search_medical);
        QWidget::setTabOrder(pushButton_search_medical, tableWidget_medical_patients);
        QWidget::setTabOrder(tableWidget_medical_patients, textEdit_json_viewer);
        QWidget::setTabOrder(textEdit_json_viewer, pushButton_update_medical);
        QWidget::setTabOrder(pushButton_update_medical, pushButton_import_medical);
        QWidget::setTabOrder(pushButton_import_medical, pushButton_export_medical);
        QWidget::setTabOrder(pushButton_export_medical, pushButton_predict_new);

        retranslateUi(Pat);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Pat);
    } // setupUi

    void retranslateUi(QMainWindow *Pat)
    {
        Pat->setWindowTitle(QCoreApplication::translate("Pat", "Patient Management", nullptr));
        actionNouveau_Patient->setText(QCoreApplication::translate("Pat", "Nouveau Patient", nullptr));
        actionExporter->setText(QCoreApplication::translate("Pat", "Exporter", nullptr));
        actionQuitter->setText(QCoreApplication::translate("Pat", "Quitter", nullptr));
        actionAide->setText(QCoreApplication::translate("Pat", "Aide", nullptr));
        actionA_propos->setText(QCoreApplication::translate("Pat", "\303\200 propos", nullptr));
        biovec_logo->setText(QString());
        dockWidget_Sidebar->setWindowTitle(QCoreApplication::translate("Pat", "Navigation", nullptr));
        sidebar_top_logo->setText(QString());
        patient_icon->setText(QString());
        patientButton->setText(QCoreApplication::translate("Pat", "Patient", nullptr));
        microvac_icon->setText(QString());
        microvacButton->setText(QCoreApplication::translate("Pat", "MicroVac", nullptr));
        personnel_icon->setText(QString());
        personnelButton->setText(QCoreApplication::translate("Pat", "Personnel", nullptr));
        inventory_icon->setText(QString());
        inventoryButton->setText(QCoreApplication::translate("Pat", "Inventory", nullptr));
        appointment_icon->setText(QString());
        appointmentButton->setText(QCoreApplication::translate("Pat", "Appointment", nullptr));
        event_icon->setText(QString());
        eventButton->setText(QCoreApplication::translate("Pat", "Event", nullptr));
        analytics_icon->setText(QString());
        analyticsButton->setText(QCoreApplication::translate("Pat", "Analytics", nullptr));
        help_icon->setText(QString());
        helpButton->setText(QCoreApplication::translate("Pat", "Help/Support", nullptr));
        groupBox_patient->setTitle(QCoreApplication::translate("Pat", "Patient Information", nullptr));
        label_cin->setText(QCoreApplication::translate("Pat", "CIN:", nullptr));
        label_dob->setText(QCoreApplication::translate("Pat", "Date de naissance:", nullptr));
        label_nom->setText(QCoreApplication::translate("Pat", "Nom:", nullptr));
        label_registration->setText(QCoreApplication::translate("Pat", "Date d'inscription:", nullptr));
        label_prenom->setText(QCoreApplication::translate("Pat", "Pr\303\251nom:", nullptr));
        label_sexe->setText(QCoreApplication::translate("Pat", "Sexe:", nullptr));
        comboBox_sexe->setItemText(0, QCoreApplication::translate("Pat", "Homme", nullptr));
        comboBox_sexe->setItemText(1, QCoreApplication::translate("Pat", "Femme", nullptr));

        label_tel->setText(QCoreApplication::translate("Pat", "T\303\251l\303\251phone:", nullptr));
        comboBox_country_code->setItemText(0, QCoreApplication::translate("Pat", "+216 (Tunisia)", nullptr));
        comboBox_country_code->setItemText(1, QCoreApplication::translate("Pat", "+33 (France)", nullptr));
        comboBox_country_code->setItemText(2, QCoreApplication::translate("Pat", "+1 (US/Canada)", nullptr));
        comboBox_country_code->setItemText(3, QCoreApplication::translate("Pat", "+44 (UK)", nullptr));
        comboBox_country_code->setItemText(4, QCoreApplication::translate("Pat", "+212 (Morocco)", nullptr));
        comboBox_country_code->setItemText(5, QCoreApplication::translate("Pat", "+213 (Algeria)", nullptr));

        label_email->setText(QCoreApplication::translate("Pat", "Email:", nullptr));
        label_medical_history->setText(QCoreApplication::translate("Pat", "Dossier M\303\251dical:", nullptr));
        lineEdit_medical_file->setPlaceholderText(QCoreApplication::translate("Pat", "Aucun fichier s\303\251lectionn\303\251", nullptr));
        pushButton_browse->setText(QCoreApplication::translate("Pat", "Parcourir...", nullptr));
        pushButton_save->setText(QCoreApplication::translate("Pat", "Enregistrer", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("Pat", "Effacer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_registration), QCoreApplication::translate("Pat", "Registration Form", nullptr));
        lineEdit_search->setPlaceholderText(QCoreApplication::translate("Pat", "Rechercher un patient...", nullptr));
        pushButton_search->setText(QCoreApplication::translate("Pat", "Rechercher", nullptr));
        label_sort->setText(QCoreApplication::translate("Pat", "Trier par:", nullptr));
        comboBox_sort->setItemText(0, QCoreApplication::translate("Pat", "Nom", nullptr));
        comboBox_sort->setItemText(1, QCoreApplication::translate("Pat", "Age", nullptr));
        comboBox_sort->setItemText(2, QCoreApplication::translate("Pat", "Sexe", nullptr));

        pushButton_sort->setText(QCoreApplication::translate("Pat", "Appliquer", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_patients->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Pat", "CIN", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_patients->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Pat", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_patients->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Pat", "Pr\303\251nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_patients->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Pat", "Date de naissance", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_patients->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Pat", "Age", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_patients->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Pat", "Sexe", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_patients->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Pat", "T\303\251l\303\251phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_patients->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Pat", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_patients->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Pat", "Date d'inscription", nullptr));
        pushButton_add->setText(QCoreApplication::translate("Pat", "Ajouter", nullptr));
        pushButton_edit->setText(QCoreApplication::translate("Pat", "Modifier", nullptr));
        pushButton_delete->setText(QCoreApplication::translate("Pat", "Supprimer", nullptr));
        pushButton_export->setText(QCoreApplication::translate("Pat", "Exporter PDF", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_list), QCoreApplication::translate("Pat", "Patient List", nullptr));
        lineEdit_search_medical->setPlaceholderText(QCoreApplication::translate("Pat", "Rechercher un patient par CIN, nom ou pr\303\251nom...", nullptr));
        pushButton_search_medical->setText(QCoreApplication::translate("Pat", "Rechercher", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_medical_patients->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("Pat", "CIN", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_medical_patients->horizontalHeaderItem(1);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("Pat", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_medical_patients->horizontalHeaderItem(2);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("Pat", "Pr\303\251nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_medical_patients->horizontalHeaderItem(3);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("Pat", "Fichier M\303\251dical", nullptr));
        groupBox_medical_details->setTitle(QCoreApplication::translate("Pat", "D\303\251tails du Dossier M\303\251dical", nullptr));
        label_patient_name->setText(QCoreApplication::translate("Pat", "S\303\251lectionnez un patient", nullptr));
        textEdit_json_viewer->setPlaceholderText(QCoreApplication::translate("Pat", "Contenu du fichier JSON s'affichera ici", nullptr));
        pushButton_update_medical->setText(QCoreApplication::translate("Pat", "Mettre \303\240 jour le dossier", nullptr));
        pushButton_import_medical->setText(QCoreApplication::translate("Pat", "Importer un nouveau fichier", nullptr));
        pushButton_export_medical->setText(QCoreApplication::translate("Pat", "Exporter", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_medical_history), QCoreApplication::translate("Pat", "Dossiers M\303\251dicaux", nullptr));
        label_placeholder_stats->setText(QCoreApplication::translate("Pat", "Statistics Content Area", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_statistics_new), QCoreApplication::translate("Pat", "Statistiques", nullptr));
        label_pred_title_new->setText(QCoreApplication::translate("Pat", "Analyse Pr\303\251dictive des Risques", nullptr));
        pushButton_predict_new->setText(QCoreApplication::translate("Pat", "Pr\303\251dire le risque pour le patient s\303\251lectionn\303\251", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_prediction_new), QCoreApplication::translate("Pat", "Pr\303\251diction des Risques", nullptr));
        label_placeholder_assistant->setText(QCoreApplication::translate("Pat", "Patient Assistant Content Area", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_assistant_new), QCoreApplication::translate("Pat", "Patient Assistant", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Pat: public Ui_Pat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAT_H
