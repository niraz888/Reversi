//
// Created by natanno4 on 06/12/17.
//

#include "PlayerSender.h"
#include "StandardPlayer.h"


PlayerSender::PlayerSender(char sign, Client *c) : Player(sign) {
    player = new StandardPlayer(sign);
    client = c;

}

Point PlayerSender::playerMove(vector<Point> &v, Board &b) {
    Point p = player->playerMove(v, b);
    client->writeToServer(p.getX(), p.getY());
    return p;
}

PlayerSender::~PlayerSender() {
    delete player;
}