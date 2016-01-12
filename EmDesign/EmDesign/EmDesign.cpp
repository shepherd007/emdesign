// EmDesign.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TouchScreenApi.h"
#include "ScreenMatrixImpl.h"
#include <algorithm>
#include <iostream>

#define ASSERT(x) if(x == false) { std::cout << "Test " << __FUNCTION__ << " failed in line "  << __LINE__ << std::endl;}
void test_matrix_report_empty_to_touch()
{
	std::vector<int> empty_vec(100);
	std::vector<int> touched_vec(100);

	touched_vec[0] = 1;

	ScreenMatrix* pMat = createScreenMatrix();

	std::string first = (*pMat)(empty_vec);
	std::string second = (*pMat)(touched_vec);

	ASSERT(0 == first.compare(""));
	ASSERT(0 == second.compare("D(1,1)"));
}

void test_matrix_report_touch_to_touch()
{
	std::vector<int> touched_vec1(100);
	std::vector<int> touched_vec2(100);

	touched_vec1[0] = 1;
	touched_vec2[1] = 1;
	ScreenMatrix* pMat = createScreenMatrix();

	std::string first = (*pMat)(touched_vec1);
	std::string second = (*pMat)(touched_vec2);

	ASSERT(0 == first.compare("D(1,1)"));
	ASSERT(0 == second.compare("D(2,1)"));
}

void test_matrix_report_empty_to_empty()
{
	std::vector<int> empty_vec1(100);
	std::vector<int> empty_vec2(100);

	ScreenMatrix* pMat = createScreenMatrix();

	std::string first = (*pMat)(empty_vec1);
	std::string second = (*pMat)(empty_vec2);

	ASSERT(0 == first.compare(""));
	ASSERT(0 == second.compare(""));
}

void test_matrix_report_touch_to_empty()
{
	std::vector<int> empty_vec(100);
	std::vector<int> touched_vec(100);

	touched_vec[0] = 1;

	ScreenMatrix* pMat = createScreenMatrix();

	std::string first = (*pMat)(touched_vec);
	std::string second = (*pMat)(empty_vec);
	std::string third = (*pMat)(empty_vec);
	ASSERT(0 == first.compare("D(1,1)"));
	ASSERT(0 == second.compare("D(1,1)"));
	ASSERT(0 == second.compare(""));
}

int _tmain(int argc, _TCHAR* argv[])
{
	test_matrix_report_empty_to_touch();
	test_matrix_report_touch_to_touch();
	test_matrix_report_touch_to_empty();
	test_matrix_report_empty_to_empty();

	return 0;
}

