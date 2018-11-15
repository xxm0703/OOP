#include<iostream>
#include<cmath>

using namespace std;

class Point {
	double x_, y_;
public:
	Point(double x, double y) :
	x_(x), y_(y)
	{}

	double get_x() {
		return x_;
	}

	double get_y() {
		return y_;
	}
};

class Shape {
protected:
	virtual double perimeter() const = 0;
};

class Circle : public Shape {
	double radius_;
	Point center_;
public:
	Circle(double radius, Point center) :
	radius_(radius), center_(center)
	{}

	double perimeter() const {
		return 2 * M_PIl * radius_;
	}
};


int main() {
	Point p1(2, 3);
	Circle c1(2.5, p1);
	cout << c1.perimeter() << endl;
	return 0;
}
