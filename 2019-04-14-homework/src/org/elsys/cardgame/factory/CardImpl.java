package org.elsys.cardgame.factory;

import org.elsys.cardgame.api.Card;
import org.elsys.cardgame.api.Rank;
import org.elsys.cardgame.api.Suit;

public class CardImpl implements Card {

    final private Rank rank;
    final private Suit suit;

    public CardImpl(Rank rank, Suit suit) {
        this.rank = rank;
        this.suit = suit;
    }

    @Override
    public Suit getSuit() {
        return suit;
    }

    @Override
    public Rank getRank() {
        return rank;
    }

    @Override
    public String toString() {
        return "" + suit + rank;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        CardImpl card = (CardImpl) o;
        return rank == card.rank &&
                suit == card.suit;
    }

}
