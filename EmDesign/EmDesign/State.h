#include "stdafx.h"

enum class States
{
	NON_PROCESSING_LE, // send last
	NON_PROCESSING_LNE, // update & send last 
	PROCESSING // send ""
};

enum class Events
{
	NO_CHANGE,
	EMPTY_TO_FULL,
	FULL_TO_EMPTY,
	EMPTY_TO_EMPTY
};


