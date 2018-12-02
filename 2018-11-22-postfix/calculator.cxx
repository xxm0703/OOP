#include<iostream>
#include<sstream>
#include"calculator.hpp"

using namespace std;

void Calculator::push(double value)
{
	values_.push_back(value);
}

double Calculator::pop()
{
	double val = value_.back();
	values_.pop_back();
	return val;
}

void Calculator::run(istream& in, ostream& out)
{
	while(!in.eof())
	{
		out << '(' << values_.size() << "): ";
		string token;
		getline(in, token);
		istringstream iss(token);
		double value;
		iss >> value;
		if (!iss.fail() && iss.eof())
		{
			push(value);
		}
	}

}
