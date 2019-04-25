package com.festu.classes;

public class Number {

    private double value;

    public Number() {
    }

    public Number(double value) {
        this.value = value;
    }

    public double plus(Number number) {
        return (this.value + number.value);
    }

    public double multiply(Number number) {
        return (this.value * number.value);
    }

    public double substract(Number number) {
        return (this.value - number.value);
    }

    @Override
    public String toString() {
        return "Number {" +
                " value = " + value +
                " }";
    }
}
