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
	NormalizeImageSize();
	finalImage = this->sourceImage.clone();
}

void AutomaticPerspectiveCorrector::NormalizeImageSize()
{
	cv::resize(sourceImage, sourceImage, cv::Size(1200, 1600), cv::INTER_LANCZOS4);
}

cv::Mat AutomaticPerspectiveCorrector::GetCorrectedImage()
{
	PreprocessImage();
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
	DetectText();


	return sourceImage;
}

void AutomaticPerspectiveCorrector::PreprocessImage()
{
	cv::cvtColor(finalImage, finalImage, cv::COLOR_BGR2GRAY);
	finalImage.convertTo(finalImage, -1, 1, -50);
	cv::threshold(finalImage, finalImage, 80, 255, cv::THRESH_BINARY);
}

void AutomaticPerspectiveCorrector::FindLargestCountur()
{
	largestContourIndex = 1;

	int maxImageArea = 1200 * 1600;
	int eightyPercentOfMaxArea = 80 * maxImageArea / 100;

	cv::findContours(finalImage, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
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

	cv::warpPerspective(sourceImage, sourceImage, homography, cv::Size(destinationImageWidth, destinationImageHeight));	
}



void AutomaticPerspectiveCorrector::DetectText()
{
	cv::Mat rgb;

	cv::pyrDown(sourceImage, rgb);
	cv::pyrDown(rgb, rgb);

	cv::Mat small;
	cv::cvtColor(rgb, small, CV_BGR2GRAY);
	SHOW(small);
	cv::Mat grad;
	cv::Mat morphKernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(3, 3));

	cv::morphologyEx(small, grad, cv::MORPH_GRADIENT, morphKernel);

	cv::Mat bw;
	cv::threshold(grad, bw, 0.0, 255.0, cv::THRESH_BINARY | cv::THRESH_OTSU);

	cv::Mat connected;
	morphKernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(9,1));
	cv::morphologyEx(bw, connected, cv::MORPH_CLOSE, morphKernel);
	cv::Mat mask = cv::Mat::zeros(bw.size(), CV_8UC1);
	std::vector<std::vector<cv::Point> > contours;
	std::vector<cv::Vec4i> hierarchy;
	cv::findContours(connected, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0));
	

	for (int idx = 0; idx >= 0; idx = hierarchy[idx][0]) {
		cv::Rect rect = boundingRect(contours[idx]);
		cv::Mat maskROI(mask, rect);
		maskROI = cv::Scalar(0, 0, 0);
		
		drawContours(mask, contours, idx, cv::Scalar(255, 255, 255), CV_FILLED);

		cv::RotatedRect rrect = minAreaRect(contours[idx]);
		double r = (double)countNonZero(maskROI) / (rrect.size.width * rrect.size.height);

		cv::Scalar color;
		int thickness = 1;
		
		if (r > 0.25 &&(rrect.size.height > 8 && rrect.size.width > 8))
		{
			thickness = 2;
			color = cv::Scalar(0, 255, 0);
		}
		else
		{
			thickness = 1;
			color = cv::Scalar(0, 0, 255);
		}

		cv::Point2f pts[4];
		rrect.points(pts);
		for (int i = 0; i < 4; i++)
		{
			line(rgb, cv::Point((int)pts[i].x, (int)pts[i].y), cv::Point((int)pts[(i + 1) % 4].x, (int)pts[(i + 1) % 4].y), color, thickness);
		}
	}

	cv::imwrite("cont.jpg", rgb);

}



int AutomaticPerspectiveCorrector::MeasureDistanceBetweenPoints(cv::Point a, cv::Point b)
{
	return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}



