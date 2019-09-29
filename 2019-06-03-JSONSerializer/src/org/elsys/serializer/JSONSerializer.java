package org.elsys.serializer;

import java.lang.reflect.Field;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.List;

public class JSONSerializer extends AbstractSerializer {
    @Override
    public String serialize(Object object) {
        List<Field> fields = getFields(object.getClass());
        List<String> outputs = new ArrayList<>();

        for (Field field : fields) {
            String fieldName = field.getName();
            StringBuilder builder = new StringBuilder();

            builder.append('"');
            builder.append(fieldName);
            builder.append('"');
            builder.append(" : ");

            field.setAccessible(true);

            try {
                Object o = field.get(object);
                if (isDirectlySerializable(o)) {
                    builder.append('"');
                    builder.append(o.toString());
                    builder.append('"');
                } else if (isCollection(o)) {
                    String result = serializeCollection((Collection) o);
                    builder.append(result);
                } else {
                    builder.append(serialize(o));
                }
            } catch (IllegalAccessException e) {
                e.printStackTrace();
            }


            outputs.add(builder.toString());
        }

        StringBuilder builder = new StringBuilder();
        builder.append('{');
        builder.append(String.join(", ", outputs));
        builder.append('}');

        return builder.toString();
    }

    @Override
    public boolean isPretty() {
        return false;
    }

    @Override
    public boolean getIncludedNullFields() {
        return false;
    }

    @Override
    public void setIncludedNullFields() {

    }

    private String serializeCollection(Collection collection) {
        List<String> outputs = new ArrayList<>();
        for (Object o : collection) {
            outputs.add('"' + o.toString() + '"');
        }

        String sb = "[" +
                String.join(", ", outputs) +
                ']';
        return sb;
    }
}
