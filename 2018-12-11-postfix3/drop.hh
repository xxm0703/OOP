#ifndef STACK_OPERATIONS_HH__
#define STACK_OPERATIONS_HH__

#include "operation.hh"

class Drop: public Operation {
public:
	Drop(Calculator& calc)
	: Operation("drop", calc)
	{}

	void execute();

};

#endif
