package com.festu.classes.impl;

import com.festu.classes.Technique;

public class Videoplayer implements Technique {

    @Override
    public String getFirm() {
        return "LG";
    }

    @Override
    public String getPatameters() {
        return "Bad";
    }

    @Override
    public Double getCost() {
        return 10.999;
    }

    @Override
    public String toString() {
        return "Videoplayer { " +
                getFirm() + ", " +
                getPatameters() + ", " +
                getCost().toString() +
                " } ";
    }
}
