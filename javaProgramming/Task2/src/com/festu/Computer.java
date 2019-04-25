package com.festu;

public class Computer {

    public int id;
    public Info info;

    @Override
    public String toString() {
        return "Computer: " +
                "id = " + id + "\n" +
                "    info\n" +
                "    {" + "\n" +
                "        OS -> " + info.OS + "\n" +
                "        RAM -> " + info.RAM + "\n" +
                "        CPU -> " + info.CPU + "\n" +
                "    }\n";
    }

    public Computer() {
    }

    public Computer(int id, Info info) {
        this.id = id;
        this.info = info;
    }

    static class Info {

        public String OS;
        public String RAM;
        public String CPU;

        public Info() {
        }

        public Info(String OS, String RAM, String CPU) {
            this.OS = OS;
            this.RAM = RAM;
            this.CPU = CPU;
        }
    }
}
