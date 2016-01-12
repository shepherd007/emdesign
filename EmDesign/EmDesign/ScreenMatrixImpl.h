#pragma once 

#include "stdafx.h"
#include "TouchScreenApi.h"
#include "State.h"
#include <algorithm>

bool isEmpty(const std::vector<int>& v);

class ScreenMatrixImpl : public ScreenMatrix {
public:
	ScreenMatrixImpl() : m_currentState(States::PROCESSING), m_lastEmpty(true) {}
	virtual string operator()(const std::vector<int>& data);
	virtual ~ScreenMatrixImpl() {}
private:
	States m_currentState;
	bool m_lastEmpty;
	std::string m_point;
	void processState(const std::vector<int>&);
	void handleProcessingState(const std::vector<int>& v);
	void handleNonProcessingLneState(const std::vector<int>& v);
	void handleNonProcessingLeState(const std::vector<int>& v);
};