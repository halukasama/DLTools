/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QPushButton *aboutButton;
    QPushButton *connectButton;
    QPushButton *refreshButton;
    QPushButton *clearButton;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *upgrade;
    QPushButton *findAndStopButton;
    QPushButton *configButton;
    QPushButton *restartButton;
    QTreeWidget *treeWidget;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(825, 597);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icon/Icon/DeviceToolbox.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        aboutButton = new QPushButton(Widget);
        aboutButton->setObjectName(QStringLiteral("aboutButton"));

        gridLayout->addWidget(aboutButton, 0, 9, 1, 2);

        connectButton = new QPushButton(Widget);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setEnabled(false);

        gridLayout->addWidget(connectButton, 0, 4, 1, 1);

        refreshButton = new QPushButton(Widget);
        refreshButton->setObjectName(QStringLiteral("refreshButton"));
        refreshButton->setEnabled(false);

        gridLayout->addWidget(refreshButton, 0, 1, 1, 1);

        clearButton = new QPushButton(Widget);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        gridLayout->addWidget(clearButton, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        upgrade = new QToolButton(Widget);
        upgrade->setObjectName(QStringLiteral("upgrade"));
        upgrade->setEnabled(false);

        gridLayout->addWidget(upgrade, 0, 7, 1, 1);

        findAndStopButton = new QPushButton(Widget);
        findAndStopButton->setObjectName(QStringLiteral("findAndStopButton"));

        gridLayout->addWidget(findAndStopButton, 0, 0, 1, 1);

        configButton = new QPushButton(Widget);
        configButton->setObjectName(QStringLiteral("configButton"));
        configButton->setEnabled(false);

        gridLayout->addWidget(configButton, 0, 5, 1, 1);

        restartButton = new QPushButton(Widget);
        restartButton->setObjectName(QStringLiteral("restartButton"));
        restartButton->setEnabled(false);

        gridLayout->addWidget(restartButton, 0, 6, 1, 1);

        treeWidget = new QTreeWidget(Widget);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setAlternatingRowColors(false);
        treeWidget->setSelectionMode(QAbstractItemView::ContiguousSelection);
        treeWidget->setTextElideMode(Qt::ElideRight);
        treeWidget->header()->setCascadingSectionResizes(false);
        treeWidget->header()->setDefaultSectionSize(130);
        treeWidget->header()->setHighlightSections(false);
        treeWidget->header()->setProperty("showSortIndicator", QVariant(false));
        treeWidget->header()->setStretchLastSection(true);

        gridLayout->addWidget(treeWidget, 1, 0, 1, 11);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 8, 1, 1);

        QWidget::setTabOrder(findAndStopButton, refreshButton);
        QWidget::setTabOrder(refreshButton, clearButton);
        QWidget::setTabOrder(clearButton, connectButton);
        QWidget::setTabOrder(connectButton, configButton);
        QWidget::setTabOrder(configButton, restartButton);
        QWidget::setTabOrder(restartButton, treeWidget);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\350\256\276\345\244\207\345\267\245\345\205\267\347\256\261", Q_NULLPTR));
        aboutButton->setText(QApplication::translate("Widget", "\345\205\263\344\272\216(&A)", Q_NULLPTR));
        connectButton->setText(QApplication::translate("Widget", "\350\277\236\346\216\245\350\256\276\345\244\207", Q_NULLPTR));
        refreshButton->setText(QApplication::translate("Widget", "\345\210\267\346\226\260\345\210\227\350\241\250", Q_NULLPTR));
        clearButton->setText(QApplication::translate("Widget", "\346\270\205\347\251\272\345\210\227\350\241\250", Q_NULLPTR));
        upgrade->setText(QApplication::translate("Widget", "\345\274\200\345\247\213\345\215\207\347\272\247", Q_NULLPTR));
        findAndStopButton->setText(QApplication::translate("Widget", "\346\220\234\347\264\242\350\256\276\345\244\207", Q_NULLPTR));
        configButton->setText(QApplication::translate("Widget", "\351\205\215\347\275\256\350\256\276\345\244\207", Q_NULLPTR));
        restartButton->setText(QApplication::translate("Widget", "\351\207\215\345\220\257", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(5, QApplication::translate("Widget", "\345\215\207\347\272\247\344\277\241\346\201\257", Q_NULLPTR));
        ___qtreewidgetitem->setText(4, QApplication::translate("Widget", "\350\277\236\346\216\245\347\212\266\346\200\201", Q_NULLPTR));
        ___qtreewidgetitem->setText(3, QApplication::translate("Widget", "\350\256\276\345\244\207ID", Q_NULLPTR));
        ___qtreewidgetitem->setText(2, QApplication::translate("Widget", "MAC\345\234\260\345\235\200", Q_NULLPTR));
        ___qtreewidgetitem->setText(1, QApplication::translate("Widget", "\350\256\276\345\244\207\345\236\213\345\217\267", Q_NULLPTR));
        ___qtreewidgetitem->setText(0, QApplication::translate("Widget", "\350\256\276\345\244\207IP", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
