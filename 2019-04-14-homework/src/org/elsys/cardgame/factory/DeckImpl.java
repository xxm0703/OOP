package org.elsys.cardgame.factory;

import org.elsys.cardgame.api.Card;
import org.elsys.cardgame.api.CardException;
import org.elsys.cardgame.api.Deck;
import org.elsys.cardgame.api.Hand;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class DeckImpl implements Deck {

    private List<Card> cards;
    final private Comparator<Card> comparator;
    private int deckSize;
    final private int handSize;

    DeckImpl(List<Card> cards, int handSize, Comparator<Card> comparator) {
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

    @Override
    public String toString() {
        StringBuilder deckRepresentation = new StringBuilder();
        for (Card card : cards) {
            deckRepresentation.append(card).append(" ");
        }

        return deckRepresentation.toString();
    }

    private List<Card> popRange(int endIndex) {
        if (cards.size() < endIndex) {
            throw new CardException("ERROR: Not enough cards in deck");
        }

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
