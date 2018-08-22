#pragma once
#include "../ManualPerspectiveCorrector.h"



cv::Mat AutomaticPerspectiveCorrection(cv::Mat sourceImage);


class AutomaticPerspectiveCorrector
{
public:
	AutomaticPerspectiveCorrector(cv::Mat sourceImage);
	cv::Mat GetCorrectedImage();


private:
	void NormalizeImageSize();
	void PreprocessImage();
	void FindLargestCountur();
	int MeasureDistanceBetweenPoints(cv::Point a, cv::Point b);
	void FindDocumentCorners();
	void FindFourDocumentCorners(int epsilon);
	void SortDocumentCorners();
	cv::Point FindLeftCorner();
	void CorrectPerspective();
	void DetectText();

	cv::Mat sourceImage;
	cv::Mat finalImage;
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;
	int largestContourIndex;
	std::vector<cv::Point> documentCorners;
	
};