
#include "RemotePlayer.h"
#include <string.h>
RemotePlayer::RemotePlayer(Client* c, char sig) : client(c), Player(sig) {}


Point RemotePlayer::playerMove(vector<Point> &v, Board &b) {
    int x,y;
    client->readFromServer(x, y);
    Point p(x, y);
    return p;
}