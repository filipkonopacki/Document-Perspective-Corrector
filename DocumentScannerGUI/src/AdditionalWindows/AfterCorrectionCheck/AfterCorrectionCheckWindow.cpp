#include "AfterCorrectionCheckWindow.h"

AfterCorrectionCheckWindow::AfterCorrectionCheckWindow(std::vector<cv::Mat> &correctedImages, DocumentScanner &scanner, QWidget *parent)
	: correctedImages(correctedImages), QDialog(parent), scanner(scanner)
{
	ui.setupUi(this);
	UpdateResultImageLabel();
}

AfterCorrectionCheckWindow::~AfterCorrectionCheckWindow()
{
}

void AfterCorrectionCheckWindow::UpdateResultImageLabel()
{
	cv::Mat sourceImage = correctedImages.at(imageIndex);
	QImage image = PerspectiveCorrectionWindow::LoadSourceImage(sourceImage);
	ui.resultLabel->setPixmap(QPixmap::fromImage(image.scaled(ui.resultLabel->size())));
}


void AfterCorrectionCheckWindow::on_AutomaticButton_clicked()
{
	std::vector<cv::Mat> results;
	results = scanner.CorrectImagePerspective(imageIndex, AUTO);
	UpdateCorrectedImages(results);
}

void AfterCorrectionCheckWindow::on_ManualButton_clicked()
{
	std::vector<cv::Mat> results;
	results = scanner.CorrectImagePerspective(imageIndex, MANUAL);
	UpdateCorrectedImages(results);
}

void AfterCorrectionCheckWindow::on_DontChangeButton_clicked()
{
	imageIndex++;
	if(imageIndex >= correctedImages.size())
	{
		this->close();
	}
	else
	{
		UpdateResultImageLabel();
	}
}

void AfterCorrectionCheckWindow::UpdateCorrectedImages(std::vector<cv::Mat> results)
{
	if (!results.at(0).empty())
	{
		correctedImages.at(imageIndex) = results.at(0);
	}
	UpdateResultImageLabel();
}


void AfterCorrectionCheckWindow::on_SaveFileButton_clicked()
{
	SaveFileWindow saveWindow(correctedImages.at(imageIndex),this);
	saveWindow.setModal(true);
	saveWindow.exec();
}