#pragma once

#include <vector>

class Point;

Point average(Point& pt1, Point& pt2);

class PointObject
{
public:
	virtual std::string toString() = 0;
};

class Point : public PointObject
{
private:
	int m_x;
	int m_y;
public:
	Point(int p);
	Point(const Point&);
	Point(int x, int y);
	int getX() const;
	int getY() const;
	std::string toString();
};

class NullPoint : public PointObject
{
public:
	std::string toString();
};

class ParsedMatrix {
public:
	ParsedMatrix(const std::vector<int>);
	bool	isEmpty();
	std::string toString();
private:
	std::vector<Point> points;
};
