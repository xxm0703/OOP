package org.elsys.serializer;

public interface Serializer {

    String serialize(Object object);

    boolean isPretty();

    boolean getIncludedNullFields();

    void setIncludedNullFields();
}
