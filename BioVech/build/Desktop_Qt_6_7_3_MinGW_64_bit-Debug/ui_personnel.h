/********************************************************************************
** Form generated from reading UI file 'personnel.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONNEL_H
#define UI_PERSONNEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_personnel
{
public:
    QAction *actionExit;
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QDockWidget *dockWidget_Sidebar;
    QWidget *dockWidgetContents;
    QVBoxLayout *sidebarVerticalLayout;
    QLabel *label_logo;
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
    QLabel *biovec_logo;
    QTabWidget *tabWidget;
    QWidget *tab_Management;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_PersonnelDetails;
    QGridLayout *gridLayout_DetailsForm;
    QLabel *PasswordLabel;
    QLineEdit *idEdit;
    QLabel *SalaireLabel;
    QLabel *idLabel;
    QLineEdit *NomEdit;
    QHBoxLayout *horizontalLayout_Actions;
    QPushButton *pushButton_add;
    QPushButton *pushButton_update;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_delete;
    QLabel *PosteLabel;
    QDoubleSpinBox *Salairedoublespinbox;
    QLabel *PrenomLabel;
    QLabel *NomLabel;
    QLineEdit *PrenomEdit;
    QLabel *AgeLabel;
    QLabel *AssuranceLabel;
    QLineEdit *AssuranceEdit;
    QLineEdit *PasswordEdit;
    QSpinBox *Agespinbox;
    QPushButton *cameraButton;
    QLineEdit *facecode;
    QComboBox *Post;
    QHBoxLayout *horizontalLayout_SearchFilter;
    QLineEdit *searchPersonnel;
    QPushButton *filterButton;
    QPushButton *exportPdfButton;
    QPushButton *statisticsButton;
    QTableWidget *tab_Personnel;

    void setupUi(QMainWindow *personnel)
    {
        if (personnel->objectName().isEmpty())
            personnel->setObjectName("personnel");
        personnel->resize(1185, 908);
        personnel->setStyleSheet(QString::fromUtf8("/* Global Window Style */\n"
"QMainWindow {\n"
" border-image: url(\":/Static/Static/white_bg.jpg\");\n"
" background-size: contain;\n"
"}\n"
"/* Header Logo (Adjusted Size Constraints) */\n"
"QLabel#biovec_logo {\n"
"    margin-left: 25px; /* Keep margin */\n"
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
"QLabel#label_logo {\n"
"\n"
"    min-width: 50px;\n"
"    max-width: 250px;\n"
"    min-height:100px;\n"
"    max-height: 150px;\n"
"    qproperty-alignment: 'AlignCenter';\n"
" "
                        "   image: url(:/Static/Static/dashboard.png);\n"
"\n"
"}\n"
"\n"
"/* Sidebar Button Styles - TEXT MADE LARGER */\n"
"QDockWidget QPushButton {\n"
"    background-color: #208c54;\n"
"    color: #f6f8fa;\n"
"   padding: 18px 32px 18px 25px; /* Slightly increased vertical padding */\n"
"    text-align: left;\n"
"    border: none;\n"
"    border-radius: 0;\n"
"    font-size: 18px;  /* INCREASED FONT SIZE */\n"
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
"QDockWidget QLabel { /* Selects icons within the DockWidget */\n"
"    min-width: 60px;   /* INCREASED ICON SIZE */\n"
"    min-height:60px;  /* INCREASED ICON SIZE */\n"
"    max-width: 60px;   /* INCREASED ICON SIZE */\n"
"    max-height: 60px;  /* INCREASED ICON SIZE */\n"
"    qproperty-alignment: 'AlignCenter';\n"
"         margin-left: 4px;\n"
"}\n"
"\n"
""
                        "/* GroupBox Styles - PADDING/MARGIN REDUCED */\n"
