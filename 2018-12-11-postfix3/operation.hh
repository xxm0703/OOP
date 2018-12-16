#ifndef OPERATION_HH_
#define OPERATION_HH_

#include <string>

#include "calculator.hh"

class Operation {
	std::string name_;
	Calculator& calc_;
public:
	Operation(const std::string name, Calculator& calc) : name_(name), calc_(calc) {}
	
	std::string get_name() const {
		return name_;
	}

	Calculator& get_calc(){
		return calc_;
	}
	
	virtual void execute() = 0;
};

#endif





