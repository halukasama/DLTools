/********************************************************************************
** Form generated from reading UI file 'AbuoutDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABUOUTDIALOG_H
#define UI_ABUOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AbuoutDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label;
    QPushButton *btnOk;
    QLabel *labelVersion;
    QLabel *label_2;

    void setupUi(QDialog *AbuoutDialog)
    {
        if (AbuoutDialog->objectName().isEmpty())
            AbuoutDialog->setObjectName(QStringLiteral("AbuoutDialog"));
        AbuoutDialog->resize(373, 144);
        gridLayout = new QGridLayout(AbuoutDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(AbuoutDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/Icon/res/icon/DeviceToolbox.ico")));
        label_3->setScaledContents(false);
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setWordWrap(false);

        gridLayout->addWidget(label_3, 0, 0, 2, 1);

        label = new QLabel(AbuoutDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        btnOk = new QPushButton(AbuoutDialog);
        btnOk->setObjectName(QStringLiteral("btnOk"));

        gridLayout->addWidget(btnOk, 0, 2, 1, 1);

        labelVersion = new QLabel(AbuoutDialog);
        labelVersion->setObjectName(QStringLiteral("labelVersion"));

        gridLayout->addWidget(labelVersion, 1, 1, 1, 1);

        label_2 = new QLabel(AbuoutDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 1, 1, 1);


        retranslateUi(AbuoutDialog);

        QMetaObject::connectSlotsByName(AbuoutDialog);
    } // setupUi

    void retranslateUi(QDialog *AbuoutDialog)
    {
        AbuoutDialog->setWindowTitle(QApplication::translate("AbuoutDialog", "Dialog", Q_NULLPTR));
        label_3->setText(QString());
        label->setText(QApplication::translate("AbuoutDialog", "\350\256\276\345\244\207\345\267\245\345\205\267\347\256\261", Q_NULLPTR));
        btnOk->setText(QApplication::translate("AbuoutDialog", "\347\241\256\345\256\232", Q_NULLPTR));
        labelVersion->setText(QApplication::translate("AbuoutDialog", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("AbuoutDialog", "\345\214\227\344\272\254\345\214\227\346\270\205\350\247\206\351\200\232\344\277\241\346\201\257\346\212\200\346\234\257\346\234\211\351\231\220\345\205\254\345\217\270\n"
"www.bqvision.com\n"
"\347\211\210\346\235\203\346\211\200\346\234\211(C) 2012-2014", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AbuoutDialog: public Ui_AbuoutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABUOUTDIALOG_H
