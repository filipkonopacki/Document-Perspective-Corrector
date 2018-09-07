#pragma once
#include "opencv2/core.hpp"
#include "opencv2/opencv.hpp"
#include "../TextDetector/TextParts/Page.h"


#include <vector>
#include <string>

enum DetectionMode{AUTO, MANUAL, };


class DocumentScanner
{
public:
	DocumentScanner();
	~DocumentScanner();
	void LoadPages(std::vector<std::string> fileNames);
	void LoadImage(std::string fileName);
	void UpdatePages();
	


private:
	std::vector<cv::Mat> sourceImages;
	std::vector<Page> pages;
	int currentPageIndex = 0;
};

