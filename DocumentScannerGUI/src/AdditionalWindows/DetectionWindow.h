#pragma once

#include <QDialog>
#include "ui_DetectionWindow.h"

class DetectionWindow : public QDialog
{
	Q_OBJECT

public:
	DetectionWindow(const QString &title, QWidget *parent);
	~DetectionWindow();

private:
	Ui::DetectionWindow ui;
};
