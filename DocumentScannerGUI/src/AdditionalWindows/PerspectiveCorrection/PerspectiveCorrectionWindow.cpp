#include "PerspectiveCorrectionWindow.h"

PerspectiveCorrectionWindow::PerspectiveCorrectionWindow(DocumentScanner &scanner, QWidget *parent)
	: QDialog(parent), scanner(scanner)
{
	ui.setupUi(this);

	maxIndex = scanner.GetNumberOfPages();
	UpdateSourceImage();
}

PerspectiveCorrectionWindow::~PerspectiveCorrectionWindow()
{
}

void PerspectiveCorrectionWindow::UpdateSourceImage()
{
	cv::Mat sourceImage = scanner.GetSourceImageAt(imageIndex);
	QImage image((uchar*)sourceImage.data, sourceImage.cols, sourceImage.rows, QImage::Format_RGB888);

	ui.label->setPixmap(QPixmap::fromImage(image.scaled(ui.label->size())));
}

void PerspectiveCorrectionWindow::on_AutomaticButton_clicked()
{
	std::vector<cv::Mat> results;
	if (ui.radioButton->isCheckable())
	{
		results = (scanner.CorrectImagePerspective(imageIndex, ALL_AUTO));
	}
	else
	{
		results = scanner.CorrectImagePerspective(imageIndex, AUTO);
	}

	for (cv::Mat image : results)
	{
		if (!image.empty())
			correctedImages.push_back(image);
	}

	UpdateCorrectedImage();
	QMessageBox::information(this, "Work done", "Image has been corrected! If result is not satisfying for you, choose manual correction method before saving.");
}

void PerspectiveCorrectionWindow::UpdateCorrectedImage()
{
	if (!correctedImages[imageIndex].empty())
	{
		QImage image((uchar*)correctedImages[imageIndex].data, correctedImages[imageIndex].cols, correctedImages[imageIndex].rows,QImage::Format_RGB888);
		ui.label_2->setPixmap(QPixmap::fromImage(image.scaled(ui.label_2->size())));
	}
}