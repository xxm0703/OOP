package org.elsys.cardgame.api;

public class CardImpl implements Card, Comparable {

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
    public int compareTo(Object o) {
        Card other = (Card) o;
        if(rank == other.getRank())
            
        return 0;
    }
}
