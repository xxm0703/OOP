package org.elsys.cardgame.api;

import java.util.List;

public class HandImpl implements Hand {

    List<Card> cards;

    HandImpl(List<Card> cards) {
        this.cards = cards;
    }

    @Override
    public List<Card> getCards() {
        return null;
    }

    @Override
    public int size() {
        return 0;
    }
}
