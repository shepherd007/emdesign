#pragma once

class Point
{
private:
	int m_x;
	int m_y;
public:
	Point(int p);
	Point(int x, int y);
	std::string toString();

	Point average(const Point&);
};

