package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class MultiMin extends TrinaryOperation {

    public MultiMin(Calculator calculator) {
        super(calculator, "trin*");
    }

    @Override
    protected double doCalculate(double value1, double value2, double value3) {
        return -1 * value1 * value2 * value3;
    }
}
