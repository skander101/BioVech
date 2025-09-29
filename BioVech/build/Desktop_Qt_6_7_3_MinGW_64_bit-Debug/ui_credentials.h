/********************************************************************************
** Form generated from reading UI file 'credentials.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDENTIALS_H
#define UI_CREDENTIALS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_credentials
{
public:
    QVBoxLayout *verticalLayout_credentials;
    QStackedWidget *stackedWidget;
    QWidget *create_account_page;
    QHBoxLayout *horizontalLayout_create_page;
    QSpacerItem *horizontalSpacer_3;
    QWidget *WordContainer;
    QGridLayout *gridLayout;
    QLabel *subtitleLabel2;
    QSpacerItem *verticalSpacer_5;
    QLabel *subtitleLabel1;
    QLabel *subtitleLabel2_4;
    QLabel *subtitleLabel2_3;
    QLabel *titleLabel;
    QPushButton *skipbutton;
    QSpacerItem *horizontalSpacer_2;
    QWidget *whiteCard;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_age_salary_fixed;
    QVBoxLayout *verticalLayout_age_fixed;
    QLabel *label_8;
    QSpinBox *AgeSpinBox;
    QVBoxLayout *verticalLayout_salary_fixed;
    QLabel *label_10;
    QDoubleSpinBox *SalaireDoubleSpinBox;
    QHBoxLayout *horizontalLayout_social_create_fixed;
    QPushButton *githubButton;
    QPushButton *googleButton;
    QLabel *label_9;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_card_bottom_create;
    QPushButton *switch_login_butt;
    QLabel *label_name;
    QLineEdit *NomEdit;
    QPushButton *cameraButton;
    QSpacerItem *verticalSpacer_3;
    QLabel *passwordLabel;
    QHBoxLayout *horizontalLayout_5;
    QLabel *biovec_logo;
    QLineEdit *IdEdit;
    QLabel *label_name_5;
    QLineEdit *PrenomEdit;
    QLabel *label_name_4;
    QLineEdit *AssuranceEdit;
    QLabel *label_name_2;
    QPushButton *create_account_button;
    QLineEdit *PasswordCreateEdit;
    QLineEdit *facecode;
    QLabel *label_name_3;
    QComboBox *Post;
    QWidget *login_page;
    QHBoxLayout *horizontalLayout_login_page_fixed;
    QWidget *whiteCard2;
    QVBoxLayout *verticalLayout_login_card_fixed;
    QHBoxLayout *horizontalLayout;
    QLabel *biovec_logo1;
    QLabel *label_11;
    QGridLayout *gridLayout_3;
    QLineEdit *EmailLineEdit;
    QPushButton *emailButton;
    QLabel *label_12;
    QGridLayout *gridLayout_4;
    QLineEdit *PasswordLineEdit;
    QPushButton *passwordButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *cameraButton2;
    QSpacerItem *verticalSpacer;
    QPushButton *Log_in_button;
    QLabel *label_91;
    QHBoxLayout *horizontalLayout_social_login_fixed;
    QPushButton *githubButton1;
    QPushButton *googleButton1;
    QPushButton *switch_create_account_button;
    QSpacerItem *verticalSpacer_2;
    QFrame *audioFrame;
    QVBoxLayout *verticalLayout_audio;
    QGroupBox *audioGroupBox;
    QGridLayout *gridLayout_audio;
    QLabel *micLabel;
    QComboBox *micSelector;
    QPushButton *refreshMicsButton;
    QLabel *volumeLabel;
    QSlider *volumeSlider;
    QPushButton *recognitionButton;
    QLabel *speechStatus;
    QCheckBox *autoFillUsername;
    QLabel *recognizedText;
    QSpacerItem *horizontalSpacer_login_L;
    QWidget *WordContainer2;
    QVBoxLayout *verticalLayout_51;
    QLabel *titleLabel1;
    QLabel *subtitleLabel11;
    QLabel *subtitleLabel21;
    QLabel *subtitleLabel2_31;
    QLabel *subtitleLabel2_41;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_word_login_expand;
    QSpacerItem *horizontalSpacer_login_R;

    void setupUi(QWidget *credentials)
    {
        if (credentials->objectName().isEmpty())
            credentials->setObjectName("credentials");
        credentials->resize(1289, 989);
        verticalLayout_credentials = new QVBoxLayout(credentials);
        verticalLayout_credentials->setObjectName("verticalLayout_credentials");
        verticalLayout_credentials->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(credentials);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setStyleSheet(QString::fromUtf8("QWidget#create_account_page {\n"
"    border-image: url(\":/Static/Static/white_bg.jpg\") 0 0 0 0 stretch stretch; /* Use your actual background path */\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-size: cover;\n"
"}\n"
"\n"
"/* White form card */\n"
"QWidget#whiteCard {\n"
"    background: white;\n"
"    border-radius: 20px;\n"
"    padding: 80px; /* Increased padding */\n"
"    max-width: 480px; /* Adjusted max width */\n"
"    min-width: 500px;\n"
"min-hight:800px;\n"
"}\n"
"\n"
"/* Logo */\n"
"QLabel#biovec_logo {\n"
"    min-width: 90px; max-width:300px; /* Adjusted size */\n"
"    min-height:80px; max-height: 120px;\n"
"    border-image: url(\":/Static/Static/logo.png\") 0 0 0 0 stretch stretch;\n"
"\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-size: contain;\n"
"    margin-bottom: 15px; /* Space below logo */\n"
"    qproperty-alignment: 'AlignCenter'; /* Center logo */\n"
"}\n"
"\n"
"/* Titles and Labels *"
                        "/\n"
