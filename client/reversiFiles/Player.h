/*
 * Player.h
 *
 *  natan furer 204594428
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Point.h"
#include "Board.h"
#include <vector>

using namespace std;

class Player {
public:

	/**
	 * Player function - creates a player with the given sign.
	 *
	 * @param sign - player's sign.
	 */
	Player(char sign);

	/**
	 * playerMove function - sets and returns the player move.
	 *
	 * @param v the points vector.
	 * @return the players move as a point.
	 */
	virtual Point playerMove(vector<Point> &v, Board &b) = 0;

	/**
	 * getSign function - return the player sign.
	 *
	 * @return the player sign.
	 */
	char getSign() const;

	/**
	 * setLastPlayPoint function - sets the player last turn point
	 * by the given one.
	 *
	 * @param p - point.
	 */
	void setLastPlayPoint(Point p);

	/**
	 * getLastPlayPoint function - returns the player last turn point.
	 *
	 * @return the player last turn point.
	 */
	Point getLastPlayPoint() const;

	/**
	 * Player - destructor.
	 *
	 */
	virtual ~Player();


protected:
    char sign;
    Point lastPlay;

};

#endif /* PLAYER_H_ */
