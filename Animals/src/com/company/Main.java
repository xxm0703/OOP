package com.company;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.function.Function;
import java.util.stream.Collectors;



public class Main {
    private static List<Mammal> jivotni = new ArrayList<>();
    private static String duma = null;

    public static void main(String[] args) {
        Mammal gosho = new Mammal("gocew", 39, 9, 4);
        Human gocew = new Human("Gocew");
        System.out.print(gocew.act());
        for (int i = 0; i <= 10; i++) {
            if (i % 2 == 0) {
                Mammal tosho = new Mammal("jivotno", 3, 1, 8);
                jivotni.add(tosho);
            } else {
                Human pesho = new Human("Pesho");
                jivotni.add(pesho);
            }
        }

        Lizard nikiDimi = new Lizard("gej", 2, 1);
        System.out.println(nikiDimi.getLimb());
//        nikiDimi.setLimb(8);
        System.out.println(nikiDimi.getLimb());

        try {
            if (duma.equals("duma")) {
                System.out.println("ne");
            } else {
                System.out.println("da");
            }
        } catch (NullPointerException e) {
            e.printStackTrace();
        }

    }

    public static List<Mammal> map(List<Mammal> mammals, Function<Mammal, Mammal> func) {
        return mammals.stream().map(func).collect(Collectors.toList());
    }

    private static void sort() {
        jivotni.sort(new CompareMammals());
    }

    static class CompareMammals implements Comparator<Mammal> {
        @Override
        public int compare(Mammal o1, Mammal o2) {
            return o1.getLimb().compareTo(o2.getLimb());
        }
    }
}