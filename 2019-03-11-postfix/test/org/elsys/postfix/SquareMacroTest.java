package org.elsys.postfix;

import org.junit.jupiter.api.Test;

public class SquareMacroTest extends CalculatorAbstractTest {

	@Test
	public void test() {
		runCalculator();

		input("\\square");
		input("dup");
		input("*");
		input("def");

		input("2");
		input("square");
		inputCtrlC();
		
		assertCalculatorLastValue(4.0);
	}

}
