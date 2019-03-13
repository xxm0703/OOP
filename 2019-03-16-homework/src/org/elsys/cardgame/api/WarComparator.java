package org.elsys.cardgame.api;

import java.util.Comparator;

public class WarComparator implements Comparator<Card> {
    @Override
    public int compare(Card o1, Card o2) {
        if (o1.getSuit().ordinal() != o2.getSuit().ordinal())
            return o1.getSuit().ordinal() - o2.getSuit().ordinal();
        return o1.getRank().ordinal() - o2.getRank().ordinal();
    }
}