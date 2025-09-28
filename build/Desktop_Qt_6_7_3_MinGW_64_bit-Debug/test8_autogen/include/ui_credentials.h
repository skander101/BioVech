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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_credentials
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *pushButton;
    QFrame *background_login;
    QWidget *whiteCard;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_9;
    QPushButton *googleButton;
    QPushButton *githubButton;
    QGridLayout *gridLayout_8;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QWidget *background_3;
    QLineEdit *lineEdit_7;
    QLabel *label_8;
    QLineEdit *lineEdit_8;
    QLabel *label_10;
    QLineEdit *lineEdit_9;
    QSpacerItem *verticalSpacer_3;
    QPushButton *Sign_in_2;
    QLabel *label_9;
    QPushButton *Loginbutt;
    QLabel *biovec_logo;
    QWidget *WordContainer;
    QWidget *widget_2;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *titleLabel;
    QLabel *subtitleLabel1;
    QLabel *subtitleLabel2;
    QLabel *subtitleLabel2_3;
    QLabel *subtitleLabel2_4;
    QWidget *page_3;
    QPushButton *pushButton1;
    QFrame *background_login2;
    QWidget *whiteCard2;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_71;
    QGridLayout *gridLayout_91;
    QPushButton *googleButton1;
    QPushButton *githubButton1;
    QGridLayout *gridLayout_81;
    QVBoxLayout *verticalLayout_31;
    QLabel *label_11;
    QWidget *background_31;
    QLineEdit *lineEdit_71;
    QLabel *label_81;
    QLineEdit *lineEdit_81;
    QSpacerItem *verticalSpacer_31;
    QPushButton *Sign_in_21;
    QLabel *label_91;
    QPushButton *SignIn_2;
    QLabel *biovec_logo1;
    QWidget *WordContainer2;
    QWidget *widget_21;
    QWidget *layoutWidget_21;
    QVBoxLayout *verticalLayout_51;
    QLabel *titleLabel1;
    QLabel *subtitleLabel11;
    QLabel *subtitleLabel21;
    QLabel *subtitleLabel2_31;
    QLabel *subtitleLabel2_41;

    void setupUi(QWidget *credentials)
    {
        if (credentials->objectName().isEmpty())
            credentials->setObjectName("credentials");
        credentials->resize(1280, 720);
        stackedWidget = new QStackedWidget(credentials);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 1280, 720));
        page = new QWidget();
        page->setObjectName("page");
        page->setStyleSheet(QString::fromUtf8("\n"
"     QWidget #background_login {\n"
"       border-image: url(\":/Static/Static/white_bg.jpg\")  0 0 0 0 stretch stretch ;\n"
"     background-repeat: no-repeat;\n"
"       background-position: center;\n"
"       background-size: cover;\n"
"   position: absolute; /* Ensures fixed positioning */\n"
"       right: 5%; /* Keeps it to the right with margin */\n"
"       top: 50%;\n"
"       transform: translateY(-50%); /* Centers vertically */\n"
"       width: 40%;\n"
"   }QWidget #whiteCard {\n"
"       /*	background: rgba(255, 255, 255, 0.9); /* Semi-transparent white */\n"
"       background: white;\n"
"       border-radius: 20px;\n"
"       padding: 30px;\n"
"       position: absolute; /* Ensures fixed positioning */\n"
"       right: 5%; /* Keeps it to the right with margin */\n"
"       top: 50%;\n"
"       transform: translateY(-50%); /* Centers vertically */\n"
"       width: 40%; /* Adjust width as needed */\n"
"   }\n"
"   QLabel#biovec_logo {\n"
"           border-image: url(\":/Static/Static/logo"
                        ".png\")0 0 0 0 stretch stretch ;\n"
"       background-repeat: no-repeat;\n"
"       background-position: center;\n"
"       background-size: contain;\n"
"   }\n"
"\n"
"   /* Title */\n"
"   QLabel#titleLabel {\n"
"       font-size: 50px;\n"
"       font-weight: bold;\n"
"       color: #00703c;\n"
"   }\n"
"\n"
"   QLabel#subtitleLabel2_3 {\n"
"       font-size: 35px;\n"
"       color: #00703c;\n"
"       font-weight: bold\n"
"   }\n"
"   QLabel#subtitleLabel2_4 {\n"
"       font-size: 35px;\n"
"       color: #00703c;\n"
"   }\n"
"\n"
"   QLabel#subtitleLabel1 {\n"
"       font-size: 35px;\n"
"       font-weight: bold;\n"
"       color: #00703c;\n"
"   }\n"
"   QLabel#subtitleLabel2 {\n"
"       font-size: 35px;\n"
"       color: #00703c;\n"
"   }\n"
"\n"
"   /* Input fields */\n"
"   QLineEdit {\n"
"       background: rgba(176, 186, 195, 0.4); /* Same as 66B0BAC3 */\n"
"       border-radius: 20px;\n"
"       border: 0px;\n"
"       padding: 15px;\n"
"       font-size: 12px;\n"
"       color: #7C838A;\n"
"   }"
                        "\n"
"\n"
"   /* Placeholder text */\n"
"   QLineEdit::placeholder {\n"
"       color: #7C838A;\n"
"       font-size: 18px;\n"
"   }\n"
"\n"
"   /* Main button */\n"
"   QPushButton#Sign_in {\n"
"       background: #1E8F53;\n"
"       border-radius: 20px;\n"
"       padding: 15px;\n"
"       font-size: 16px;\n"
"       font-weight: bold;\n"
"       color: white;\n"
"   }\n"
"\n"
"   /* Hover effect */\n"
"   QPushButton#Sign_in:hover {\n"
"       background: #17663D;\n"
"   }\n"
"\n"
"   /* Social login buttons */\n"
"   QPushButton#googleButton, QPushButton#githubButton {\n"
"           background-color: rgb(72, 72, 72);\n"
"\n"
"       border-radius: 20px;\n"
"       padding: 6px;\n"
"       background: #f2f2f2;\n"
"       font-weight: bold;\n"
"\n"
"   }\n"
"\n"
"   QPushButton#googleButton:hover, QPushButton#githubButton:hover {\n"
"       background: rgb(230, 230, 230);\n"
"       font-weight: bold;\n"
"\n"
"   }\n"
"\n"
"   "));
        page->setProperty("currentIndex", QVariant(1));
        pushButton = new QPushButton(page);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(190, 190, 83, 29));
        background_login = new QFrame(page);
        background_login->setObjectName("background_login");
        background_login->setGeometry(QRect(1, 1, 1280, 720));
        background_login->setFrameShape(QFrame::Shape::StyledPanel);
        background_login->setFrameShadow(QFrame::Shadow::Raised);
        whiteCard = new QWidget(background_login);
        whiteCard->setObjectName("whiteCard");
        whiteCard->setGeometry(QRect(0, 0, 641, 581));
        layoutWidget = new QWidget(whiteCard);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(90, 111, 451, 447));
        gridLayout_7 = new QGridLayout(layoutWidget);
        gridLayout_7->setObjectName("gridLayout_7");
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName("gridLayout_9");
        googleButton = new QPushButton(layoutWidget);
        googleButton->setObjectName("googleButton");
        googleButton->setMinimumSize(QSize(80, 40));
        googleButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Static/Static/github logo.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        googleButton->setIcon(icon);

        gridLayout_9->addWidget(googleButton, 1, 1, 1, 1);

        githubButton = new QPushButton(layoutWidget);
        githubButton->setObjectName("githubButton");
        githubButton->setMinimumSize(QSize(80, 40));
        githubButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Static/Static/IOS_Google_icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        githubButton->setIcon(icon1);

        gridLayout_9->addWidget(githubButton, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_9, 1, 0, 1, 1);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName("gridLayout_8");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");

        verticalLayout_3->addWidget(label_7);

        background_3 = new QWidget(layoutWidget);
        background_3->setObjectName("background_3");

        verticalLayout_3->addWidget(background_3);

        lineEdit_7 = new QLineEdit(layoutWidget);
        lineEdit_7->setObjectName("lineEdit_7");

        verticalLayout_3->addWidget(lineEdit_7);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName("label_8");

        verticalLayout_3->addWidget(label_8);

        lineEdit_8 = new QLineEdit(layoutWidget);
        lineEdit_8->setObjectName("lineEdit_8");

        verticalLayout_3->addWidget(lineEdit_8);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName("label_10");

        verticalLayout_3->addWidget(label_10);

        lineEdit_9 = new QLineEdit(layoutWidget);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout_3->addWidget(lineEdit_9);


        gridLayout_8->addLayout(verticalLayout_3, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_8->addItem(verticalSpacer_3, 1, 0, 1, 1);

        Sign_in_2 = new QPushButton(layoutWidget);
        Sign_in_2->setObjectName("Sign_in_2");
        Sign_in_2->setStyleSheet(QString::fromUtf8("background: #1E8F53;\n"
"border-radius: 20px;\n"
"padding: 15px;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"color: white;"));

        gridLayout_8->addWidget(Sign_in_2, 2, 0, 1, 1);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName("label_9");

        gridLayout_8->addWidget(label_9, 4, 0, 1, 1);

        Loginbutt = new QPushButton(layoutWidget);
        Loginbutt->setObjectName("Loginbutt");
        Loginbutt->setMinimumSize(QSize(80, 40));
        Loginbutt->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"           border-radius: 10px;    /* Makes corners rounded */\n"
"       padding: 5px 10px;;\n"
"\n"
"   }\n"
"\n"
"   QPushButton:hover {\n"
"       font-weight: bold;  /* Make text bold */\n"
"   }"));

        gridLayout_8->addWidget(Loginbutt, 3, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_8, 0, 0, 1, 1);

        biovec_logo = new QLabel(whiteCard);
        biovec_logo->setObjectName("biovec_logo");
        biovec_logo->setGeometry(QRect(180, 30, 281, 71));
        WordContainer = new QWidget(background_login);
        WordContainer->setObjectName("WordContainer");
        WordContainer->setGeometry(QRect(650, 50, 431, 531));
        widget_2 = new QWidget(WordContainer);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(169, 59, 161, 71));
        layoutWidget_2 = new QWidget(WordContainer);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(10, 60, 421, 302));
        verticalLayout_5 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        titleLabel = new QLabel(layoutWidget_2);
        titleLabel->setObjectName("titleLabel");

        verticalLayout_5->addWidget(titleLabel);

        subtitleLabel1 = new QLabel(layoutWidget_2);
        subtitleLabel1->setObjectName("subtitleLabel1");

        verticalLayout_5->addWidget(subtitleLabel1);

        subtitleLabel2 = new QLabel(layoutWidget_2);
        subtitleLabel2->setObjectName("subtitleLabel2");

        verticalLayout_5->addWidget(subtitleLabel2);

        subtitleLabel2_3 = new QLabel(layoutWidget_2);
        subtitleLabel2_3->setObjectName("subtitleLabel2_3");

        verticalLayout_5->addWidget(subtitleLabel2_3);

        subtitleLabel2_4 = new QLabel(layoutWidget_2);
        subtitleLabel2_4->setObjectName("subtitleLabel2_4");

        verticalLayout_5->addWidget(subtitleLabel2_4);

        stackedWidget->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        page_3->setStyleSheet(QString::fromUtf8("\n"
"    QWidget #background_login2 {\n"
"      border-image: url(\":/Static/Static/white_bg.jpg\")  0 0 0 0 stretch stretch ;\n"
"    background-repeat: no-repeat;\n"
"      background-position: center;\n"
"      background-size: cover;\n"
"  position: absolute; /* Ensures fixed positioning */\n"
"      right: 5%; /* Keeps it to the right with margin */\n"
"      top: 50%;\n"
"      transform: translateY(-50%); /* Centers vertically */\n"
"      width: 40%;\n"
"  }QWidget #whiteCard2 {\n"
"      /*	background: rgba(255, 255, 255, 0.9); /* Semi-transparent white */\n"
"      background: white;\n"
"      border-radius: 20px;\n"
"      padding: 30px;\n"
"      position: absolute; /* Ensures fixed positioning */\n"
"      right: 5%; /* Keeps it to the right with margin */\n"
"      top: 50%;\n"
"      transform: translateY(-50%); /* Centers vertically */\n"
"      width: 40%; /* Adjust width as needed */\n"
"  }\n"
"  QLabel#biovec_logo1 {\n"
"          border-image: url(\":/Static/Static/logo.png\")0 0 0 0 stret"
                        "ch stretch ;\n"
"      background-repeat: no-repeat;\n"
"      background-position: center;\n"
"      background-size: contain;\n"
"  }\n"
"\n"
"  /* Title */\n"
"  QLabel#titleLabel1 {\n"
"      font-size: 50px;\n"
"      font-weight: bold;\n"
"      color: #00703c;\n"
"  }\n"
"\n"
"  QLabel#subtitleLabel2_31 {\n"
"      font-size: 35px;\n"
"      color: #00703c;\n"
"      font-weight: bold\n"
"  }\n"
"  QLabel#subtitleLabel2_41 {\n"
"      font-size: 35px;\n"
"      color: #00703c;\n"
"  }\n"
"\n"
"  QLabel#subtitleLabel11 {\n"
"      font-size: 35px;\n"
"      font-weight: bold;\n"
"      color: #00703c;\n"
"  }\n"
"  QLabel#subtitleLabel21 {\n"
"      font-size: 35px;\n"
"      color: #00703c;\n"
"  }\n"
"\n"
"  /* Input fields */\n"
"  QLineEdit {\n"
"      background: rgba(176, 186, 195, 0.4); /* Same as 66B0BAC3 */\n"
"      border-radius: 20px;\n"
"      border: 0px;\n"
"      padding: 15px;\n"
"      font-size: 12px;\n"
"      color: #7C838A;\n"
"  }\n"
"\n"
"  /* Placeholder text */\n"
"  QLineEdit::"
                        "placeholder {\n"
"      color: #7C838A;\n"
"      font-size: 18px;\n"
"  }\n"
"\n"
"  /* Main button */\n"
"  QPushButton#Sign_in_21 {\n"
"      background: #1E8F53;\n"
"      border-radius: 20px;\n"
"      padding: 15px;\n"
"      font-size: 16px;\n"
"      font-weight: bold;\n"
"      color: white;\n"
"  }\n"
"\n"
"  /* Hover effect */\n"
"  QPushButton#Sign_in_2:hover {\n"
"      background: #17663D;\n"
"  }\n"
"\n"
"  /* Social login buttons */\n"
"  QPushButton#googleButton1, QPushButton#githubButton1 {\n"
"          background-color: rgb(72, 72, 72);\n"
"\n"
"      border-radius: 20px;\n"
"      padding: 6px;\n"
"      background: #f2f2f2;\n"
"      font-weight: bold;\n"
"\n"
"  }\n"
"\n"
"  QPushButton#googleButton1:hover, QPushButton#githubButton1:hover {\n"
"      background: rgb(230, 230, 230);\n"
"      font-weight: bold;\n"
"\n"
"  }\n"
"\n"
"  "));
        page_3->setProperty("currentIndex", QVariant(1));
        pushButton1 = new QPushButton(page_3);
        pushButton1->setObjectName("pushButton1");
        pushButton1->setGeometry(QRect(190, 190, 83, 29));
        background_login2 = new QFrame(page_3);
        background_login2->setObjectName("background_login2");
        background_login2->setGeometry(QRect(1, 1, 1280, 720));
        background_login2->setFrameShape(QFrame::Shape::StyledPanel);
        background_login2->setFrameShadow(QFrame::Shadow::Raised);
        whiteCard2 = new QWidget(background_login2);
        whiteCard2->setObjectName("whiteCard2");
        whiteCard2->setGeometry(QRect(580, 0, 641, 581));
        layoutWidget1 = new QWidget(whiteCard2);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(90, 111, 451, 447));
        gridLayout_71 = new QGridLayout(layoutWidget1);
        gridLayout_71->setObjectName("gridLayout_71");
        gridLayout_71->setContentsMargins(0, 0, 0, 0);
        gridLayout_91 = new QGridLayout();
        gridLayout_91->setObjectName("gridLayout_91");
        googleButton1 = new QPushButton(layoutWidget1);
        googleButton1->setObjectName("googleButton1");
        googleButton1->setMinimumSize(QSize(80, 40));
        googleButton1->setStyleSheet(QString::fromUtf8(""));
        googleButton1->setIcon(icon);

        gridLayout_91->addWidget(googleButton1, 1, 1, 1, 1);

        githubButton1 = new QPushButton(layoutWidget1);
        githubButton1->setObjectName("githubButton1");
        githubButton1->setMinimumSize(QSize(80, 40));
        githubButton1->setStyleSheet(QString::fromUtf8(""));
        githubButton1->setIcon(icon1);

        gridLayout_91->addWidget(githubButton1, 1, 0, 1, 1);


        gridLayout_71->addLayout(gridLayout_91, 1, 0, 1, 1);

        gridLayout_81 = new QGridLayout();
        gridLayout_81->setObjectName("gridLayout_81");
        verticalLayout_31 = new QVBoxLayout();
        verticalLayout_31->setObjectName("verticalLayout_31");
        label_11 = new QLabel(layoutWidget1);
        label_11->setObjectName("label_11");

        verticalLayout_31->addWidget(label_11);

        background_31 = new QWidget(layoutWidget1);
        background_31->setObjectName("background_31");

        verticalLayout_31->addWidget(background_31);

        lineEdit_71 = new QLineEdit(layoutWidget1);
        lineEdit_71->setObjectName("lineEdit_71");

        verticalLayout_31->addWidget(lineEdit_71);

        label_81 = new QLabel(layoutWidget1);
        label_81->setObjectName("label_81");

        verticalLayout_31->addWidget(label_81);

        lineEdit_81 = new QLineEdit(layoutWidget1);
        lineEdit_81->setObjectName("lineEdit_81");

        verticalLayout_31->addWidget(lineEdit_81);


        gridLayout_81->addLayout(verticalLayout_31, 0, 0, 1, 1);

        verticalSpacer_31 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_81->addItem(verticalSpacer_31, 1, 0, 1, 1);

        Sign_in_21 = new QPushButton(layoutWidget1);
        Sign_in_21->setObjectName("Sign_in_21");
        Sign_in_21->setStyleSheet(QString::fromUtf8("background: #1E8F53;\n"
"border-radius: 20px;\n"
"padding: 15px;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"color: white;"));

        gridLayout_81->addWidget(Sign_in_21, 2, 0, 1, 1);

        label_91 = new QLabel(layoutWidget1);
        label_91->setObjectName("label_91");

        gridLayout_81->addWidget(label_91, 4, 0, 1, 1);

        SignIn_2 = new QPushButton(layoutWidget1);
        SignIn_2->setObjectName("SignIn_2");
        SignIn_2->setMinimumSize(QSize(80, 40));
        SignIn_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"          border-radius: 10px;    /* Makes corners rounded */\n"
"      padding: 5px 10px;;\n"
"\n"
"  }\n"
"\n"
"  QPushButton:hover {\n"
"      font-weight: bold;  /* Make text bold */\n"
"  }"));

        gridLayout_81->addWidget(SignIn_2, 3, 0, 1, 1);


        gridLayout_71->addLayout(gridLayout_81, 0, 0, 1, 1);

        biovec_logo1 = new QLabel(whiteCard2);
        biovec_logo1->setObjectName("biovec_logo1");
        biovec_logo1->setGeometry(QRect(180, 30, 281, 71));
        WordContainer2 = new QWidget(background_login2);
        WordContainer2->setObjectName("WordContainer2");
        WordContainer2->setGeometry(QRect(10, 60, 431, 531));
        widget_21 = new QWidget(WordContainer2);
        widget_21->setObjectName("widget_21");
        widget_21->setGeometry(QRect(169, 59, 161, 71));
        layoutWidget_21 = new QWidget(WordContainer2);
        layoutWidget_21->setObjectName("layoutWidget_21");
        layoutWidget_21->setGeometry(QRect(10, 60, 421, 302));
        verticalLayout_51 = new QVBoxLayout(layoutWidget_21);
        verticalLayout_51->setObjectName("verticalLayout_51");
        verticalLayout_51->setContentsMargins(0, 0, 0, 0);
        titleLabel1 = new QLabel(layoutWidget_21);
        titleLabel1->setObjectName("titleLabel1");

        verticalLayout_51->addWidget(titleLabel1);

        subtitleLabel11 = new QLabel(layoutWidget_21);
        subtitleLabel11->setObjectName("subtitleLabel11");

        verticalLayout_51->addWidget(subtitleLabel11);

        subtitleLabel21 = new QLabel(layoutWidget_21);
        subtitleLabel21->setObjectName("subtitleLabel21");

        verticalLayout_51->addWidget(subtitleLabel21);

        subtitleLabel2_31 = new QLabel(layoutWidget_21);
        subtitleLabel2_31->setObjectName("subtitleLabel2_31");

        verticalLayout_51->addWidget(subtitleLabel2_31);

        subtitleLabel2_41 = new QLabel(layoutWidget_21);
        subtitleLabel2_41->setObjectName("subtitleLabel2_41");

        verticalLayout_51->addWidget(subtitleLabel2_41);

        stackedWidget->addWidget(page_3);

        retranslateUi(credentials);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(credentials);
    } // setupUi

    void retranslateUi(QWidget *credentials)
    {
        credentials->setWindowTitle(QCoreApplication::translate("credentials", "credentials", nullptr));
        pushButton->setText(QCoreApplication::translate("credentials", "ptnn", nullptr));
        googleButton->setText(QCoreApplication::translate("credentials", "Sign Up with GitHub", nullptr));
        githubButton->setText(QCoreApplication::translate("credentials", "Sign Up with Google", nullptr));
        label_7->setText(QCoreApplication::translate("credentials", "Full Name", nullptr));
        lineEdit_7->setText(QString());
        lineEdit_7->setPlaceholderText(QCoreApplication::translate("credentials", "Enter your Fullname here", nullptr));
        label_8->setText(QCoreApplication::translate("credentials", "Email", nullptr));
        lineEdit_8->setText(QString());
        lineEdit_8->setPlaceholderText(QCoreApplication::translate("credentials", "Enter your Email here", nullptr));
        label_10->setText(QCoreApplication::translate("credentials", "Password", nullptr));
        lineEdit_9->setText(QString());
        lineEdit_9->setPlaceholderText(QCoreApplication::translate("credentials", "Enter your password here", nullptr));
        Sign_in_2->setText(QCoreApplication::translate("credentials", "Create Account", nullptr));
        label_9->setText(QCoreApplication::translate("credentials", "                                                                -OR-", nullptr));
        Loginbutt->setText(QCoreApplication::translate("credentials", "Arleady have an Account? Log In", nullptr));
        biovec_logo->setText(QString());
        titleLabel->setText(QCoreApplication::translate("credentials", "Welcome back ", nullptr));
        subtitleLabel1->setText(QCoreApplication::translate("credentials", "Simplifying", nullptr));
        subtitleLabel1->setProperty("sublabel", QVariant(QString()));
        subtitleLabel2->setText(QCoreApplication::translate("credentials", "Management", nullptr));
        subtitleLabel2->setProperty("sublabel", QVariant(QString()));
        subtitleLabel2_3->setText(QCoreApplication::translate("credentials", "Advancing", nullptr));
        subtitleLabel2_3->setProperty("sublabel", QVariant(QString()));
        subtitleLabel2_4->setText(QCoreApplication::translate("credentials", "Research", nullptr));
        subtitleLabel2_4->setProperty("sublabel", QVariant(QString()));
        pushButton1->setText(QCoreApplication::translate("credentials", "ptnn", nullptr));
        googleButton1->setText(QCoreApplication::translate("credentials", "Log In with GitHub", nullptr));
        githubButton1->setText(QCoreApplication::translate("credentials", "Log In with Google", nullptr));
        label_11->setText(QCoreApplication::translate("credentials", "Email", nullptr));
        lineEdit_71->setText(QString());
        lineEdit_71->setPlaceholderText(QCoreApplication::translate("credentials", "Enter your Email here", nullptr));
        label_81->setText(QCoreApplication::translate("credentials", "Password", nullptr));
        lineEdit_81->setText(QString());
        lineEdit_81->setPlaceholderText(QCoreApplication::translate("credentials", "Enter your Password here", nullptr));
        Sign_in_21->setText(QCoreApplication::translate("credentials", "Log In", nullptr));
        label_91->setText(QCoreApplication::translate("credentials", "                                                                -OR-", nullptr));
        SignIn_2->setText(QCoreApplication::translate("credentials", "Don't have an Account? Sign Up", nullptr));
        biovec_logo1->setText(QString());
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
