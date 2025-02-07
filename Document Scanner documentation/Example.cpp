#include "ManualPerspectiveCorrector.h"
#include "AutomaticPerspectiveCorrector/AutomaticPerspectiveCorrector.h"
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
	cv::Mat image = cv::imread("Documents\\DSC_2830.JPG");
	cv::Mat correctedImage;

	std::cout << "~~~~~~~~~~Welcome in document perspective corrector, part of document scanner~~~~~~~~~~" << std::endl;
	std::cout << "Choose option you want to use\nM:manual\nA:automatic" << std::endl;

	char option = ChooseOption('M','A');
	if (option == 'M')
	{
		std::cout << "----------Manual option----------" << std::endl;
		correctedImage = getCorrectedImage(image);
		std::cout << "Choose option you want to use\nS:save\nD:display" << std::endl;
		option = ChooseOption('S', 'D');
	}
	else
	{
		std::cout << "----------Automatic option----------" << std::endl;
		AutomaticPerspectiveCorrector corrector(image);
		correctedImage = corrector.GetCorrectedImage();
		std::cout << "Choose option you want to use\nS:save\nD:display" << std::endl;
		option = ChooseOption('S', 'D');
	}
	
	if (option == 'S')
	{
		cv::imwrite("corrected.jpg", correctedImage);
		std::cin.get();
	}
	else if (option == 'D')
	{
		cv::imshow("corrected", correctedImage);
		cv::waitKey(0);
	}
}

