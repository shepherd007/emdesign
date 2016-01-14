#pragma once

#include <vector>

class ScreenMatrixImpl;
class PointObject;

enum class States
{
	NON_PROCESSING_LE, // send last
	NON_PROCESSING_LNE, // update & send last
	PROCESSING // send ""
};

class State
{
protected:
	ScreenMatrixImpl* m_pContext;
public:
	virtual void process(const std::vector<int>& v) = 0;
};

class ProcessingState : public State
{
public:
	ProcessingState(ScreenMatrixImpl*);
	void process(const std::vector<int>& v);
};

class ProcessingStateLastEmpty : public State
{
public:
	ProcessingStateLastEmpty(ScreenMatrixImpl*);
	void process(const std::vector<int>& v);
};

class ProcessingStateLastNotEmpty : public State
{
public:
	ProcessingStateLastNotEmpty(ScreenMatrixImpl*);
	void process(const std::vector<int>& v);
};
