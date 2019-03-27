package org.elsys.cardgame.factory.operations;

import org.elsys.cardgame.api.Deck;
import org.elsys.cardgame.api.Game;

public class PeekBottomCard extends AbstractOperation {

    public PeekBottomCard(final String name, final Game game) {
        super(name, game);
    }

    @Override
    public void execute() {
        final Deck deck = game.getDeck();
        System.out.println(deck.bottomCard());
    }
}
