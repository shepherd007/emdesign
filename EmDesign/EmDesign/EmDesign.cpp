// EmDesign.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TouchScreenApi.h"
#include "ScreenMatrixImpl.h"
#include <algorithm>
#include <cassert>

void test_matrix_report_new_touch()
{
	std::vector<int> empty_vec(100);
	std::vector<int> touched_vec(100);

	std::generate(empty_vec.begin(), empty_vec.end(), []()
	{
		return 0;
	});

	std::generate(touched_vec.begin(), touched_vec.end(), []()
	{
		return 0;
	});

	touched_vec[0] = 1;

	ScreenMatrix* pMat = createScreenMatrix();

	std::string first = (*pMat)(empty_vec);
	std::string second = (*pMat)(touched_vec);

	assert(0 == second.compare("D(0,0)"));
}


int _tmain(int argc, _TCHAR* argv[])
{
	test_matrix_report_new_touch();
	return 0;
}

