//
// Created by natanno4 on 07/12/17.
//

#include "DisplayOnlineGame.h"
#include "ConsoleDisplay.h"

DisplayOnlineGame::DisplayOnlineGame(bool myTurn) : GameDisplay() {
    gameDisplay = new ConsoleDisplay();
    sendersTurn = myTurn;
    firstTurn = true;
}

void DisplayOnlineGame::displayGame(Board &b, vector<Point> v,
                                    Player *player, Player *lastTurn) {
    if (sendersTurn) {
        gameDisplay->displayGame(b, v, player, lastTurn);
        sendersTurn = false;
        firstTurn = false;
        return;
    }

    cout <<endl << "current board" << endl;
    b.print();

    if (!firstTurn) {
        cout << lastTurn->getSign() << " played " << lastTurn->getLastPlayPoint() << endl
             << endl;
    } else {
        firstTurn = false;
    }
    cout << "waiting for other player's move ..." << endl;
    sendersTurn = true;
}

DisplayOnlineGame::~DisplayOnlineGame() {
    delete gameDisplay;
}