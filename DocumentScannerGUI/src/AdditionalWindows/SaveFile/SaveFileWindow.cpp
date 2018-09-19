#include "SaveFileWindow.h"

SaveFileWindow::SaveFileWindow(cv::Mat imageToSave, QWidget *parent)
	: imageToSave(imageToSave), QDialog(parent)
{
	ui.setupUi(this);
	imageHeight = imageToSave.rows;
	imageWidth = imageToSave.cols;
	ratio = (double)imageWidth / imageHeight;
	ui.widthBox->setText(QString::fromStdString(toString(imageWidth)));
	ui.heightBox->setText(QString::fromStdString(toString(imageHeight)));
	ui.filePathBox->setText(QString::fromStdString(filePath));
}

SaveFileWindow::~SaveFileWindow()
{
}

void SaveFileWindow::on_browseButton_clicked()
{
	QString fileName = QFileDialog::getSaveFileName(this, "Save image", QString::fromStdString(filePath),"Images (*.png *.jpg *.jpeg *.bmp)");
	if (fileName.isEmpty())
		return;

	filePath = fileName.toStdString();
	ui.filePathBox->setText(fileName);
}

void SaveFileWindow::on_acceptButton_clicked()
{
	if (ValidateFileFormat())
	{
		imageHeight = ui.heightBox->text().toInt();
		imageWidth = ui.widthBox->text().toInt();
		cv::resize(imageToSave, imageToSave, cv::Size(imageWidth, imageHeight));
		cv::imwrite(filePath, imageToSave);
		QMessageBox::information(this, "Success!", "File saved.");
		this->close();
	}
	else
	{
		QMessageBox::critical(this, "Fail!", "Enter valid file path.");
	}
}

bool SaveFileWindow::ValidateFileFormat()
{
	if (strstr(filePath.c_str(),".png") || strstr(filePath.c_str(), ".jpg") || strstr(filePath.c_str(), ".jpeg") || strstr(filePath.c_str(), ".bmp"))
	{
		return true;
	}
}

void SaveFileWindow::on_aspectRatioCheck_stateChanged()
{

	if (ui.aspectRatioCheck->checkState() == Qt::CheckState::Checked)
	{
		QString height;
		int h = ui.widthBox->text().toInt() / ratio;
		height = QString::fromStdString(toString(h));
		ui.heightBox->setText(height);
		ui.heightBox->setReadOnly(true);
	}
	else
	{
		ui.heightBox->setReadOnly(false);
	}
}

