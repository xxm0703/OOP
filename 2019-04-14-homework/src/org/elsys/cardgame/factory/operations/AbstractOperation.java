package org.elsys.cardgame.factory.operations;

import org.elsys.cardgame.api.Game;
import org.elsys.cardgame.api.Operation;

public abstract class AbstractOperation implements Operation {

    private final String name;
    final Game game;

    AbstractOperation(final String name, final Game game) {
        this.name = name;
        this.game = game;
    }

    @Override
    public String getName() {
        return name;
    }
}
