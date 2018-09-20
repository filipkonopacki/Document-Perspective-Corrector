#include "DocumentScannerGUI.h"

DocumentScannerGUI::DocumentScannerGUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}


void DocumentScannerGUI::on_LoadButton_clicked()
{
	QStringList fileNames = QFileDialog::getOpenFileNames(this, "Open files","",tr("Images (*.png *.jpg *.jpeg *.bmp)"));
	std::vector<std::string> filePaths;

	for (QString fileName : fileNames)
	{
		filePaths.push_back(fileName.toStdString());
	}

	scanner.LoadPages(filePaths);
	if (!scanner.AreEmpty() || filePaths.size() == 0)
	{
		QMessageBox::critical(this, "Loading failed", "At least one of your files can not be open!");
		return;
	}

	QMessageBox::information(this, "Loading finished", "Your image(s) has been loaded!");
	openCorrectorWindow();
}


void DocumentScannerGUI::openCorrectorWindow()
{
	PerspectiveCorrectionWindow win(scanner,this);
	win.setModal(true);
	win.exec();


}


void DocumentScannerGUI::on_DetectButton_clicked()
{
	int numberOfPages = scanner.pages.size();
	QString n = QString::fromStdString(toString(numberOfPages));
	QMessageBox::information(this, "Detected pages", "Number of pages " + n);
}