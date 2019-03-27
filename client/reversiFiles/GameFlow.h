/*
 * GameFlow.h
 *
 *  natan furer 204594428
 */

#ifndef GAMEFLOW_H_
#define GAMEFLOW_H_
#include "Board.h"
#include "StandardLogic.h"
#include "ConsoleDisplay.h"
#include "StandardPlayer.h"
#include "AIPlayer.h"
#include "ConsoleMenu.h"
#include "PlayerSender.h"
#include "RemotePlayer.h"
#include "DisplayOnlineGame.h"
#include "OnlineStartGameMenu.h"
#include <fstream>
#include <unistd.h>

class GameFlow {
public:

	/**
	 * GameFlow function - creates a game flow object.
	 * runs the game
	 *
	 *@param b the game board.
	 */
	GameFlow(Board &b);

	/**
	 * playOneTurn function - runs one turn- logic + display.
	 *
	 */
	void playOneTurn();

	/**
	 * runGame function - runs the game.
	 * changes turns.
	 * checks who wins.
	 *
	 */
	void runGame();

    /**
     * initializeGame function - displays the game menu.
     * initialize the players type by the player choice.
     *
     * @param menu the game menu.
     *
     */
	void initializeGame(ConsoleMenu menu);


	/**
	 * GameFlow function - desructor.
	 *
	 */
	~GameFlow();

private:
	Player * turn;
	Player * playerX;
	Player * playerO;
	GameLogic * logic;
	GameDisplay * display;
	Player* noTurn;
	Board & b;
	bool noMovesX;
	bool noMovesO;
    bool senderMove;
	Client *client;
	bool onlineGame;
	void setOnlinePlayers ();
    string readFromFile(int *port);
};

#endif /* GAMEFLOW_H_ */
