#ifndef MULT__
#define MULT__

#include "binary.hh"

	class Mult: public BinaryOperation {
	public:
		Mult(Calculator& calc)
		: BinaryOperation("mult", calc)
		{}
	protected:

		double eval(double v1, double v2);
};

#endif
