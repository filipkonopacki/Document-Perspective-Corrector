#pragma once

#include <vector>
#include <string>

#include "opencv2/core.hpp"
#include "opencv2/opencv.hpp"
#include "../TextDetector/TextParts/Page.h"




enum DetectionMode { AUTO, MANUAL, ALL_AUTO, ALL_MANUAL };


class DocumentScanner
{
public:
	DocumentScanner();
	~DocumentScanner();
	void LoadPages(std::vector<std::string> fileNames);
	std::vector<cv::Mat> CorrectImagePerspective(int imageIndex, DetectionMode mode);
	cv::Mat GetSourceImageAt(int index);
	int GetNumberOfPages();
	bool AreEmpty();
	void PushPage(Page page);
	

private:
	void LoadImage(std::string fileName);
	


	std::vector<cv::Mat> sourceImages;
	std::vector<Page> pages;
};

