#ifndef SWAP_HH__
#define SWAP_HH__

#include "operation.hh"

class Swap: public Operation {
public:
	Swap(Calculator& calc)
	: Operation("swap", calc)
	{}

	void execute();

};


#endif
