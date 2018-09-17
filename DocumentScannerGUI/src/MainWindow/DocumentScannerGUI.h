#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_DocumentScannerGUI.h"
#include "QFileDialog"
#include "QMessageBox"
#include "../../Document-Scanner/Document-Scanner/src/DocumentScanner/DocumentScanner.h"
#include "../AdditionalWindows/PerspectiveCorrection/PerspectiveCorrectionWindow.h"



class DocumentScannerGUI : public QMainWindow
{
	Q_OBJECT

public:
	DocumentScannerGUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::DocumentScannerGUIClass ui;
	DocumentScanner scanner;
	


private slots:
	void on_LoadButton_clicked();
	void openCorrectorWindow();
};
