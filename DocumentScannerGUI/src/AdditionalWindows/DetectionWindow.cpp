#include "DetectionWindow.h"

DetectionWindow::DetectionWindow(const QString &title, QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

DetectionWindow::~DetectionWindow()
{
}
