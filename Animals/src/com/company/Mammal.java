package com.company;

import java.util.Objects;

public class Mammal extends Animal {
    private Integer pregnancy;


//    public boolean equals(Object o){}
//
//    public int hashCode(){}

    public Mammal(String type, Integer year, Integer pregnancy, Integer limb){
        super(type,year,limb);
        this.pregnancy = pregnancy;

    }
    public Mammal(String type,Integer year, Integer pregnancy){
        super(type,year);
        this.pregnancy = pregnancy;
    }
    public Integer getPregnancy(){
        return pregnancy;
    }
    public void setPregnancy(Integer pregnancy){
        this.pregnancy = pregnancy;
    }
    public String act(){
        return this.getType() + " ,who lives " + this.getYear() + " years, acted!";
    }
}
