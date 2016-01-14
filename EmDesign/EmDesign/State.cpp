#include "stdafx.h"
#include "State.h"
#include "ScreenMatrixImpl.h"
#include <vector>
#include <typeinfo>

PointObject* calcPoint(const std::vector<int>& v);

bool isPointValid(PointObject* pPoint)
{
	return typeid(*pPoint) == typeid(NullPoint);
}
//
ProcessingState::ProcessingState(ScreenMatrixImpl* pContext)
{
	m_pContext = pContext;
}

void ProcessingState::process(const std::vector<int>& v)
{
	PointObject* pCurrentPoint = calcPoint(v);

	bool isCurrentEmpty = isPointValid(pCurrentPoint);
	bool isPrevEmpty = isPointValid(m_pContext->getPoint());

	if (!isCurrentEmpty && isPrevEmpty)
	{
		m_pContext->print();
		m_pContext->changeState(States::NON_PROCESSING_LNE);
	}

	m_pContext->setPoint(pCurrentPoint);
}

//
ProcessingStateLastNotEmpty::ProcessingStateLastNotEmpty(ScreenMatrixImpl* pContext)
{
	m_pContext = pContext;
}

void ProcessingStateLastNotEmpty::process(const std::vector<int>& v)
{
	PointObject* pCurrentPoint = calcPoint(v);

	bool isCurrentEmpty = isPointValid(pCurrentPoint);
	bool isPrevEmpty = isPointValid(m_pContext->getPoint());

	if (isCurrentEmpty && !isPrevEmpty)
	{
		m_pContext->print();
		m_pContext->changeState(States::NON_PROCESSING_LE);
	}

	m_pContext->setPoint(pCurrentPoint);
}

//
ProcessingStateLastEmpty::ProcessingStateLastEmpty(ScreenMatrixImpl* pContext)
{
	m_pContext = pContext;
}

void ProcessingStateLastEmpty::process(const std::vector<int>& v)
{
	PointObject* pCurrentPoint = calcPoint(v);

	bool isCurrentEmpty = isPointValid(pCurrentPoint);
	bool isPrevEmpty = isPointValid(m_pContext->getPoint());

	if (isCurrentEmpty && isPrevEmpty)
	{
		m_pContext->print();
		m_pContext->changeState(States::PROCESSING);
	}

	m_pContext->setPoint(pCurrentPoint);
}
