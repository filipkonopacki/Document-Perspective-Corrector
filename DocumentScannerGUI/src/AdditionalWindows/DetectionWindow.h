#pragma once

#include <QWidget>
#include "ui_DetectionWindow.h"

class DetectionWindow : public QWidget
{
	Q_OBJECT

public:
	DetectionWindow(QWidget *parent = Q_NULLPTR);
	~DetectionWindow();

private:
	Ui::DetectionWindow ui;
};
