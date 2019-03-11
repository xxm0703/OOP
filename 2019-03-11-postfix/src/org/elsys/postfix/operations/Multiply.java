package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class Multiply extends BinaryOperation {

    public Multiply(Calculator calculator) {
        super(calculator, "*");
    }

    @Override
    protected double doCalculate(double value1, double value2) {
        return value1 * value2;
    }
}