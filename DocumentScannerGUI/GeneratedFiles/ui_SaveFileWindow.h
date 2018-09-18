/********************************************************************************
** Form generated from reading UI file 'SaveFileWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEFILEWINDOW_H
#define UI_SAVEFILEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SaveFileWindow
{
public:
    QLineEdit *filePathBox;
    QLineEdit *widthBox;
    QLineEdit *heightBox;
    QPushButton *browseButton;
    QPushButton *acceptButton;
    QLabel *widthLabel;
    QLabel *heightLabel;
    QCheckBox *aspectRatioCheck;

    void setupUi(QDialog *SaveFileWindow)
    {
        if (SaveFileWindow->objectName().isEmpty())
            SaveFileWindow->setObjectName(QStringLiteral("SaveFileWindow"));
        SaveFileWindow->resize(400, 187);
        filePathBox = new QLineEdit(SaveFileWindow);
        filePathBox->setObjectName(QStringLiteral("filePathBox"));
        filePathBox->setGeometry(QRect(20, 110, 231, 20));
        widthBox = new QLineEdit(SaveFileWindow);
        widthBox->setObjectName(QStringLiteral("widthBox"));
        widthBox->setGeometry(QRect(120, 20, 41, 20));
        heightBox = new QLineEdit(SaveFileWindow);
        heightBox->setObjectName(QStringLiteral("heightBox"));
        heightBox->setGeometry(QRect(120, 60, 41, 20));
        heightBox->setReadOnly(false);
        browseButton = new QPushButton(SaveFileWindow);
        browseButton->setObjectName(QStringLiteral("browseButton"));
        browseButton->setGeometry(QRect(290, 110, 75, 23));
        acceptButton = new QPushButton(SaveFileWindow);
        acceptButton->setObjectName(QStringLiteral("acceptButton"));
        acceptButton->setGeometry(QRect(320, 150, 75, 23));
        widthLabel = new QLabel(SaveFileWindow);
        widthLabel->setObjectName(QStringLiteral("widthLabel"));
        widthLabel->setGeometry(QRect(30, 20, 81, 16));
        heightLabel = new QLabel(SaveFileWindow);
        heightLabel->setObjectName(QStringLiteral("heightLabel"));
        heightLabel->setGeometry(QRect(30, 60, 81, 16));
        aspectRatioCheck = new QCheckBox(SaveFileWindow);
        aspectRatioCheck->setObjectName(QStringLiteral("aspectRatioCheck"));
        aspectRatioCheck->setGeometry(QRect(170, 40, 101, 17));

        retranslateUi(SaveFileWindow);

        QMetaObject::connectSlotsByName(SaveFileWindow);
    } // setupUi

    void retranslateUi(QDialog *SaveFileWindow)
    {
        SaveFileWindow->setWindowTitle(QApplication::translate("SaveFileWindow", "SaveFileWindow", nullptr));
        browseButton->setText(QApplication::translate("SaveFileWindow", "Browse...", nullptr));
        acceptButton->setText(QApplication::translate("SaveFileWindow", "Ok", nullptr));
        widthLabel->setText(QApplication::translate("SaveFileWindow", "Image width:", nullptr));
        heightLabel->setText(QApplication::translate("SaveFileWindow", "Image height:", nullptr));
        aspectRatioCheck->setText(QApplication::translate("SaveFileWindow", "Use aspect ratio", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SaveFileWindow: public Ui_SaveFileWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEFILEWINDOW_H
