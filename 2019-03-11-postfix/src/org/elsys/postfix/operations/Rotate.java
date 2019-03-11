package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class Rotate extends TrinaryOperation {
    public Rotate(Calculator calculator) {
        super(calculator, "rot3");
    }

    @Override
    protected double doCalculate(double value1, double value2, double value3) {
        getCalculator().addValue(value1);
        getCalculator().addValue(value3);
        return value2;
    }
}
