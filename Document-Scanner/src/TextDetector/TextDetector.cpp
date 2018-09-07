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

void SaveToFile(std::vector<std::string> toSave)
{
	std::ofstream file;
	file.open("swapRegister.txt");

	for (std::string line : toSave)
	{
		file << line << "\n"; 
	}
	file.close();
}


void TextDetector::UpdateRectanglesState(int leftSideSwapIndex, int rightSideSwapIndex, int pivot)
{
	if (leftSideSwapIndex == -1)
		rectanglesSwapRegister = std::vector<std::string>(rectangles.size());
	
	for (int i = 0; i < rectanglesSwapRegister.size(); i++)
	{
		if (leftSideSwapIndex == -1)
			rectanglesSwapRegister[i] = toString(i) + "\t(" + toString(rectangles[i].x) + "," + toString(rectangles[i].y) + ")";

		else
		{
			if(rectangles[i].y == pivot)
				rectanglesSwapRegister[i].append("[P]");
			if(i == leftSideSwapIndex)
				rectanglesSwapRegister[i].append("*");
			rectanglesSwapRegister[i].append("\t");
			if(i == rightSideSwapIndex)
				rectanglesSwapRegister[i].append("*");
			
			rectanglesSwapRegister[i].append(toString(i) + "(" + toString(rectangles[i].x) + "," + toString(rectangles[i].y) + ")");
		}
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

	//SortRectangles();

	for (int i = 0; i < rectangles.size(); i++)
	{
		cv::rectangle(sourceImage, rectangles[i], cv::Scalar(0, 255, 0), 1);
		cv::putText(sourceImage, toString(i), cv::Point(rectangles[i].x, rectangles[i].y), cv::FONT_HERSHEY_COMPLEX, 0.3, cv::Scalar(0, 0, 255));
	}

	cv::imwrite("labeled.jpg", sourceImage);
	SHOW(sourceImage)
}




void TextDetector::SortRectangles()
{
	for (int i = 0; i < rectangles.size(); i++)
	{
		for (int j = 0; j < rectangles.size()-1; j++)
		{
			if (std::abs(rectangles[j].y - rectangles[i].y) <= rectangles[j].height)
			{
				if (rectangles[j].x > rectangles[i].x)
					std::swap(rectangles[j], rectangles[i]);
			}
			else if (rectangles[j].y > rectangles[i].y)
			{
				std::swap(rectangles[j], rectangles[i]);
			}
		}
	}
}