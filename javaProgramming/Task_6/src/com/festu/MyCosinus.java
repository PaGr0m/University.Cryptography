package com.festu;

import static java.lang.Math.cos;
import static java.lang.Math.exp;

public class MyCosinus<T extends Number> {

    T value;

    public MyCosinus() {
    }

    public MyCosinus(T value) {
        this.value = value;
    }

    public void solve(T k) {

        System.out.println(value.getClass());

        if (k.getClass() == Integer.class) {
            System.out.println(exp(value.intValue() - k.intValue()));
        } else if (k.getClass() == Double.class) {
            System.out.println(exp(value.doubleValue() - k.doubleValue()));
        } else if (k.getClass() == Byte.class) {
            System.out.println(exp(value.byteValue() - k.byteValue()));
        } else if (k.getClass() == Float.class) {
            System.out.println(exp(value.floatValue() - k.floatValue()));
        } else if (k.getClass() == Long.class) {
            System.out.println(exp(value.longValue() - k.longValue()));
        } else if (k.getClass() == Short.class) {
            System.out.println(exp(value.shortValue() - k.shortValue()));
        }
        System.out.println();
    }
}
