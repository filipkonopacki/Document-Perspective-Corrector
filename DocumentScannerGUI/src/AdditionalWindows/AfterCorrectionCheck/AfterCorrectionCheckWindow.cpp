#include "AfterCorrectionCheckWindow.h"

AfterCorrectionCheckWindow::AfterCorrectionCheckWindow(std::vector<cv::Mat> correctedImages, PerspectiveCorrectionWindow &parentWindow, QWidget *parent)
	: QDialog(parent), correctedImages(correctedImages)
{
	ui.setupUi(this);
	UpdateResultImageLabel();
}

AfterCorrectionCheckWindow::~AfterCorrectionCheckWindow()
{
}

void AfterCorrectionCheckWindow::UpdateResultImageLabel()
{
	cv::Mat sourceImage = correctedImages[imageIndex];
	QImage image = 
	ui.label->setPixmap(QPixmap::fromImage(image.scaled(ui.label->size())));
}

