#pragma once 

#include "stdafx.h"
#include "TouchScreenApi.h"
#include "State.h"
#include <algorithm>

bool isEmpty(const std::vector<int>& v);

class ScreenMatrixImpl : public ScreenMatrix {
public:
	ScreenMatrixImpl() : currentState(States::PROCESSING), lastEmpty(true) {}
	virtual string operator()(const std::vector<int>& data);
	virtual ~ScreenMatrixImpl() {}
private:
	States currentState;
	bool lastEmpty;
	std::string point;
	void ScreenMatrixImpl::ChangeState(const std::vector<int>& vy);
	

};