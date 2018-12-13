#ifndef PLUS__
#define PLUS__

#include "binary.hh"

	class Div: public BinaryOperation {
	public:
		Div(Calculator& calc)
		: BinaryOperation("div", calc)
		{}
	protected:

		double eval(double v1, double v2);
};

#endif
