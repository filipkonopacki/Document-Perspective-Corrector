#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DocumentScannerGUI.h"
#include "../Document Scanner/src/D"

class DocumentScannerGUI : public QMainWindow
{
	Q_OBJECT

public:
	DocumentScannerGUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::DocumentScannerGUIClass ui;
};
