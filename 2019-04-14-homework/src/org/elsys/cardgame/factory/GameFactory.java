package org.elsys.cardgame.factory;

import org.elsys.cardgame.api.Card;
import org.elsys.cardgame.api.CardException;
import org.elsys.cardgame.api.Deck;
import org.elsys.cardgame.api.Game;
import org.elsys.cardgame.factory.operations.*;

import java.util.Comparator;
import java.util.List;

public class GameFactory {

    public static Game createWarGame(List<Card> cards) {
        WarComparator comparator = new WarComparator();
        Deck warDeck = DeckFactory.defaultWarDeck();

        return composeGameObj(cards, warDeck, comparator);
    }

    public static Game createSantaseGame(List<Card> cards) {
        NoTrumpComparator comparator = new NoTrumpComparator();
        Deck santaseDeck = DeckFactory.defaultSantaseDeck();

        return composeGameObj(cards, santaseDeck, comparator);
    }

    public static Game createBeloteGame(List<Card> cards) {
        NoTrumpComparator comparator = new NoTrumpComparator();
        Deck beloteDeck = DeckFactory.defaultBeloteDeck();

        return composeGameObj(cards, beloteDeck, comparator);
    }

    private static void loadBasicOperations(final Game game) {
        game.addOperation(new Size("size", game));
        game.addOperation(new DrawTopCard("draw_top_card", game));
        game.addOperation(new DrawBottomCard("draw_bottom_card", game));
        game.addOperation(new PeekTopCard("top_card", game));
        game.addOperation(new PeekBottomCard("bottom_card", game));
        game.addOperation(new Shuffle("shuffle", game));
        game.addOperation(new Sort("sort", game));
        game.addOperation(new Deal("deal", game));
    }

    private static List<Card> filterDeck(List<Card> cards, final List<Card> filter) {
        for (Card card : cards) {
            if (!filter.contains(card)) {
                cards.remove(card);
            }
        }
        return cards;
    }

    private static Game composeGameObj(List<Card> cards, final Deck defaultDeck, Comparator<Card> cmp) {
        List<Card> defaultCards = defaultDeck.getCards();

        if (cards.containsAll(defaultCards)) {

            List<Card> filteredCards = filterDeck(cards, defaultCards);
            Deck newDeck = new DeckImpl(filteredCards, defaultDeck.handSize(), cmp);

            GameImpl game = new GameImpl(newDeck);

            loadBasicOperations(game);
            return game;
        }
        throw new CardException("ERROR: Not enough cards for Belote");
    }
}
