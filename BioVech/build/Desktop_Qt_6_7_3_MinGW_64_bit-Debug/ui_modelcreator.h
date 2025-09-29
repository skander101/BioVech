/********************************************************************************
** Form generated from reading UI file 'modelcreator.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODELCREATOR_H
#define UI_MODELCREATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModelCreator
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *controlsLayout;
    QGroupBox *sceneGroup;
    QVBoxLayout *verticalLayout_3;
    QTreeWidget *sceneTree;
    QGroupBox *shapeGroup;
    QVBoxLayout *verticalLayout;
    QComboBox *shapeComboBox;
    QPushButton *addShapeButton;
    QGroupBox *transformGroup;
    QFormLayout *formLayout;
    QLabel *positionLabel;
    QLabel *positionXLabel;
    QDoubleSpinBox *positionXSpinBox;
    QLabel *positionYLabel;
    QDoubleSpinBox *positionYSpinBox;
    QLabel *positionZLabel;
    QDoubleSpinBox *positionZSpinBox;
    QLabel *rotationLabel;
    QLabel *rotationXLabel;
    QDoubleSpinBox *rotationXSpinBox;
    QLabel *rotationYLabel;
    QDoubleSpinBox *rotationYSpinBox;
    QLabel *rotationZLabel;
    QDoubleSpinBox *rotationZSpinBox;
    QLabel *scaleLabel;
    QDoubleSpinBox *scaleSpinBox;
    QGroupBox *gridGroup;
    QFormLayout *formLayout_2;
    QCheckBox *snapToGridCheckBox;
    QLabel *gridSizeLabel;
    QDoubleSpinBox *gridSizeSpinBox;
    QGroupBox *appearanceGroup;
    QVBoxLayout *verticalLayout_2;
    QPushButton *colorButton;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *viewLayout;

    void setupUi(QWidget *ModelCreator)
    {
        if (ModelCreator->objectName().isEmpty())
            ModelCreator->setObjectName("ModelCreator");
        ModelCreator->resize(1200, 800);
        horizontalLayout = new QHBoxLayout(ModelCreator);
        horizontalLayout->setObjectName("horizontalLayout");
        controlsLayout = new QVBoxLayout();
        controlsLayout->setObjectName("controlsLayout");
        controlsLayout->setSizeConstraint(QLayout::SetFixedSize);
        sceneGroup = new QGroupBox(ModelCreator);
        sceneGroup->setObjectName("sceneGroup");
        verticalLayout_3 = new QVBoxLayout(sceneGroup);
        verticalLayout_3->setObjectName("verticalLayout_3");
        sceneTree = new QTreeWidget(sceneGroup);
        sceneTree->setObjectName("sceneTree");

        verticalLayout_3->addWidget(sceneTree);


        controlsLayout->addWidget(sceneGroup);

        shapeGroup = new QGroupBox(ModelCreator);
        shapeGroup->setObjectName("shapeGroup");
        shapeGroup->setMinimumSize(QSize(200, 0));
        shapeGroup->setMaximumSize(QSize(250, 16777215));
        verticalLayout = new QVBoxLayout(shapeGroup);
        verticalLayout->setObjectName("verticalLayout");
        shapeComboBox = new QComboBox(shapeGroup);
        shapeComboBox->addItem(QString());
        shapeComboBox->addItem(QString());
        shapeComboBox->addItem(QString());
        shapeComboBox->addItem(QString());
        shapeComboBox->setObjectName("shapeComboBox");

        verticalLayout->addWidget(shapeComboBox);

        addShapeButton = new QPushButton(shapeGroup);
        addShapeButton->setObjectName("addShapeButton");

        verticalLayout->addWidget(addShapeButton);


        controlsLayout->addWidget(shapeGroup);

        transformGroup = new QGroupBox(ModelCreator);
        transformGroup->setObjectName("transformGroup");
        formLayout = new QFormLayout(transformGroup);
        formLayout->setObjectName("formLayout");
        positionLabel = new QLabel(transformGroup);
        positionLabel->setObjectName("positionLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, positionLabel);

        positionXLabel = new QLabel(transformGroup);
        positionXLabel->setObjectName("positionXLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, positionXLabel);

        positionXSpinBox = new QDoubleSpinBox(transformGroup);
        positionXSpinBox->setObjectName("positionXSpinBox");
        positionXSpinBox->setMinimum(-100.000000000000000);
        positionXSpinBox->setMaximum(100.000000000000000);

        formLayout->setWidget(1, QFormLayout::FieldRole, positionXSpinBox);

        positionYLabel = new QLabel(transformGroup);
        positionYLabel->setObjectName("positionYLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, positionYLabel);

        positionYSpinBox = new QDoubleSpinBox(transformGroup);
        positionYSpinBox->setObjectName("positionYSpinBox");
        positionYSpinBox->setMinimum(-100.000000000000000);
        positionYSpinBox->setMaximum(100.000000000000000);

        formLayout->setWidget(2, QFormLayout::FieldRole, positionYSpinBox);

        positionZLabel = new QLabel(transformGroup);
        positionZLabel->setObjectName("positionZLabel");

        formLayout->setWidget(3, QFormLayout::LabelRole, positionZLabel);

        positionZSpinBox = new QDoubleSpinBox(transformGroup);
        positionZSpinBox->setObjectName("positionZSpinBox");
        positionZSpinBox->setMinimum(-100.000000000000000);
        positionZSpinBox->setMaximum(100.000000000000000);

        formLayout->setWidget(3, QFormLayout::FieldRole, positionZSpinBox);

        rotationLabel = new QLabel(transformGroup);
        rotationLabel->setObjectName("rotationLabel");

        formLayout->setWidget(4, QFormLayout::LabelRole, rotationLabel);

        rotationXLabel = new QLabel(transformGroup);
        rotationXLabel->setObjectName("rotationXLabel");

        formLayout->setWidget(5, QFormLayout::LabelRole, rotationXLabel);

        rotationXSpinBox = new QDoubleSpinBox(transformGroup);
        rotationXSpinBox->setObjectName("rotationXSpinBox");
        rotationXSpinBox->setMinimum(-360.000000000000000);
        rotationXSpinBox->setMaximum(360.000000000000000);

        formLayout->setWidget(5, QFormLayout::FieldRole, rotationXSpinBox);

        rotationYLabel = new QLabel(transformGroup);
        rotationYLabel->setObjectName("rotationYLabel");

        formLayout->setWidget(6, QFormLayout::LabelRole, rotationYLabel);

        rotationYSpinBox = new QDoubleSpinBox(transformGroup);
        rotationYSpinBox->setObjectName("rotationYSpinBox");
        rotationYSpinBox->setMinimum(-360.000000000000000);
        rotationYSpinBox->setMaximum(360.000000000000000);

        formLayout->setWidget(6, QFormLayout::FieldRole, rotationYSpinBox);

        rotationZLabel = new QLabel(transformGroup);
        rotationZLabel->setObjectName("rotationZLabel");

        formLayout->setWidget(7, QFormLayout::LabelRole, rotationZLabel);

        rotationZSpinBox = new QDoubleSpinBox(transformGroup);
        rotationZSpinBox->setObjectName("rotationZSpinBox");
        rotationZSpinBox->setMinimum(-360.000000000000000);
        rotationZSpinBox->setMaximum(360.000000000000000);

        formLayout->setWidget(7, QFormLayout::FieldRole, rotationZSpinBox);

        scaleLabel = new QLabel(transformGroup);
        scaleLabel->setObjectName("scaleLabel");

        formLayout->setWidget(8, QFormLayout::LabelRole, scaleLabel);

        scaleSpinBox = new QDoubleSpinBox(transformGroup);
        scaleSpinBox->setObjectName("scaleSpinBox");
        scaleSpinBox->setMinimum(0.010000000000000);
        scaleSpinBox->setMaximum(100.000000000000000);
        scaleSpinBox->setSingleStep(0.100000000000000);
        scaleSpinBox->setValue(1.000000000000000);

        formLayout->setWidget(8, QFormLayout::FieldRole, scaleSpinBox);


        controlsLayout->addWidget(transformGroup);

        gridGroup = new QGroupBox(ModelCreator);
        gridGroup->setObjectName("gridGroup");
        formLayout_2 = new QFormLayout(gridGroup);
        formLayout_2->setObjectName("formLayout_2");
        snapToGridCheckBox = new QCheckBox(gridGroup);
        snapToGridCheckBox->setObjectName("snapToGridCheckBox");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, snapToGridCheckBox);

        gridSizeLabel = new QLabel(gridGroup);
        gridSizeLabel->setObjectName("gridSizeLabel");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, gridSizeLabel);

        gridSizeSpinBox = new QDoubleSpinBox(gridGroup);
        gridSizeSpinBox->setObjectName("gridSizeSpinBox");
        gridSizeSpinBox->setMinimum(0.100000000000000);
        gridSizeSpinBox->setMaximum(10.000000000000000);
        gridSizeSpinBox->setSingleStep(0.100000000000000);
        gridSizeSpinBox->setValue(1.000000000000000);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, gridSizeSpinBox);


        controlsLayout->addWidget(gridGroup);

        appearanceGroup = new QGroupBox(ModelCreator);
        appearanceGroup->setObjectName("appearanceGroup");
        verticalLayout_2 = new QVBoxLayout(appearanceGroup);
        verticalLayout_2->setObjectName("verticalLayout_2");
        colorButton = new QPushButton(appearanceGroup);
        colorButton->setObjectName("colorButton");

        verticalLayout_2->addWidget(colorButton);


        controlsLayout->addWidget(appearanceGroup);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        controlsLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(controlsLayout);

        viewLayout = new QVBoxLayout();
        viewLayout->setObjectName("viewLayout");
        viewLayout->setSizeConstraint(QLayout::SetDefaultConstraint);

        horizontalLayout->addLayout(viewLayout);


        retranslateUi(ModelCreator);

        QMetaObject::connectSlotsByName(ModelCreator);
    } // setupUi

    void retranslateUi(QWidget *ModelCreator)
    {
        ModelCreator->setWindowTitle(QCoreApplication::translate("ModelCreator", "3D Model Creator", nullptr));
        sceneGroup->setTitle(QCoreApplication::translate("ModelCreator", "Scene", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = sceneTree->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("ModelCreator", "Objects", nullptr));
        shapeGroup->setTitle(QCoreApplication::translate("ModelCreator", "Shape", nullptr));
        shapeComboBox->setItemText(0, QCoreApplication::translate("ModelCreator", "Cube", nullptr));
        shapeComboBox->setItemText(1, QCoreApplication::translate("ModelCreator", "Sphere", nullptr));
        shapeComboBox->setItemText(2, QCoreApplication::translate("ModelCreator", "Cylinder", nullptr));
        shapeComboBox->setItemText(3, QCoreApplication::translate("ModelCreator", "Cone", nullptr));

        addShapeButton->setText(QCoreApplication::translate("ModelCreator", "Add Shape", nullptr));
        transformGroup->setTitle(QCoreApplication::translate("ModelCreator", "Transform", nullptr));
        positionLabel->setText(QCoreApplication::translate("ModelCreator", "Position:", nullptr));
        positionXLabel->setText(QCoreApplication::translate("ModelCreator", "X:", nullptr));
        positionYLabel->setText(QCoreApplication::translate("ModelCreator", "Y:", nullptr));
        positionZLabel->setText(QCoreApplication::translate("ModelCreator", "Z:", nullptr));
        rotationLabel->setText(QCoreApplication::translate("ModelCreator", "Rotation:", nullptr));
        rotationXLabel->setText(QCoreApplication::translate("ModelCreator", "X:", nullptr));
        rotationYLabel->setText(QCoreApplication::translate("ModelCreator", "Y:", nullptr));
        rotationZLabel->setText(QCoreApplication::translate("ModelCreator", "Z:", nullptr));
        scaleLabel->setText(QCoreApplication::translate("ModelCreator", "Scale:", nullptr));
        gridGroup->setTitle(QCoreApplication::translate("ModelCreator", "Grid Settings", nullptr));
        snapToGridCheckBox->setText(QCoreApplication::translate("ModelCreator", "Snap to Grid", nullptr));
        gridSizeLabel->setText(QCoreApplication::translate("ModelCreator", "Grid Size:", nullptr));
        appearanceGroup->setTitle(QCoreApplication::translate("ModelCreator", "Appearance", nullptr));
        colorButton->setText(QCoreApplication::translate("ModelCreator", "Change Color", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModelCreator: public Ui_ModelCreator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODELCREATOR_H
