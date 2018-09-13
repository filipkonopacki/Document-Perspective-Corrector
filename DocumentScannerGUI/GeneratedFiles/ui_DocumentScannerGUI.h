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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DocumentScannerGUIClass
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *LoadButton;
    QPushButton *DetectButton;
    QPushButton *CloseButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DocumentScannerGUIClass)
    {
        if (DocumentScannerGUIClass->objectName().isEmpty())
            DocumentScannerGUIClass->setObjectName(QStringLiteral("DocumentScannerGUIClass"));
        DocumentScannerGUIClass->resize(301, 303);
        centralWidget = new QWidget(DocumentScannerGUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 160, 281, 83));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        LoadButton = new QPushButton(layoutWidget);
        LoadButton->setObjectName(QStringLiteral("LoadButton"));

        verticalLayout->addWidget(LoadButton);

        DetectButton = new QPushButton(layoutWidget);
        DetectButton->setObjectName(QStringLiteral("DetectButton"));

        verticalLayout->addWidget(DetectButton);

        CloseButton = new QPushButton(layoutWidget);
        CloseButton->setObjectName(QStringLiteral("CloseButton"));

        verticalLayout->addWidget(CloseButton);

        DocumentScannerGUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DocumentScannerGUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 301, 21));
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
        DocumentScannerGUIClass->setWindowTitle(QApplication::translate("DocumentScannerGUIClass", "Document Scanner", nullptr));
        LoadButton->setText(QApplication::translate("DocumentScannerGUIClass", "Load", nullptr));
        DetectButton->setText(QApplication::translate("DocumentScannerGUIClass", "Detect Text", nullptr));
        CloseButton->setText(QApplication::translate("DocumentScannerGUIClass", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DocumentScannerGUIClass: public Ui_DocumentScannerGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCUMENTSCANNERGUI_H
