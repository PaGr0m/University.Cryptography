package com.festu;

import java.util.*;
import java.util.concurrent.TimeUnit;


public class Main {

    public static void main(String[] args) throws InterruptedException {
        System.out.println("ArrayList: ");
	    task_ArrayList();

        System.out.println("\nLinkedList: ");
	    task_LinkedList();

        System.out.println("\nDeque: ");
        task_Deque();

        System.out.println("\nSet: ");
        task_Set();
    }

    public static void task_ArrayList() {
        Integer max = Integer.MIN_VALUE;
        Integer min = Integer.MAX_VALUE;

        List<Integer> list = new ArrayList<>();

        list.add(1);
        list.add(2);
        list.add(3);
        list.add(4);
        list.add(5);

        System.out.println(list);

        for (Integer element: list) {
            if (element > max) max = element;
            if (element < min) min = element;
        }

        Integer avg = (max+min)/2;
        for (int i = 0; i < list.size(); i++) {
            list.set(i, list.get(i) + avg);
        }

        System.out.println(list);
    }

    public static void task_LinkedList() {
        Integer max = Integer.MIN_VALUE;
        Integer min = Integer.MAX_VALUE;

        LinkedList<Integer> list = new LinkedList<>();

        list.addLast(10);
        list.addLast(20);
        list.addLast(30);
        list.addLast(40);
        list.addLast(50);

        System.out.println(list);

        for (Integer element: list) {
            if (element > max) max = element;
            if (element < min) min = element;
        }

        Integer avg = (max+min)/2;
        for (int i = 0; i < list.size(); i++) {
            list.set(i, list.get(i) + avg);
        }

        System.out.println(list);
    }

    public static void task_Deque() {
        Integer max = Integer.MIN_VALUE;
        Integer min = Integer.MAX_VALUE;

        Deque<Integer> list = new LinkedList<>();

        list.offer(100);
        list.offer(200);
        list.offer(300);
        list.offer(400);
        list.offer(500);

        System.out.println(list);

        for (Integer element: list) {
            if (element > max) max = element;
            if (element < min) min = element;
        }

        Integer tmp;
        Integer avg = (max+min)/2;

        for (int i = 0; i < list.size(); i++) {
            tmp = list.getFirst();
            list.pop();
            list.offer(tmp+avg);
        }

        System.out.println(list);
    }

    public static void task_Set() throws InterruptedException {
        Set<String> toySet = new HashSet<>(Arrays.asList("a", "b", "c", "d", "e", "f"));

        ArrayList<Set<String>> kindergaten = new ArrayList<Set<String>>();
        kindergaten.add(new HashSet<>(Arrays.asList("a", "b")));
        kindergaten.add(new HashSet<>(Arrays.asList("a", "c")));
        kindergaten.add(new HashSet<>(Arrays.asList("a", "e")));

        ArrayList<String> toyMissing = new ArrayList<>();

        Map<String, Integer> map = new HashMap<>();
        map.put("a", 0);
        map.put("b", 0);
        map.put("c", 0);
        map.put("d", 0);
        map.put("e", 0);
        map.put("f", 0);

        Thread thread = new Thread(new Runnable() {
            @Override
            public void run() {
                for (Set<String> kinder : kindergaten) {
                    Iterator<String> it = toySet.iterator();
                    while (it.hasNext()) {
                        String tmp = it.next();
                        if (!kinder.contains(tmp)) {
                            toyMissing.add(tmp);
                        }
                    }
                }

                System.out.println("Missing: " + toyMissing + "\n");

                for (String element: toyMissing) map.put(element, map.get(element) + 1);
            }
        });

        thread.start();
        TimeUnit.SECONDS.sleep(1);

        for (String elem: map.keySet()) {
            if (map.get(elem) == 0) System.out.println(elem + " - есть везде!");
            else if (map.get(elem) == kindergaten.size()) System.out.println(elem + " - нет нигде!");
            else System.out.println(elem + " - есть хотя бы в одном");
        }

        System.out.println("\nMap -> " + map);
    }
}
