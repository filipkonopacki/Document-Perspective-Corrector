#pragma once

#include <QDialog>
#include <QMessageBox>
#include "ui_PerspectiveCorrectionWindow.h"
//#include "../AfterCorrectionCheck/AfterCorrectionCheckWindow.h"
#include "../../Document-Scanner/Document-Scanner/src/DocumentScanner/DocumentScanner.h"


#include <sstream>
#include <string>

class PerspectiveCorrectionWindow : public QDialog
{
	Q_OBJECT

	friend class AfterCorrectionCheckWindow;

public:
	PerspectiveCorrectionWindow(DocumentScanner &scanner, QWidget *parent);
	~PerspectiveCorrectionWindow();

private:
	void UpdateSourceImageLabel();
	void UpdateCorrectedImageLabel();
	QImage LoadSourceImage(cv::Mat sourceImage);
	void UpdateCorrectedImages(std::vector<cv::Mat> results);
	
	
	Ui::PerspectiveCorrectionWindow ui;
	DocumentScanner scanner;
	int imageIndex = 0;
	int maxIndex;
	std::vector<cv::Mat> correctedImages;

private slots:
	void on_AutomaticButton_clicked();
	void on_ManualButton_clicked();
	void on_DontChangeButton_clicked();
	void on_SaveButton_clicked();
};


