/*
 * GameFlow.cpp
 *
 *  natan furer 204594428
 */


#include <cstdlib>
#include "GameFlow.h"



using namespace std;


GameFlow::GameFlow(Board &b) : b(b) {
	logic = new StandardLogic();
	noMovesX = false;
	noMovesO = false;
    senderMove = true;
}

void GameFlow::playOneTurn() {
    vector<Point> points;
    //get possible point for the current player and turn.
    points = logic->possiblePoints(b, turn->getSign());
    //display turn
    display->displayGame(b, points, turn, noTurn);
    //handle no moves situation
    if (senderMove) {
        if (points.empty()) {
            if (turn->getSign() == 'X') {
                noMovesX = true;
            } else {
                noMovesO = true;
            }
            if (onlineGame) {
                turn->playerMove(points, b);
            }
            return;

        } else {
            noMovesX = false;
            noMovesX = false;
        }
    }
	//gets player point
	Point p = turn->playerMove(points, b);
    if (onlineGame && !senderMove && (p.getX() == NOMOVE) &&
    (p.getY() == NOMOVE)) {
        if (turn->getSign() == 'X') {
            noMovesX = true;
        } else {
            noMovesO = true;
        }
        return;
    }
	turn->setLastPlayPoint(p);
	//apply the point in the game
	logic->applyMoveWithGivenPoint(b, p, turn->getSign());
}

void GameFlow::runGame() {
    try {
        while ((!b.checkIfTableFull())) {
            playOneTurn();
            if ((noMovesX) && (noMovesO)) {
                if (senderMove && onlineGame) {
                    client->writeToServer(ENDGAME, ENDGAME);
                }
                break;
            }
            //change turns
            if (turn->getSign() == 'X') {
                turn = playerO;
                noTurn = playerX;
            } else {
                turn = playerX;
                noTurn = playerO;
            }
            if (onlineGame) {
                if (senderMove) {
                    senderMove = false;
                } else {
                    senderMove = true;
                }
            }
        }
        //player O won.
        if (b.getNumberOfO() > b.getNumberOfX()) {
            display->endGameDisplay(playerO, playerX, b.getNumberOfO(), b.getNumberOfX(), false, b);
            return;
        }
        //player X won.
        if (b.getNumberOfO() < b.getNumberOfX()) {
            display->endGameDisplay(playerX, playerO, b.getNumberOfX(), b.getNumberOfO(), false, b);
            return;
        }
        //draw.
        display->endGameDisplay(playerX, playerO, b.getNumberOfX(), b.getNumberOfO(),
                                true, b);
    } catch (const char * msg) {
        delete logic;
        delete playerX;
        delete playerO;
        delete display;
        delete client;
        cout << "server crashed, exit game" << endl;
        exit(1);
    }
}

void GameFlow::initializeGame(ConsoleMenu menu) {
	menu.displayMenu();
	int choice = menu.getAndCheckPLayersChoice();
	if (choice == 2) {
        display = new ConsoleDisplay();
		playerX = new StandardPlayer('X');
		playerO = new AIPlayer(logic, 'O');
        onlineGame = false;
	} else if (choice == 1) {
        display = new ConsoleDisplay();
		playerX = new StandardPlayer('X');
		playerO = new StandardPlayer('O');
        onlineGame = false;
	} else if(choice == 3) {
        try {
            setOnlinePlayers();
        }catch (const char * msg) {
            cout << "server crashed, exit game" << endl;
            exit(1);
        }

        display = new DisplayOnlineGame(senderMove);
        onlineGame = true;
	}
	turn = playerX;
	noTurn = playerO;

}

void GameFlow::setOnlinePlayers () {
    int whichSign, port;
    string s = readFromFile(&port);
    const char* chai = s.c_str();
    client = new Client(chai, port);
    ////////////////
    OnlineStartGameMenu onlineStartGameMenu;
    onlineStartGameMenu.handlePlayerOption(client);
    whichSign = client->updateSign();
    if (whichSign == 1) {
        playerX = new PlayerSender('X', client);
        playerO = new RemotePlayer(client, 'O');
        senderMove = true;
    } else if (whichSign == 2) {
        playerO = new PlayerSender('O', client);
        playerX = new RemotePlayer(client, 'X');
        senderMove = false;
    }

}

string GameFlow::readFromFile(int *port) {
    string str;
    string po;
    ifstream op;
    op.open("settings.txt");
    getline(op, str);
    getline(op, po);

    op.close();
    const char* pom = po.c_str();
    *port = atoi(pom);
    return str;
}
GameFlow::~GameFlow() {
    delete logic;
    delete playerX;
    delete playerO;
    delete display;
    delete client;
}







