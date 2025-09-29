/********************************************************************************
** Form generated from reading UI file 'cameradialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERADIALOG_H
#define UI_CAMERADIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CameraDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *cameraComboBox;
    QPushButton *settingsButton;
    QVideoWidget *viewfinder;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *captureButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *CameraDialog)
    {
        if (CameraDialog->objectName().isEmpty())
            CameraDialog->setObjectName("CameraDialog");
        CameraDialog->resize(640, 550);
        verticalLayout = new QVBoxLayout(CameraDialog);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(CameraDialog);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        cameraComboBox = new QComboBox(CameraDialog);
        cameraComboBox->setObjectName("cameraComboBox");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cameraComboBox->sizePolicy().hasHeightForWidth());
        cameraComboBox->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(cameraComboBox);

        settingsButton = new QPushButton(CameraDialog);
        settingsButton->setObjectName("settingsButton");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(settingsButton->sizePolicy().hasHeightForWidth());
        settingsButton->setSizePolicy(sizePolicy1);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/settings.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        settingsButton->setIcon(icon);

        horizontalLayout_2->addWidget(settingsButton);


        verticalLayout->addLayout(horizontalLayout_2);

        viewfinder = new QVideoWidget(CameraDialog);
        viewfinder->setObjectName("viewfinder");

        verticalLayout->addWidget(viewfinder);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        captureButton = new QPushButton(CameraDialog);
        captureButton->setObjectName("captureButton");
        captureButton->setMinimumSize(QSize(120, 30));

        horizontalLayout->addWidget(captureButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(CameraDialog);

        QMetaObject::connectSlotsByName(CameraDialog);
    } // setupUi

    void retranslateUi(QDialog *CameraDialog)
    {
        CameraDialog->setWindowTitle(QCoreApplication::translate("CameraDialog", "Barcode Scanner", nullptr));
        label->setText(QCoreApplication::translate("CameraDialog", "Camera:", nullptr));
        settingsButton->setText(QCoreApplication::translate("CameraDialog", "Settings", nullptr));
        captureButton->setText(QCoreApplication::translate("CameraDialog", "Capture", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CameraDialog: public Ui_CameraDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERADIALOG_H
