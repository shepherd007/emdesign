#include "stdafx.h"
#include "ScreenMatrixImpl.h"
#include <sstream>
#include "Point.h"

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

void ScreenMatrixImpl::handleProcessingState(const std::vector<int>& v)
{
	bool isCurrentEmpty = isEmpty(v);
	if(!isCurrentEmpty && m_lastEmpty)
	{
		Point pt(0);
		
		m_point = pt.toString();
		m_currentState = States::NON_PROCESSING_LNE;
	}
	m_lastEmpty = isCurrentEmpty;
}

void ScreenMatrixImpl::handleNonProcessingLneState(const std::vector<int>& v)
{
	bool isCurrentEmpty = isEmpty(v);
	if (isCurrentEmpty && m_lastEmpty)
	{
		m_point = std::string("");
		m_currentState = States::PROCESSING;
	}
	m_lastEmpty = isCurrentEmpty;
}

void ScreenMatrixImpl::handleNonProcessingLeState(const std::vector<int>& v)
{
	bool isCurrentEmpty = isEmpty(v);
	if (isCurrentEmpty && !m_lastEmpty)
	{
		m_currentState = States::NON_PROCESSING_LE;
	}
	else
	{
		// just update position
		Point pt(0);		
		m_point = pt.toString();
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
		handleNonProcessingLneState(v);
		break;
	case States::NON_PROCESSING_LNE:
		handleNonProcessingLeState(v);
		break;
	}
}

string ScreenMatrixImpl::operator()(const std::vector<int>& data)
{
	processState(data);

	return m_point;
}
