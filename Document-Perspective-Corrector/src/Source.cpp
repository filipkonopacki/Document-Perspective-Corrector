#include "ManualPerspectiveCorrector.h"
#include "AutomaticPerspectiveCorrector/AutomaticPerspectiveCorrector.h"
#include <iostream>



int main()
{
	cv::Mat image = cv::imread("C:\\Users\\fkonopac\\Documents\\GitHub\\Document-Perspective-Corrector\\x64\\Debug\\Documents\\IMG_0417.jpg");
	cv::Mat correctedImage;

	//correctedImage = getCorrectedImage(image);
	
	AutomaticPerspectiveCorrector corrector(image);
	correctedImage = corrector.GetCorrectedImage();
	corrector.DetectText();
	cv::imshow("Result", correctedImage);
	cv::waitKey(0);
}