"QLabel#formTitleLabel { /* New ID for \"Create your Free Account\" */\n"
"    font-size: 20px;\n"
"    font-weight: bold;\n"
"    color: #333;\n"
"    margin-bottom: 25px; /* Space below title */\n"
"    qproperty-alignment: 'AlignCenter';\n"
"}\n"
"QLabel { /* Default label style (e.g., \"Full Name\", \"Email\") */\n"
"    font-size: 12px;\n"
"    color: #555;\n"
"\n"
"}\n"
"\n"
"/* Input Fields */\n"
"QLineEdit {\n"
"    background: #f0f2f5; /* Lighter grey background */\n"
"    border-radius: 15px; /* Slightly smaller radius */\n"
"    border: 1px solid #e0e2e7; /* Subtle border */\n"
"    padding: 0px 5px;\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"    min-height: 30px; /* Ensure height */\n"
" /* Space below input */\n"
"}\n"
"QLineEdit::placeholder {\n"
"    color: #888;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"/* Buttons */\n"
"QPushButton#create_account_button {\n"
"    background: #1E8F53;\n"
"    border-radius: 20px;\n"
"    padding: 12px;\n"
"    font-size: 16px;\n"
"    font-weight: bol"
                        "d;\n"
"    color: white;\n"
"    min-height: 40px;\n"
"    margin-top: 10px; /* Space above button */\n"
"    margin-bottom: 20px; /* Space below button */\n"
"}\n"
"QPushButton {\n"
"background-color: #32cc77;\n"
"    border-radius: 20px;\n"
"    font-size: 16px;\n"
"    padding: 5px;\n"
"    font-weight: bold;\n"
"    color: white;\n"
"    min-height: 30px;\n"
"\n"
"}\n"
"QPushButton#create_account_button:hover {\n"
"    background: #17663D;\n"
"}\n"
"QPushButton:hover {\n"
"    background: #2baf66;\n"
"}\n"
"\n"
"/* Google/GitHub Buttons */\n"
"QPushButton#googleButton, QPushButton#githubButton {\n"
"    background-color: white;\n"
"    border-radius: 12px;\n"
"    padding: 10px;\n"
"    font-weight: normal; /* Normal weight */\n"
"    font-size: 14px;\n"
"    color: #555;\n"
"    border: 1px solid #ddd;\n"
"    min-height: 40px;\n"
"    text-align: center; /* Center text */\n"
"}\n"
"QPushButton#googleButton:hover, QPushButton#githubButton:hover {\n"
"    background: #f8f8f8;\n"
"}\n"
"\n"
"/* Switch Butto"
                        "n (Log In) */\n"
"QPushButton#switch_login_butt {\n"
"    color: #1E8F53; /* Use theme color */\n"
"    font-size: 14px;\n"
"    border: none;\n"
"    background: transparent;\n"
"    padding: 5px;\n"
"    text-decoration: none; /* Remove underline if any */\n"
"}\n"
"QPushButton#switch_login_butt:hover {\n"
"    font-weight: bold;\n"
"    text-decoration: underline;\n"
"}\n"
"\n"
"/* OR Label */\n"
"QLabel#orLabel { /* Give the \"OR\" label an ID */\n"
"    color: #aaa;\n"
"    font-size: 13px;\n"
"    qproperty-alignment: 'AlignCenter';\n"
"    margin-top: 15px;\n"
"    margin-bottom: 15px;\n"
"}\n"
"\n"
"/* Decorative Text Container */\n"
"QWidget#WordContainer QLabel { /* Style labels inside the text container */\n"
"    font-size: 55px;\n"
"    font-weight: bold;\n"
"    color: #1E8F53; /* Match button green */\n"
"    margin-bottom: 5px;\n"
"    qproperty-alignment: 'AlignCenter';\n"
"}\n"
"\n"
"QSpinBox {\n"
"    background: #f0f2f5; /* Lighter grey background */\n"
"    border-radius: 18px; /* Slightly"
                        " smaller radius */\n"
"    border: 1px solid #e0e2e7; /* Subtle border */\n"
"    padding: 0px 5px;\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"    min-height: 35px; /* Ensure height */\n"
"    margin-bottom: 15px; /* Space below input */\n"
"}\n"
"\n"
"QDoubleSpinBox {\n"
"    background: #f0f2f5; /* Lighter grey background */\n"
"    border-radius: 18px; /* Slightly smaller radius */\n"
"    border: 1px solid #e0e2e7; /* Subtle border */\n"
"    padding: 0px 5px;\n"
"    font-size: 14px;\n"
"    color: #333;\n"
"    min-height: 35px; /* Ensure height */\n"
"    margin-bottom: 15px; /* Space below input */\n"
"\n"
"}\n"
" QLabel#cameraPreview {\n"
" background: #2C2C2C; border-radius: 10px; padding: 5px; color: #aaa; min-height: 200px; max-height: 240px; min-width: 280px; max-width: 320px; alignment: AlignCenter; }\n"
"\n"
"QWidget#login_page {\n"
"    border-image: url(\":/Static/Static/white_bg.jpg\") 0 0 0 0 stretch stretch; /* Use your actual background path */\n"
"    background-repeat: no-repeat;\n"
""
                        "    background-position: center;\n"
