#include "stdafx.h"
#include "TouchScreenApi.h"


class ScreenMatrixImpl : public ScreenMatrix {
public:
	ScreenMatrixImpl() {}
	virtual string operator()(const std::vector<int>& data) { return std::string("");  };
	virtual ~ScreenMatrixImpl() {}
};