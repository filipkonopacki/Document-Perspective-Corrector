#include "ManualPerspectiveCorrector.h"
#include <math.h>
#include <iostream>
#include <vector>

cv::Mat sourceImage;
std::vector<cv::Point2f> sourceCorrespondingPoints;
int imageHeight = 1800;
int imageWidth = 1200;

cv::Mat getCorrectedImage(cv::Mat image)
{
	sourceImage = image;

	cv::Mat homography;
	cv::Mat destinationImage;
	std::vector<cv::Point2f> destinationCorrespondingPoints;

	sourceImage = NormalizeImageSize(sourceImage);

	std::cout << "Your document photo will be displayed. Double click on 4 corners in order.\nPress enter to continue" << std::endl;
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


	int destinationImageWidth;
	int destinationImageHeight;

	int firstSide = measureDistanceBetweenPoints(sourceCorrespondingPoints[0], sourceCorrespondingPoints[1]);
	int secondSide = measureDistanceBetweenPoints(sourceCorrespondingPoints[0], sourceCorrespondingPoints[3]);

	if (firstSide > secondSide)
	{
		destinationImageWidth = secondSide;
		destinationImageHeight = firstSide;
		if (sourceCorrespondingPoints[0].y < sourceCorrespondingPoints[1].y)
		{
			destinationCorrespondingPoints.push_back(cv::Point(destinationImageWidth - 1, 0));
			destinationCorrespondingPoints.push_back(cv::Point(destinationImageWidth - 1, destinationImageHeight - 1));
			destinationCorrespondingPoints.push_back(cv::Point(0, destinationImageHeight - 1));
			destinationCorrespondingPoints.push_back(cv::Point(0, 0));
		}
		else
		{
			destinationCorrespondingPoints.push_back(cv::Point(0, destinationImageHeight - 1));
			destinationCorrespondingPoints.push_back(cv::Point(0, 0));
			destinationCorrespondingPoints.push_back(cv::Point(destinationImageWidth - 1, 0));
			destinationCorrespondingPoints.push_back(cv::Point(destinationImageWidth - 1, destinationImageHeight - 1));
		}
	}
	else
	{
		destinationImageWidth = firstSide;
		destinationImageHeight = secondSide;
		if (sourceCorrespondingPoints[0].y > sourceCorrespondingPoints[3].y)
		{
			destinationCorrespondingPoints.push_back(cv::Point(destinationImageWidth - 1, destinationImageHeight - 1));
			destinationCorrespondingPoints.push_back(cv::Point(0, destinationImageHeight - 1));
			destinationCorrespondingPoints.push_back(cv::Point(0, 0));
			destinationCorrespondingPoints.push_back(cv::Point(destinationImageWidth - 1, 0));
		}
		else
		{
			destinationCorrespondingPoints.push_back(cv::Point(0, 0));
			destinationCorrespondingPoints.push_back(cv::Point(destinationImageWidth - 1, 0));
			destinationCorrespondingPoints.push_back(cv::Point(destinationImageWidth - 1, destinationImageHeight - 1));
			destinationCorrespondingPoints.push_back(cv::Point(0, destinationImageHeight - 1));
		}
	}

	homography = cv::findHomography(sourceCorrespondingPoints, destinationCorrespondingPoints);

	cv::warpPerspective(sourceImage, destinationImage, homography, cv::Size(destinationImageWidth, destinationImageHeight));

	return destinationImage;
}

cv::Mat NormalizeImageSize(cv::Mat image)
{
	cv::resize(image, image, cv::Size(imageWidth, imageHeight), cv::INTER_LANCZOS4);
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
