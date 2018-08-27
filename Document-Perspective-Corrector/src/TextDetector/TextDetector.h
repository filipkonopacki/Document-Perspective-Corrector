#pragma once
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string.h>

#include <sstream>
#include <iostream>
#include <fstream>

void SaveToFile(std::string toSave);
std::string toString(int a);


class TextDetector
{
public:
	TextDetector(cv::Mat);
	void DetectText();


private:

	cv::Mat sourceImage;
	cv::Mat processedImage;
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;
};
