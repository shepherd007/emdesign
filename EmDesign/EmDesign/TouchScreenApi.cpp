#include "stdafx.h"
#include "TouchScreenApi.h"
#include "ScreenMatrixImpl.h"

ScreenMatrix* createScreenMatrix()
{
	return new ScreenMatrixImpl();
}
