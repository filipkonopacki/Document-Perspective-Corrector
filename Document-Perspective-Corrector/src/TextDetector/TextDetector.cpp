#include "TextDetector.h"

#define LOG(x) {std::cout << x <<std::endl;}
#define SHOW(x){cv::imshow("TEST", x);cv::waitKey(0);}

TextDetector::TextDetector(cv::Mat image)
	:sourceImage(image), processedImage(image)
{
	
	processedImage = sourceImage.clone();
}


bool Comparator(cv::Rect firstRect, cv::Rect secondRect)
{
	return firstRect.y < secondRect.y && firstRect.x < firstRect.x;
}

void TextDetector::DetectText()
{
	std::vector<cv::Rect> rectangles;
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

	std::stable_sort(rectangles.begin(), rectangles.end(), Comparator);


	for (int i = 0; i < rectangles.size(); i++)
	{
		cv::rectangle(sourceImage, rectangles[i], cv::Scalar(0, 255, 0), 3);
		cv::putText(sourceImage, toString(i), cv::Point(rectangles[i].x, rectangles[i].y), cv::FONT_HERSHEY_COMPLEX, 0.5, cv::Scalar(0,0,255));
	}

	SHOW(sourceImage)
}



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