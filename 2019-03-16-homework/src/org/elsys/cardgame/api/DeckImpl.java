package org.elsys.cardgame.api;

import java.util.ArrayList;
import java.util.List;

public class DeckImpl implements Deck {

    private ArrayList<Card> cards;
    private int deckSize;
    private int handSize;

    public DeckImpl(ArrayList<Card> cards, int handSize) {
        this.cards = cards;
        deckSize = cards.size();
        this.handSize = handSize;
    }

    @Override
    public List<Card> getCards() {
        return null;
    }

    @Override
    public int size() {
        return deckSize;
    }

    @Override
    public int handSize() {
        return handSize;
    }

    @Override
    public Card drawTopCard() {
        Card tmp = cards.get(0);
        cards.remove(0);
        return tmp;
    }

    @Override
    public Card topCard() {
        return cards.get(0);;
    }

    @Override
    public Card drawBottomCard() {
        Card tmp = cards.get(deckSize - 1);
        cards.remove(deckSize - 1);
        return tmp;
    }

    @Override
    public Card bottomCard() {
        return cards.get(deckSize - 1);;
    }

    @Override
    public Hand deal() {
        return null;
    }

    @Override
    public void sort() {

    }

    @Override
    public void shuffle() {

    }
}
