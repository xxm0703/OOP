package org.elsys.serializer;

import java.util.List;

public class Student {
    private String firstName, fatherName, lastName;
    private List<Integer> grades;
    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public void setFatherName(String fatherName) {
        this.fatherName = fatherName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public void setGrades(List<Integer> grades) {
        this.grades = grades;
    }

    public Student() {
    }
}
