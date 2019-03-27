package org.elsys.cardgame.api;

public class CardException extends RuntimeException {

    public CardException() {
        super("ERROR: Not enough cards in deck");
    }

    public CardException(String message) {
        super(message);
    }

    private static final long serialVersionUID = 8822513014262189134L;

}
