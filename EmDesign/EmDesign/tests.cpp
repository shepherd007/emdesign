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
	void SetUp() { 
		pMat = createScreenMatrix(); 
	}
	void TearDown() {
		delete pMat;
	}
};


TEST_F(TouchFixture, test_matrix_report_empty_to_touch)
{
	std::vector<int> empty_vec(100);
	std::vector<int> touched_vec(100);

	touched_vec[0] = 1;

	

	std::string first = (*pMat)(empty_vec);
	std::string second = (*pMat)(touched_vec);

	EXPECT_EQ(0, first.compare(""));
	EXPECT_EQ(0, second.compare(""));
}