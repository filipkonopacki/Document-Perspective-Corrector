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
		LoadImage(fileName);
}

void DocumentScanner::LoadImage(std::string fileName)
{
	cv::Mat image = cv::imread(fileName);
	sourceImages.push_back(image);
}

bool DocumentScanner::AreEmpty()
{
	for (cv::Mat image : sourceImages)
		if (image.empty())
			return false;
	
	return true;
}

cv::Mat DocumentScanner::GetSourceImageAt(int index)
{
	return sourceImages.at(index);
}

int DocumentScanner::GetNumberOfPages()
{
	return sourceImages.size();
}

std::vector<cv::Mat> DocumentScanner::CorrectImagePerspective(int index, DetectionMode mode)
{
	AutomaticPerspectiveCorrector corrector;
	std::vector<cv::Mat> result;
	switch (mode)
	{
		case AUTO:
			result.push_back(corrector.GetCorrectedImage(sourceImages.at(index)));
			break;
		case ALL_AUTO:
			for (int i = index; i < sourceImages.size(); i++)
			{
				result.push_back(corrector.GetCorrectedImage(sourceImages.at(i)));
			}
			break;
		case MANUAL:
			result.push_back(getCorrectedImage(sourceImages.at(index)));
			break;
		case ALL_MANUAL:
			for (int i = index; i < sourceImages.size(); i++)
			{
				result.push_back(getCorrectedImage(sourceImages.at(i)));
			}
			break;
	}

	return result;
}

void DocumentScanner::PushPage(Page page)
{
	pages.push_back(page);
}