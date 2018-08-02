#include "pch.h"
#include "..//Document-Perspective-Corrector/src/PerspectiveCorrector.h"



class PerspectiveCorrectorTest : public ::testing::Test
{
private:
	PerspectiveCorrector test;

protected:
	bool LoadImage(std::string fileName)
	{
		return test.LoadImage(fileName);
	}

	void NormalizeSize()
	{
		test.NormalizeSize();
	}

	std::pair <int, int> getSize()
	{
		test.NormalizeSize();
		std::pair <int, int> size(test.sourceImage.cols, test.sourceImage.rows);
		return size;
	}
};


TEST_F(PerspectiveCorrectorTest, LoadInvalidImage)
{
	bool result = LoadImage("Testing_data\\invalidImage.jpg");
	EXPECT_FALSE(result);
}




TEST_F(PerspectiveCorrectorTest, LoadValidImage)
{
	bool result = LoadImage("IMG_0345.jpg");
	ASSERT_TRUE(result);
}



TEST_F(PerspectiveCorrectorTest, CheckSizeAfterNormalization)
{
	std::pair <int, int> size = getSize();
	EXPECT_EQ(size.first, 600);
	EXPECT_EQ(size.second, 800);
}


int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}