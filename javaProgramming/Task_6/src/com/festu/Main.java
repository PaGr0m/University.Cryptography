package com.festu;

public class Main {

    public static void main(String[] args) {
        testByte();
        testDouble();
        testFloat();
        testInteger();
        testLong();
        testShort();
    }

    public static void testInteger() {
        Integer initial = 10;
        Integer argument = 200;

        MyCosinus<Integer> myCosinus = new MyCosinus<>(initial);

        myCosinus.solve(argument);
    }

    public static void testDouble() {
        Double initial = 10.5;
        Double argument = 200.6;

        MyCosinus<Double> myCosinus = new MyCosinus<>(initial);

        myCosinus.solve(argument);
    }

    public static void testShort() {
        Short initial = 10;
        Short argument = 20;

        MyCosinus<Short> myCosinus = new MyCosinus<>(initial);

        myCosinus.solve(argument);
    }

    public static void testLong() {
        Long initial = 10L;
        Long argument = 200L;

        MyCosinus<Long> myCosinus = new MyCosinus<>(initial);

        myCosinus.solve(argument);
    }

    public static void testByte() {
        Byte initial = 10;
        Byte argument = 100;

        MyCosinus<Byte> myCosinus = new MyCosinus<>(initial);

        myCosinus.solve(argument);
    }

    public static void testFloat() {
        Float initial = 10.6f;
        Float argument = 200.6f;

        MyCosinus<Float> myCosinus = new MyCosinus<>(initial);

        myCosinus.solve(argument);
    }
}
