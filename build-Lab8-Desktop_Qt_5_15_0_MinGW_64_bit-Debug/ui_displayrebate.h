/********************************************************************************
** Form generated from reading UI file 'displayrebate.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYREBATE_H
#define UI_DISPLAYREBATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_DisplayRebate
{
public:

    void setupUi(QDialog *DisplayRebate)
    {
        if (DisplayRebate->objectName().isEmpty())
            DisplayRebate->setObjectName(QString::fromUtf8("DisplayRebate"));
        DisplayRebate->resize(400, 400);

        retranslateUi(DisplayRebate);

        QMetaObject::connectSlotsByName(DisplayRebate);
    } // setupUi

    void retranslateUi(QDialog *DisplayRebate)
    {
        DisplayRebate->setWindowTitle(QCoreApplication::translate("DisplayRebate", "Rebate Due", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DisplayRebate: public Ui_DisplayRebate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYREBATE_H
