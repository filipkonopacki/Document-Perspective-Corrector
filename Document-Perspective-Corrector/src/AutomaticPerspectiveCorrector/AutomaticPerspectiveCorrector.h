#pragma once
#include "../ManualPerspectiveCorrector.h"


class AutomaticPerspectiveCorrector
{
public:
	AutomaticPerspectiveCorrector(cv::Mat sourceImage);
	cv::Mat GetCorrectedImage();
	void DetectText();

private:
	cv::Mat NormalizeImageSize(cv::Mat image);
	cv::Mat PreprocessImage(cv::Mat image);
	void FindLargestCountur();
	int MeasureDistanceBetweenPoints(cv::Point a, cv::Point b);
	void FindDocumentCorners();
	void FindFourDocumentCorners(int epsilon);
	void CorrectPerspective();

	cv::Mat sourceImage;
	cv::Mat processedImage;
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;
	int largestContourIndex;
	std::vector<cv::Point> documentCorners;	
};