/*
 * GameLogic.h
 *
 *  natan furer 204594428
 */

#ifndef GAMELOGIC_H_
#define GAMELOGIC_H_

using namespace std;
#include <vector>
#include "Point.h"
#include "Board.h"
#include <string>

class GameLogic {
public:

	/**
	 * GameLogic function - creates a game logic object.
	 * handles the game logic.
	 *
	 */
	GameLogic();

	/**
	 * GameLogic function - returns the possible points to make the
	 * move for the given player(sign).
	 *
	 * @param - b the game board.
	 * @param s the sign of the player.
	 */
	virtual const vector<Point>& possiblePoints(Board &b, char s) = 0;

	/**
	 * applyMoveWithGivenPoint function - applies the given point in the board.
	 * the function also applies (flips) the rival discs around the given point.
	 *
	 * @param - b the game board.
	 * @param s the sign of the player.
	 */
	virtual void applyMoveWithGivenPoint(Board &b, Point &p, char s) = 0;

	/**
	 * GameLogic function - destructor.
	 *
	 */
	virtual ~GameLogic();

};

#endif /* GAMELOGIC_H_ */
