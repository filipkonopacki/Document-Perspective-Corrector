#include "pch.h"
#include "..//Document-Perspective-Corrector/src/ManualPerspectiveCorrector.h"
#include <random>

cv::Mat sourceImageT;

int getRandomIntInRange(int min, int max)
{
	std::random_device randomDevice;
	std::mt19937 generator(randomDevice());
	std::uniform_int_distribution<int> randomInt(min, max);
	return randomInt(generator);
}

TEST(InputTest, LoadInvalidImage)
{
	bool result = LoadImage("invalidImage.jpg",sourceImageT);
	EXPECT_FALSE(result);
}

TEST(InputTest, LoadValidImage)
{
	bool result = LoadImage("IMG_0345.jpg",sourceImageT);
	ASSERT_TRUE(result);
}


TEST(LogicTest, CheckSizeAfterNormalization)
{
	ASSERT_TRUE(LoadImage("IMG_0345.jpg",sourceImageT));
	sourceImageT = NormalizeImageSize(sourceImageT);
	EXPECT_EQ(sourceImageT.cols, 600);
	EXPECT_EQ(sourceImageT.rows, 800);
}

TEST(LogicTest, CheckDistanceMeasurmentCorrectness)
{
	ASSERT_TRUE(LoadImage("IMG_0345.jpg", sourceImageT));
	cv::Point2f firstPoint(getRandomIntInRange(0, 600), getRandomIntInRange(0, 800));
	cv::Point2f secondPoint(getRandomIntInRange(0, 600), getRandomIntInRange(0, 800));
	int result = measureDistanceBetweenPoints(firstPoint, secondPoint);
	EXPECT_LT(result, 1000);
}


int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}