package org.elsys.cardgame.factory;

import org.elsys.cardgame.api.Card;
import org.elsys.cardgame.api.Hand;

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

    @Override
    public String toString() {
        StringBuilder handRepresentation = new StringBuilder();
        for (Card card : cards) {
            handRepresentation.append(card).append(" ");
        }

        return handRepresentation.toString();
    }
}
