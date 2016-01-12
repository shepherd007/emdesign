#include "stdafx.h"
#include "ScreenMatrixImpl.h"

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

void ScreenMatrixImpl::ChangeState(const std::vector<int>& v)
{
	bool isCurrentEmpty = isEmpty(v);

	Events currentEvent = Events::NO_CHANGE;

	if (isCurrentEmpty && !m_lastEmpty)
	{
		currentEvent = Events::FULL_TO_EMPTY;
	}
	else if (!isCurrentEmpty && m_lastEmpty)
	{
		currentEvent = Events::EMPTY_TO_FULL;
	}
	else if (isCurrentEmpty && m_lastEmpty)
	{
		currentEvent = Events::EMPTY_TO_EMPTY;
	}

	//
	switch (m_currentState)
	{
	case States::PROCESSING:
		if (currentEvent == Events::EMPTY_TO_FULL)
		{
			m_point = std::string("D(1,1)");
			m_currentState = States::NON_PROCESSING_LNE;
		}
		break;
	case States::NON_PROCESSING_LE:
		if (currentEvent == Events::EMPTY_TO_EMPTY)
		{
			m_point = std::string("");
			m_currentState = States::PROCESSING;
		}

		break;
	case States::NON_PROCESSING_LNE:
		if (currentEvent == Events::FULL_TO_EMPTY)
		{
			m_currentState = States::NON_PROCESSING_LE;
		}
		else
		{
			// just update position
			m_point = std::string("D(1,1)");
		}
		break;
	}

	m_lastEmpty = isCurrentEmpty;
}

string ScreenMatrixImpl::operator()(const std::vector<int>& data)
{
	ChangeState(data);

	return m_point;
}
