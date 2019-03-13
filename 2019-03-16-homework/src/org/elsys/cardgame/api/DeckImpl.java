package org.elsys.cardgame.api;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class DeckImpl implements Deck {

    private List<Card> cards;
    private Comparator<Card> comparator;
    private int deckSize;
    private int handSize;

    public DeckImpl(List<Card> cards, int handSize, Comparator<Card> comparator) {
        this.cards = cards;
        deckSize = cards.size();
        this.handSize = handSize;
        this.comparator = comparator;
    }

    @Override
    public List<Card> getCards() {
        return cards;
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
        return popRange(1).get(0);
    }

    @Override
    public Card topCard() {
        return cards.get(0);
    }

    @Override
    public Card drawBottomCard() {
        Collections.reverse(cards);
        Card tmp = drawTopCard();
        Collections.reverse(cards);
        return tmp;
    }

    @Override
    public Card bottomCard() {
        return cards.get(deckSize - 1);
    }

    @Override
    public Hand deal() {
        return new HandImpl(popRange(handSize), handSize);
    }

    @Override
    public void sort() {
        cards.sort(comparator);
    }

    @Override
    public void shuffle() {
        Collections.shuffle(cards);
    }

    private List<Card> popRange(int endIndex) {
        List<Card> tmp = new ArrayList<>(cards.subList(0, endIndex));
        cards.removeAll(tmp);
        deckSize = cards.size();
        return tmp;
    }
//    private List popRange(int startIndex, int endIndex) {
//        List tmp = cards.subList(startIndex, endIndex);
//        cards.removeAll(tmp);
//        deckSize = cards.size();
//        return tmp;
//    }
}
