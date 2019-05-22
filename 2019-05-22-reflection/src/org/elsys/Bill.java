package org.elsys.bank;

public class Bill implements Comparable<Bill> {

    private int value;

    public Bill(int value) {
        this.value = value;
    }

    public Bill() {
        this.value = 1;
    }

    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = value;
    }

    @Override
    public int compareTo(Bill o) {
        return this.value - o.value;
    }
}