"QGroupBox {\n"
"    border: 1px solid #2ecc71;\n"
"    border-radius: 8px;\n"
"    margin-top: 12px; /* REDUCED margin-top slightly */\n"
"    font-weight: bold;\n"
"    background-color: #ffffff;\n"
"    padding: 4px; /* REDUCED padding inside the groupbox */\n"
"}\n"
"QGroupBox QPushButton{\n"
"    border-radius:20px; /* Adjusted to match general button radius */\n"
"    font-weight: bold;\n"
"    padding: 10px 20px; /* Adjusted padding to match general buttons */\n"
"    font-size: 15px; /* Match general button font size */\n"
"    min-height: 35px; /* Match general button height */\n"
"}\n"
"\n"
"QGroupBox QLineEdit, QGroupBox QSpinBox, QGroupBox QDoubleSpinBox { /* Added SpinBox styling */\n"
"    border: 1px solid #2ecc71;\n"
"    border-radius: 18px; /* Match general input radius */\n"
"    padding: 8px 12px; /* Match general input padding */\n"
"    background-color: #ffffff;\n"
"    font-size: 15px; /* Match general input font size */\n"
"    min-heig"
                        "ht: 35px; /* Match general input height */\n"
"}\n"
"\n"
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
"QTableWidget::item { /* Added item alignment from original personnel */\n"
"  text-align: center;\n"
"  padding-top: 5px;\n"
"  padding-bottom: 5px;\n"
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
"    padding: 10px; /* Adju"
                        "sted padding */\n"
"    border: none;\n"
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
"QPushButton#pushButton_delete { /* Kept original personnel delete style for difference */\n"
"    background-color: #e74c3c;\n"
"    color: white;\n"
"}\n"
"QPushButton#pushButton_delete:hover {\n"
"    background-color: #c0392b;\n"
"}\n"
"QPushButton#pushButton_delete:pressed {\n"
"    background-color: #a93226;\n"
"}\n"
"\n"
"QPushButton#pushButton_clear { /* Kept original personnel clear style for difference */\n"
"   background-color: #95a5a6"
                        ";\n"
"   color: white;\n"
"}\n"
"QPushButton#pushButton_clear:hover {\n"
"    background-color: #7f8c8d;\n"
"}\n"
"QPushButton#pushButton_clear:pressed {\n"
"    background-color: #6c7a7d;\n"
"}\n"
"\n"
"/* Input Field Styles */\n"
"QLineEdit, QDateEdit, QComboBox, QSpinBox, QDoubleSpinBox { /* Added SpinBox/DoubleSpinBox */\n"
"    border: 1px solid #2ecc71;\n"
"    border-radius: 18px;\n"
"    padding: 8px 12px;\n"
"    background-color: #ffffff;\n"
"    font-size: 15px;\n"
"    min-height: 35px;\n"
"}\n"
"\n"
"/* Specific SpinBox styling if needed */\n"
"QSpinBox::up-button, QDoubleSpinBox::up-button {\n"
"    subcontrol-origin: border;\n"
"    subcontrol-position: top right;\n"
"    width: 16px;\n"
"    border-image: url(:/qt-project.org/styles/commonstyle/images/spinup-16x16.png); /* Example icon */\n"
"    border-width: 1px;\n"
"}\n"
"QSpinBox::down-button, QDoubleSpinBox::down-button {\n"
"    subcontrol-origin: border;\n"
"    subcontrol-position: bottom right;\n"
"    width: 16px;\n"
"    border-image"
                        ": url(:/qt-project.org/styles/commonstyle/images/spindown-16x16.png); /* Example icon */\n"
