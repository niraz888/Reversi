/*
 * GameDisplay.h
 *
 *  natan furer 204594428
 */

#ifndef GAMEDISPLAY_H_
#define GAMEDISPLAY_H_
#include <vector>
#include "Player.h"
#include "Board.h"
using namespace std;

class GameDisplay {
public:

	/**
	 * GameDisplay function - creates game display object.
	 *
	 */
	GameDisplay();

	/**
	 * endGameDisplay function - display the end of the game screen.
	 *
	 * @param winner - the winner player.
	 * @param loser - the loser player.
	 * @param numberOfDiscsW - number of winer's discs.
	 * @param numberOfDiscsL - number of loser's discs.
	 * @param draw - true if the game ended with a draw, else false.
	 * @param b - the game board.
	 */
	void endGameDisplay(Player *winner,Player * loser,
			int numberOfDiscsW, int numberOfDiscsL, bool draw, const Board& b) const;

	/**
	 * displayGame function - display the game (one turn).
	 *
	 * @param b - the game board.
	 * @param v - the possible points vector.
	 * @param player - the player that is playing now.
	 * @param lastTurn - the other player.
	 */
	virtual void displayGame(Board &b, vector<Point> v, Player *player, Player *lastTurn) = 0;

	/**
	 * GameDisplay function - destructor.
	 *
	 */
	virtual ~GameDisplay();

protected :
	bool firstTurn;
};

#endif /* GAMEDISPLAY_H_ */
