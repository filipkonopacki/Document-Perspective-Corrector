#pragma once
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string.h>


class AutomaticPerspectiveCorrector
{
public:
	AutomaticPerspectiveCorrector(cv::Mat sourceImage);
	cv::Mat GetCorrectedImage();

private:
	cv::Mat NormalizeImageSize(cv::Mat image);
	cv::Mat PreprocessImage(cv::Mat image);
	void FindLargestCountur();
	int MeasureDistanceBetweenPoints(cv::Point a, cv::Point b);
	void GetDocumentCorners();
	void FindFourDocumentCorners(int epsilon);
	void CorrectPerspective();

	cv::Mat sourceImage;
	cv::Mat processedImage;
	int imageWidth = 1600;
	int imageHeight = 1800;
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;
	int largestContourIndex;
	std::vector<cv::Point> documentCorners;	
};