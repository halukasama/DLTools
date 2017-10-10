/********************************************************************************
** Form generated from reading UI file 'ConfigDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGDIALOG_H
#define UI_CONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_ConfigDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *ipLineEdit;
    QLabel *label_2;
    QLineEdit *gatewayLineEdit;
    QLineEdit *subnetLineEdit;
    QLabel *label_3;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ConfigDialog)
    {
        if (ConfigDialog->objectName().isEmpty())
            ConfigDialog->setObjectName(QStringLiteral("ConfigDialog"));
        ConfigDialog->resize(370, 200);
        ConfigDialog->setMinimumSize(QSize(370, 200));
        ConfigDialog->setMaximumSize(QSize(370, 200));
        gridLayout = new QGridLayout(ConfigDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(ConfigDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        ipLineEdit = new QLineEdit(ConfigDialog);
        ipLineEdit->setObjectName(QStringLiteral("ipLineEdit"));
        ipLineEdit->setEnabled(false);

        gridLayout->addWidget(ipLineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(ConfigDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        gatewayLineEdit = new QLineEdit(ConfigDialog);
        gatewayLineEdit->setObjectName(QStringLiteral("gatewayLineEdit"));
        gatewayLineEdit->setEnabled(false);

        gridLayout->addWidget(gatewayLineEdit, 2, 1, 1, 1);

        subnetLineEdit = new QLineEdit(ConfigDialog);
        subnetLineEdit->setObjectName(QStringLiteral("subnetLineEdit"));
        subnetLineEdit->setEnabled(false);

        gridLayout->addWidget(subnetLineEdit, 1, 1, 1, 1);

        label_3 = new QLabel(ConfigDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        buttonBox = new QDialogButtonBox(ConfigDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 2);


        retranslateUi(ConfigDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConfigDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConfigDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfigDialog)
    {
        ConfigDialog->setWindowTitle(QApplication::translate("ConfigDialog", "\350\256\276\345\244\207\344\277\241\346\201\257", Q_NULLPTR));
        label->setText(QApplication::translate("ConfigDialog", "IP\345\234\260\345\235\200:", Q_NULLPTR));
        label_2->setText(QApplication::translate("ConfigDialog", "\345\255\220\347\275\221\346\216\251\347\240\201:", Q_NULLPTR));
        label_3->setText(QApplication::translate("ConfigDialog", "\347\275\221\345\205\263:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ConfigDialog: public Ui_ConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGDIALOG_H
