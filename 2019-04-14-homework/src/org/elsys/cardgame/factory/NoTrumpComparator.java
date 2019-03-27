package org.elsys.cardgame.factory;

import org.elsys.cardgame.api.Card;
import org.elsys.cardgame.api.Rank;

import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

import static org.elsys.cardgame.api.Rank.*;

public class NoTrumpComparator implements Comparator<Card> {
    private final List<Rank> order = Arrays.asList(SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE);

    @Override
    public int compare(Card o1, Card o2) {
        if (o1.getSuit().ordinal() != o2.getSuit().ordinal())
            return o1.getSuit().ordinal() - o2.getSuit().ordinal();

        return order.indexOf(o1.getRank()) - order.indexOf(o2.getRank());
    }
}