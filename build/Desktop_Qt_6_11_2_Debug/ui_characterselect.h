/********************************************************************************
** Form generated from reading UI file 'characterselect.ui'
**
** Created by: Qt User Interface Compiler version 6.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARACTERSELECT_H
#define UI_CHARACTERSELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CharacterSelect
{
public:

    void setupUi(QWidget *CharacterSelect)
    {
        if (CharacterSelect->objectName().isEmpty())
            CharacterSelect->setObjectName("CharacterSelect");
        CharacterSelect->resize(16, 16);

        retranslateUi(CharacterSelect);

        QMetaObject::connectSlotsByName(CharacterSelect);
    } // setupUi

    void retranslateUi(QWidget *CharacterSelect)
    {
        CharacterSelect->setWindowTitle(QCoreApplication::translate("CharacterSelect", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CharacterSelect: public Ui_CharacterSelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARACTERSELECT_H
