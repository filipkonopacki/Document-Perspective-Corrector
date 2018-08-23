#include "AutomaticPerspectiveCorrector.h"

#if DPC_DEBUG
	bool debug = true;
#else
	bool debug = false;
#endif


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
	cv::resize(image, image, cv::Size(1200, 1600), cv::INTER_LANCZOS4);
	return image;
}

cv::Mat AutomaticPerspectiveCorrector::GetCorrectedImage()
{
	processedImage = PreprocessImage(processedImage);
	FindLargestCountur();

	if (!debug) {
		cv::drawContours(sourceImage, contours, largestContourIndex, cv::Scalar(0, 255, 0), 3);
		cv::imwrite("Contours.png", sourceImage);
	}
	
	FindDocumentCorners();

	if (!debug)
	{
		LOG(documentCorners)
		cv::polylines(sourceImage, documentCorners, true, cv::Scalar(0, 255, 0), 3);
		cv::imwrite("Contours2.png", sourceImage);
	}
	
	CorrectPerspective();

	return processedImage;
}

cv::Mat AutomaticPerspectiveCorrector::PreprocessImage(cv::Mat image)
{
	cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);
	image.convertTo(image, -1, 1, -40);
	cv::threshold(image, image, 80, 255, cv::THRESH_BINARY);
	return image;
}

void AutomaticPerspectiveCorrector::FindLargestCountur()
{
	largestContourIndex = 1;

	int maxImageArea = 1200 * 1600;
	int eightyPercentOfMaxArea = 80 * maxImageArea / 100;

	cv::findContours(processedImage, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
	for (int i = 2; i < contours.size(); i++)
	{
		if (cv::contourArea(contours[i]) > cv::contourArea(contours[largestContourIndex]) && cv::contourArea(contours[i]) < eightyPercentOfMaxArea)
			largestContourIndex = i;
	}
}

void AutomaticPerspectiveCorrector::FindDocumentCorners()
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

	int firstSide = MeasureDistanceBetweenPoints(documentCorners.at(0), documentCorners.at(1));
	int secondSide = MeasureDistanceBetweenPoints(documentCorners.at(0), documentCorners.at(3));

	if (firstSide > secondSide)
	{
		destinationImageWidth = secondSide;
		destinationImageHeight = firstSide;

		destinationCorners.push_back(cv::Point(destinationImageWidth - 1, 0));
		destinationCorners.push_back(cv::Point(destinationImageWidth - 1, destinationImageHeight - 1));
		destinationCorners.push_back(cv::Point(0, destinationImageHeight - 1));
		destinationCorners.push_back(cv::Point(0, 0));
	}
	else
	{
		destinationImageWidth = firstSide;
		destinationImageHeight = secondSide;

		destinationCorners.push_back(cv::Point(destinationImageWidth - 1, destinationImageHeight - 1));
		destinationCorners.push_back(cv::Point(0, destinationImageHeight - 1));
		destinationCorners.push_back(cv::Point(0, 0));
		destinationCorners.push_back(cv::Point(destinationImageWidth - 1, 0));
	}

	homography = cv::findHomography(documentCorners, destinationCorners);
	cv::warpPerspective(sourceImage, processedImage, homography, cv::Size(destinationImageWidth, destinationImageHeight));	
}

int AutomaticPerspectiveCorrector::MeasureDistanceBetweenPoints(cv::Point a, cv::Point b)
{
	return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}


void AutomaticPerspectiveCorrector::DetectText()
{
	cv::Mat imageForDetection = processedImage;

	imageForDetection = PreprocessImage(imageForDetection);


	cv::findContours(imageForDetection, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0));

	

	int minimumArea = 75;
	int maximumArea = 25000;
	
	for (int i = 0; i < contours.size(); i++)
	{
		int area = cv::contourArea(contours[i]);
		if (area >= minimumArea && area <= maximumArea)
		{
			cv::Rect boundRectangle = cv::boundingRect(contours[i]);
			int height = boundRectangle.height;
			int width = boundRectangle.width;
			double occupyrate = area / (height*width);
			int aspectRatio = std::max(height, width) / std::min(height, width);
			double compactness = area / (cv::arcLength(contours[i], true) *cv::arcLength(contours[i], true));

			if ((occupyrate >= 0.02) && (occupyrate <= 0.95))
			{
				if (aspectRatio <= 6)
				{
					if (compactness > 0.003 && compactness <= 0.95)
					{
						cv::drawContours(processedImage, contours, i, cv::Scalar(0, 255, 0), 3);
					}
				}
			}
		}
	}

	SHOW(processedImage)
}







