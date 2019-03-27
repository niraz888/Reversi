/*
 * ConsoleDisplay.h
 *
 *  natan furer 204594428
 */

#ifndef CONSOLEDISPLAY_H_
#define CONSOLEDISPLAY_H_

#include <vector>
#include "Board.h"
#include "Player.h"
#include "GameDisplay.h"
#include <iostream>
using namespace std;

class ConsoleDisplay : public GameDisplay {

public:

	/**
	 * ConsoleDisplay function - creates ConsoleDisplay object.
	 *
	 */
	ConsoleDisplay();

	virtual void displayGame(Board &b, vector<Point> v, Player *player, Player *lastTurn);
	virtual ~ConsoleDisplay();

private:

	/**
	 * printPlayerOption function - prints the possible points in the
	 * given vector.
	 *
	 * @param v - the points vector.
	 */
	void printPlayerOption(vector<Point> &v) const;

};

#endif /* CONSOLEDISPLAY_H_ */
