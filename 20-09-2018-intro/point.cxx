#include<iostream>

using namespace std;
class Point {
	int x_, y_;

public:

	Point(int x, int y) {
		x_ = x;
		y_ = y;
	}

	void print() {
		cout << '(' << x_ << ", " << y_ << ')' << endl;
	}

	int get_x() {
		return x_;
	}

	void set_x(int x) {
		x_ = x;
	}

	int get_y() {
		return y_;
	}

	void set_y(int y) {
		y_ = y;
	}
};

int main(){
	Point p1(10,15);
	Point p2(-1, 20);
	p1.print();
	p2.print();
	cout << "Value of x_ is: " << p1.get_x() << endl;
	return 0;
}
