/********************************************************************************
** Form generated from reading UI file 'PerspectiveCorrectionWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSPECTIVECORRECTIONWINDOW_H
#define UI_PERSPECTIVECORRECTIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PerspectiveCorrectionWindow
{
public:
    QPushButton *AutomaticButton;
    QPushButton *ManualButton;
    QRadioButton *radioButton;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *SaveFileButton;
    QLabel *label;
    QLabel *label_2;
    QPushButton *AbandonCorrectionButton;
    QPushButton *SaveButton;

    void setupUi(QWidget *PerspectiveCorrectionWindow)
    {
        if (PerspectiveCorrectionWindow->objectName().isEmpty())
            PerspectiveCorrectionWindow->setObjectName(QStringLiteral("PerspectiveCorrectionWindow"));
        PerspectiveCorrectionWindow->resize(808, 643);
        AutomaticButton = new QPushButton(PerspectiveCorrectionWindow);
        AutomaticButton->setObjectName(QStringLiteral("AutomaticButton"));
        AutomaticButton->setGeometry(QRect(100, 550, 75, 23));
        ManualButton = new QPushButton(PerspectiveCorrectionWindow);
        ManualButton->setObjectName(QStringLiteral("ManualButton"));
        ManualButton->setGeometry(QRect(210, 550, 75, 23));
        radioButton = new QRadioButton(PerspectiveCorrectionWindow);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(20, 500, 221, 17));
        label_3 = new QLabel(PerspectiveCorrectionWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(460, 30, 47, 13));
        label_4 = new QLabel(PerspectiveCorrectionWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 30, 64, 13));
        SaveFileButton = new QPushButton(PerspectiveCorrectionWindow);
        SaveFileButton->setObjectName(QStringLiteral("SaveFileButton"));
        SaveFileButton->setGeometry(QRect(720, 600, 75, 23));
        label = new QLabel(PerspectiveCorrectionWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 70, 300, 400));
        label_2 = new QLabel(PerspectiveCorrectionWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(450, 70, 300, 400));
        AbandonCorrectionButton = new QPushButton(PerspectiveCorrectionWindow);
        AbandonCorrectionButton->setObjectName(QStringLiteral("AbandonCorrectionButton"));
        AbandonCorrectionButton->setGeometry(QRect(320, 550, 121, 23));
        SaveButton = new QPushButton(PerspectiveCorrectionWindow);
        SaveButton->setObjectName(QStringLiteral("SaveButton"));
        SaveButton->setGeometry(QRect(620, 600, 81, 23));

        retranslateUi(PerspectiveCorrectionWindow);

        QMetaObject::connectSlotsByName(PerspectiveCorrectionWindow);
    } // setupUi

    void retranslateUi(QWidget *PerspectiveCorrectionWindow)
    {
        PerspectiveCorrectionWindow->setWindowTitle(QApplication::translate("PerspectiveCorrectionWindow", "Perspective Correction", nullptr));
        AutomaticButton->setText(QApplication::translate("PerspectiveCorrectionWindow", "Auto", nullptr));
        ManualButton->setText(QApplication::translate("PerspectiveCorrectionWindow", "Manual", nullptr));
        radioButton->setText(QApplication::translate("PerspectiveCorrectionWindow", "Use this method for the rest of pictures", nullptr));
        label_3->setText(QApplication::translate("PerspectiveCorrectionWindow", "Result", nullptr));
        label_4->setText(QApplication::translate("PerspectiveCorrectionWindow", "Source image", nullptr));
        SaveFileButton->setText(QApplication::translate("PerspectiveCorrectionWindow", "Save file", nullptr));
        label->setText(QApplication::translate("PerspectiveCorrectionWindow", "TextLabel", nullptr));
        label_2->setText(QApplication::translate("PerspectiveCorrectionWindow", "Choose one of the correction methods", nullptr));
        AbandonCorrectionButton->setText(QApplication::translate("PerspectiveCorrectionWindow", "Keep without change", nullptr));
        SaveButton->setText(QApplication::translate("PerspectiveCorrectionWindow", "Save changes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PerspectiveCorrectionWindow: public Ui_PerspectiveCorrectionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSPECTIVECORRECTIONWINDOW_H
