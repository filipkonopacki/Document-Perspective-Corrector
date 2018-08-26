#include "ManualPerspectiveCorrector.h"
#include "AutomaticPerspectiveCorrector/AutomaticPerspectiveCorrector.h"
#include <iostream>


char ChooseOption()
{
	char option;
	std::cin >> option;
	if (option == 'M' || option == 'A')
		return option;
	
	ChooseOption();
}


int main()
{
	cv::Mat image = cv::imread("Documents\\DSC_2830.JPG");
	cv::Mat correctedImage;

	std::cout << "~~~~~~~~~~Welcome in document perspective corrector, part of document scanner~~~~~~~~~~" << std::endl;
	std::cout << "Choose option you want to use\nM:manual\nA:automatic" << std::endl;

	char option = ChooseOption();
	if (option == 'M')
	{
		std::cout << "----------Manual option----------" << std::endl;
		correctedImage = getCorrectedImage(image);
	}
	else
	{
		std::cout << "----------Automatic option----------" << std::endl;
		AutomaticPerspectiveCorrector corrector(image);
		correctedImage = corrector.GetCorrectedImage();
	}
	
	cv::imshow("Corrected", correctedImage);
	cv::waitKey(0);
}

