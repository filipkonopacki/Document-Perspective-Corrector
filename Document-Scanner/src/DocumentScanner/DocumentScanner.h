#pragma once
#include "opencv2/core.hpp"
#include "opencv2/opencv.hpp"
#include "../TextDetector/TextParts/Page.h"


#include <vector>
#include <string>

enum DetectionMode{AUTO, MANUAL, ALL_AUTO, ALL_MANUAL};


class DocumentScanner
{
public:
	DocumentScanner();
	~DocumentScanner();
	void LoadPages(std::vector<std::string> fileNames);
	
	


private:
	void LoadImage(std::string fileName);
	void UpdatePages();


	std::vector<cv::Mat> sourceImages;
	std::vector<Page> pages;
	int currentPageIndex = 0;
};

