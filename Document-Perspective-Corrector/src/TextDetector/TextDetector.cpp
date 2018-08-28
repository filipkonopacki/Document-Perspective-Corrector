#include "TextDetector.h"


//----------------------------------------------------------------------------------------------------------------
#define LOG(x) {std::cout << x <<std::endl;}
#define SHOW(x){cv::imshow("TEST", x);cv::waitKey(0);}

#include <sstream>
#include <iostream>
#include <fstream>

std::string toString(int a)
{
	std::stringstream ss;
	ss << a;
	return ss.str();
}

void SaveToFile(std::string toSave)
{
	std::ofstream file;
	file.open("distances.txt");
	file << toSave;
	file.close();
}

bool Comparator(cv::Rect firstRect, cv::Rect secondRect)
{
	if (std::abs(firstRect.y - secondRect.y) < firstRect.height)
	{
		return firstRect.x < secondRect.x;
	}
	else
	{
		return firstRect.y < secondRect.y;
	}
}


//-----------------------------------------------------------------------------------------------------------------



TextDetector::TextDetector(cv::Mat image)
	:sourceImage(image), processedImage(image)
{
	
	processedImage = sourceImage.clone();
}


void TextDetector::DetectText()
{
	cv::Rect rectangle;
	cv::cvtColor(processedImage, processedImage, cv::COLOR_BGR2GRAY);	
	cv::threshold(processedImage, processedImage, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
	cv::findContours(processedImage, contours, hierarchy, cv::RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE);
	int maxArea = sourceImage.rows * sourceImage.cols;
	int minRectArea = 0.005 * maxArea / 100;
	int maxRectArea = 1.5 * maxArea / 100;

	for (int i = 0; i < contours.size(); i++)
	{
		 rectangle = cv::boundingRect(contours[i]);
		 if (rectangle.area() < maxRectArea && rectangle.area() > minRectArea)
		 {
			 rectangles.push_back(rectangle);
		 }
	}


	QuickSortRectangles(0, rectangles.size() - 1);
	for (int i = 0; i < rectangles.size(); i++)
	{
		cv::rectangle(sourceImage, rectangles[i], cv::Scalar(0, 255, 0), 1);
		cv::putText(sourceImage, toString(i), cv::Point(rectangles[i].x, rectangles[i].y), cv::FONT_HERSHEY_COMPLEX, 0.5, cv::Scalar(0,0,255));
	}

	SHOW(sourceImage)
}


void TextDetector::QuickSortRectangles(unsigned int leftSide, unsigned int rightSide)
{
	if (rightSide <= leftSide)
		return;

	int i = leftSide -1;
	int j = rightSide +1;

	int middleIndex = (leftSide + rightSide) / 2;

	int pivot = rectangles[middleIndex].y;

	while (true)
	{	
		while (pivot > rectangles[++i].y);
		while (pivot < rectangles[--j].y);
		

		if (i <= j)
		{
			if (std::abs(rectangles[i].y - rectangles[j].y) <= rectangles[i].height)
			{
				if(rectangles[i].x > rectangles[j].x)
					std::swap(rectangles[i], rectangles[j]);
			}
			std::swap(rectangles[i], rectangles[j]);
		}
		else
		{
			break;
		}
	}

	if (j > leftSide)
	{
		QuickSortRectangles(leftSide, j);
	}
	if (i < rightSide) 
	{
		QuickSortRectangles(i, rightSide);
	}
}