package org.elsys.cardgame.api;

import java.util.HashMap;
import java.util.Map;

public enum Rank {

    TWO("2"),
    THREE("3"),
    FOUR("4"),
    FIVE("5"),
    SIX("6"),
    SEVEN("7"),
    EIGHT("8"),
    NINE("9"),
    TEN("10"),
    JACK("J"),
    QUEEN("Q"),
    KING("K"),
    ACE("A");

    final private String symbol;
    final static Map<String, Rank> lookup = new HashMap<>();

    static {
        for (Rank r : Rank.values()) {
            lookup.put(r.getSymbol(), r);
        }
    }

    public static Rank get(String value) {
        return lookup.get(value);
    }

    Rank(String symbol) {
        this.symbol = symbol;
    }

    public String getSymbol() {
        return symbol;
    }

    @Override
    public String toString() {
        return symbol;
    }
}
