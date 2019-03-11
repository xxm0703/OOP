package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

import java.util.EmptyStackException;

public abstract class TrinaryOperation extends AbstractOperation {
    public TrinaryOperation(Calculator calculator, String token) {
        super(calculator, token);
    }

    @Override
    public void calculate() {
        Calculator calculator = getCalculator();

        if (calculator.stackSize() < 3)
            throw new EmptyStackException();
        double value1 = calculator.popValue();
        double value2 = calculator.popValue();
        double value3 = calculator.popValue();
        double result = doCalculate(value1, value2, value3);
        calculator.addValue(result);
    }

    protected abstract double doCalculate(double value1, double value2, double value3);
}
