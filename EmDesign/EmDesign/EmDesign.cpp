 // EmDesign.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TouchScreenApi.h"
#include "ScreenMatrixImpl.h"
#include "Point.h"
#include <algorithm>
#include <iostream>
#include <tchar.h>
#include "gtest.h"
#include "gmock.h"


int failedTests = 0;

PointObject* calcPoint(const std::vector<int>& v);
#define ASSERT(x) if(x == false) { std::cout << "Test " << __FUNCTION__ << " failed in line "  << __LINE__ << std::endl; failedTests++; }

// Sygnalem rozpoczecia przetwarzania jest odczyt pelnej matrycy nastepujacej po pustej




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

// Sygnalem zakonczenia przetwarzania jest odczyt pustej matrycy po pelnej
void test_matrix_report_touch_to_empty1()
{
	std::vector<int> empty_vec(100);
	std::vector<int> touched_vec(100);

	touched_vec[0] = 1;

	ScreenMatrix* pMat = createScreenMatrix();

	std::string first = (*pMat)(touched_vec);
	std::string second = (*pMat)(empty_vec);
	std::string third = (*pMat)(empty_vec);
	ASSERT(0 == first.compare(""));
	ASSERT(0 == second.compare("D(1,1)"));
	ASSERT(0 == third.compare(""));
}

// Gdy matryca pusta jest poprzedzona wiecej niz jedna matryca pelna, wynik powinien pochodzic z ostatniej pelnej matrycy
void test_matrix_report_touch_to_empty2()
{
	std::vector<int> empty_vec(100);
	std::vector<int> touched_vec1(100);
	std::vector<int> touched_vec2(100);

	touched_vec1[0] = 1;
	touched_vec2[1] = 1;

	ScreenMatrix* pMat = createScreenMatrix();

	std::string first = (*pMat)(touched_vec1);
	std::string second = (*pMat)(touched_vec2);
	std::string third = (*pMat)(empty_vec);

	ASSERT(0 == first.compare(""));
	ASSERT(0 == second.compare(""));
	ASSERT(0 == third.compare("D(2,1)"));
}

void test_matrix_report_empty_to_touch_to_empty()
{
	std::vector<int> empty_vec(100);
	std::vector<int> touched_vec(100);
	touched_vec[99] = 1;
	ScreenMatrix* pMat = createScreenMatrix();
	std::string first = (*pMat)(empty_vec);
	std::string second = (*pMat)(touched_vec);
	std::string third = (*pMat)(empty_vec);

	ASSERT(0 == first.compare(""));
	ASSERT(0 == second.compare(""));
	ASSERT(0 == third.compare("D(10,10)"));
}

int _tmain(int argc, _TCHAR* argv[])
{

	::testing::InitGoogleMock(&argc, argv);

	return RUN_ALL_TESTS();
}

