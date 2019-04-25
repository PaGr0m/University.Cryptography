package com.festu.classes;

import static java.lang.Math.pow;
import static java.lang.Math.sqrt;

public class Hyperbola extends Function {

    public double getResult(double a, double b, double x) {
        return sqrt(((pow(x, 2) * pow(b, 2)) - (pow(a, 2) * pow(b, 2)))/(pow(a, 2)));
    }

    public void solveAndPrint(double a, double b, double x) {
        result = sqrt(((pow(x, 2) * pow(b, 2)) - (pow(a, 2) * pow(b, 2)))/(pow(a, 2)));
        System.out.println("Result = " + result);
    }
}
