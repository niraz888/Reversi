//
// Created by nir on 01/01/18.
//

#include "CloseClientsSocketsCommand.h"
using namespace std;

CloseClientsSocketsCommand::CloseClientsSocketsCommand(GameRooms *rooms) : rooms (rooms){}

void CloseClientsSocketsCommand::execute(vector<string> vec) {
    rooms->removeAllPlayersInGames();
}