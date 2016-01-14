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

//
TEST_F(TouchFixture, test_matrix_too_big_index_out_of_bounds)
{
	std::vector<int> empty_vec(100);
	std::vector<int> touched_vec(200);
	touched_vec[199] = 1;

	std::string first = (*pMat)(empty_vec);
	std::string second = (*pMat)(touched_vec);
	std::string third = (*pMat)(empty_vec);
	std::string fourth = (*pMat)(empty_vec);

	EXPECT_EQ(0, first.compare(""));
	EXPECT_EQ(0, second.compare(""));
	EXPECT_EQ(0, third.compare(""));
	EXPECT_EQ(0, fourth.compare(""));
}

TEST_F(TouchFixture, test_matrix_too_big_index_in_bounds)
{
	std::vector<int> empty_vec(100);
	std::vector<int> touched_vec(200);
	touched_vec[99] = 1;

	std::string first = (*pMat)(empty_vec);
	std::string second = (*pMat)(touched_vec);
	std::string third = (*pMat)(empty_vec);
	std::string fourth = (*pMat)(empty_vec);

	EXPECT_EQ(0, first.compare(""));
	EXPECT_EQ(0, second.compare(""));
	EXPECT_EQ(0, third.compare("D(10,10)"));
	EXPECT_EQ(0, fourth.compare(""));
}

TEST_F(TouchFixture, test_matrix_too_small_index_out_of_bounds)
{
	std::vector<int> empty_vec(100);
	std::vector<int> touched_vec(200);
	touched_vec[149] = 1;

	std::string first = (*pMat)(empty_vec);
	std::string second = (*pMat)(touched_vec);
	std::string third = (*pMat)(empty_vec);
	std::string fourth = (*pMat)(empty_vec);

	EXPECT_EQ(0, first.compare(""));
	EXPECT_EQ(0, second.compare(""));
	EXPECT_EQ(0, third.compare(""));
	EXPECT_EQ(0, fourth.compare(""));
}

TEST_F(TouchFixture, test_matrix_too_small_index_in_bounds)
{
	std::vector<int> empty_vec(100);
	std::vector<int> touched_vec(50);
	touched_vec[49] = 1;

	std::string first = (*pMat)(empty_vec);
	std::string second = (*pMat)(touched_vec);
	std::string third = (*pMat)(empty_vec);
	std::string fourth = (*pMat)(empty_vec);

	EXPECT_EQ(0, first.compare(""));
	EXPECT_EQ(0, second.compare(""));
	EXPECT_EQ(0, third.compare("D(10,5)"));
	EXPECT_EQ(0, fourth.compare(""));
}

TEST_F(TouchFixture, test_point_to_string)
{
	Point pt1(0);
	EXPECT_EQ("D(1,1)", pt1.toString());

	Point pt2(99);
	EXPECT_EQ("D(10,10)", pt2.toString());
}

TEST_F(TouchFixture, test_point_single_touch)
{
	std::vector<int> empty_vec(100);
	std::vector<int> touched_vec(100);

	touched_vec[8] = 1;

	PointObject* pt = calcPoint(touched_vec);
	EXPECT_EQ("D(9,1)", pt->toString());
}

TEST_F(TouchFixture, test_point_multi_touch)
{
	std::vector<int> empty_vec(100);
	std::vector<int> touched_vec(100);

	touched_vec[4] = 1;
	touched_vec[21] = 1;
	PointObject* pt = calcPoint(touched_vec);
	EXPECT_EQ("D(3,2)", pt->toString());
}