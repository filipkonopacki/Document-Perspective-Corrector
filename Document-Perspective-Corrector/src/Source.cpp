#include "ManualPerspectiveCorrector.h"
#include "AutomaticPerspectiveCorrector/AutomaticPerspectiveCorrector.h"
#include <iostream>


void CorrectingImagePerspective()
{
	std::cout << "Please enter document picture name you want to correct. The file should be in \\Document-Perspective-Corrector\\x64\Debug\\Documents\\" << std::endl;
	std::string fileName;
	std::cin >> fileName;

	cv::Mat sourceImage;
	LoadImage(fileName, sourceImage);
	cv::Mat correctedImage = getCorrectedImage(sourceImage);
	cv::imshow("Corrected image", correctedImage);
	cv::waitKey(0);
}




int main()
{
	cv::Mat image = cv::imread("C:\\Users\\fkonopac\\Documents\\GitHub\\Document-Perspective-Corrector\\x64\\Debug\\Documents\\IMG_0392.jpg");

	AutomaticPerspectiveCorrector corretor(image);
	image = corretor.GetCorrectedImage();
	
	cv::imshow("Largest contour", image);
	cv::waitKey(0);
}
