/********************************************************************************
** Form generated from reading UI file 'DocumentScannerGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCUMENTSCANNERGUI_H
#define UI_DOCUMENTSCANNERGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DocumentScannerGUIClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DocumentScannerGUIClass)
    {
        if (DocumentScannerGUIClass->objectName().isEmpty())
            DocumentScannerGUIClass->setObjectName(QStringLiteral("DocumentScannerGUIClass"));
        DocumentScannerGUIClass->resize(600, 400);
        menuBar = new QMenuBar(DocumentScannerGUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        DocumentScannerGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DocumentScannerGUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DocumentScannerGUIClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(DocumentScannerGUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        DocumentScannerGUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(DocumentScannerGUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DocumentScannerGUIClass->setStatusBar(statusBar);

        retranslateUi(DocumentScannerGUIClass);

        QMetaObject::connectSlotsByName(DocumentScannerGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *DocumentScannerGUIClass)
    {
        DocumentScannerGUIClass->setWindowTitle(QApplication::translate("DocumentScannerGUIClass", "DocumentScannerGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DocumentScannerGUIClass: public Ui_DocumentScannerGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCUMENTSCANNERGUI_H
