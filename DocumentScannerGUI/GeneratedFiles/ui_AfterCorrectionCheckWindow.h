/********************************************************************************
** Form generated from reading UI file 'AfterCorrectionCheckWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AFTERCORRECTIONCHECKWINDOW_H
#define UI_AFTERCORRECTIONCHECKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AfterCorrectionCheckWindow
{
public:
    QPushButton *AutomaticButton;
    QPushButton *SaveFileButton;
    QPushButton *DontChangeButton;
    QPushButton *ManualButton;
    QLabel *label_3;
    QLabel *resultLabel;
    QPushButton *pushButton;

    void setupUi(QDialog *AfterCorrectionCheckWindow)
    {
        if (AfterCorrectionCheckWindow->objectName().isEmpty())
            AfterCorrectionCheckWindow->setObjectName(QStringLiteral("AfterCorrectionCheckWindow"));
        AfterCorrectionCheckWindow->resize(509, 555);
        AutomaticButton = new QPushButton(AfterCorrectionCheckWindow);
        AutomaticButton->setObjectName(QStringLiteral("AutomaticButton"));
        AutomaticButton->setGeometry(QRect(30, 500, 75, 23));
        SaveFileButton = new QPushButton(AfterCorrectionCheckWindow);
        SaveFileButton->setObjectName(QStringLiteral("SaveFileButton"));
        SaveFileButton->setGeometry(QRect(410, 500, 75, 23));
        DontChangeButton = new QPushButton(AfterCorrectionCheckWindow);
        DontChangeButton->setObjectName(QStringLiteral("DontChangeButton"));
        DontChangeButton->setGeometry(QRect(240, 500, 121, 23));
        ManualButton = new QPushButton(AfterCorrectionCheckWindow);
        ManualButton->setObjectName(QStringLiteral("ManualButton"));
        ManualButton->setGeometry(QRect(130, 500, 75, 23));
        label_3 = new QLabel(AfterCorrectionCheckWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(220, 20, 47, 13));
        resultLabel = new QLabel(AfterCorrectionCheckWindow);
        resultLabel->setObjectName(QStringLiteral("resultLabel"));
        resultLabel->setGeometry(QRect(110, 50, 300, 400));
        pushButton = new QPushButton(AfterCorrectionCheckWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 240, 75, 23));

        retranslateUi(AfterCorrectionCheckWindow);

        QMetaObject::connectSlotsByName(AfterCorrectionCheckWindow);
    } // setupUi

    void retranslateUi(QDialog *AfterCorrectionCheckWindow)
    {
        AfterCorrectionCheckWindow->setWindowTitle(QApplication::translate("AfterCorrectionCheckWindow", "AfterCorrectionCheckWindow", nullptr));
        AutomaticButton->setText(QApplication::translate("AfterCorrectionCheckWindow", "Auto", nullptr));
        SaveFileButton->setText(QApplication::translate("AfterCorrectionCheckWindow", "Save file", nullptr));
        DontChangeButton->setText(QApplication::translate("AfterCorrectionCheckWindow", "Keep without change", nullptr));
        ManualButton->setText(QApplication::translate("AfterCorrectionCheckWindow", "Manual", nullptr));
        label_3->setText(QApplication::translate("AfterCorrectionCheckWindow", "Result", nullptr));
        resultLabel->setText(QApplication::translate("AfterCorrectionCheckWindow", "Choose one of the correction methods", nullptr));
        pushButton->setText(QApplication::translate("AfterCorrectionCheckWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AfterCorrectionCheckWindow: public Ui_AfterCorrectionCheckWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFTERCORRECTIONCHECKWINDOW_H