"    background-size: cover;\n"
"}\n"
"\n"
"/* White form card */\n"
"QWidget#whiteCard2 {\n"
"    background: white;\n"
"    border-radius: 20px;\n"
"    padding: 80px;\n"
"    max-width: 480px;\n"
"    min-width: 500px;\n"
"}\n"
"\n"
"/* Logo */\n"
"QLabel#biovec_logo1 {\n"
"    min-width: 90px; max-width:300px; /* Adjusted size */\n"
"    min-height:80px; max-height: 120px;\n"
"    border-image: url(\":/Static/Static/logo.png\") 0 0 0 0 stretch stretch;\n"
"\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-size: contain;\n"
"    margin-bottom: 15px; /* Space below logo */\n"
"    qproperty-alignment: 'AlignCenter'; /* Center logo */\n"
"}\n"
"\n"
"\n"
"/* Titles and Labels */\n"
"QLabel#formTitleLabel_Login { /* New ID for \"Sign In\" */\n"
"    font-size: 20px;\n"
"    font-weight: bold;\n"
"    color: #333;\n"
"    margin-bottom: 25px;\n"
"    qproperty-alignment: 'AlignCenter';\n"
"}\n"
"/* Note: Original had conflicting QLa"
                        "bel default styles. Keeping the first one. */\n"
"\n"
"\n"
"/* Input Fields */\n"
"/* Reusing the QLineEdit style from above */\n"
"\n"
"/* Buttons */\n"
"QPushButton#Log_in_button {\n"
"    background: #1E8F53;\n"
"    border-radius: 30px;\n"
"    padding: 12px;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    color: white;\n"
"    min-height: 40px;\n"
"    margin-top: 20px;\n"
"    margin-bottom: 10px; /* Reduced bottom margin */\n"
"}\n"
"QPushButton#Log_in_button:hover {\n"
"    background: #17663D;\n"
"}\n"
"\n"
"/* Forgot Password Button */\n"
"QPushButton#forgotPasswordButton {\n"
"     color: #1E8F53;\n"
"     font-size: 13px;\n"
"     border: none;\n"
"     background: transparent;\n"
"     padding: 0px; /* Minimal padding */\n"
"     margin-bottom: 20px; /* Space below */\n"
"     qproperty-alignment: AlignRight; /* Align to right */\n"
"     text-decoration: none;\n"
"}\n"
"QPushButton#forgotPasswordButton:hover {\n"
"    text-decoration: underline;\n"
"}\n"
"\n"
"/* Google/GitHub Buttons"
                        " */\n"
"QPushButton#googleButton1, QPushButton#githubButton1 {\n"
"    background-color: white;\n"
"    border-radius: 12px;\n"
"    padding: 10px;\n"
"    font-weight: normal;\n"
"    font-size: 14px;\n"
"    color: #555;\n"
"    border: 1px solid #ddd;\n"
"    min-height: 40px;\n"
"    text-align: center;\n"
"}\n"
"QPushButton#googleButton1:hover, QPushButton#githubButton1:hover {\n"
"    background: #f8f8f8;\n"
"}\n"
"\n"
"/* Switch Button (Sign Up) */\n"
"QPushButton#switch_create_account_button {\n"
"    color: #1E8F53;\n"
"    font-size: 14px;\n"
"    border: none;\n"
"    background: transparent;\n"
"    padding: 5px;\n"
"    text-decoration: none;\n"
"}\n"
"QPushButton#switch_create_account_button:hover {\n"
"    font-weight: bold;\n"
"    text-decoration: underline;\n"
"}\n"
"\n"
"/* OR Label */\n"
"QLabel#orLabel_Login { /* Give the \"OR\" label an ID */\n"
"    color: #aaa;\n"
"    font-size: 13px;\n"
"    qproperty-alignment: 'AlignCenter';\n"
"    margin-top: 15px;\n"
"    margin-bottom: 15px;\n"
""
                        "}\n"
