package org.elsys.cardgame.api;

import java.util.List;

public class HandImpl implements Hand {

    private List<Card> cards;
    private int size;

    HandImpl(List<Card> cards, int size) {
        this.cards = cards;
        this.size = size;
    }

    @Override
    public List<Card> getCards() {
        return cards;
    }

    @Override
    public int size() {
        return size;
    }
}
