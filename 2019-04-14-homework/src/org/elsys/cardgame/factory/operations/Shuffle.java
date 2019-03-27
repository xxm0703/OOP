package org.elsys.cardgame.factory.operations;

import org.elsys.cardgame.api.Deck;
import org.elsys.cardgame.api.Game;

public class Shuffle extends AbstractOperation {

    public Shuffle(final String name, final Game game) {
        super(name, game);
    }

    @Override
    public void execute() {
        final Deck deck = game.getDeck();
        deck.shuffle();
    }
}
