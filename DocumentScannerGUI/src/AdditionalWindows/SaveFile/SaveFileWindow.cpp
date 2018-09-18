#include "SaveFileWindow.h"

SaveFileWindow::SaveFileWindow(cv::Mat imageToSave, QWidget *parent)
	: imageToSave(imageToSave), QDialog(parent)
{
	ui.setupUi(this);
	imageHeight = imageToSave.rows;
	imageWidth = imageToSave.cols;
	ratio = imageWidth / imageHeight;
	ui.widthBox->setText(QString::fromStdString(toString(imageWidth)));
	ui.heightBox->setText(QString::fromStdString(toString(imageHeight)));
}

SaveFileWindow::~SaveFileWindow()
{
}

void SaveFileWindow::on_browseButton_clicked()
{
	QString fileName = QFileDialog::getSaveFileName(this, "Save image", "","Images (*.png *.jpg *.jpeg *.bmp *.gif)");
	if (fileName.isEmpty())
		return;

	filePath = fileName.toStdString();
	ui.filePathBox->setText(fileName);
}

void SaveFileWindow::on_acceptButton_clicked()
{
	if (!filePath.empty())
	{
		cv::imwrite(filePath, imageToSave);
		this->close();
	}
}