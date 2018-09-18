#include "PerspectiveCorrectionWindow.h"

PerspectiveCorrectionWindow::PerspectiveCorrectionWindow(DocumentScanner &scanner, QWidget *parent)
	: QDialog(parent), scanner(scanner)
{
	ui.setupUi(this);

	maxIndex = scanner.GetNumberOfPages();
	UpdateSourceImageLabel();
}

PerspectiveCorrectionWindow::~PerspectiveCorrectionWindow()
{
}

void PerspectiveCorrectionWindow::UpdateSourceImageLabel()
{
	cv::Mat sourceImage = scanner.GetSourceImageAt(imageIndex);
	QImage image = LoadSourceImage(sourceImage);
	ui.label->setPixmap(QPixmap::fromImage(image.scaled(ui.label->size())));

	ui.label_2->setText("Choose one of the correction methods");
}

std::string toString(int a)
{
	std::stringstream ss;
	ss << a;
	return ss.str();
}

QImage PerspectiveCorrectionWindow::LoadSourceImage(cv::Mat sourceImage)
{
	std::string fileName = "tmp_im" + toString(imageIndex) + ".jpg";
	cv::imwrite(fileName, sourceImage);

	QImage image;
	QString filePath = QString::fromStdString(fileName);
	image.load(filePath);

	remove(fileName.c_str());
	
	return image;
}






void PerspectiveCorrectionWindow::on_AutomaticButton_clicked()
{
	std::vector<cv::Mat> results;
	if (ui.radioButton->isChecked())
	{
		results = (scanner.CorrectImagePerspective(imageIndex, ALL_AUTO));
	}
	else
	{
		results = scanner.CorrectImagePerspective(imageIndex, AUTO);
	}

	UpdateCorrectedImages(results);
}

void PerspectiveCorrectionWindow::on_ManualButton_clicked()
{
	std::vector<cv::Mat> results;
	QMessageBox::information(this, "Manual correction", "Your image(s) will be displayed. Select four corners in order by double clicking.");

	if (ui.radioButton->isChecked())
	{
		results = scanner.CorrectImagePerspective(imageIndex, ALL_MANUAL);
	}
	else
	{
		results = scanner.CorrectImagePerspective(imageIndex, MANUAL);
	}

	UpdateCorrectedImages(results);
}

void PerspectiveCorrectionWindow::on_DontChangeButton_clicked()
{
	std::vector<cv::Mat> results;
	if (ui.radioButton->isChecked())
	{
		for (int i = imageIndex; i < maxIndex; i++)
		{
			results.push_back(scanner.GetSourceImageAt(imageIndex));
		}
	}
	else
	{
		results.push_back(scanner.GetSourceImageAt(imageIndex));
	}
	UpdateCorrectedImages(results);
}







void PerspectiveCorrectionWindow::UpdateCorrectedImages(std::vector<cv::Mat> results)
{
	for (cv::Mat image : results)
	{
		if (!image.empty())
			correctedImages.push_back(image);
	}

	if (results.size() == 1)
	{
		UpdateCorrectedImageLabel();
		QMessageBox::information(this, "Work done", "Image has been corrected! Result is not satisfying? Try another correction method before saving!");
	}
	else
	{
		QMessageBox::StandardButton reply = QMessageBox::question(this, "Images corrected","Do you want to check results?", QMessageBox::Yes | QMessageBox::No);

		if (reply == QMessageBox::Yes)
		{
			// TODO:
			//		Display all corrected images one by one and ask user if result is satisfying


			//AfterCorrectionCheckWindow checker(correctedImages,this);
			//checker.setModal(true);
			//checker.exec();
		}
		else
		{
			for (imageIndex; imageIndex < maxIndex; imageIndex++)
				on_SaveButton_clicked();
		}
	}
}

void PerspectiveCorrectionWindow::UpdateCorrectedImageLabel()
{
	if (!correctedImages.at(imageIndex).empty())
	{
		QImage image = LoadSourceImage(correctedImages[imageIndex]);
		ui.label_2->setPixmap(QPixmap::fromImage(image.scaled(ui.label_2->size())));
	}
}






void PerspectiveCorrectionWindow::on_SaveButton_clicked()
{
	scanner.PushPage(Page(correctedImages[imageIndex]));
	imageIndex++;
	if (imageIndex >= maxIndex)
	{
		QMessageBox::information(this, "Work done", "All images have been corrected and saved!");
		this->close();
	}
	else
	{
		UpdateSourceImageLabel();
	}
}

void PerspectiveCorrectionWindow::on_SaveFileButton_clicked()
{
	try
	{
		SaveFileWindow saveWindow(correctedImages.at(imageIndex), this);
		saveWindow.setModal(true);
		saveWindow.exec();
	}
	catch (std::out_of_range ex)
	{
		QMessageBox::warning(this, "Save error", "There is no corrected image to save!");
	}
}