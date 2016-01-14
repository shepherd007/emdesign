#include "stdafx.h"
#include "gtest.h"
#include "gmock.h"
#include "TouchScreenApi.h"
#include "ScreenMatrixImpl.h"
#include "Point.h"

class TouchFixture : public ::testing::Test
{
protected:
	ScreenMatrix* pMat;

	std::vector<int> empty_vec;
	std::vector<int> touched_vec;
	std::vector<int> touched_vec1;
	std::vector<int> touched_vec2;

	
	void SetUp() { 
		pMat = createScreenMatrix();
		empty_vec = std::vector<int>(100);
		touched_vec = std::vector<int>(100);
		touched_vec[0] = 1;
		touched_vec1 = std::vector<int>(touched_vec);
		touched_vec2 = std::vector<int>(touched_vec);
	}
	void TearDown() {
		delete pMat;
	}
};


TEST_F(TouchFixture, test_matrix_report_empty_to_touch)
{
	std::string first = (*pMat)(empty_vec);
	std::string second = (*pMat)(touched_vec);

	EXPECT_EQ(0, first.compare(""));
	EXPECT_EQ(0, second.compare(""));
}

TEST_F(TouchFixture, test_matrix_report_touch_to_touch)
{
	std::string first = (*pMat)(touched_vec1);
	std::string second = (*pMat)(touched_vec2);

	EXPECT_EQ(0, first.compare(""));
	EXPECT_EQ(0, second.compare(""));
}