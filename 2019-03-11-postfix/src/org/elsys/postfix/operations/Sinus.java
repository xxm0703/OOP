package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class Sinus extends UnaryOperation {

    public Sinus(Calculator calculator) {
        super(calculator, "sin");
    }

    @Override
    protected double doCalculate(double value) {
        return Math.sin(value);
    }

}