"\n"
"/* Decorative Text Container */\n"
"QWidget#WordContainer2 QLabel {\n"
"    font-size: 45px;\n"
"    font-weight: bold;\n"
"    color: #1E8F53;\n"
"    margin-bottom: 5px;\n"
"    qproperty-alignment: 'AlignCenter';\n"
"}\n"
"\n"
" QLabel#loginCameraPreview { background: #2C2C2C; border-radius: 10px; padding: 5px; color: #aaa; min-height: 200px; max-height: 240px; min-width: 280px; max-width: 320px; alignment: AlignCenter; }\n"
""));
        create_account_page = new QWidget();
        create_account_page->setObjectName("create_account_page");
        horizontalLayout_create_page = new QHBoxLayout(create_account_page);
        horizontalLayout_create_page->setSpacing(30);
        horizontalLayout_create_page->setObjectName("horizontalLayout_create_page");
        horizontalLayout_create_page->setContentsMargins(50, 30, 50, 30);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_create_page->addItem(horizontalSpacer_3);

        WordContainer = new QWidget(create_account_page);
        WordContainer->setObjectName("WordContainer");
        gridLayout = new QGridLayout(WordContainer);
        gridLayout->setObjectName("gridLayout");
        subtitleLabel2 = new QLabel(WordContainer);
        subtitleLabel2->setObjectName("subtitleLabel2");

        gridLayout->addWidget(subtitleLabel2, 2, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 5, 0, 1, 1);

        subtitleLabel1 = new QLabel(WordContainer);
        subtitleLabel1->setObjectName("subtitleLabel1");

        gridLayout->addWidget(subtitleLabel1, 1, 0, 1, 1);

        subtitleLabel2_4 = new QLabel(WordContainer);
        subtitleLabel2_4->setObjectName("subtitleLabel2_4");

        gridLayout->addWidget(subtitleLabel2_4, 4, 0, 1, 1);

        subtitleLabel2_3 = new QLabel(WordContainer);
        subtitleLabel2_3->setObjectName("subtitleLabel2_3");

        gridLayout->addWidget(subtitleLabel2_3, 3, 0, 1, 1);

        titleLabel = new QLabel(WordContainer);
        titleLabel->setObjectName("titleLabel");

        gridLayout->addWidget(titleLabel, 0, 0, 1, 1);


        horizontalLayout_create_page->addWidget(WordContainer);

        skipbutton = new QPushButton(create_account_page);
        skipbutton->setObjectName("skipbutton");

        horizontalLayout_create_page->addWidget(skipbutton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_create_page->addItem(horizontalSpacer_2);

        whiteCard = new QWidget(create_account_page);
        whiteCard->setObjectName("whiteCard");
        gridLayout_2 = new QGridLayout(whiteCard);
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalLayout_age_salary_fixed = new QHBoxLayout();
        horizontalLayout_age_salary_fixed->setObjectName("horizontalLayout_age_salary_fixed");
        verticalLayout_age_fixed = new QVBoxLayout();
        verticalLayout_age_fixed->setSpacing(0);
        verticalLayout_age_fixed->setObjectName("verticalLayout_age_fixed");
        label_8 = new QLabel(whiteCard);
        label_8->setObjectName("label_8");

        verticalLayout_age_fixed->addWidget(label_8);

        AgeSpinBox = new QSpinBox(whiteCard);
        AgeSpinBox->setObjectName("AgeSpinBox");

        verticalLayout_age_fixed->addWidget(AgeSpinBox);


        horizontalLayout_age_salary_fixed->addLayout(verticalLayout_age_fixed);

        verticalLayout_salary_fixed = new QVBoxLayout();
        verticalLayout_salary_fixed->setSpacing(0);
        verticalLayout_salary_fixed->setObjectName("verticalLayout_salary_fixed");
        label_10 = new QLabel(whiteCard);
        label_10->setObjectName("label_10");

        verticalLayout_salary_fixed->addWidget(label_10);

        SalaireDoubleSpinBox = new QDoubleSpinBox(whiteCard);
        SalaireDoubleSpinBox->setObjectName("SalaireDoubleSpinBox");
        SalaireDoubleSpinBox->setMaximum(9999999999.000000000000000);
        SalaireDoubleSpinBox->setSingleStep(1000.000000000000000);

        verticalLayout_salary_fixed->addWidget(SalaireDoubleSpinBox);


        horizontalLayout_age_salary_fixed->addLayout(verticalLayout_salary_fixed);


        gridLayout_2->addLayout(horizontalLayout_age_salary_fixed, 13, 0, 1, 1);

        horizontalLayout_social_create_fixed = new QHBoxLayout();
        horizontalLayout_social_create_fixed->setObjectName("horizontalLayout_social_create_fixed");
        githubButton = new QPushButton(whiteCard);
        githubButton->setObjectName("githubButton");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Static/Static/IOS_Google_icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        githubButton->setIcon(icon);

        horizontalLayout_social_create_fixed->addWidget(githubButton);

        googleButton = new QPushButton(whiteCard);
        googleButton->setObjectName("googleButton");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Static/Static/github logo.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        googleButton->setIcon(icon1);

        horizontalLayout_social_create_fixed->addWidget(googleButton);


        gridLayout_2->addLayout(horizontalLayout_social_create_fixed, 27, 0, 1, 2);

        label_9 = new QLabel(whiteCard);
        label_9->setObjectName("label_9");
        label_9->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(label_9, 25, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout_2->addItem(verticalSpacer_6, 20, 0, 1, 1);

        verticalSpacer_card_bottom_create = new QSpacerItem(20, 1, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_card_bottom_create, 28, 0, 1, 1);

        switch_login_butt = new QPushButton(whiteCard);
        switch_login_butt->setObjectName("switch_login_butt");

        gridLayout_2->addWidget(switch_login_butt, 26, 0, 1, 1);

        label_name = new QLabel(whiteCard);
        label_name->setObjectName("label_name");

        gridLayout_2->addWidget(label_name, 3, 0, 1, 1);

        NomEdit = new QLineEdit(whiteCard);
        NomEdit->setObjectName("NomEdit");
        NomEdit->setEchoMode(QLineEdit::EchoMode::Normal);

        gridLayout_2->addWidget(NomEdit, 6, 0, 1, 1);

        cameraButton = new QPushButton(whiteCard);
        cameraButton->setObjectName("cameraButton");
        cameraButton->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(cameraButton, 18, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 2, 0, 1, 1);

        passwordLabel = new QLabel(whiteCard);
        passwordLabel->setObjectName("passwordLabel");

        gridLayout_2->addWidget(passwordLabel, 14, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        biovec_logo = new QLabel(whiteCard);
        biovec_logo->setObjectName("biovec_logo");

        horizontalLayout_5->addWidget(biovec_logo);


        gridLayout_2->addLayout(horizontalLayout_5, 1, 0, 1, 1);

        IdEdit = new QLineEdit(whiteCard);
        IdEdit->setObjectName("IdEdit");

        gridLayout_2->addWidget(IdEdit, 4, 0, 1, 1);

        label_name_5 = new QLabel(whiteCard);
        label_name_5->setObjectName("label_name_5");

        gridLayout_2->addWidget(label_name_5, 11, 0, 1, 1);

        PrenomEdit = new QLineEdit(whiteCard);
        PrenomEdit->setObjectName("PrenomEdit");

        gridLayout_2->addWidget(PrenomEdit, 8, 0, 1, 1);

        label_name_4 = new QLabel(whiteCard);
        label_name_4->setObjectName("label_name_4");

        gridLayout_2->addWidget(label_name_4, 9, 0, 1, 1);

        AssuranceEdit = new QLineEdit(whiteCard);
        AssuranceEdit->setObjectName("AssuranceEdit");
        AssuranceEdit->setEchoMode(QLineEdit::EchoMode::Normal);

        gridLayout_2->addWidget(AssuranceEdit, 10, 0, 1, 1);

        label_name_2 = new QLabel(whiteCard);
        label_name_2->setObjectName("label_name_2");

        gridLayout_2->addWidget(label_name_2, 5, 0, 1, 1);

        create_account_button = new QPushButton(whiteCard);
        create_account_button->setObjectName("create_account_button");

        gridLayout_2->addWidget(create_account_button, 24, 0, 1, 1);

        PasswordCreateEdit = new QLineEdit(whiteCard);
        PasswordCreateEdit->setObjectName("PasswordCreateEdit");
        PasswordCreateEdit->setEchoMode(QLineEdit::EchoMode::Password);

        gridLayout_2->addWidget(PasswordCreateEdit, 15, 0, 1, 1);

        facecode = new QLineEdit(whiteCard);
        facecode->setObjectName("facecode");

        gridLayout_2->addWidget(facecode, 16, 0, 1, 1);

        label_name_3 = new QLabel(whiteCard);
        label_name_3->setObjectName("label_name_3");

        gridLayout_2->addWidget(label_name_3, 7, 0, 1, 1);

        Post = new QComboBox(whiteCard);
        Post->addItem(QString());
        Post->addItem(QString());
        Post->addItem(QString());
        Post->addItem(QString());
        Post->setObjectName("Post");

        gridLayout_2->addWidget(Post, 12, 0, 1, 1);


        horizontalLayout_create_page->addWidget(whiteCard);

        stackedWidget->addWidget(create_account_page);
        login_page = new QWidget();
        login_page->setObjectName("login_page");
        horizontalLayout_login_page_fixed = new QHBoxLayout(login_page);
        horizontalLayout_login_page_fixed->setSpacing(30);
        horizontalLayout_login_page_fixed->setObjectName("horizontalLayout_login_page_fixed");
        horizontalLayout_login_page_fixed->setContentsMargins(50, 30, 50, 30);
        whiteCard2 = new QWidget(login_page);
        whiteCard2->setObjectName("whiteCard2");
        verticalLayout_login_card_fixed = new QVBoxLayout(whiteCard2);
        verticalLayout_login_card_fixed->setSpacing(0);
        verticalLayout_login_card_fixed->setObjectName("verticalLayout_login_card_fixed");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        biovec_logo1 = new QLabel(whiteCard2);
        biovec_logo1->setObjectName("biovec_logo1");

        horizontalLayout->addWidget(biovec_logo1);


        verticalLayout_login_card_fixed->addLayout(horizontalLayout);

        label_11 = new QLabel(whiteCard2);
        label_11->setObjectName("label_11");

        verticalLayout_login_card_fixed->addWidget(label_11);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        EmailLineEdit = new QLineEdit(whiteCard2);
        EmailLineEdit->setObjectName("EmailLineEdit");

        gridLayout_3->addWidget(EmailLineEdit, 0, 0, 1, 1);

        emailButton = new QPushButton(whiteCard2);
        emailButton->setObjectName("emailButton");

        gridLayout_3->addWidget(emailButton, 0, 1, 1, 1);


        verticalLayout_login_card_fixed->addLayout(gridLayout_3);

        label_12 = new QLabel(whiteCard2);
        label_12->setObjectName("label_12");

        verticalLayout_login_card_fixed->addWidget(label_12);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        PasswordLineEdit = new QLineEdit(whiteCard2);
        PasswordLineEdit->setObjectName("PasswordLineEdit");
        PasswordLineEdit->setEchoMode(QLineEdit::EchoMode::Normal);

        gridLayout_4->addWidget(PasswordLineEdit, 0, 0, 1, 1);

        passwordButton = new QPushButton(whiteCard2);
        passwordButton->setObjectName("passwordButton");

        gridLayout_4->addWidget(passwordButton, 0, 1, 1, 1);


        verticalLayout_login_card_fixed->addLayout(gridLayout_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout_login_card_fixed->addItem(horizontalSpacer);

        cameraButton2 = new QPushButton(whiteCard2);
        cameraButton2->setObjectName("cameraButton2");

        verticalLayout_login_card_fixed->addWidget(cameraButton2);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_login_card_fixed->addItem(verticalSpacer);

        Log_in_button = new QPushButton(whiteCard2);
        Log_in_button->setObjectName("Log_in_button");

        verticalLayout_login_card_fixed->addWidget(Log_in_button);

        label_91 = new QLabel(whiteCard2);
        label_91->setObjectName("label_91");
        label_91->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_login_card_fixed->addWidget(label_91);

        horizontalLayout_social_login_fixed = new QHBoxLayout();
        horizontalLayout_social_login_fixed->setObjectName("horizontalLayout_social_login_fixed");
        githubButton1 = new QPushButton(whiteCard2);
        githubButton1->setObjectName("githubButton1");
        githubButton1->setIcon(icon);

        horizontalLayout_social_login_fixed->addWidget(githubButton1);

        googleButton1 = new QPushButton(whiteCard2);
        googleButton1->setObjectName("googleButton1");
        googleButton1->setIcon(icon1);

        horizontalLayout_social_login_fixed->addWidget(googleButton1);


        verticalLayout_login_card_fixed->addLayout(horizontalLayout_social_login_fixed);

        switch_create_account_button = new QPushButton(whiteCard2);
        switch_create_account_button->setObjectName("switch_create_account_button");

        verticalLayout_login_card_fixed->addWidget(switch_create_account_button);

        verticalSpacer_2 = new QSpacerItem(20, 15, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_login_card_fixed->addItem(verticalSpacer_2);

        audioFrame = new QFrame(whiteCard2);
        audioFrame->setObjectName("audioFrame");
        audioFrame->setFrameShape(QFrame::Shape::StyledPanel);
        audioFrame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_audio = new QVBoxLayout(audioFrame);
        verticalLayout_audio->setObjectName("verticalLayout_audio");
        audioGroupBox = new QGroupBox(audioFrame);
        audioGroupBox->setObjectName("audioGroupBox");
        gridLayout_audio = new QGridLayout(audioGroupBox);
        gridLayout_audio->setObjectName("gridLayout_audio");
        micLabel = new QLabel(audioGroupBox);
        micLabel->setObjectName("micLabel");

        gridLayout_audio->addWidget(micLabel, 0, 0, 1, 1);

        micSelector = new QComboBox(audioGroupBox);
        micSelector->setObjectName("micSelector");

        gridLayout_audio->addWidget(micSelector, 0, 1, 1, 1);

        refreshMicsButton = new QPushButton(audioGroupBox);
        refreshMicsButton->setObjectName("refreshMicsButton");

        gridLayout_audio->addWidget(refreshMicsButton, 0, 2, 1, 1);

        volumeLabel = new QLabel(audioGroupBox);
        volumeLabel->setObjectName("volumeLabel");

        gridLayout_audio->addWidget(volumeLabel, 1, 0, 1, 1);

        volumeSlider = new QSlider(audioGroupBox);
        volumeSlider->setObjectName("volumeSlider");
        volumeSlider->setMaximum(0);
        volumeSlider->setValue(0);
        volumeSlider->setOrientation(Qt::Orientation::Horizontal);

        gridLayout_audio->addWidget(volumeSlider, 1, 1, 1, 2);

        recognitionButton = new QPushButton(audioGroupBox);
        recognitionButton->setObjectName("recognitionButton");

        gridLayout_audio->addWidget(recognitionButton, 2, 0, 1, 1);

        speechStatus = new QLabel(audioGroupBox);
        speechStatus->setObjectName("speechStatus");
        speechStatus->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_audio->addWidget(speechStatus, 2, 1, 1, 1);

        autoFillUsername = new QCheckBox(audioGroupBox);
        autoFillUsername->setObjectName("autoFillUsername");
        autoFillUsername->setChecked(true);

        gridLayout_audio->addWidget(autoFillUsername, 2, 2, 1, 1);

        recognizedText = new QLabel(audioGroupBox);
        recognizedText->setObjectName("recognizedText");

        gridLayout_audio->addWidget(recognizedText, 3, 0, 1, 3);


        verticalLayout_audio->addWidget(audioGroupBox);


        verticalLayout_login_card_fixed->addWidget(audioFrame);


        horizontalLayout_login_page_fixed->addWidget(whiteCard2);

        horizontalSpacer_login_L = new QSpacerItem(1, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_login_page_fixed->addItem(horizontalSpacer_login_L);

        WordContainer2 = new QWidget(login_page);
        WordContainer2->setObjectName("WordContainer2");
        verticalLayout_51 = new QVBoxLayout(WordContainer2);
        verticalLayout_51->setObjectName("verticalLayout_51");
        titleLabel1 = new QLabel(WordContainer2);
        titleLabel1->setObjectName("titleLabel1");

        verticalLayout_51->addWidget(titleLabel1);

        subtitleLabel11 = new QLabel(WordContainer2);
        subtitleLabel11->setObjectName("subtitleLabel11");

        verticalLayout_51->addWidget(subtitleLabel11);

        subtitleLabel21 = new QLabel(WordContainer2);
        subtitleLabel21->setObjectName("subtitleLabel21");

        verticalLayout_51->addWidget(subtitleLabel21);

        subtitleLabel2_31 = new QLabel(WordContainer2);
        subtitleLabel2_31->setObjectName("subtitleLabel2_31");

        verticalLayout_51->addWidget(subtitleLabel2_31);

        subtitleLabel2_41 = new QLabel(WordContainer2);
        subtitleLabel2_41->setObjectName("subtitleLabel2_41");

        verticalLayout_51->addWidget(subtitleLabel2_41);

        verticalSpacer_4 = new QSpacerItem(20, 30, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_51->addItem(verticalSpacer_4);

        verticalSpacer_word_login_expand = new QSpacerItem(20, 1, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_51->addItem(verticalSpacer_word_login_expand);


        horizontalLayout_login_page_fixed->addWidget(WordContainer2);

        horizontalSpacer_login_R = new QSpacerItem(1, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_login_page_fixed->addItem(horizontalSpacer_login_R);

        stackedWidget->addWidget(login_page);

        verticalLayout_credentials->addWidget(stackedWidget);

        QWidget::setTabOrder(IdEdit, NomEdit);
        QWidget::setTabOrder(NomEdit, PrenomEdit);
        QWidget::setTabOrder(PrenomEdit, AssuranceEdit);
        QWidget::setTabOrder(AssuranceEdit, AgeSpinBox);
        QWidget::setTabOrder(AgeSpinBox, SalaireDoubleSpinBox);
        QWidget::setTabOrder(SalaireDoubleSpinBox, cameraButton);
        QWidget::setTabOrder(cameraButton, githubButton);
        QWidget::setTabOrder(githubButton, googleButton);
        QWidget::setTabOrder(googleButton, EmailLineEdit);
        QWidget::setTabOrder(EmailLineEdit, emailButton);
        QWidget::setTabOrder(emailButton, PasswordLineEdit);
        QWidget::setTabOrder(PasswordLineEdit, passwordButton);
        QWidget::setTabOrder(passwordButton, cameraButton2);
        QWidget::setTabOrder(cameraButton2, Log_in_button);
        QWidget::setTabOrder(Log_in_button, githubButton1);
        QWidget::setTabOrder(githubButton1, googleButton1);
        QWidget::setTabOrder(googleButton1, switch_create_account_button);
        QWidget::setTabOrder(switch_create_account_button, micSelector);
        QWidget::setTabOrder(micSelector, refreshMicsButton);
        QWidget::setTabOrder(refreshMicsButton, volumeSlider);
        QWidget::setTabOrder(volumeSlider, recognitionButton);
        QWidget::setTabOrder(recognitionButton, autoFillUsername);

        retranslateUi(credentials);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(credentials);
    } // setupUi

    void retranslateUi(QWidget *credentials)
    {
        credentials->setWindowTitle(QCoreApplication::translate("credentials", "Form", nullptr));
        subtitleLabel2->setText(QCoreApplication::translate("credentials", "Management", nullptr));
        subtitleLabel2->setProperty("sublabel", QVariant(QString()));
        subtitleLabel1->setText(QCoreApplication::translate("credentials", "Simplifying", nullptr));
        subtitleLabel1->setProperty("sublabel", QVariant(QString()));
        subtitleLabel2_4->setText(QCoreApplication::translate("credentials", "Research", nullptr));
        subtitleLabel2_4->setProperty("sublabel", QVariant(QString()));
        subtitleLabel2_3->setText(QCoreApplication::translate("credentials", "Advancing", nullptr));
        subtitleLabel2_3->setProperty("sublabel", QVariant(QString()));
        titleLabel->setText(QCoreApplication::translate("credentials", "Hello ", nullptr));
        skipbutton->setText(QCoreApplication::translate("credentials", "Skip", nullptr));
        label_8->setText(QCoreApplication::translate("credentials", "Age", nullptr));
        label_10->setText(QCoreApplication::translate("credentials", "Salary", nullptr));
        githubButton->setText(QCoreApplication::translate("credentials", "Sign Up with Google", nullptr));
        googleButton->setText(QCoreApplication::translate("credentials", "Sign Up with GitHub", nullptr));
        label_9->setText(QCoreApplication::translate("credentials", "- OR -", nullptr));
        switch_login_butt->setText(QCoreApplication::translate("credentials", "Already have an Account? Log In", nullptr));
        label_name->setText(QCoreApplication::translate("credentials", "ID:", nullptr));
        NomEdit->setPlaceholderText(QCoreApplication::translate("credentials", "Enter your Last Name here", nullptr));
        cameraButton->setText(QCoreApplication::translate("credentials", "Face-Save", nullptr));
        passwordLabel->setText(QCoreApplication::translate("credentials", "Password", nullptr));
        biovec_logo->setText(QString());
        IdEdit->setPlaceholderText(QCoreApplication::translate("credentials", "Enter your ID here", nullptr));
        label_name_5->setText(QCoreApplication::translate("credentials", "Post:", nullptr));
        PrenomEdit->setPlaceholderText(QCoreApplication::translate("credentials", "Enter your First Name here", nullptr));
        label_name_4->setText(QCoreApplication::translate("credentials", "Insurance :", nullptr));
        AssuranceEdit->setPlaceholderText(QCoreApplication::translate("credentials", "Enter your Insurance here", nullptr));
        label_name_2->setText(QCoreApplication::translate("credentials", "Last Name:", nullptr));
        create_account_button->setText(QCoreApplication::translate("credentials", "Create Account", nullptr));
        PasswordCreateEdit->setPlaceholderText(QCoreApplication::translate("credentials", "Enter your password here", nullptr));
        facecode->setPlaceholderText(QCoreApplication::translate("credentials", "Your facecode will appear here once it's been scanned", nullptr));
        label_name_3->setText(QCoreApplication::translate("credentials", "First Name", nullptr));
        Post->setItemText(0, QCoreApplication::translate("credentials", "Analyst", nullptr));
        Post->setItemText(1, QCoreApplication::translate("credentials", "Developer", nullptr));
        Post->setItemText(2, QCoreApplication::translate("credentials", "Designer", nullptr));
        Post->setItemText(3, QCoreApplication::translate("credentials", "Manager", nullptr));

        biovec_logo1->setText(QString());
        label_11->setText(QCoreApplication::translate("credentials", "ID", nullptr));
        EmailLineEdit->setText(QString());
        EmailLineEdit->setPlaceholderText(QCoreApplication::translate("credentials", "Enter your ID here", nullptr));
#if QT_CONFIG(tooltip)
        emailButton->setToolTip(QCoreApplication::translate("credentials", "Click to use voice recognition for email", nullptr));
#endif // QT_CONFIG(tooltip)
        emailButton->setText(QCoreApplication::translate("credentials", "Voice", nullptr));
        label_12->setText(QCoreApplication::translate("credentials", "Password", nullptr));
        PasswordLineEdit->setPlaceholderText(QCoreApplication::translate("credentials", "Enter your Password here", nullptr));
#if QT_CONFIG(tooltip)
        passwordButton->setToolTip(QCoreApplication::translate("credentials", "Click to use voice recognition for password", nullptr));
#endif // QT_CONFIG(tooltip)
        passwordButton->setText(QCoreApplication::translate("credentials", "Voice", nullptr));
        cameraButton2->setText(QCoreApplication::translate("credentials", "Face-Check", nullptr));
        Log_in_button->setText(QCoreApplication::translate("credentials", "Log In", nullptr));
        label_91->setText(QCoreApplication::translate("credentials", "- OR -", nullptr));
        githubButton1->setText(QCoreApplication::translate("credentials", "Log In with Google", nullptr));
        googleButton1->setText(QCoreApplication::translate("credentials", "Log In with GitHub", nullptr));
        switch_create_account_button->setText(QCoreApplication::translate("credentials", "Don't have an Account? Sign Up", nullptr));
        audioGroupBox->setTitle(QCoreApplication::translate("credentials", "Voice Recognition Settings", nullptr));
        micLabel->setText(QCoreApplication::translate("credentials", "Microphone:", nullptr));
        micSelector->setPlaceholderText(QCoreApplication::translate("credentials", "Select Microphone", nullptr));
        refreshMicsButton->setText(QCoreApplication::translate("credentials", "Refresh", nullptr));
        volumeLabel->setText(QCoreApplication::translate("credentials", "Volume:", nullptr));
        recognitionButton->setText(QCoreApplication::translate("credentials", "Start Listening", nullptr));
        speechStatus->setText(QCoreApplication::translate("credentials", "Ready", nullptr));
        autoFillUsername->setText(QCoreApplication::translate("credentials", "Auto-fill username", nullptr));
        recognizedText->setText(QString());
        titleLabel1->setText(QCoreApplication::translate("credentials", "Welcome back ", nullptr));
        subtitleLabel11->setText(QCoreApplication::translate("credentials", "Simplifying", nullptr));
        subtitleLabel11->setProperty("sublabel", QVariant(QString()));
        subtitleLabel21->setText(QCoreApplication::translate("credentials", "Management", nullptr));
        subtitleLabel21->setProperty("sublabel", QVariant(QString()));
        subtitleLabel2_31->setText(QCoreApplication::translate("credentials", "Advancing", nullptr));
        subtitleLabel2_31->setProperty("sublabel", QVariant(QString()));
        subtitleLabel2_41->setText(QCoreApplication::translate("credentials", "Research", nullptr));
        subtitleLabel2_41->setProperty("sublabel", QVariant(QString()));
    } // retranslateUi

};

namespace Ui {
    class credentials: public Ui_credentials {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDENTIALS_H
