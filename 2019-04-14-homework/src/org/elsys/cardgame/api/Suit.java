package org.elsys.cardgame.api;

import java.util.HashMap;
import java.util.Map;

public enum Suit {

    CLUBS("C"),
    DIAMONDS("D"),
    HEARTS("H"),
    SPADES("S");

    final private String symbol;
    final static Map<String, Suit> lookup = new HashMap<>();

    static {
        for (Suit s : Suit.values()) {
            lookup.put(s.getSymbol(), s);
        }
    }

    public static Suit get(String value) {
        return lookup.get(value);
    }

    Suit(String symbol) {
        this.symbol = symbol;
    }

    public String getSymbol() {
        return symbol;
    }

    @Override
    public String toString() {
        return getSymbol();
    }
}
