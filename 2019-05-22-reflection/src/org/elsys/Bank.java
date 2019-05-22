package org.elsys.bank;

import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.util.Arrays;

public class Bank {
    public static void main(String[] args) throws NoSuchMethodException, InvocationTargetException, IllegalAccessException {
        Bill b = new Bill(15);
        Class<? extends Bill> bClass = b.getClass();
        System.out.println(bClass.getName());
        System.out.println(bClass.getSuperclass().getName());

        Arrays.stream(bClass.getInterfaces())
                .map(Class::getName)
                .forEach(System.out::println);

        Arrays.stream(bClass.getDeclaredConstructors())
                .forEach(System.out::println);

        Arrays.stream(bClass.getDeclaredFields())
                .map(Field::getModifiers)
                .map(Modifier::toString)
                .forEach(System.out::println);

            Method getValue = bClass.getDeclaredMethod("getValue");
            System.out.println(getValue.invoke(b));

        System.out.println(serializer(b));

    }
    public static String serializer(Object obj) {
        Class<?> objClass = obj.getClass();
        StringBuilder result = new StringBuilder();

        result.append(objClass.getName())
                .append(" /\n");

        Arrays.stream(objClass.getDeclaredFields())
        .peek(field -> field.setAccessible(true))
        .forEach(field -> {
            try {
                result.append(field.getName())
                        .append(" = ")
                        .append(field.get(obj))
                        .append("\n");
            } catch (IllegalAccessException e) {
                e.printStackTrace();
            }
        });


        result.append("/ ")
                .append(objClass.getName());

        return result.toString();
    }
}
