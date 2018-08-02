#pragma once
#include <opencv2/core.hpp>
#include <string.h>

class PerspectiveCorrector
{
	friend class PerspectiveCorrectorTest;

private: 
	cv::Mat sourceImage;
	cv::Mat correctedImage;
	cv::Mat homography;
	std::vector<cv::Point2f> sourceCorrespondingPoints;
	std::vector<cv::Point2f> destinationCorrespondingPoints;


	bool LoadImage(std::string fileName);
	void NormalizeSize();
	void getCorrespondingPoints(int action, int x, int y, int flags, void *userdata);
	int measureDistanceBetweenPoints(cv::Point a, cv::Point b);


public:
	int startCorrection();
};