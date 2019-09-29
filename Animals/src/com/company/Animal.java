package com.company;

public abstract class Animal {
    protected String type;
    protected Integer year;
    protected Integer limb;


    Animal(String type,Integer year,Integer limb){
        this.type = type;
        this.year = year;
        this.limb = limb;
    }
    Animal(String type,Integer year){
        this(type,year,4);
    }
    public String getType(){
        return type;
    }
    public Integer getYear(){
        return year;
    }
    public Integer getLimb(){
        return limb;
    }

//    @Override
//    public int compareTo(Animal other) {
//        // TODO
//    }
}
