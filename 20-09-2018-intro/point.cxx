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
};

int main(){
	Point p1(10,15);
	Point p2(-1, 20);
	p1.print();
	p2.print();
	return 0;
}
