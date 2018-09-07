#include "ManualPerspectiveCorrector/ManualPerspectiveCorrector.h"
#include "AutomaticPerspectiveCorrector/AutomaticPerspectiveCorrector.h"
#include "TextDetector/TextDetector.h"
#include <iostream>


char ChooseOption(char firstOption, char secondOption)
{
	char option;
	std::cin >> option;
	if (option == firstOption || option == secondOption)
		return option;
	
	std::cout << "Wrong option! Choose once more." << std::endl;
	ChooseOption(firstOption,secondOption);
}


int main()
{
	cv::Mat image = cv::imread("Documents\\DSC_2851.JPG");
	cv::Mat correctedImage;
	AutomaticPerspectiveCorrector corrector(image);

	correctedImage = corrector.GetCorrectedImage();
	
	cv::imwrite("corrected.jpg", correctedImage);
	cv::imshow("corrected", correctedImage);
	cv::waitKey(0);

	TextDetector detector(correctedImage);

	detector.DetectText();
}

