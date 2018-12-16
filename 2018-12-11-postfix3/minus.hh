#ifndef SUB__
#define SUB__

#include "binary.hh"

	class Sub: public BinaryOperation {
	public:
		Sub(Calculator& calc)
		: BinaryOperation("sub", calc)
		{}
	protected:

		double eval(double v1, double v2);
};
#endif
