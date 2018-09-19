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
	QString fileName = QFileDialog::getSaveFileName(this, "Save image", QString::fromStdString(filePath),"Images (*.png *.jpg *.jpeg *.bmp *.gif)");
	if (fileName.isEmpty())
		return;

	filePath = fileName.toStdString();
	ui.filePathBox->setText(fileName);
}

void SaveFileWindow::on_acceptButton_clicked()
{
	if (!filePath.empty())
	{
		imageHeight = ui.heightBox->text().toInt();
		imageWidth = ui.widthBox->text().toInt();
		cv::resize(imageToSave, imageToSave, cv::Size(imageWidth, imageHeight));
		cv::imwrite(filePath, imageToSave);
		QMessageBox::information(this, "Success!", "File saved.");
		this->close();
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

