#ifndef BINARY_HH__
#define BINARY_HH__

#include "operation.hh"

class BinaryOperation : public Operation{

public:
	BinaryOperation(const std::string& name, Calculator& calc)
		: Operation(name, calc) {}

	void execute();

protected:
	virtual double eval(double v1, double v2) = 0;

};

class Plus;
class Mult;

#endif
