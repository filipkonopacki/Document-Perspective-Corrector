#include "AutomaticPerspectiveCorrector.h"

#if DPC_DEBUG
	bool debug = true;
#else
	bool debug = false;
#endif


#define LOG(x) {std::cout << x <<std::endl;}

AutomaticPerspectiveCorrector::AutomaticPerspectiveCorrector(cv::Mat sourceImage)
	:sourceImage(sourceImage)
{
	NormalizeImageSize();
	finalImage = this->sourceImage.clone();
}

void AutomaticPerspectiveCorrector::NormalizeImageSize()
{
	cv::resize(sourceImage, sourceImage, cv::Size(600, 800));
}

cv::Mat AutomaticPerspectiveCorrector::GetCorrectedImage()
{
	PreprocessImage();
	FindLargestCountur();
	FindDocumentCorners(0);
	CorrectPerspective();
	DetectText();


	return sourceImage;
}

void AutomaticPerspectiveCorrector::PreprocessImage()
{
	cv::cvtColor(finalImage, finalImage, cv::COLOR_BGR2GRAY);
	finalImage.convertTo(finalImage, -1, 1, -50);
	cv::threshold(finalImage, finalImage, 80, 255, cv::THRESH_BINARY);
	//cv::Canny(finalImage, finalImage, 30,90);
}

void AutomaticPerspectiveCorrector::FindLargestCountur()
{
	largestContourIndex = 0;
	cv::findContours(finalImage, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	for (int i = 1; i < contours.size(); i++)
	{
		if (cv::contourArea(contours[i]) > cv::contourArea(contours[largestContourIndex]))
			largestContourIndex = i;
	}
}

void AutomaticPerspectiveCorrector::FindDocumentCorners(int epsilon)
{
	cv::approxPolyDP(cv::Mat(contours[largestContourIndex]), documentCorners, epsilon, true);
		if (documentCorners.size() != 4)
			FindDocumentCorners(epsilon + 1);


}



void AutomaticPerspectiveCorrector::CorrectPerspective()
{
	cv::Rect boundingRectangle = cv::boundingRect(contours[largestContourIndex]);
	std::vector<cv::Point> destinationCorners;
	cv::Mat homography;


	int destinationImageWidth = MeasureDistanceBetweenPoints(documentCorners.at(0), documentCorners.at(1))*2;
	int destinationImageHeight = MeasureDistanceBetweenPoints(documentCorners.at(0), documentCorners.at(2))*2;
	
	LOG(documentCorners)

	destinationCorners.push_back(cv::Point(destinationImageWidth - 1,0));
	destinationCorners.push_back(cv::Point(0, 0));
	destinationCorners.push_back(cv::Point(0, destinationImageHeight - 1));
	destinationCorners.push_back(cv::Point(destinationImageWidth-1, destinationImageHeight - 1));

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



