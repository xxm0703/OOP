#include <iostream>
#include "point.hpp"
#include "shape.hpp"

class Rectangle : public Shape
{
	Point ul_, br_;
public:
	Rectangle(Point ul, Point br)
	: ul_(ul), br_(br)
	{}

	void print() const
	{
		std::cout << "Rectangle: ";
		ul_.print();
		br_.print();
	}
};
