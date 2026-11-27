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
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BoardSetup
{
public:
    QLabel *label;

    void setupUi(QWidget *BoardSetup)
    {
        if (BoardSetup->objectName().isEmpty())
            BoardSetup->setObjectName("BoardSetup");
        BoardSetup->resize(132, 250);
        label = new QLabel(BoardSetup);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 111, 51));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label->setWordWrap(true);

        retranslateUi(BoardSetup);

        QMetaObject::connectSlotsByName(BoardSetup);
    } // setupUi

    void retranslateUi(QWidget *BoardSetup)
    {
        BoardSetup->setWindowTitle(QCoreApplication::translate("BoardSetup", "Form", nullptr));
        label->setText(QCoreApplication::translate("BoardSetup", "Insert the width and height of the game board", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BoardSetup: public Ui_BoardSetup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOARDSETUP_H
