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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DetectionWindow
{
public:
    QPushButton *AutomaticButton;
    QPushButton *ManualButton;
    QRadioButton *radioButton;
    QPushButton *CloseButton;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *NextButton;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *DetectionWindow)
    {
        if (DetectionWindow->objectName().isEmpty())
            DetectionWindow->setObjectName(QStringLiteral("DetectionWindow"));
        DetectionWindow->resize(808, 643);
        AutomaticButton = new QPushButton(DetectionWindow);
        AutomaticButton->setObjectName(QStringLiteral("AutomaticButton"));
        AutomaticButton->setGeometry(QRect(100, 550, 75, 23));
        ManualButton = new QPushButton(DetectionWindow);
        ManualButton->setObjectName(QStringLiteral("ManualButton"));
        ManualButton->setGeometry(QRect(210, 550, 75, 23));
        radioButton = new QRadioButton(DetectionWindow);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(20, 520, 121, 17));
        CloseButton = new QPushButton(DetectionWindow);
        CloseButton->setObjectName(QStringLiteral("CloseButton"));
        CloseButton->setGeometry(QRect(690, 600, 75, 23));
        label_3 = new QLabel(DetectionWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(460, 30, 47, 13));
        label_4 = new QLabel(DetectionWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 30, 64, 13));
        NextButton = new QPushButton(DetectionWindow);
        NextButton->setObjectName(QStringLiteral("NextButton"));
        NextButton->setGeometry(QRect(600, 600, 75, 23));
        label = new QLabel(DetectionWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 70, 300, 400));
        label_2 = new QLabel(DetectionWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(450, 70, 300, 400));

        retranslateUi(DetectionWindow);

        QMetaObject::connectSlotsByName(DetectionWindow);
    } // setupUi

    void retranslateUi(QWidget *DetectionWindow)
    {
        DetectionWindow->setWindowTitle(QApplication::translate("DetectionWindow", "DetectionWindow", nullptr));
        AutomaticButton->setText(QApplication::translate("DetectionWindow", "Auto", nullptr));
        ManualButton->setText(QApplication::translate("DetectionWindow", "Manual", nullptr));
        radioButton->setText(QApplication::translate("DetectionWindow", "Use for all pictures", nullptr));
        CloseButton->setText(QApplication::translate("DetectionWindow", "Close", nullptr));
        label_3->setText(QApplication::translate("DetectionWindow", "Result", nullptr));
        label_4->setText(QApplication::translate("DetectionWindow", "Source image", nullptr));
        NextButton->setText(QApplication::translate("DetectionWindow", "Next", nullptr));
        label->setText(QApplication::translate("DetectionWindow", "TextLabel", nullptr));
        label_2->setText(QApplication::translate("DetectionWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DetectionWindow: public Ui_DetectionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETECTIONWINDOW_H
