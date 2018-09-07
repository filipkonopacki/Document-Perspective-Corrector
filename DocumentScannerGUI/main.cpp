#include "DocumentScannerGUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	DocumentScannerGUI w;
	w.show();
	return a.exec();
}
