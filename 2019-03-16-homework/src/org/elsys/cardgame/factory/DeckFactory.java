package org.elsys.cardgame.factory;

import org.elsys.cardgame.api.*;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class DeckFactory {

	public static Deck defaultWarDeck() {
		ArrayList<Card> cards = new ArrayList<>();
		for(Suit s: Suit.values()) {
			for (Rank r : Rank.values()) {
				cards.add(new CardImpl(r, s));
			}
		}

		class warComparator implements Comparator<Card> {
			@Override
			public int compare(Card o1, Card o2) {
				if (o1.getSuit().ordinal() != o2.getSuit().ordinal())
					return o2.getSuit().ordinal() - o1.getSuit().ordinal();
				return o2.getRank().ordinal() - o1.getRank().ordinal();
			}
		}

		return new DeckImpl(cards, 26, new warComparator());
	}

	public static Deck defaultSantaseDeck() {
		// TODO
		return null;
	}

	public static Deck defaultBeloteDeck() {
		// TODO
		return null;
	}
}
