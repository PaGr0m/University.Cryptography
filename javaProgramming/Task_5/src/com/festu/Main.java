package com.festu;

import java.util.InputMismatchException;
import java.util.Scanner;

import static java.lang.Math.pow;
import static java.lang.Math.scalb;
import static java.lang.Math.sqrt;

public class Main {

    public static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws CathetusException, InfinityException, NanException {

        task_1(2.0);
//        task_2();
    }

    private static void task_1(double a) throws InfinityException, NanException {

        double z1;
        double z2;

//        if(a == 2)
//            throw new InfinityException("Infinity");

        try {
            double first = (1+a+pow(a, 2)) / (2*a + pow(a, 2));
            double second = (1-a+pow(a, 2)) / (2*a - pow(a, 2));
            double third = 5 - 2*pow(a, 2);

            System.out.println("1 = " + first);
            System.out.println("2 = " + second);
            System.out.println("3 = " + third);

            if (Double.isInfinite(first) ||
                    Double.isInfinite(second) ||
                    Double.isInfinite(third))
                throw new InfinityException("Infinity value");



            z1 = pow(first + 2 - second, -1) * third;
            z2 = (4-pow(a, 2))/2;

            if (Double.isNaN(z1) || Double.isInfinite(z1))
                throw new NanException("Nan value");

            System.out.println("Z1 = " + z1);
            System.out.println("Z2 = " + z2);
        }
        catch (ArithmeticException e) {
            e.getMessage();
            System.out.println("Arithmetic Error !");
        }
        catch (InputMismatchException e) {
            e.getMessage();
            System.out.println("Input value Error !");
        }
    }

    private static void task_2() throws CathetusException {

        double hypotenuse = Double.NaN;

        System.out.println("First cathetus ---> ");
        double cathetusA = scanner.nextDouble();

        System.out.println("Second cathetus ---> ");
        double cathetusB = scanner.nextDouble();

        if (cathetusA <= 0 || cathetusB <= 0)
            throw new CathetusException("Not correct value");


        hypotenuse = sqrt(pow(cathetusA, 2) + pow(cathetusB, 2));
        double alpha = Math.asin(cathetusA/hypotenuse);
        double beta = Math.asin(cathetusB/hypotenuse);

        System.out.println("Alpha = " + alpha);
        System.out.println("Beta = " + beta);
    }

    static class CathetusException extends Exception {
        public CathetusException(String message) {
            super(message);
        }
    }

    static class InfinityException extends Exception {
        public InfinityException(String message) {
            super(message);
        }
    }

    static class NanException extends Exception {
        public NanException(String message) {
            super(message);
        }
    }
}
