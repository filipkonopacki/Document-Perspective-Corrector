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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DocumentScannerGUIClass
{
public:
    QWidget *centralWidget;
    QPushButton *CloseButton;
    QPushButton *LoadButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DocumentScannerGUIClass)
    {
        if (DocumentScannerGUIClass->objectName().isEmpty())
            DocumentScannerGUIClass->setObjectName(QStringLiteral("DocumentScannerGUIClass"));
        DocumentScannerGUIClass->resize(600, 400);
        centralWidget = new QWidget(DocumentScannerGUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        CloseButton = new QPushButton(centralWidget);
        CloseButton->setObjectName(QStringLiteral("CloseButton"));
        CloseButton->setGeometry(QRect(460, 300, 75, 23));
        LoadButton = new QPushButton(centralWidget);
        LoadButton->setObjectName(QStringLiteral("LoadButton"));
        LoadButton->setGeometry(QRect(460, 250, 75, 23));
        DocumentScannerGUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DocumentScannerGUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        DocumentScannerGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DocumentScannerGUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DocumentScannerGUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DocumentScannerGUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DocumentScannerGUIClass->setStatusBar(statusBar);

        retranslateUi(DocumentScannerGUIClass);
        QObject::connect(CloseButton, SIGNAL(clicked()), DocumentScannerGUIClass, SLOT(close()));

        QMetaObject::connectSlotsByName(DocumentScannerGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *DocumentScannerGUIClass)
    {
        DocumentScannerGUIClass->setWindowTitle(QApplication::translate("DocumentScannerGUIClass", "DocumentScannerGUI", nullptr));
        CloseButton->setText(QApplication::translate("DocumentScannerGUIClass", "Close", nullptr));
        LoadButton->setText(QApplication::translate("DocumentScannerGUIClass", "Load", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DocumentScannerGUIClass: public Ui_DocumentScannerGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCUMENTSCANNERGUI_H
