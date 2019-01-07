#include <iostream>
using namespace std;
#include "turtle.hh"

class Sierpinski {
	Turtle& turtle_;
	double step_;
	short depth_;
public:

	Sierpinski(Turtle& turtle)
	: turtle_(turtle), step_(0)
	{}

	void draw_base(int order);
	void draw_a(int order, int rotates);
	void draw_b(int order, int rotates);
	void draw_c(int order, int rotates);
	void draw_d(int order, int rotates);


};

void Sierpinski::draw_base(int depth)
{
	depth_ = depth;

	turtle_.set_heading(0).forward(step_);
	turtle_.set_heading(45).forward(step_);
	draw_b(1, 0);
	turtle_.set_heading(-135).forward(step_);
	turtle_.set_heading(-90).forward(step_);
	turtle_.set_heading(-45).forward(step_);
	draw_c(1, 0);
	turtle_.set_heading(135).forward(step_);
	turtle_.set_heading(180).forward(step_);
	turtle_.set_heading(-135).forward(step_);
	draw_d(1, 0);
	turtle_.set_heading(45).forward(step_);
	turtle_.set_heading(90).forward(step_);
	turtle_.set_heading(135).forward(step_);
	draw_a(1, 0);
	turtle_.set_heading(-45).forward(step_);
}

void Sierpinski::draw_a(int order, int rotates) {
	if(order >= depth_ || rotates == 2) {
		turtle_.set_heading(45);
		turtle_.forward(step_);
		return;
	}

		turtle_.set_heading(180).forward(step_);
		turtle_.set_heading(-135).forward(step_);
		draw_d(depth_-order+1, rotates+1);
		turtle_.set_heading(45).forward(step_);
		turtle_.set_heading(90).forward(step_);
		turtle_.set_heading(135).forward(step_);
		draw_a(order + 1, rotates);
		turtle_.set_heading(-45).forward(step_);
		turtle_.set_heading(0).forward(step_);
		turtle_.set_heading(45).forward(step_);
		draw_b(depth_-order+1, rotates+1);
		turtle_.set_heading(-135).forward(step_);
		turtle_.set_heading(-90).forward(step_);
}

void Sierpinski::draw_b(int order, int rotates) {

	if(order >= depth_ || rotates == 2) {
		turtle_.set_heading(-45);
		turtle_.forward(step_);
		return;
	}

	turtle_.set_heading(90).forward(step_);
	turtle_.set_heading(135).forward(step_);
	draw_a(depth_-order+1, rotates+1);
	turtle_.set_heading(-45).forward(step_);
	turtle_.set_heading(0).forward(step_);
	turtle_.set_heading(45).forward(step_);
	draw_b(order + 1, rotates);
	turtle_.set_heading(-135).forward(step_);
	turtle_.set_heading(-90).forward(step_);
	turtle_.set_heading(-45).forward(step_);
	draw_c(depth_-order+1, rotates+1);
	turtle_.set_heading(135).forward(step_);
	turtle_.set_heading(180).forward(step_);
}

void Sierpinski::draw_c(int order, int rotates) {

	if(order >= depth_ || rotates == 2) {
		turtle_.set_heading(-135);
		turtle_.forward(step_);
		return;
	}

	turtle_.set_heading(0).forward(step_);
	turtle_.set_heading(45).forward(step_);
	draw_b(depth_-order+1, rotates+1);
	turtle_.set_heading(-135).forward(step_);
	turtle_.set_heading(-90).forward(step_);
	turtle_.set_heading(-45).forward(step_);
	draw_c(order + 1, rotates);
	turtle_.set_heading(135).forward(step_);
	turtle_.set_heading(180).forward(step_);
	turtle_.set_heading(-135).forward(step_);
	draw_d(depth_-order+1, rotates+1);
	turtle_.set_heading(45).forward(step_);
	turtle_.set_heading(90).forward(step_);
}
void Sierpinski::draw_d(int order, int rotates) {

	if(order >= depth_ || rotates == 2) {
		turtle_.set_heading(135);
		turtle_.forward(step_);
		return;
	}

	turtle_.set_heading(-90).forward(step_);
	turtle_.set_heading(-45).forward(step_);
	draw_c(depth_-order+1, rotates+1);
	turtle_.set_heading(135).forward(step_);
	turtle_.set_heading(180).forward(step_);
	turtle_.set_heading(-135).forward(step_);
	draw_d(order + 1, rotates);
	turtle_.set_heading(45).forward(step_);
	turtle_.set_heading(90).forward(step_);
	turtle_.set_heading(135).forward(step_);
	draw_a(depth_-order+1, rotates+1);
	turtle_.set_heading(-45).forward(step_);
	turtle_.set_heading(0).forward(step_);
}


int main() {
	PSTurtle t = PSTurtle(300, 300);
	t.setup().moveto(Point(150,150));
	t.pendown();

	Sierpinski h(t);
	h.draw_base(3);

	return 0;
}
