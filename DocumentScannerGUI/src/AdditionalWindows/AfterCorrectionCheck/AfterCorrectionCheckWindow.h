#pragma once

#include "../PerspectiveCorrection/CorrectorAndChecker.h"


class AfterCorrectionCheckWindow : public QDialog
{
	Q_OBJECT

public:
	AfterCorrectionCheckWindow(std::vector<cv::Mat> correctedImages, PerspectiveCorrectionWindow &parentWindow, QWidget *parent);
	~AfterCorrectionCheckWindow();

private:
	void UpdateResultImageLabel();


	Ui::AfterCorrectionCheckWindow ui;
	std::vector<cv::Mat> correctedImages;
	int imageIndex = 0;

private slots:
	//void on_SaveFileButton_clicked();
	void on_AutomaticButton_clicked();
	void on_ManualButton_clicked();
	void on_DontChangeButton_clicked();
};
