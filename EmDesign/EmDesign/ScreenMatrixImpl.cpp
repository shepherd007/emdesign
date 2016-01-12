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

		if (isCurrentEmpty && !lastEmpty)
		{
			currentEvent = Events::FULL_TO_EMPTY;
		}
		else if (!isCurrentEmpty && lastEmpty)
		{
			currentEvent = Events::EMPTY_TO_FULL;
		}
		else if (isCurrentEmpty && lastEmpty)
		{
			currentEvent = Events::EMPTY_TO_EMPTY;
		}

		//
		switch (currentState)
		{
		case States::PROCESSING:
			if (currentEvent == Events::EMPTY_TO_FULL)
			{
				point = std::string("D(1,1)");
				currentState = States::NON_PROCESSING_LNE;
			}
			break;
		case States::NON_PROCESSING_LE:
			if (currentEvent == Events::EMPTY_TO_EMPTY)
			{
				point = std::string("");
				currentState = States::PROCESSING;
			}

			break;
		case States::NON_PROCESSING_LNE:
			if (currentEvent == Events::FULL_TO_EMPTY)
			{
				currentState = States::NON_PROCESSING_LE;
			}
			else
			{
				// just update position
				point = std::string("D(1,1)");
			}
			break;
		}

		lastEmpty = isCurrentEmpty;
	}

string ScreenMatrixImpl::operator()(const std::vector<int>& data)
{
	ChangeState(data);

	return point;
}
