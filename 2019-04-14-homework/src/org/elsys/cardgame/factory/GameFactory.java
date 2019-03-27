package org.elsys.cardgame.factory;

import org.elsys.cardgame.api.Card;
import org.elsys.cardgame.api.Game;

import java.util.List;

public class GameFactory {

    public static Game createWarGame(List<Card> cards) {
        return new GameImpl(DeckFactory.defaultWarDeck(), null);
    }

    public static Game createSantaseGame(List<Card> cards) {
        return new GameImpl(DeckFactory.defaultSantaseDeck(), null);
    }

    public static Game createBeloteGame(List<Card> cards) {
        return new GameImpl(DeckFactory.defaultBeloteDeck(), null);
    }
}
