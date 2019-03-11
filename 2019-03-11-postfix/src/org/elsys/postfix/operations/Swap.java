package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class Swap extends BinaryOperation {
    public Swap(Calculator calculator) {
        super(calculator, "swap");
    }

    @Override
    protected double doCalculate(double value1, double value2) {
        getCalculator().addValue(value1);

        return value2;
    }
}
