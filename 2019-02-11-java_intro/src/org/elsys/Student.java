package org.elsys;

import org.jetbrains.annotations.Contract;

// import static kotlin.test.AssertionsKt.*;

public class Student {
    private long id;
    private String fName;
    private String lName;

    public Student() {
        this.id = 0;
        this.fName = "";
        this.lName = "";
    }

    public Student(long id, String first, String last) {
        this.id = id;
        this.fName = first;
        this.lName = last;
    }

    @Override
    public String toString() {
        return String.format("Student: %d %s %s", this.id, this.fName, this.lName);
    }

    @Contract(value = "null -> false", pure = true)
    @Override
    public boolean equals(Object obj) {
        if (obj == null)
            return false;
        Student other = (Student) obj;
        return this.id == other.id &&
                this.fName.equals(other.fName) &&
                this.lName.equals(other.lName);
    }

    @Override
    public int hashCode() {
        final int salt = 17;
        return (int) this.id +
                this.fName.hashCode() * salt +
                this.lName.hashCode();
    }
}
