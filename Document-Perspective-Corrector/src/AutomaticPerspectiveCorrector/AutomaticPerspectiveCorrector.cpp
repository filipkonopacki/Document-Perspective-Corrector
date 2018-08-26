#include "AutomaticPerspectiveCorrector.h"

//Macros for testing purpose
#define LOG(x) {std::cout << x <<std::endl;}
#define SHOW(x){cv::imshow("TEST", x);cv::waitKey(0);}


AutomaticPerspectiveCorrector::AutomaticPerspectiveCorrector(cv::Mat sourceImage)
	:sourceImage(sourceImage)
{
	this->sourceImage = NormalizeImageSize(this->sourceImage);
	processedImage = this->sourceImage.clone();
}

cv::Mat AutomaticPerspectiveCorrector::NormalizeImageSize(cv::Mat image)
{
	cv::Size normalizeSize = cv::Size(imageWidth,imageHeight);
	cv::resize(image, image, normalizeSize, cv::INTER_LANCZOS4);
	return image;
}

cv::Mat AutomaticPerspectiveCorrector::GetCorrectedImage()
{
	processedImage = PreprocessImage(processedImage);
	FindLargestCountur();
	GetDocumentCorners();
	CorrectPerspective();

	return processedImage;
}

cv::Mat AutomaticPerspectiveCorrector::PreprocessImage(cv::Mat image)
{
	cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);
	cv::threshold(image, image, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
	return image;
}

void AutomaticPerspectiveCorrector::FindLargestCountur()
{
	largestContourIndex = 0;

	int maxImageArea = imageWidth * imageHeight;
	int eightyPercentOfMaxArea = 80 * maxImageArea / 100;

	cv::findContours(processedImage, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
	for (int i = 1; i < contours.size(); i++)
	{
		if (cv::contourArea(contours[i]) < eightyPercentOfMaxArea && cv::contourArea(contours[i]) > cv::contourArea(contours[largestContourIndex]))
			largestContourIndex = i;
	}
}

void AutomaticPerspectiveCorrector::GetDocumentCorners()
{
	std::vector<cv::Point> points;

	for (int j = 0; j < contours[largestContourIndex].size(); j++)
	{
		points.push_back(contours[largestContourIndex][j]);
	}
	
	cv::convexHull(points, documentCorners);
	FindFourDocumentCorners(0);
}

void AutomaticPerspectiveCorrector::FindFourDocumentCorners(int epsilon)
{
	cv::approxPolyDP(cv::Mat(documentCorners), documentCorners, epsilon, true);
	if (documentCorners.size() != 4)
		FindFourDocumentCorners(epsilon + 1);
}



void AutomaticPerspectiveCorrector::CorrectPerspective()
{
	std::vector<cv::Point> destinationCorners;
	cv::Mat homography;
	int destinationImageWidth;
	int destinationImageHeight;

	int firstSide = MeasureDistanceBetweenPoints(documentCorners[0], documentCorners[1]);
	int secondSide = MeasureDistanceBetweenPoints(documentCorners[0], documentCorners[3]);

	if (firstSide > secondSide)
	{
		destinationImageWidth = secondSide;
		destinationImageHeight = firstSide;
		if (documentCorners[0].y < documentCorners[1].y)
		{
			destinationCorners.push_back(cv::Point(destinationImageWidth - 1, 0));
			destinationCorners.push_back(cv::Point(destinationImageWidth - 1, destinationImageHeight - 1));
			destinationCorners.push_back(cv::Point(0, destinationImageHeight - 1));
			destinationCorners.push_back(cv::Point(0, 0));
		}
		else
		{
			destinationCorners.push_back(cv::Point(0, destinationImageHeight - 1));
			destinationCorners.push_back(cv::Point(0, 0));
			destinationCorners.push_back(cv::Point(destinationImageWidth - 1, 0));
			destinationCorners.push_back(cv::Point(destinationImageWidth - 1, destinationImageHeight - 1));
		}
	}
	else
	{
		destinationImageWidth = firstSide;
		destinationImageHeight = secondSide;
		if (documentCorners[0].y > documentCorners[3].y)
		{
			destinationCorners.push_back(cv::Point(destinationImageWidth - 1, destinationImageHeight - 1));
			destinationCorners.push_back(cv::Point(0, destinationImageHeight - 1));
			destinationCorners.push_back(cv::Point(0, 0));
			destinationCorners.push_back(cv::Point(destinationImageWidth - 1, 0));
		}
		else
		{
			destinationCorners.push_back(cv::Point(0, 0));
			destinationCorners.push_back(cv::Point(destinationImageWidth - 1, 0));
			destinationCorners.push_back(cv::Point(destinationImageWidth - 1, destinationImageHeight - 1));
			destinationCorners.push_back(cv::Point(0, destinationImageHeight - 1));
		}
	}

	homography = cv::findHomography(documentCorners, destinationCorners);
	cv::warpPerspective(sourceImage, processedImage, homography, cv::Size(destinationImageWidth, destinationImageHeight));	
}

int AutomaticPerspectiveCorrector::MeasureDistanceBetweenPoints(cv::Point a, cv::Point b)
{
	return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}









