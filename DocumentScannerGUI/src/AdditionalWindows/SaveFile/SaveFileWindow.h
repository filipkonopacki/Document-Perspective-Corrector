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
	Ui::SaveFileWindow ui;
	cv::Mat imageToSave;
	std::string filePath;
	int imageHeight;
	int imageWidth;
	float ratio;


private slots:
	void on_browseButton_clicked();
	void on_acceptButton_clicked();
};