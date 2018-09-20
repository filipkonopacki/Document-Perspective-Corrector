#pragma once

#include <QDialog>
#include <QMessageBox>
#include "ui_PerspectiveCorrectionWindow.h"
#include "../AfterCorrectionCheck/AfterCorrectionCheckWindow.h"
#include "../../Document-Scanner/Document-Scanner/src/DocumentScanner/DocumentScanner.h"
#include "../SaveFile/SaveFileWindow.h"


#include <exception>
#include <sstream>
#include <string>

std::string toString(int);

class PerspectiveCorrectionWindow : public QDialog
{
	Q_OBJECT

	friend class AfterCorrectionCheckWindow;

public:
	PerspectiveCorrectionWindow(DocumentScanner &scanner, QWidget *parent);
	~PerspectiveCorrectionWindow();

private:
	static QImage LoadSourceImage(cv::Mat sourceImage);
	void UpdateSourceImageLabel();
	void UpdateCorrectedImageLabel();
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
	void on_SaveFileButton_clicked();
};


