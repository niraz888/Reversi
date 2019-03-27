//
// Created by nir on 08/12/17.
//

#ifndef LAST_REMOTEPLAYER_H
#define LAST_REMOTEPLAYER_H


#include "Player.h"
#include "Client.h"
#define NOMOVE (-2)
#define ENDGAME (-1)

class RemotePlayer : public Player {
public:
    /**
     * constructor.
     * @param c a client that interface the the player with server
     * @param sign the sign represent type of player: X/O
     */
    RemotePlayer(Client* c, char sign);
    /**
     * PlayerMove.
     * read from server the point that the opponent played,
     * and returned it.
     * @param v vector
     * @param b board
     * @return the point that the opponent played
     */
    virtual Point playerMove(vector<Point>& v, Board &b);

private:
    Client* client;
};



#endif //LAST_REMOTEPLAYER_H
