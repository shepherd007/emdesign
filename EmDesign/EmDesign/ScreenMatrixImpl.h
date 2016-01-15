#pragma once

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
	void changeState(States);
	PointObject* getPoint();
	void setPoint(PointObject*);
	void print();
private:
	std::string m_pointStr;
	PointObject* m_lastPoint;
	ParsedMatrix x;
	State* m_pProcessingState;
	State* m_pLastEmptyState;
	State* m_pLastNonEmptyState;

	State* m_pCurrentState;
};
