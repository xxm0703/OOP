package org.elsys.cardgame.api;

public class CardImpl implements Card {

    private Rank rank;
    private Suit suit;

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
        return "CardImpl{" +
                "rank=" + rank +
                ", suit=" + suit +
                '}';
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
