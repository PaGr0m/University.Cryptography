package com.festu.classes;

public abstract class Function {

    protected double result;

    public double getResult(double a, double b, double x) {
        return Double.NaN;
    }

    public void solve(double a, double b, double x) {
        result = 0;
    }
}
