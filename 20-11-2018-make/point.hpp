#ifndef __POINT_HPP__
#define __POINT_HPP__

class Point {
	int x_, y_;
public:
	Point(int x, int y)
	: x_(x), y_(y)
	{}

	int get_y() const;
	int get_x() const;
	void print() const;
};
#endif
