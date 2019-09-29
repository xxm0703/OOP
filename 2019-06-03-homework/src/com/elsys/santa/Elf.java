package com.elsys.santa;

import java.util.Random;

public class Elf extends Thread {
    private Santa santa;
    private Random rnd;

    public boolean waiting;

    public Elf(Santa santa) {
        this.santa = santa;
        rnd = new Random();
        waiting = false;
    }

    @Override
    public void run() {
        while (true) {
            try {
                int pause = rnd.nextInt(6000) + 1000; // 1 - 21 s
                sleep(pause);

                System.out.println("Elf is needing help");

                santa.wake();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            getHelp();
        }
    }

    public void getHelp() {
        System.out.println("An elf is getting help");
    }
}
