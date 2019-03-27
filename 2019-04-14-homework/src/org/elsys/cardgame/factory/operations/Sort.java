package org.elsys.cardgame.factory.operations;

import org.elsys.cardgame.api.Deck;
import org.elsys.cardgame.api.Game;

public class Sort extends AbstractOperation {

    public Sort(final String name, final Game game) {
        super(name, game);
    }

    @Override
    public void execute() {
        final Deck deck = game.getDeck();
        deck.sort();
    }
}
