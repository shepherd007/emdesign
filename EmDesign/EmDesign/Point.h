#pragma once

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
	Point(Point&);
	Point(int x, int y);
	int getX();
	int getY();
	std::string toString();
};

class NullPoint : public PointObject
{
public:
	std::string toString();
};
