#include "TextDetector.h"

#define LOG(x) {std::cout << x <<std::endl;}
#define SHOW(x){cv::imshow("TEST", x);cv::waitKey(0);}

TextDetector::TextDetector(cv::Mat image)
	:sourceImage(image), processedImage(image)
{
	sourceImage = NormalizeImageSize(sourceImage);
	processedImage = sourceImage.clone();
}

void TextDetector::DetectText()
{
	SHOW(sourceImage)
	cv::cvtColor(processedImage, processedImage, cv::COLOR_BGR2GRAY);
	
	processedImage.convertTo(processedImage, -1, 1, -40);
	cv::threshold(processedImage, processedImage, 80, 255, cv::THRESH_BINARY);

	SHOW(processedImage)

	cv::findContours(processedImage, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

	std::vector<cv::Rect> rectangles(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		rectangles[i] = cv::boundingRect(contours[i]);
	}

	int i = 0, j;

	std::vector<cv::Rect> newRect;

	for (j = 0 + i; j < rectangles.size(); j++)
	{
		int distance = (rectangles[j].x + rectangles[j].width) - rectangles[j+1].x;

		if (std::abs(distance) < 0.025)
		{
			newRect.push_back(AddRectangles(rectangles[j], rectangles[j + 1], distance));
			for (i = j + 1; i < rectangles.size(); i++)
			{
				distance = (rectangles[i].x + rectangles[i].width) - rectangles[i + 1].x;
				if (distance < 0.025)
				{
					newRect[newRect.size()-1] = AddRectangles(newRect[newRect.size()-1], rectangles[i + 1], distance);
				}
				break;
			}
			cv::rectangle(sourceImage, newRect[newRect.size()-1], cv::Scalar(0, 0, 255), 3);
		}
	}


	SHOW(sourceImage)
}


cv::Mat TextDetector::NormalizeImageSize(cv::Mat image)
{
	cv::resize(image, image, cv::Size(600, 800), cv::INTER_LANCZOS4);
	return image;
}


cv::Rect TextDetector::AddRectangles(cv::Rect firstRect, cv::Rect secondRect, int distance)
{
	firstRect.width = firstRect.width + distance + secondRect.width;
	firstRect.height = firstRect.height + std::abs(firstRect.height - secondRect.height);

	return firstRect;
}