#pragma once
#include "opencv2/core.hpp"
#include "Line.h"
#include "../../AutomaticPerspectiveCorrector/AutomaticPerspectiveCorrector.h"
#include "../../ManualPerspectiveCorrector/ManualPerspectiveCorrector.h"


#include <vector>

class Page
{
public:
	Page(cv::Mat sourceImage);
	~Page();



private:
	cv::Mat page;

	std::vector<Line> lines;
};

