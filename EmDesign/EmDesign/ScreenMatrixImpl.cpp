#include "stdafx.h"
#include "ScreenMatrixImpl.h"
#include <sstream>
#include "Point.h"
#include <algorithm>

bool isEmpty(const std::vector<int>& v)
{
	auto it = std::find_if(v.begin(), v.end(), [](int elem)
	{
		return elem != 0;
	});

	if (it != v.end())
		return false;

	return true;
}

PointObject* calcPoint(const std::vector<int>& v)
{
	PointObject* pO = nullptr;

	int start_point = 0;
	int end_point = 0;

	auto it = std::find_if(v.begin(), v.end(), [](const int a) { return (a != 0); });
	auto it2 = std::find_if(v.rbegin(), v.rend(), [](int a) { return (a != 0); });

	if ((it != v.end()))// && (it2 != v.rbegin()))
	{
		Point startPt(std::distance(v.begin(), it));
		Point endPt(std::distance(it2, v.rend()) - 1);

		pO = new Point(average(startPt, endPt));
	}
	else
	{
		pO = new NullPoint();
	}

	return pO;
}

ScreenMatrixImpl::ScreenMatrixImpl() : 
m_lastEmpty(true)
{
	m_lastPoint = new NullPoint();

	m_pProcessingState = new ProcessingState(this);
	m_pLastEmptyState = new ProcessingStateLastEmpty(this);
	m_pLastNonEmptyState = new ProcessingStateLastNotEmpty(this);

	m_pCurrentState = m_pProcessingState;
}

bool ScreenMatrixImpl::getLastEmptyFlag()
{
	return m_lastEmpty;
}

void ScreenMatrixImpl::setLastEmptyFlag(bool flag)
{
	m_lastEmpty = flag;
}

PointObject* ScreenMatrixImpl::getLastPoint()
{
	return m_lastPoint;
}

void ScreenMatrixImpl::print()
{
	m_pointStr = m_lastPoint->toString();
}

void ScreenMatrixImpl::setLastPoint(PointObject* pPoint)
{
	m_lastPoint = pPoint;
}

void ScreenMatrixImpl::changeState(States state)
{
	switch (state)
	{
	case States::PROCESSING:
		m_pCurrentState = m_pProcessingState;
		break;
	case States::NON_PROCESSING_LE:
		m_pCurrentState = m_pLastEmptyState;
		break;
	case States::NON_PROCESSING_LNE:
		m_pCurrentState = m_pLastNonEmptyState;
		break;
	}
}

string ScreenMatrixImpl::operator()(const std::vector<int>& data)
{
	//std::vector<int> vecCopy;
	//std::copy_n(data.begin(), 100, std::back_inserter(vecCopy));

	if (data.size() == 100)
	{
		m_pCurrentState->process(data);
	}
	return m_pointStr;
}
