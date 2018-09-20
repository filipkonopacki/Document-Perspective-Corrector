#pragma once

#include <QDialog>
#include <QFileDialog>
#include "ui_AfterCorrectionCheckWindow.h"
#include "../PerspectiveCorrection/PerspectiveCorrectionWindow.h"
#include "../../../Document-Scanner/Document-Scanner/src/DocumentScanner/DocumentScanner.h"

class AfterCorrectionCheckWindow : public QDialog
{
	Q_OBJECT

public:
	AfterCorrectionCheckWindow(std::vector<cv::Mat> &correctedImages,DocumentScanner &scanner, QWidget *parent);
	~AfterCorrectionCheckWindow();

private:
	void UpdateResultImageLabel();
	void UpdateCorrectedImages(std::vector<cv::Mat> results);

	Ui::AfterCorrectionCheckWindow ui;
	std::vector<cv::Mat> *correctedImages;
	int imageIndex = 0;
	DocumentScanner *scanner;

private slots:
	void on_SaveFileButton_clicked();
	void on_AutomaticButton_clicked();
	void on_ManualButton_clicked();
	void on_DontChangeButton_clicked();
};
