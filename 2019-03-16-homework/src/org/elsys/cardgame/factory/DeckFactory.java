package org.elsys.cardgame.factory;

import org.elsys.cardgame.api.*;

import java.util.ArrayList;

public class DeckFactory {

//    public static void main(String[] args);

	public static Deck defaultWarDeck() {
		ArrayList<Card> cards = generateCards(Rank.TWO);

		return new DeckImpl(cards, 26, new WarComparator());
	}

	public static Deck defaultSantaseDeck() {
        ArrayList<Card> cards = generateCards(Rank.NINE);

        return new DeckImpl(cards, 6, new NoTrumpComparator());

	}

	public static Deck defaultBeloteDeck() {
        ArrayList<Card> cards = generateCards(Rank.SEVEN);

        return new DeckImpl(cards, 8, new NoTrumpComparator());
	}

	private static ArrayList<Card> generateCards(Rank startRank) {
        ArrayList<Card> cards = new ArrayList<>();

        for(Suit s: Suit.values()) {
            for (Rank r : Rank.values()) {
                if (r.ordinal() >= startRank.ordinal()) {
                    cards.add(new CardImpl(r, s));
                }
            }
        }

        return cards;
    }
}
