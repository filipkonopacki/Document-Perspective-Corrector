#include "PerspectiveCorrector.h"

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <math.h>
#include <iostream>
#include <vector>



int PerspectiveCorrector::startCorrection()
{
	std::cout << "Please enter document picture name you want to correct. The file should be in \\Document-Perspective-Corrector\\x64\Debug\\Documents\\" << std::endl;
	std::string fileName;
	std::cin >> fileName;

	if (!LoadImage(fileName))
		return -1;



	std::cout << "Your document photo will be displayed. Double click on 4 corners in order starting with upper corners.\nPress enter to continue" << std::endl;
	return 0;
}

bool PerspectiveCorrector::LoadImage(std::string fileName)
{
	std::string filePath = "C:\\Users\\fkonopac\\Documents\\GitHub\\Document-Perspective-Corrector\\x64\\Debug\\Documents\\" + fileName;
	sourceImage = cv::imread(filePath);

	if (sourceImage.empty())
		return false;

	return true;
}


void PerspectiveCorrector::NormalizeSize()