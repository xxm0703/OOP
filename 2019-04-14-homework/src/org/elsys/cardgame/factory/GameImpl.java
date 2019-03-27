package org.elsys.cardgame.factory;

import org.elsys.cardgame.api.*;

import java.util.Map;

public class GameImpl implements Game {

    private Deck deck;
    private Map<String, Operation> operations;
    private Hand hand;

    GameImpl(Deck deck, Map<String, Operation> operations) {
        this.deck = deck;
        this.operations = operations;
        hand = null;
    }

    @Override
    public Deck getDeck() {
        return deck;
    }

    @Override
    public Hand getDealtHand() {
        return hand;
    }

    @Override
    public void setDealtHand(Hand hand) {
        this.hand = hand;
    }

    @Override
    public void process(String command) {
        if (operations.containsKey(command)) {
            operations.get(command).execute();
        } else {
            throw new CardException("ERROR: Unknown operation");
        }
    }

    @Override
    public void addOperation(Operation operation) {
        operations.put(operation.getName(), operation);
    }
}
