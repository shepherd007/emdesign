#include "stdafx.h"
#include <string>
#include <sstream>
#include "Point.h"

Point::Point(int pos)
{
	m_x = (pos % 10) + 1;
	m_y = (pos / 10) + 1;
}

std::string Point::toString()
{
	std::stringstream ss;
	ss << "D(" << m_x << "," << m_y << ")";

	return ss.str();
}
