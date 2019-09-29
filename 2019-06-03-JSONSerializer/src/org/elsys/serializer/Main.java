package org.elsys.serializer;

import java.util.ArrayList;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        Student st = new Student();
        st.setFirstName("Bruce");
        st.setFatherName("Tomas");
        st.setLastName("Wayne");
        st.setGrades(new ArrayList<>(Arrays.asList(6,5,6,3,4,6)));

        Serializer serializer = new JSONSerializer();
        System.out.println(serializer.serialize(st));
    }
}
