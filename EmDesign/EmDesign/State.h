#pragma once

#include "stdafx.h"

enum class States
{
	NON_PROCESSING_LE, // send last
	NON_PROCESSING_LNE, // update & send last 
	PROCESSING // send ""
};

