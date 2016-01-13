#include "stdafx.h"
#include "State.h"
#include "ScreenMatrixImpl.h"
#include <vector>

bool isEmpty(const std::vector<int>& v);
PointObject* calcPoint(const std::vector<int>& v);

//
ProcessingState::ProcessingState(ScreenMatrixImpl* pContext)
{
	m_pContext = pContext;
}

void ProcessingState::process(const std::vector<int>& v)
{
	bool isCurrentEmpty = isEmpty(v);

	if (!isCurrentEmpty && m_pContext->getLastEmptyFlag())
	{
		m_pContext->print();
		m_pContext->setLastPoint(calcPoint(v));
		m_pContext->changeState(States::NON_PROCESSING_LNE);
	}
	
	m_pContext->setLastEmptyFlag(isCurrentEmpty);
}

//
ProcessingStateLastNotEmpty::ProcessingStateLastNotEmpty(ScreenMatrixImpl* pContext)
{
	m_pContext = pContext;
}

void ProcessingStateLastNotEmpty::process(const std::vector<int>& v)
{
	bool isCurrentEmpty = isEmpty(v);

	if (isCurrentEmpty && !m_pContext->getLastEmptyFlag())
	{
		m_pContext->print();
		m_pContext->setLastPoint(new NullPoint());
		m_pContext->changeState(States::NON_PROCESSING_LE);
	}
	else if (!isCurrentEmpty)
	{
		m_pContext->setLastPoint(calcPoint(v));
	}

	m_pContext->setLastEmptyFlag(isCurrentEmpty);
}

//
ProcessingStateLastEmpty::ProcessingStateLastEmpty(ScreenMatrixImpl* pContext)
{
	m_pContext = pContext;
}

void ProcessingStateLastEmpty::process(const std::vector<int>& v)
{
	bool isCurrentEmpty = isEmpty(v);

	if (isCurrentEmpty && m_pContext->getLastEmptyFlag())
	{
		m_pContext->print();
		m_pContext->changeState(States::PROCESSING);
	}
	m_pContext->setLastEmptyFlag(isCurrentEmpty);
}
