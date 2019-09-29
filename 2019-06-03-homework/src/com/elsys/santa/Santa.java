package com.elsys.santa;

import java.util.Random;
import java.util.concurrent.CyclicBarrier;
import java.util.concurrent.Semaphore;

public class Santa extends Thread {

    private final static int REINDEER_THRESHOLD = 9;
    private final static int ELF_THRESHOLD = 3;

    private final CyclicBarrier reindeerBarrier = new CyclicBarrier(9);
    private final CyclicBarrier elfBarrier = new CyclicBarrier(3);
    final Semaphore reindeerSemaphore = new Semaphore(9);
    final Semaphore elfSemaphore = new Semaphore(3);

    private int reindeerCount;
    private int elfCount;
    private Random random;

    public Santa() {
        random = new Random();
        reindeerCount = 0;
        elfCount = 0;
    }

    @Override
    public void run() {
        while (true) {
            synchronized (reindeerSemaphore) {
                synchronized (elfSemaphore) {
                    if (reindeerCount >= REINDEER_THRESHOLD) {
                        System.out.println("Santa is preparing the sleigh");
                        prepareSleigh();
                        System.out.println("Santa is ready with the sleigh");
                        reindeerCount = 0;
                    } else if (elfCount == ELF_THRESHOLD) {
                        System.out.println("Santa is getting ready to help");
                        helpElves();
                        System.out.println("Santa is ready to help");
                        elfCount = 0;
                    }
                }
            }
        }
    }

    public void wake() throws InterruptedException {
        elfSemaphore.acquire();
        synchronized (elfSemaphore) {
            elfCount++;
            elfSemaphore.wait();
        }
        elfSemaphore.release();
    }

    public void hitch() throws InterruptedException {
        synchronized (reindeerSemaphore) {
            reindeerCount++;
            reindeerSemaphore.wait();
        }
    }

    private synchronized void helpElves() {
//        System.out.println("Santa is helping 3 of the elves");
        elfSemaphore.notifyAll();
    }

    private void prepareSleigh() {

        try {
            int pause = random.nextInt(6000) + 3000;
            sleep(pause);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        reindeerSemaphore.notifyAll();
    }

}