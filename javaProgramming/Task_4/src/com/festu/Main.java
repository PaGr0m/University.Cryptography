package com.festu;

import com.festu.classes.impl.Player;
import com.festu.classes.impl.Videoplayer;

public class Main {

    public static void main(String[] args) {
        Player player = new Player();
        Videoplayer videoplayer = new Videoplayer();

        System.out.println(player);
        System.out.println(videoplayer);
    }
}