"    border-width: 1px;\n"
"}\n"
"QSpinBox::up-button:hover, QDoubleSpinBox::up-button:hover,\n"
"QSpinBox::down-button:hover, QDoubleSpinBox::down-button:hover {\n"
"    background-color: #e0e0e0;\n"
"}\n"
"\n"
"\n"
"/* Label Styles */\n"
"QLabel {\n"
"    color: #2c3e50;\n"
"    font-size: 15px; /* Adjusted font size */\n"
"    background-color: transparent;\n"
"    padding: 2px;\n"
"}\n"
"/* Align specific labels from personnel form if needed */\n"
"QLabel#idLabel, QLabel#NomLabel, QLabel#PrenomLabel, QLabel#AgeLabel, QLabel#SalaireLabel, QLabel#PosteLabel, QLabel#AssuranceLabel, QLabel#PasswordLabel {\n"
"    qproperty-alignment: 'AlignRight | AlignVCenter'; /* Keep right alignment for form labels */\n"
"    padding-right: 5px; /* Add some padding */\n"
"}\n"
"\n"
"\n"
"/* Main Tab Widget */\n"
"QTabWidget::pane {\n"
"    border:1px solid #2ecc71;\n"
"    border-radius: 20px 20px 20px;\n"
"    border-top: none;\n"
""
                        "    background: white;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
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
"/* Calendar styles are kept from appointment UI but won't be used unless a calendar is added */\n"
"QCalendarWidget {\n"
"    /* Background Color */\n"
"    background-color: #29aa63;\n"
"    color: #ffffff; /* White text */\n"
"    font-family: \"Segoe UI\", \"Arial\", sans-serif;\n"
"    font-size: 16px;\n"
"    border: none;\n"
"    border-radius: 15px; /* "
                        "Rounded corners */\n"
