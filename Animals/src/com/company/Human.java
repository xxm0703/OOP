package com.company;

public class Human extends Mammal {
    private String name;

    public Human(String name){
        super("human",80,9,4);
    }

    public Integer getArms(){
        return 2;
    }
    public String getName(){
        return name;
    }
    public void setName(String name){
        this.name = name;
    }
    @Override
    public String act(){
        return this.getType() + " ,who lives " + this.getYear() + " years, speaks!";
    }
}
