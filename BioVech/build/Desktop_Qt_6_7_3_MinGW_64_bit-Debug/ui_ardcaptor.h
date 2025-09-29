/********************************************************************************
** Form generated from reading UI file 'ardcaptor.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARDCAPTOR_H
#define UI_ARDCAPTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ardcaptor
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *temperatureLabel;
    QPushButton *sendButton;
    QLabel *statusLabel;
    QLineEdit *lineEdit;
    QPushButton *GoBack;

    void setupUi(QMainWindow *Ardcaptor)
    {
        if (Ardcaptor->objectName().isEmpty())
            Ardcaptor->setObjectName("Ardcaptor");
        Ardcaptor->resize(400, 300);
        centralwidget = new QWidget(Ardcaptor);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        temperatureLabel = new QLabel(centralwidget);
        temperatureLabel->setObjectName("temperatureLabel");
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        temperatureLabel->setFont(font);
        temperatureLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(temperatureLabel);

        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName("sendButton");

        verticalLayout->addWidget(sendButton);

        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(statusLabel);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");

        verticalLayout->addWidget(lineEdit);

        GoBack = new QPushButton(centralwidget);
        GoBack->setObjectName("GoBack");

        verticalLayout->addWidget(GoBack);

        Ardcaptor->setCentralWidget(centralwidget);

        retranslateUi(Ardcaptor);

        QMetaObject::connectSlotsByName(Ardcaptor);
    } // setupUi

    void retranslateUi(QMainWindow *Ardcaptor)
    {
        Ardcaptor->setWindowTitle(QCoreApplication::translate("Ardcaptor", "Temperature Monitor", nullptr));
        temperatureLabel->setText(QCoreApplication::translate("Ardcaptor", "Current Temp: --\302\260C", nullptr));
        sendButton->setText(QCoreApplication::translate("Ardcaptor", "Get Temperature", nullptr));
        statusLabel->setText(QCoreApplication::translate("Ardcaptor", "Ready", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("Ardcaptor", "Enter the Vaccine name", nullptr));
        GoBack->setText(QCoreApplication::translate("Ardcaptor", "Return to Inventory", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ardcaptor: public Ui_Ardcaptor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARDCAPTOR_H
