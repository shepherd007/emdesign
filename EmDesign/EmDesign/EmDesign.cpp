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

int _tmain(int argc, _TCHAR* argv[])
{

	::testing::InitGoogleMock(&argc, argv);

	return RUN_ALL_TESTS();
}

