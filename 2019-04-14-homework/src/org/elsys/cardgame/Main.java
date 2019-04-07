package org.elsys.cardgame;

import org.elsys.cardgame.api.*;
import org.elsys.cardgame.factory.CardImpl;
import org.elsys.cardgame.factory.GameFactory;

import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        run();

    }

    private static void run() {
        List<Card> cards = new LinkedList<>();
        Scanner in = new Scanner(System.in);
        String cmd;
        Game game = null;

        readCards(cards, in);

        while (true) {
            cmd = in.nextLine();

            try {
                switch (cmd) {
                    case "quit":
                        return;
                    case "War":
                        game = GameFactory.createWarGame(cards);
                        break;
                    case "Belote":
                        game = GameFactory.createBeloteGame(cards);
                        break;
                    case "Santase":
                        game = GameFactory.createSantaseGame(cards);
                        break;
                    default:
                        if (game != null)
                            game.process(cmd);
                        else
                            throw new CardException("ERROR: No deck");
                }
            } catch (CardException e) {
                System.out.println(e.getMessage());
            }

        }
    }

    private static void readCards(final List<Card> cards, Scanner in) {
        String[] line = in.nextLine().split(" ");
        String suitStr, rankStr;


        for (String card : line) {
            suitStr = card.substring(0, 1);
            rankStr = card.substring(1);

            final Suit suit = Suit.get(suitStr);
            final Rank rank = Rank.get(rankStr);
            cards.add(new CardImpl(rank, suit));
        }
    }

}
