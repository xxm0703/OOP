package org.elsys.cardgame.api;

import java.util.Comparator;

public class NoTrumpComparator implements Comparator<Card> {
    @Override
    public int compare(Card o1, Card o2) {
        if (o1.getSuit().ordinal() != o2.getSuit().ordinal())
            return o2.getSuit().ordinal() - o1.getSuit().ordinal();

        if(o1.getRank() != Rank.TEN && o2.getRank() != Rank.TEN)
            return o2.getRank().ordinal() - o1.getRank().ordinal();

        if(o1.getRank() == Rank.ACE || o2.getRank() == Rank.ACE)
            return o2.getRank().ordinal() - o1.getRank().ordinal();

        return o1.getRank() == Rank.TEN ? -1 : 1;
    }
}