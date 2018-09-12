#include "DocumentScannerGUI.h"

DocumentScannerGUI::DocumentScannerGUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}


void DocumentScannerGUI::on_LoadButton_clicked()
{
	DocumentScanner scanner;

	QStringList fileNames = QFileDialog::getOpenFileNames(this, "Open files");
	std::vector<std::string> filePaths;

	for (QString fileName : fileNames)
	{
		filePaths.push_back(fileName.toStdString());
	}

	scanner.LoadPages(filePaths);
	if (!scanner.AreEmpty())
	{
		QMessageBox::warning(this, "Loading failed", "At least one of your files can not be open! Check file format.");
		return;
	}

	QMessageBox::information(this, "Loading finished", "Your image(s) has been loaded!");
	

}
