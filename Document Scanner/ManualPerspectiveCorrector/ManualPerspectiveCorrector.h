#pragma once
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string.h>



bool LoadImage(std::string fileName, cv::Mat &sourceImage);
cv::Mat getCorrectedImage(cv::Mat sourceImage);
cv::Mat NormalizeImageSize(cv::Mat sourceImage);
void getCorrespondingPoints(int action, int x, int y, int flags, void *userdata);
int measureDistanceBetweenPoints(cv::Point a, cv::Point b);

