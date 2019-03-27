//
// Created by natan furer 204594428
//

#ifndef EX2_AIPLAYER_H
#define EX2_AIPLAYER_H

#include "Player.h"
#include "StandardLogic.h"

class AIPlayer : public Player {
private:
    GameLogic* logic;

public:

    /**
     * AIPlayer function - creates a player with the given sign.
     * default sign is 'O', if sign is not given.
     *
     * @param sign - player's sign.
     */
    AIPlayer(GameLogic * gameLogic, char sign = 'O');

    virtual Point playerMove(vector<Point> &v, Board &b);
};


#endif //EX2_AIPLAYER_H
