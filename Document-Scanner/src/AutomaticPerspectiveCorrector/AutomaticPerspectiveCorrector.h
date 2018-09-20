#pragma once
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string.h>


class AutomaticPerspectiveCorrector
{
public:
	AutomaticPerspectiveCorrector();
	cv::Mat GetCorrectedImage(cv::Mat sourceImage);

private:
	void NormalizeImageSize(cv::Mat &image);
	void PreprocessImage(cv::Mat &image);
	void FindLargestCountur();
	void GetDocumentCorners();
	void FindFourDocumentCorners(int epsilon);
	void CorrectPerspective();
	int MeasureDistanceBetweenPoints(cv::Point a, cv::Point b);
	std::vector<cv::Point> GetCornersForUpperRightOrBottomLeftCorner(int firstSide, int secondSide);
	std::vector<cv::Point> GetCornersForUpperLeftOrBottomRightCorner(int firstSide, int secondSide);

	
	int imageWidth = 1600;
	int imageHeight = 1800;
	cv::Mat sourceImage;
	cv::Mat processedImage;
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;
	int largestContourIndex;
	std::vector<cv::Point> documentCorners;
};