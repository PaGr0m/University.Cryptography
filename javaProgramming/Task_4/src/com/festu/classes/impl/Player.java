package com.festu.classes.impl;

import com.festu.classes.Technique;

public class Player implements Technique {

    @Override
    public String getFirm() {
        return "Samsung";
    }

    @Override
    public String getPatameters() {
        return "Good";
    }

    @Override
    public Double getCost() {
        return 7.999;
    }

    @Override
    public String toString() {
        return "Player { " +
                getFirm() + ", " +
                getPatameters() + ", " +
                getCost().toString() +
                " } ";
    }
}
