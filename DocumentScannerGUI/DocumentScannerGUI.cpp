#include "DocumentScannerGUI.h"


DocumentScannerGUI::DocumentScannerGUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

}



void DocumentScannerGUI::on_LoadButton_clicked()
{
	QStringList fileNames = QFileDialog::getOpenFileNames(this, "Open files");
	std::vector<std::string> filePaths;

	for (QString fileName : fileNames)
	{
		filePaths.push_back(fileName.toStdString());
	}

	scanner.LoadPages(filePaths);
	QMessageBox::information(this, "Loading finished", "Your image/images has been loaded!");
}
