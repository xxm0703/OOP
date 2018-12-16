#include "calculator.hh"
#include <iostream>
#include "unary.hh"
#include "sqrt.hh"
#include "multiply.hh"
#include "plus.hh"
#include "negate.hh"
#include "binary.hh"
#include "drop.hh"
#include "duplicate.hh"
#include "swap.hh"
#include "composite.hh"


int main() {
	Calculator calc;
	calc.add_operation(new Negate(calc));
	calc.add_operation(new Plus(calc));
	calc.add_operation(new Mult(calc));
	calc.add_operation(new Sqrt(calc));
	calc.add_operation(new Dup(calc));
	calc.add_operation(new Swap(calc));
	calc.add_operation(new Drop(calc));

	Composite* hypo = new Composite("hypo", calc);
	hypo->add_operation(new Dup(calc));
	hypo->add_operation(new Mult(calc));
	hypo->add_operation(new Swap(calc));
	hypo->add_operation(new Dup(calc));
	hypo->add_operation(new Mult(calc));
	hypo->add_operation(new Plus(calc));
	hypo->add_operation(new Sqrt(calc));

	calc.add_operation(hypo);

	Composite* squared = new Composite("squr", calc);
	squared->add_operation(new Dup(calc));
	squared->add_operation(new Mult(calc));

	calc.add_operation(squared);

	calc.run(std::cin, std::cout);
	return 0;
}
