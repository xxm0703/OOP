#ifndef SQRT__
#define SQRT__

#include "unary.hh"

	class Sqrt: public UnaryOperation {
	public:
		Sqrt(Calculator& calc)
		: UnaryOperation("sqrt", calc)
		{}
	protected:

		double eval(double val);
};
#endif
