/********************************************************************************
** Form generated from reading UI file 'DetectionWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETECTIONWINDOW_H
#define UI_DETECTIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DetectionWindow
{
public:

    void setupUi(QWidget *DetectionWindow)
    {
        if (DetectionWindow->objectName().isEmpty())
            DetectionWindow->setObjectName(QStringLiteral("DetectionWindow"));
        DetectionWindow->resize(546, 341);

        retranslateUi(DetectionWindow);

        QMetaObject::connectSlotsByName(DetectionWindow);
    } // setupUi

    void retranslateUi(QWidget *DetectionWindow)
    {
        DetectionWindow->setWindowTitle(QApplication::translate("DetectionWindow", "DetectionWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DetectionWindow: public Ui_DetectionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETECTIONWINDOW_H
