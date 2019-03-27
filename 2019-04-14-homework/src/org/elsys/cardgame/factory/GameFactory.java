package org.elsys.cardgame.factory;

import org.elsys.cardgame.api.Card;
import org.elsys.cardgame.api.CardException;
import org.elsys.cardgame.api.Deck;
import org.elsys.cardgame.api.Game;
import org.elsys.cardgame.factory.operations.*;

import java.util.List;

public class GameFactory {

    public static Game createWarGame(List<Card> cards) {
        final Deck defaultWarDeck = DeckFactory.defaultWarDeck();

        if (cards.containsAll(defaultWarDeck.getCards())) {
            final GameImpl game = new GameImpl(defaultWarDeck, null);
            loadBasicOperations(game);
            return game;
        }
        throw new CardException("ERROR: Not enough cards for War");
    }

    public static Game createSantaseGame(List<Card> cards) {
        final Deck defaultSantaseDeck = DeckFactory.defaultSantaseDeck();

        if (cards.containsAll(defaultSantaseDeck.getCards())) {
            final GameImpl game = new GameImpl(defaultSantaseDeck, null);
            loadBasicOperations(game);
            return game;
        }
        throw new CardException("ERROR: Not enough cards for Santase");
    }

    public static Game createBeloteGame(List<Card> cards) {
        final Deck defaultBeloteDeck = DeckFactory.defaultBeloteDeck();

        if (cards.containsAll(defaultBeloteDeck.getCards())) {
            final GameImpl game = new GameImpl(defaultBeloteDeck, null);
            loadBasicOperations(game);
            return game;
        }
        throw new CardException("ERROR: Not enough cards for Belote");
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
}
