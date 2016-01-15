#include "stdafx.h"
#include <string>
#include <sstream>
#include "Point.h"
#include <algorithm>
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


//
ParsedMatrix::ParsedMatrix(const std::vector<int> v) 
{
	// szukaj kolejnych punktow w wektorze
	// laduj punkty do wektora points
	auto it = v.begin();
	while (it != v.end())
	{
		auto curr = std::find_if(it, v.end(), [](int a) { return a != 0;  });
		if (curr == v.end())
			break;
		points.push_back(new Point(std::distance(it, v.begin())));
		it = curr;


		it++;
	}
	

}

bool ParsedMatrix::isEmpty() 
{
	return points.empty();
}

std::string ParsedMatrix::toString()
{
	int calc = points.size();

	switch (calc)
	{
	case 0:
		return "";
		break;
	case 1:
		return "D(1,1)";
	default:
		return "W[2(1,1)(1,1)]";
	}

}