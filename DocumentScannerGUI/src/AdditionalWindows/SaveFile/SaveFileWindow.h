#pragma once

#include <QDialog>
#include <QFileDialog>
#include "ui_SaveFileWindow.h"
#include "../PerspectiveCorrection/PerspectiveCorrectionWindow.h"

class SaveFileWindow : public QDialog
{
	Q_OBJECT

public:
	SaveFileWindow(cv::Mat imageToSave, QWidget *parent);
	~SaveFileWindow();

private:
	bool ValidateFileFormat();



	Ui::SaveFileWindow ui;
	cv::Mat imageToSave;
	std::string filePath = "C:\\";
	int imageHeight;
	int imageWidth;
	double ratio;


private slots:
	void on_browseButton_clicked();
	void on_acceptButton_clicked();
	void on_aspectRatioCheck_stateChanged();
};