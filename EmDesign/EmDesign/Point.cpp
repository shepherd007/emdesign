#include "stdafx.h"
#include <string>
#include <sstream>
#include "Point.h"

//
Point average(Point& pt1, Point& pt2)
{
	int x = (pt1.getX() + pt2.getX()) / 2;
	int y = (pt1.getY() + pt2.getY()) / 2;

	return Point(x, y);
}

//
Point::Point(const Point& pt)
{
	m_x = pt.getX();
	m_y = pt.getY();
}

Point::Point(int pos)
{
	m_x = (pos % 10) + 1;
	m_y = (pos / 10) + 1;
}

Point::Point(int x, int y) : m_x(x), m_y(y)
{
}

int Point::getX() const
{
	return m_x;
}

int Point::getY() const
{
	return m_y;
}

std::string Point::toString()
{
	std::stringstream ss;
	ss << "D(" << m_x << "," << m_y << ")";

	return ss.str();
}

//
std::string NullPoint::toString()
{
	std::stringstream ss;
	ss << "";

	return ss.str();
}
