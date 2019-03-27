//
// Created by nir on 26/12/17.
//

#ifndef SERVER_STARTCOMMAND_H
#define SERVER_STARTCOMMAND_H

#include "Command.h"
#include <map>
#include "GameRooms.h"

/***
 * StartCommand class, herit from command. responsible of client who want
 * to start a new game.
 */
class StartCommand: public Command {
private:
    /**
     * pointer to GameRooms
     */
    GameRooms *gameRooms;
public:
    /**
     * constructor.
     * @param game GameRooms
     */
    StartCommand(GameRooms *game);
    virtual void execute(vector<string> vec);
};


#endif //SERVER_STARTCOMMAND_H