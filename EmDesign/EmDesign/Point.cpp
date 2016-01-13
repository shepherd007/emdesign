#include "stdafx.h"
#include <string>
#include <sstream>
#include "Point.h"

Point::Point(int pos)
{
	m_x = (pos % 10) + 1;
	m_y = (pos / 10) + 1;
}

Point::Point(int x, int y) : m_x(x), m_y(y)
{
}
std::string Point::toString()
{
	std::stringstream ss;
	ss << "D(" << m_x << "," << m_y << ")";

	return ss.str();
}



Point Point::average(const Point& pt)
{
	int x = (m_x + pt.m_x) / 2;
	int y = (m_y + pt.m_y) / 2;

	return Point(x, y);
}