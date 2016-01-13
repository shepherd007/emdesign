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

Point calcPoint(const std::vector<int>& v)
{
	int start_point = 0;
	int end_point = 0;
	auto it = std::find_if(v.begin(), v.end(), [](const int a) { return a != 0; });
	if (it != v.end())
	{
		start_point = std::distance(v.begin(), it);
	}
	auto it2 = std::find_if(v.rbegin(), v.rend(), [](int a) { return (a == 1); });
	if (it2 != v.rbegin())
	{
		end_point = std::distance(it2, v.rend()) - 1;
	}
	Point start(start_point);
	Point end(end_point);

	
	return start.average(end);
}

void ScreenMatrixImpl::handleProcessingState(const std::vector<int>& v)
{
	bool isCurrentEmpty = isEmpty(v);
	if(!isCurrentEmpty && m_lastEmpty)
	{
		m_point = m_lastPoint.toString();
		m_currentState = States::NON_PROCESSING_LNE;
	}
	m_lastEmpty = isCurrentEmpty;
}

void ScreenMatrixImpl::handleNonProcessingLastEmptyState(const std::vector<int>& v)
{
	bool isCurrentEmpty = isEmpty(v);
	if (isCurrentEmpty && m_lastEmpty)
	{
		m_point = std::string("");
		m_currentState = States::PROCESSING;
	}
	m_lastEmpty = isCurrentEmpty;
}

void ScreenMatrixImpl::handleNonProcessingLastNotEmptyState(const std::vector<int>& v)
{
	bool isCurrentEmpty = isEmpty(v);
	if (isCurrentEmpty && !m_lastEmpty)
	{
		m_currentState = States::NON_PROCESSING_LE;
	}
	else
	{
		// just update position	
		m_lastPoint = calcPoint(v);
		m_point = m_lastPoint.toString();
	}
	m_lastEmpty = isCurrentEmpty;
}

void ScreenMatrixImpl::processState(const std::vector<int>& v)
{
	switch (m_currentState)
	{
	case States::PROCESSING:
		handleProcessingState(v);
		break;
	case States::NON_PROCESSING_LE:
		handleNonProcessingLastEmptyState(v);
		break;
	case States::NON_PROCESSING_LNE:
		handleNonProcessingLastNotEmptyState(v);
		break;
	}
}

string ScreenMatrixImpl::operator()(const std::vector<int>& data)
{
	processState(data);

	return m_point;
}
