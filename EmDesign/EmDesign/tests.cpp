#include "stdafx.h"
#include "gtest.h"
#include "gmock.h"
#include "TouchScreenApi.h"
#include "ScreenMatrixImpl.h"
#include "Point.h"

PointObject* calcPoint(const std::vector<int>& v);

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


//
TEST_F(TouchFixture, test_point_multi_touch)
{
	std::vector<int> empty_vec(100);
	std::vector<int> touched_vec(100);

	touched_vec[4] = 1;
	touched_vec[21] = 1;
	PointObject* pt = calcPoint(touched_vec);
	EXPECT_EQ("D(3,2)", pt->toString());
}