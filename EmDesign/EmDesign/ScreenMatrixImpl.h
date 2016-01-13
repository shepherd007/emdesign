#pragma once 

#include "stdafx.h"
#include "TouchScreenApi.h"
#include "State.h"
#include "Point.h"
#include <algorithm>

bool isEmpty(const std::vector<int>& v);

class ScreenMatrixImpl : public ScreenMatrix {
public:
	ScreenMatrixImpl();
	virtual string operator()(const std::vector<int>& data);
	virtual ~ScreenMatrixImpl() {}
	bool getLastEmptyFlag();
	void setLastEmptyFlag(bool flag);
	void changeState(States);
	PointObject* getLastPoint();
	void setLastPoint(PointObject*);
	void print();
private:
	States m_currentState;
	bool m_lastEmpty;
	std::string m_pointStr;
	PointObject* m_lastPoint;

	State* m_pProcessingState;
	State* m_pLastEmptyState;
	State* m_pLastNonEmptyState;

	State* m_pCurrentState;
};