/********************************************************************************
** Form generated from reading UI file 'boardsetup.ui'
**
** Created by: Qt User Interface Compiler version 6.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOARDSETUP_H
#define UI_BOARDSETUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BoardSetup
{
public:

    void setupUi(QWidget *BoardSetup)
    {
        if (BoardSetup->objectName().isEmpty())
            BoardSetup->setObjectName("BoardSetup");
        BoardSetup->resize(16, 16);

        retranslateUi(BoardSetup);

        QMetaObject::connectSlotsByName(BoardSetup);
    } // setupUi

    void retranslateUi(QWidget *BoardSetup)
    {
        BoardSetup->setWindowTitle(QCoreApplication::translate("BoardSetup", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BoardSetup: public Ui_BoardSetup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOARDSETUP_H
