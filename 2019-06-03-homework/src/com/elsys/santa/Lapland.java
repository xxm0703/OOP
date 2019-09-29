package com.elsys.santa;

public class Lapland {
    public static void main(String[] args){

        Santa santa = new Santa();
        santa.start();

        for(int i = 1; i <= 8; i++){
            Elf elf = new Elf(santa);
            elf.start();
        }

        for(int i = 1; i <= 9; i++){
            Reindeer reindeer = new Reindeer(santa);
            reindeer.start();
        }

    }
}