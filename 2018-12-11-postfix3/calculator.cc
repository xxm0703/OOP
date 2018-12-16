#include "calculator.hh"
#include "operation.hh"
#include "composite.hh"
#include <string>
#include <iostream>
#include <sstream>
#include <exception>
#include <list>

using namespace std;

void Calculator::push(double value) {
	values_.push_back(value);
}

double Calculator::pop() {
	double result = values_.back();
	values_.pop_back();
	return result;
}

void Calculator::add_operation(Operation* op) {
	operations_.push_back(op);
}

Operation* Calculator::get_operation(const string& name) const {
	for (list<Operation*>::const_iterator it = operations_.begin(); it != operations_.end(); it++) {
		if ((*it) -> get_name() == name) {
			return *it;
		}
	}
	throw exception();
}

void Calculator::run(istream& in, ostream& out) {
	size_t cursor;
	bool macros_mode = false;
	Composite *macro;

	while (!in.eof()) {
		out << "(" << values_.size() << "): ";
		string token;
		getline(in, token);
		istringstream iss(token);
		double value;
		iss >> value;
		if (!macros_mode && !iss.fail() && iss.eof()) {
			push(value);
		}
		else if (!macros_mode  && (cursor = token.find("\\\\")) != string::npos)
		{
			macros_mode = true;
			macro = new Composite(token.substr(cursor + 2), *this);
		}
		else if (macros_mode)
		{
			if (token == "def")
			{
				add_operation(macro);
				macros_mode = false;
				continue;
			}

			Operation* op = get_operation(token);
			macro->add_operation(op);
		}
		else
		{
			Operation* op = get_operation(token);
			op -> execute();
			double result = values_.back();
			out << result << endl;
		}

	}
}
