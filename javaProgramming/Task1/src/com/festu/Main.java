package com.festu;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class Main {

    public static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        System.out.println("Hello, Java Programming!\n");

//        taskFirst();
//        taskSecond();
//        taskThird();
//        taskFourth();
//        taskFifth();
//        taskSixth();
//        taskSeventh();
//        task8();
//        task9();
//        task10();
        task11();
//        task12();
    }

    public static void showTask(String taskNumber) {
        System.out.println("Hello, I'm " + taskNumber + " task!");
        System.out.print("Enter the number: ");
    }

    // begin
    public static void taskFirst() {

        showTask("FIRST");

        int number = scanner.nextInt();
        int tmp;

        tmp = number*number;
        tmp = tmp*tmp;
        tmp = tmp*tmp;

        System.out.println("Result = " + tmp);
    }

    // if
    public static void taskSecond() {
        showTask("2");

        double argument = scanner.nextDouble();

        if (argument < 0)
            System.out.println("0");
        else if ((int) argument % 2 == 0)
            System.out.println("1");
        else if ((int) argument % 2 == 1)
            System.out.println("-1");
    }

    // for
    public static void taskThird() {

        int N = scanner.nextInt();
        double arg = scanner.nextDouble();

        double sum = 0;
        double value;
        double koef = 1;
        double determinate = 1;

        for (int i = 1; i < N; i++) {
            koef *= 2*i-1;
            determinate *= 2*i;

            value = koef * Math.pow(arg, 2*i+1)/(determinate*(2*i+1));
            sum += value;
        }

        System.out.println("Summa = " + sum);
        System.out.println(Math.asin(arg));
    }

    // while
    public static void taskFourth() {
        showTask("FOURTH");

        int number = scanner.nextInt();
        int fibonachiPrevious = 1;
        int fibonachiNext = 1;
        int fibonachiSum = fibonachiPrevious + fibonachiNext;
        int counter = 1;

        while (fibonachiSum <= number) {
            fibonachiSum = fibonachiPrevious + fibonachiNext;
            fibonachiPrevious = fibonachiNext;
            fibonachiNext = fibonachiSum;
            counter += 1;
        }
        System.out.println("K = " + counter);
    }

    // minmax
    public static void taskFifth() {

        int size = scanner.nextInt();
        int[] array = new int[size];

        for (int i = 0; i < size; i++) {
            array[i] = scanner.nextInt();
        }

        int maxNumber = 0;
        int maxSeq = 1;

        int tmpMaxNumber = 0;
        int tmpMaxSeq = 1;

        int counter = 1;
        while (counter < array.length) {
            tmpMaxNumber = counter-1;
            while (counter < array.length && array[counter-1] == array[counter]) {
                tmpMaxSeq+=1;
                counter+=1;
            }

            if (tmpMaxSeq > maxSeq) {
                maxSeq = tmpMaxSeq;
                maxNumber = tmpMaxNumber;

                tmpMaxSeq = 1;
            }
            counter+=1;
        }

        System.out.println("Sequence = " + maxSeq);
        System.out.println("Index = " + maxNumber);
    }

    // array
    public static void taskSixth() {
        int size = scanner.nextInt();
        int[] array = new int[size];

        for (int i = 0; i < size; i++) {
            array[i] = scanner.nextInt();
        }

        boolean flag = true;
        for (int i = 1; i < array.length; i++) {
            if (Math.signum(array[i-1]) == Math.signum(array[i])) {
                System.out.println("Iteration = " + i);
                flag = false;
                break;
            }
        }

        if (flag)
            System.out.println(0);
    }

    // array 2
    public static void taskSeventh() {
        int size = scanner.nextInt();
        int[] array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = scanner.nextInt();
        }

        for (int i = 0; i < array.length; i++) {
            for (int j = 1; j < array.length; j++) {
                if (i != j && array[i] == array[j]) {
                    System.out.println(i + " - " + j);
                    System.out.println(array[i] + " = " + array[j]);
                    break;
                }
            }
        }
    }

    // array 3
    public static void task8() {

        int size = scanner.nextInt();
        ArrayList<Integer> array = new ArrayList<>();

        for (int i = 0; i < size; i++) {
            array.add(scanner.nextInt());
        }

        int startDelete = scanner.nextInt();
        int stopDelete = scanner.nextInt();

        for (int i = stopDelete-1; i > startDelete-2; i--) {
            array.remove(i);
        }

        System.out.println("Size = " + array.size());
        System.out.println("Array = " + array);

    }

    // matrix
    public static void task9() {

        final int RAND_MAX = 30;
        final int RAND_MIN = 0;

        int row = scanner.nextInt();
        int column = scanner.nextInt();

        int[][] matrix = new int[row][column];

        Random rand = new Random();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                matrix[i][j] = rand.nextInt(RAND_MAX - RAND_MIN + 1) + RAND_MIN;
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }

        int min = RAND_MAX + 1;
        int[] array = new int[row];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++)
                if (min > matrix[i][j])
                    min = matrix[i][j];
            array[i] = min;
            min = RAND_MAX + 1;
        }

        System.out.println();
        for (int i: array)
            System.out.print(i + " ");

        int maxElement = RAND_MIN + 1;
        for (int element: array) {
            if (element > maxElement)
                maxElement = element;
        }

        System.out.println();
        System.out.println("Minimum = " + maxElement);
    }

    // string
    public static void task10() {
        String wordFirst = scanner.next();
        String wordSecond = scanner.next();
        String wordNew = "";

        int numFirst = scanner.nextInt();
        int numSecond = scanner.nextInt();

        wordNew = wordFirst.substring(0, numFirst) +  wordSecond.substring(numSecond, wordSecond.length());

        System.out.println("Word New = " + wordNew);
    }

    // string 2
    public static void task11() {

        System.out.println("Введите строку: ");
        String text = scanner.nextLine();

        int current = 96;
        boolean flag = true;
        for (int i = 0; i < text.length(); i++) {
            if (text.charAt(i) > (char) 96 && text.charAt(i) < (char) 123)
                if (text.charAt(i) > (char) current)
                    current = text.charAt(i);
                else {
                    System.out.println("Error: " + i);
                    flag = false;
                    break;
                }
        }

        if (flag)
            System.out.println("0");
    }

    // TODO: 25.02.19 text
    //Text 26. Дан текстовый файл. Найти количество абзацев в тексте, если первая
    //строка каждого абзаца начинается с 5 пробелов («красная строка»). Пус-
    //тые строки между абзацами не учитывать.

    //Text27. Дано целое число K и текстовый файл. Удалить из файла абзац с номе-
    //ром K (абзацы выделяются с помощью красной строки — см. задание
    //Text26). Пустые строки между абзацами не учитывать и не удалять. Если
    //абзац с данным номером отсутствует, то оставить файл без изменений.
    public static <var> void task12() throws IOException {

        List<String> list = new ArrayList<>();

        try {

            list =Files.readAllLines(Paths.get("resources/input.txt"));

        } catch (IOException e) {

            e.printStackTrace();

        }

        list.forEach(x->System.out.println(x));

        int i=0;

        boolean f=true;

        try(FileWriter wr=new FileWriter(new File("resources/output.txt")))

        {

            for (String x: list)
            {

                if (x.indexOf(" ")==0)

                {

                    i++;

                    f=(i==4)?false:true;

                }

                if (f)

                    wr.write(x+"\n");

            }

        } catch (IOException e) {

            e.printStackTrace();

        }

        System.out.println(i);

    }

}
