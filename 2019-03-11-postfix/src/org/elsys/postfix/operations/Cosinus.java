package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class Cosinus extends UnaryOperation {

    public Cosinus(Calculator calculator) {
        super(calculator, "cos");
    }

    @Override
    protected double doCalculate(double value) {
        return Math.cos(value);
    }
}
