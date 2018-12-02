#include<iostream>
#include "point.hpp"

int Point::get_x() const
{
	return x_;
}

int Point::get_y() const
{
	return y_;
}

void Point::print() const
{
	std::cout << "P(" << x_ << ", " << y_ << ")" << std::endl;
}
