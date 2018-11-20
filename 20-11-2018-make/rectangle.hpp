#include "point.hpp"

class Rectangle {
	Point ul_, br_;
public:
	Rectangle(Point ul, Point br)
	: ul_(ul), br_(br)
	{}

	void print()
	{
		ul_.print();
		br_.print();
	}
};
