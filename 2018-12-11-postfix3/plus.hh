#ifndef PLUS__
#define PLUS__

#include "binary.hh"

	class Plus: public BinaryOperation {
	public:
		Plus(Calculator& calc)
		: BinaryOperation("plus", calc)
		{}
	protected:

		double eval(double v1, double v2);
};

#endif
