package com.festu.classes;

public class Real {

    private double value;
    private final double PI = 3.14;

    public double sqrt(int value, int power) {
        return Math.pow(value, 1.0/power);
    }

    public double powerPi(int power) {
        return Math.pow(PI, power);
    }
}
