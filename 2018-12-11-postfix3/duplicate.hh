#ifndef DUP_HH__
#define DUP_HH__

#include "operation.hh"

class Dup: public Operation {
public:
	Dup(Calculator& calc)
	: Operation("dup", calc)
	{}

	void execute();
};


#endif
