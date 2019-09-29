package org.elsys.serializer;

import java.lang.reflect.Field;
import java.util.*;

public abstract class AbstractSerializer implements Serializer {
    protected List<Field> getFields(Class aClass) {
        List<Field> fieldList = new ArrayList<>();

        while (aClass != Object.class) {
            fieldList.addAll(Arrays.asList(aClass.getDeclaredFields()));
            aClass = aClass.getSuperclass();
        }

        return fieldList;
    }

    protected boolean isDirectlySerializable(Object o) {
        return o instanceof String
                || o instanceof Number
                || o instanceof Character
                || o instanceof Boolean;
    }

    protected boolean isCollection(Object o) {
        return o instanceof Collection;
    }
}
