#pragma once
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string.h>



class TextDetector
{
public:
	TextDetector(cv::Mat);
	void DetectText();


private:
	void QuickSortRectangles(unsigned int leftSide, unsigned int rightSide);

	cv::Mat sourceImage;
	cv::Mat processedImage;
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;
	std::vector<cv::Rect> rectangles;
};
