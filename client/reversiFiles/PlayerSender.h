

#ifndef LAST_PLAYERSENDER_H
#define LAST_PLAYERSENDER_H


#include "Player.h"
#include "Client.h"

class PlayerSender : public Player {
public:
    /**
     * constructor.
     * @param sign sign represent which player
     * @param c client
     */
    PlayerSender(char sign, Client *c);
    /**
     * PlayerMove.
     * play a move with a given point, write it to
     * the server and return it.
     * @param v vector of points
     * @param b board
     * @return point was played
     */
    virtual Point playerMove(vector<Point> &v, Board &b);
    /**
     * destructor
     */
    virtual~PlayerSender();

private:
    Player *player;
    Client *client;

};


#endif //LAST_PLAYERSENDER_H
