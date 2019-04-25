package com.festu;

import com.festu.classes.Hyperbola;
import com.festu.classes.Number;
import com.festu.classes.Real;

public class Main {

    public static void main(String[] args) {
        task_1();
        task_2();
    }

    public static void task_1() {

        Number first = new Number(2.0);
        Number second = new Number(5.0);

        Number resultSub = new Number(first.multiply(second));
        Number resultMul = new Number(first.substract(second));

        System.out.println(resultMul);
        System.out.println(resultSub);
        System.out.println();

        Real real = new Real();
        System.out.println("Sqrt = " + real.sqrt(27, 3));
        System.out.println("PI = " + real.powerPi(3));
    }

    public static void task_2() {
        double argA = 1.0;
        double argB = 1.0;
        double argX = 2.0;

        Hyperbola hyperbola = new Hyperbola();
        hyperbola.solveAndPrint(argA, argB, argX);
    }
}
