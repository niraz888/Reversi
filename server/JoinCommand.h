//
// Created by nir on 27/12/17.
//

#ifndef SERVER_JOINCOMMAND_H
#define SERVER_JOINCOMMAND_H

#include "GameRooms.h"
#include "Command.h"
#include "GameManager.h"

using namespace std;

/**
 * JoinCommand. herit from command, responsible of client who join the game.
 */
class JoinCommand: public Command {
private:
    /**
     * pointer to GameRooms.
     */
    GameRooms *gameRooms;

    /**
     * pointer to GameManger.
     */
    GameManager *gameManager;
public:
    /**
     * constructor.
     * @param rooms gamerooms
     * @param mng GameManager
     */
    JoinCommand(GameRooms *rooms, GameManager *mng);


    virtual void execute(vector<string> vec);
};


#endif //SERVER_JOINCOMMAND_H