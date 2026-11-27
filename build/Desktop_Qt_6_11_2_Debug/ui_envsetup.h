/********************************************************************************
** Form generated from reading UI file 'envsetup.ui'
**
** Created by: Qt User Interface Compiler version 6.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENVSETUP_H
#define UI_ENVSETUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EnvSetup
{
public:
    QToolBox *toolBox;
    QWidget *page;
    QWidget *page_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *EnvSetup)
    {
        if (EnvSetup->objectName().isEmpty())
            EnvSetup->setObjectName("EnvSetup");
        EnvSetup->resize(400, 300);
        toolBox = new QToolBox(EnvSetup);
        toolBox->setObjectName("toolBox");
        toolBox->setGeometry(QRect(50, 50, 68, 126));
        page = new QWidget();
        page->setObjectName("page");
        page->setGeometry(QRect(0, 0, 68, 68));
        toolBox->addItem(page, QString::fromUtf8("Page 1"));
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        page_2->setGeometry(QRect(0, 0, 68, 68));
        toolBox->addItem(page_2, QString::fromUtf8("Page 2"));
        pushButton = new QPushButton(EnvSetup);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(210, 60, 84, 23));
        pushButton_2 = new QPushButton(EnvSetup);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(220, 140, 84, 23));

        retranslateUi(EnvSetup);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(EnvSetup);
    } // setupUi

    void retranslateUi(QWidget *EnvSetup)
    {
        EnvSetup->setWindowTitle(QCoreApplication::translate("EnvSetup", "Form", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("EnvSetup", "Page 1", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("EnvSetup", "Page 2", nullptr));
        pushButton->setText(QCoreApplication::translate("EnvSetup", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("EnvSetup", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EnvSetup: public Ui_EnvSetup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENVSETUP_H
