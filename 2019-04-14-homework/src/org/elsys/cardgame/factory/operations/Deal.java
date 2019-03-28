package org.elsys.cardgame.factory.operations;

import org.elsys.cardgame.api.Deck;
import org.elsys.cardgame.api.Game;
import org.elsys.cardgame.api.Hand;

public class Deal extends AbstractOperation {

    public Deal(final String name, final Game game) {
        super(name, game);
    }

    @Override
    public void execute() {
        final Deck deck = game.getDeck();
        final Hand hand = deck.deal();
        game.setDealtHand(hand);

        System.out.println(hand);
    }
}
