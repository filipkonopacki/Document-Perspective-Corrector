#include "DocumentScanner.h"



DocumentScanner::DocumentScanner()
{
}


DocumentScanner::~DocumentScanner()
{
}


void DocumentScanner::LoadPages(std::vector<std::string> fileNames)
{
	if (sourceImages.size() != 0)
		sourceImages.clear();

	for (std::string fileName : fileNames)
	{
		LoadImage(fileName);
	}

	UpdatePages();
}

void DocumentScanner::LoadImage(std::string fileName)
{
	cv::Mat image = cv::imread(fileName);
	sourceImages.push_back(image);
}

void DocumentScanner::UpdatePages()
{
	for (cv::Mat image : sourceImages)
	{
		pages.push_back(Page(image));
	}
}

bool DocumentScanner::AreEmpty()
{
	for (cv::Mat image : sourceImages)
		if (image.empty())
			return false;
	
	return true;
}