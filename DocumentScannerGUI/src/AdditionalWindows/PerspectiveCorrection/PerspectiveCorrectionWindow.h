#pragma once

#include <QDialog>
#include <QMessageBox>
#include "ui_PerspectiveCorrectionWindow.h"
#include "../../Document-Scanner/Document-Scanner/src/DocumentScanner/DocumentScanner.h"

class PerspectiveCorrectionWindow : public QDialog
{
	Q_OBJECT

public:
	PerspectiveCorrectionWindow(DocumentScanner &scanner, QWidget *parent);
	~PerspectiveCorrectionWindow();

private:
	void UpdateSourceImage();
	void UpdateCorrectedImage();
	
	
	
	Ui::PerspectiveCorrectionWindow ui;
	DocumentScanner scanner;
	int imageIndex = 0;
	int maxIndex;
	std::vector<cv::Mat> correctedImages;

private slots:
	//void on_AbandonCorrectionButton_clicked();
	void on_AutomaticButton_clicked();
	//void on_ManualButton_clicked();
	//void on_RadioButton_toggled(bool state);
};
