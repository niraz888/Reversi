//
// Created by nir on 26/12/17.
//

#ifndef SERVER_LISTGAMESCOMMAND_H
#define SERVER_LISTGAMESCOMMAND_H

#include "Command.h"
#include "GameRooms.h"

/**
 * ListGamesCommand class, herit from command. responsible of holding and
 * returning the list of waiting and running games.
 */
class ListGamesCommand: public Command {
private:
    /**
     * pointer to GameRooms.
     */
    GameRooms *gameRooms;
public:
    /**
     * constructor.
     * @param rooms GameRooms.
     */
    ListGamesCommand(GameRooms *rooms);

    virtual void execute(vector<string> vec);
};

#endif //SERVER_LISTGAMESCOMMAND_H