package com.elsys.santa;

import java.util.Random;

public class Reindeer extends Thread {

    private Santa santa;
    private Random random;
    public boolean waiting;

    public Reindeer(Santa santa) {
        this.santa = santa;
        random = new Random();
        waiting = false;
    }

    @Override
    public void run() {
        try {
            int pause = random.nextInt(2500) + 5000;
            sleep(pause);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Reindeer got home");

        try {
            santa.hitch();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        getHitched();

    }

    public void getHitched() {
        try {
            int pause = random.nextInt(3000) + 3000;
            sleep(pause);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Reindeer ready to set off");
    }

}