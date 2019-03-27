//
// Created by nir on 01/01/18.
//

#ifndef LAST_CLOSECLIENTSSOCKETSCOMMAND_H
#define LAST_CLOSECLIENTSSOCKETSCOMMAND_H

#include "GameRooms.h"
#include "Command.h"
#include "GameManager.h"

using namespace std;

/**
 * CloseClientsSocketsCommand. herit from command, responsible of closing
 * all clients's socket.
 */
class CloseClientsSocketsCommand :  public Command {
private:
    /**
     * pointer to GameRooms.
     */
    GameRooms* rooms;
public:
    /**
     * constructor.
     * @param rooms pointer to GameRooms
     */
    CloseClientsSocketsCommand(GameRooms* rooms);

    virtual void execute(vector<string> vec);

};


#endif //LAST_CLOSECLIENTSSOCKETSCOMMAND_H