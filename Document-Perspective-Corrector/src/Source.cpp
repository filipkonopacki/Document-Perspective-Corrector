#include "ManualPerspectiveCorrector.h"
#include "AutomaticPerspectiveCorrector/AutomaticPerspectiveCorrector.h"
#include "TextDetector/TextDetector.h"
#include <iostream>



int main()
{
	//cv::Mat image = cv::imread("C:\\Users\\fkonopac\\Documents\\GitHub\\Document-Perspective-Corrector\\x64\\Debug\\Documents\\IMG_0416.jpg");
	//cv::Mat image = cv::imread("C:\\Users\\fkonopac\\Documents\\GitHub\\Document-Perspective-Corrector\\x64\\Debug\\Documents\\cvl-database-1-1\\testset\\pages\\0052-1.tif");
	cv::Mat image = cv::imread("C:\\Users\\fkonopac\\Documents\\GitHub\\Document-Perspective-Corrector\\Document-Perspective-Corrector\\Corrected.png");
	cv::Mat correctedImage = image;
	

	TextDetector detector(correctedImage);
	detector.DetectText();

	
}

