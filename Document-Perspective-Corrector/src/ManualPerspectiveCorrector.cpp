#include "ManualPerspectiveCorrector.h"
#include <math.h>
#include <iostream>
#include <vector>



bool LoadImage(std::string fileName, cv::Mat &sourceImage)
{
	std::string filePath = "C:\\Users\\fkonopac\\Documents\\GitHub\\Document-Perspective-Corrector\\x64\\Debug\\Documents\\" + fileName;
	sourceImage = cv::imread(filePath);

	if (sourceImage.empty())
		return false;

	return true;
}



cv::Mat sourceImage;
std::vector<cv::Point2f> sourceCorrespondingPoints;


cv::Mat getCorrectedImage(cv::Mat image)
{
	sourceImage = image;

	cv::Mat homography;
	cv::Mat destinationImage;
	std::vector<cv::Point2f> destinationCorrespondingPoints;
	
	sourceImage = NormalizeImageSize(sourceImage);

	std::cout << "Your document photo will be displayed. Double click on 4 corners in order starting with upper corners.\nPress enter to continue" << std::endl;
	std::cin.get();
	std::cin.get();


	cv::namedWindow("Window");
	cv::setMouseCallback("Window", getCorrespondingPoints);



	while (sourceCorrespondingPoints.size() < 4)
	{
		cv::imshow("Window", sourceImage);
		cv::waitKey(20);
	}
	cv::destroyWindow("Window");


	int destinationImageHeight = measureDistanceBetweenPoints(sourceCorrespondingPoints.at(0), sourceCorrespondingPoints.at(3)) * 2;
	int destinationImageWidth = measureDistanceBetweenPoints(sourceCorrespondingPoints.at(0), sourceCorrespondingPoints.at(1)) * 2;

	destinationCorrespondingPoints.push_back(cv::Point(0, 0));
	destinationCorrespondingPoints.push_back(cv::Point(destinationImageWidth, 0));
	destinationCorrespondingPoints.push_back(cv::Point(destinationImageWidth - 1, destinationImageHeight - 1));
	destinationCorrespondingPoints.push_back(cv::Point(0, destinationImageHeight - 1));


	homography = cv::findHomography(sourceCorrespondingPoints, destinationCorrespondingPoints);

	cv::warpPerspective(sourceImage, destinationImage, homography, cv::Size(destinationImageWidth, destinationImageHeight));

	return destinationImage;
}

cv::Mat NormalizeImageSize(cv::Mat image)
{
	cv::resize(image, image, cv::Size(600, 800));
	return image;
}

void getCorrespondingPoints(int action, int x, int y, int flags, void *userdata)
{
	cv::Point correspondingPoint;

	if (action == cv::EVENT_LBUTTONDBLCLK)
	{
		correspondingPoint = cv::Point(x, y);
		cv::circle(sourceImage, correspondingPoint, 2, cv::Scalar(0, 0, 255), -1, CV_AA);
		sourceCorrespondingPoints.push_back(correspondingPoint);
	}
}

int measureDistanceBetweenPoints(cv::Point a, cv::Point b)
{
	return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}
