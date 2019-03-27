/*
 * StandardPlayer.h
 *
 *  natan furer 204594428
 */

#ifndef STANDARDPLAYER_H_
#define STANDARDPLAYER_H_
#include "Player.h"

class StandardPlayer : public Player {
public:

	/**
	 * StandardPlayer function - creates a standard player.
	 *
	 * @param sign - the player sign.
	 */
	StandardPlayer(char sign);

	virtual Point playerMove(vector<Point> &v, Board &b);

	/**
	 * StandardPlayer function - destructor.
	 *
	 *
	 */
	virtual ~StandardPlayer();
};

#endif /* STANDARDPLAYER_H_ */