"}\n"
"/* ... (rest of the calendar styles from appointment.ui) ... */\n"
""));
        actionExit = new QAction(personnel);
        actionExit->setObjectName("actionExit");
        centralwidget = new QWidget(personnel);
        centralwidget->setObjectName("centralwidget");
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName("gridLayout_3");
        dockWidget_Sidebar = new QDockWidget(centralwidget);
        dockWidget_Sidebar->setObjectName("dockWidget_Sidebar");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dockWidget_Sidebar->sizePolicy().hasHeightForWidth());
        dockWidget_Sidebar->setSizePolicy(sizePolicy);
        dockWidget_Sidebar->setFeatures(QDockWidget::DockWidgetFeature::NoDockWidgetFeatures);
        dockWidget_Sidebar->setAllowedAreas(Qt::DockWidgetArea::LeftDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName("dockWidgetContents");
        sidebarVerticalLayout = new QVBoxLayout(dockWidgetContents);
        sidebarVerticalLayout->setSpacing(15);
        sidebarVerticalLayout->setObjectName("sidebarVerticalLayout");
        sidebarVerticalLayout->setContentsMargins(0, 10, 0, 10);
        label_logo = new QLabel(dockWidgetContents);
        label_logo->setObjectName("label_logo");

        sidebarVerticalLayout->addWidget(label_logo);

        buttonsVerticalLayout = new QVBoxLayout();
        buttonsVerticalLayout->setSpacing(5);
        buttonsVerticalLayout->setObjectName("buttonsVerticalLayout");
        patientLayout = new QHBoxLayout();
        patientLayout->setObjectName("patientLayout");
        patient_icon = new QLabel(dockWidgetContents);
        patient_icon->setObjectName("patient_icon");
        patient_icon->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/1.png);"));

        patientLayout->addWidget(patient_icon);

        patientButton = new QPushButton(dockWidgetContents);
        patientButton->setObjectName("patientButton");

        patientLayout->addWidget(patientButton);


        buttonsVerticalLayout->addLayout(patientLayout);

        microvacLayout = new QHBoxLayout();
        microvacLayout->setObjectName("microvacLayout");
        microvac_icon = new QLabel(dockWidgetContents);
        microvac_icon->setObjectName("microvac_icon");
        microvac_icon->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/2.png);"));

        microvacLayout->addWidget(microvac_icon);

        microvacButton = new QPushButton(dockWidgetContents);
        microvacButton->setObjectName("microvacButton");

        microvacLayout->addWidget(microvacButton);


        buttonsVerticalLayout->addLayout(microvacLayout);

        personnelLayout = new QHBoxLayout();
        personnelLayout->setObjectName("personnelLayout");
        personnel_icon = new QLabel(dockWidgetContents);
        personnel_icon->setObjectName("personnel_icon");
        personnel_icon->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/3.png);"));

        personnelLayout->addWidget(personnel_icon);

        personnelButton = new QPushButton(dockWidgetContents);
        personnelButton->setObjectName("personnelButton");

        personnelLayout->addWidget(personnelButton);


        buttonsVerticalLayout->addLayout(personnelLayout);

        inventoryLayout = new QHBoxLayout();
        inventoryLayout->setObjectName("inventoryLayout");
        inventory_icon = new QLabel(dockWidgetContents);
        inventory_icon->setObjectName("inventory_icon");
        inventory_icon->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/4.png);"));

        inventoryLayout->addWidget(inventory_icon);

        inventoryButton = new QPushButton(dockWidgetContents);
        inventoryButton->setObjectName("inventoryButton");

        inventoryLayout->addWidget(inventoryButton);


        buttonsVerticalLayout->addLayout(inventoryLayout);

        appointmentLayout = new QHBoxLayout();
        appointmentLayout->setObjectName("appointmentLayout");
        appointment_icon = new QLabel(dockWidgetContents);
        appointment_icon->setObjectName("appointment_icon");
        appointment_icon->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/5.png);"));

        appointmentLayout->addWidget(appointment_icon);

        appointmentButton = new QPushButton(dockWidgetContents);
        appointmentButton->setObjectName("appointmentButton");

        appointmentLayout->addWidget(appointmentButton);


        buttonsVerticalLayout->addLayout(appointmentLayout);

        eventLayout = new QHBoxLayout();
        eventLayout->setObjectName("eventLayout");
        event_icon = new QLabel(dockWidgetContents);
        event_icon->setObjectName("event_icon");
        event_icon->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/6.png);"));

        eventLayout->addWidget(event_icon);

        eventButton = new QPushButton(dockWidgetContents);
        eventButton->setObjectName("eventButton");

        eventLayout->addWidget(eventButton);


        buttonsVerticalLayout->addLayout(eventLayout);

        analyticsLayout = new QHBoxLayout();
        analyticsLayout->setObjectName("analyticsLayout");
        analytics_icon = new QLabel(dockWidgetContents);
        analytics_icon->setObjectName("analytics_icon");
        analytics_icon->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/7.png);"));

        analyticsLayout->addWidget(analytics_icon);

        analyticsButton = new QPushButton(dockWidgetContents);
        analyticsButton->setObjectName("analyticsButton");

        analyticsLayout->addWidget(analyticsButton);


        buttonsVerticalLayout->addLayout(analyticsLayout);

        helpLayout = new QHBoxLayout();
        helpLayout->setObjectName("helpLayout");
        help_icon = new QLabel(dockWidgetContents);
        help_icon->setObjectName("help_icon");
        help_icon->setStyleSheet(QString::fromUtf8("image: url(:/Static/Static/8.png);"));

        helpLayout->addWidget(help_icon);

        helpButton = new QPushButton(dockWidgetContents);
        helpButton->setObjectName("helpButton");

        helpLayout->addWidget(helpButton);


        buttonsVerticalLayout->addLayout(helpLayout);


        sidebarVerticalLayout->addLayout(buttonsVerticalLayout);

        dockWidget_Sidebar->setWidget(dockWidgetContents);

        gridLayout_3->addWidget(dockWidget_Sidebar, 1, 1, 2, 1);

        biovec_logo = new QLabel(centralwidget);
        biovec_logo->setObjectName("biovec_logo");
        biovec_logo->setStyleSheet(QString::fromUtf8("/* Style defined globally via object name */"));

        gridLayout_3->addWidget(biovec_logo, 1, 2, 1, 1);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tab_Management = new QWidget();
        tab_Management->setObjectName("tab_Management");
        gridLayout = new QGridLayout(tab_Management);
        gridLayout->setObjectName("gridLayout");
        groupBox_PersonnelDetails = new QGroupBox(tab_Management);
        groupBox_PersonnelDetails->setObjectName("groupBox_PersonnelDetails");
        gridLayout_DetailsForm = new QGridLayout(groupBox_PersonnelDetails);
        gridLayout_DetailsForm->setObjectName("gridLayout_DetailsForm");
        gridLayout_DetailsForm->setHorizontalSpacing(20);
        gridLayout_DetailsForm->setVerticalSpacing(10);
        PasswordLabel = new QLabel(groupBox_PersonnelDetails);
        PasswordLabel->setObjectName("PasswordLabel");

        gridLayout_DetailsForm->addWidget(PasswordLabel, 3, 3, 1, 1);

        idEdit = new QLineEdit(groupBox_PersonnelDetails);
        idEdit->setObjectName("idEdit");
        idEdit->setClearButtonEnabled(true);

        gridLayout_DetailsForm->addWidget(idEdit, 0, 1, 1, 1);

        SalaireLabel = new QLabel(groupBox_PersonnelDetails);
        SalaireLabel->setObjectName("SalaireLabel");

        gridLayout_DetailsForm->addWidget(SalaireLabel, 1, 3, 1, 1);

        idLabel = new QLabel(groupBox_PersonnelDetails);
        idLabel->setObjectName("idLabel");

        gridLayout_DetailsForm->addWidget(idLabel, 0, 0, 1, 1);

        NomEdit = new QLineEdit(groupBox_PersonnelDetails);
        NomEdit->setObjectName("NomEdit");
        NomEdit->setClearButtonEnabled(true);

        gridLayout_DetailsForm->addWidget(NomEdit, 1, 1, 1, 1);

        horizontalLayout_Actions = new QHBoxLayout();
        horizontalLayout_Actions->setObjectName("horizontalLayout_Actions");
        pushButton_add = new QPushButton(groupBox_PersonnelDetails);
        pushButton_add->setObjectName("pushButton_add");
        pushButton_add->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_Actions->addWidget(pushButton_add);

        pushButton_update = new QPushButton(groupBox_PersonnelDetails);
        pushButton_update->setObjectName("pushButton_update");
        pushButton_update->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_Actions->addWidget(pushButton_update);

        pushButton_clear = new QPushButton(groupBox_PersonnelDetails);
        pushButton_clear->setObjectName("pushButton_clear");
        pushButton_clear->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_Actions->addWidget(pushButton_clear);

        pushButton_delete = new QPushButton(groupBox_PersonnelDetails);
        pushButton_delete->setObjectName("pushButton_delete");
        pushButton_delete->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_Actions->addWidget(pushButton_delete);


        gridLayout_DetailsForm->addLayout(horizontalLayout_Actions, 4, 0, 1, 5);

        PosteLabel = new QLabel(groupBox_PersonnelDetails);
        PosteLabel->setObjectName("PosteLabel");

        gridLayout_DetailsForm->addWidget(PosteLabel, 2, 3, 1, 1);

        Salairedoublespinbox = new QDoubleSpinBox(groupBox_PersonnelDetails);
        Salairedoublespinbox->setObjectName("Salairedoublespinbox");
        Salairedoublespinbox->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::PlusMinus);
        Salairedoublespinbox->setMaximum(99999.990000000005239);

        gridLayout_DetailsForm->addWidget(Salairedoublespinbox, 1, 4, 1, 1);

        PrenomLabel = new QLabel(groupBox_PersonnelDetails);
        PrenomLabel->setObjectName("PrenomLabel");

        gridLayout_DetailsForm->addWidget(PrenomLabel, 2, 0, 1, 1);

        NomLabel = new QLabel(groupBox_PersonnelDetails);
        NomLabel->setObjectName("NomLabel");

        gridLayout_DetailsForm->addWidget(NomLabel, 1, 0, 1, 1);

        PrenomEdit = new QLineEdit(groupBox_PersonnelDetails);
        PrenomEdit->setObjectName("PrenomEdit");
        PrenomEdit->setClearButtonEnabled(true);

        gridLayout_DetailsForm->addWidget(PrenomEdit, 2, 1, 1, 1);

        AgeLabel = new QLabel(groupBox_PersonnelDetails);
        AgeLabel->setObjectName("AgeLabel");

        gridLayout_DetailsForm->addWidget(AgeLabel, 0, 3, 1, 1);

        AssuranceLabel = new QLabel(groupBox_PersonnelDetails);
        AssuranceLabel->setObjectName("AssuranceLabel");

        gridLayout_DetailsForm->addWidget(AssuranceLabel, 3, 0, 1, 1);

        AssuranceEdit = new QLineEdit(groupBox_PersonnelDetails);
        AssuranceEdit->setObjectName("AssuranceEdit");
        AssuranceEdit->setClearButtonEnabled(true);

        gridLayout_DetailsForm->addWidget(AssuranceEdit, 3, 1, 1, 1);

        PasswordEdit = new QLineEdit(groupBox_PersonnelDetails);
        PasswordEdit->setObjectName("PasswordEdit");
        PasswordEdit->setEchoMode(QLineEdit::EchoMode::Password);
        PasswordEdit->setClearButtonEnabled(true);

        gridLayout_DetailsForm->addWidget(PasswordEdit, 3, 4, 1, 1);

        Agespinbox = new QSpinBox(groupBox_PersonnelDetails);
        Agespinbox->setObjectName("Agespinbox");

        gridLayout_DetailsForm->addWidget(Agespinbox, 0, 4, 1, 1);

        cameraButton = new QPushButton(groupBox_PersonnelDetails);
        cameraButton->setObjectName("cameraButton");

        gridLayout_DetailsForm->addWidget(cameraButton, 2, 2, 1, 1);

        facecode = new QLineEdit(groupBox_PersonnelDetails);
        facecode->setObjectName("facecode");

        gridLayout_DetailsForm->addWidget(facecode, 1, 2, 1, 1);

        Post = new QComboBox(groupBox_PersonnelDetails);
        Post->addItem(QString());
        Post->addItem(QString());
        Post->addItem(QString());
        Post->addItem(QString());
        Post->setObjectName("Post");

        gridLayout_DetailsForm->addWidget(Post, 2, 4, 1, 1);


        gridLayout->addWidget(groupBox_PersonnelDetails, 0, 0, 1, 1);

        horizontalLayout_SearchFilter = new QHBoxLayout();
        horizontalLayout_SearchFilter->setObjectName("horizontalLayout_SearchFilter");
        searchPersonnel = new QLineEdit(tab_Management);
        searchPersonnel->setObjectName("searchPersonnel");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(searchPersonnel->sizePolicy().hasHeightForWidth());
        searchPersonnel->setSizePolicy(sizePolicy2);
        searchPersonnel->setClearButtonEnabled(true);

        horizontalLayout_SearchFilter->addWidget(searchPersonnel);

        filterButton = new QPushButton(tab_Management);
        filterButton->setObjectName("filterButton");
        filterButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_SearchFilter->addWidget(filterButton);

        exportPdfButton = new QPushButton(tab_Management);
        exportPdfButton->setObjectName("exportPdfButton");
        exportPdfButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_SearchFilter->addWidget(exportPdfButton);

        statisticsButton = new QPushButton(tab_Management);
        statisticsButton->setObjectName("statisticsButton");
        statisticsButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout_SearchFilter->addWidget(statisticsButton);


        gridLayout->addLayout(horizontalLayout_SearchFilter, 1, 0, 1, 1);

        tab_Personnel = new QTableWidget(tab_Management);
        if (tab_Personnel->columnCount() < 7)
            tab_Personnel->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tab_Personnel->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tab_Personnel->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tab_Personnel->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tab_Personnel->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tab_Personnel->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tab_Personnel->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tab_Personnel->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tab_Personnel->setObjectName("tab_Personnel");
        tab_Personnel->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(2);
        sizePolicy3.setHeightForWidth(tab_Personnel->sizePolicy().hasHeightForWidth());
        tab_Personnel->setSizePolicy(sizePolicy3);
        tab_Personnel->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tab_Personnel->setAlternatingRowColors(true);
        tab_Personnel->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        tab_Personnel->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tab_Personnel->setShowGrid(true);
        tab_Personnel->horizontalHeader()->setStretchLastSection(true);
        tab_Personnel->verticalHeader()->setVisible(false);

        gridLayout->addWidget(tab_Personnel, 2, 0, 1, 1);

        tabWidget->addTab(tab_Management, QString());

        gridLayout_3->addWidget(tabWidget, 2, 2, 1, 1);

        personnel->setCentralWidget(centralwidget);
        QWidget::setTabOrder(patientButton, microvacButton);
        QWidget::setTabOrder(microvacButton, personnelButton);
        QWidget::setTabOrder(personnelButton, inventoryButton);
        QWidget::setTabOrder(inventoryButton, appointmentButton);
        QWidget::setTabOrder(appointmentButton, eventButton);
        QWidget::setTabOrder(eventButton, analyticsButton);
        QWidget::setTabOrder(analyticsButton, helpButton);
        QWidget::setTabOrder(helpButton, tabWidget);
        QWidget::setTabOrder(tabWidget, idEdit);
        QWidget::setTabOrder(idEdit, Agespinbox);
        QWidget::setTabOrder(Agespinbox, NomEdit);
        QWidget::setTabOrder(NomEdit, Salairedoublespinbox);
        QWidget::setTabOrder(Salairedoublespinbox, PrenomEdit);
        QWidget::setTabOrder(PrenomEdit, AssuranceEdit);
        QWidget::setTabOrder(AssuranceEdit, PasswordEdit);
        QWidget::setTabOrder(PasswordEdit, pushButton_add);
        QWidget::setTabOrder(pushButton_add, pushButton_update);
        QWidget::setTabOrder(pushButton_update, pushButton_clear);
        QWidget::setTabOrder(pushButton_clear, pushButton_delete);
        QWidget::setTabOrder(pushButton_delete, searchPersonnel);
        QWidget::setTabOrder(searchPersonnel, filterButton);
        QWidget::setTabOrder(filterButton, exportPdfButton);
        QWidget::setTabOrder(exportPdfButton, statisticsButton);
        QWidget::setTabOrder(statisticsButton, tab_Personnel);

        retranslateUi(personnel);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(personnel);
    } // setupUi

    void retranslateUi(QMainWindow *personnel)
    {
        personnel->setWindowTitle(QCoreApplication::translate("personnel", "Personnel Management", nullptr));
        actionExit->setText(QCoreApplication::translate("personnel", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("personnel", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        dockWidget_Sidebar->setWindowTitle(QCoreApplication::translate("personnel", "Navigation", nullptr));
        label_logo->setText(QString());
        patient_icon->setText(QString());
        patientButton->setText(QCoreApplication::translate("personnel", "Patient", nullptr));
        microvac_icon->setText(QString());
        microvacButton->setText(QCoreApplication::translate("personnel", "MicroVac", nullptr));
        personnel_icon->setText(QString());
        personnelButton->setText(QCoreApplication::translate("personnel", "Personnel", nullptr));
        inventory_icon->setText(QString());
        inventoryButton->setText(QCoreApplication::translate("personnel", "Inventory", nullptr));
        appointment_icon->setText(QString());
        appointmentButton->setText(QCoreApplication::translate("personnel", "Appointment", nullptr));
        event_icon->setText(QString());
        eventButton->setText(QCoreApplication::translate("personnel", "Event", nullptr));
        analytics_icon->setText(QString());
        analyticsButton->setText(QCoreApplication::translate("personnel", "Analytics", nullptr));
        help_icon->setText(QString());
        helpButton->setText(QCoreApplication::translate("personnel", "Help/Support", nullptr));
        biovec_logo->setText(QString());
        groupBox_PersonnelDetails->setTitle(QCoreApplication::translate("personnel", "Employee Details", nullptr));
        PasswordLabel->setText(QCoreApplication::translate("personnel", "Password:", nullptr));
        idEdit->setPlaceholderText(QCoreApplication::translate("personnel", "Enter ID", nullptr));
        SalaireLabel->setText(QCoreApplication::translate("personnel", "Salary:", nullptr));
        idLabel->setText(QCoreApplication::translate("personnel", "ID:", nullptr));
        NomEdit->setPlaceholderText(QCoreApplication::translate("personnel", "Enter Family Name", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_add->setToolTip(QCoreApplication::translate("personnel", "Add a new employee with the details above", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_add->setText(QCoreApplication::translate("personnel", "Add", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_update->setToolTip(QCoreApplication::translate("personnel", "Update the selected employee using the ID", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_update->setText(QCoreApplication::translate("personnel", "Update", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_clear->setToolTip(QCoreApplication::translate("personnel", "Clear all fields in the form", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_clear->setText(QCoreApplication::translate("personnel", "Clear", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_delete->setToolTip(QCoreApplication::translate("personnel", "Delete the selected employee", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_delete->setText(QCoreApplication::translate("personnel", "Delete", nullptr));
        PosteLabel->setText(QCoreApplication::translate("personnel", "Position:", nullptr));
        PrenomLabel->setText(QCoreApplication::translate("personnel", "First Name:", nullptr));
        NomLabel->setText(QCoreApplication::translate("personnel", "Last Name:", nullptr));
        PrenomEdit->setPlaceholderText(QCoreApplication::translate("personnel", "Enter Name", nullptr));
        AgeLabel->setText(QCoreApplication::translate("personnel", "Age:", nullptr));
        AssuranceLabel->setText(QCoreApplication::translate("personnel", "Insurance:", nullptr));
        AssuranceEdit->setPlaceholderText(QCoreApplication::translate("personnel", "Enter Insurance Type", nullptr));
        PasswordEdit->setPlaceholderText(QCoreApplication::translate("personnel", "Enter Password", nullptr));
        cameraButton->setText(QCoreApplication::translate("personnel", "facerecon", nullptr));
        facecode->setText(QString());
        facecode->setPlaceholderText(QCoreApplication::translate("personnel", "Facecode Holder", nullptr));
        Post->setItemText(0, QCoreApplication::translate("personnel", "Analyst", nullptr));
        Post->setItemText(1, QCoreApplication::translate("personnel", "Developper", nullptr));
        Post->setItemText(2, QCoreApplication::translate("personnel", "Designer", nullptr));
        Post->setItemText(3, QCoreApplication::translate("personnel", "Manager", nullptr));

        Post->setPlaceholderText(QCoreApplication::translate("personnel", "Choose your position", nullptr));
        searchPersonnel->setPlaceholderText(QCoreApplication::translate("personnel", "Search personnel (e.g., by Name, ID, Position)...", nullptr));
#if QT_CONFIG(tooltip)
        filterButton->setToolTip(QCoreApplication::translate("personnel", "Apply filters (e.g., position, salary range)", nullptr));
#endif // QT_CONFIG(tooltip)
        filterButton->setText(QCoreApplication::translate("personnel", "Filter", nullptr));
#if QT_CONFIG(tooltip)
        exportPdfButton->setToolTip(QCoreApplication::translate("personnel", "Export current view to PDF", nullptr));
#endif // QT_CONFIG(tooltip)
        exportPdfButton->setText(QCoreApplication::translate("personnel", "Export PDF", nullptr));
#if QT_CONFIG(tooltip)
        statisticsButton->setToolTip(QCoreApplication::translate("personnel", "View personnel statistics", nullptr));
#endif // QT_CONFIG(tooltip)
        statisticsButton->setText(QCoreApplication::translate("personnel", "Statistics", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tab_Personnel->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("personnel", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tab_Personnel->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("personnel", "Last Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tab_Personnel->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("personnel", "First Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tab_Personnel->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("personnel", "Position", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tab_Personnel->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("personnel", "Salary", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tab_Personnel->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("personnel", "Age", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tab_Personnel->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("personnel", "Insurance", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Management), QCoreApplication::translate("personnel", "Management", nullptr));
    } // retranslateUi

};

namespace Ui {
    class personnel: public Ui_personnel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONNEL_H
