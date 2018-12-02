#ifndef __CALCULATOR__HPP__
#define __CALCULATOR__HPP__

#include<vector>

class Calculator
{
	std::vector<double> values_;

	void push(double value);
	double pop();
public:
	void run(std::istream& in, std::ostream& out);
};


#endif
