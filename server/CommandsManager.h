//
// Created by natanno4 on 24/12/17.
//


#ifndef LAST_COMMANDSMANAGER_H
#define LAST_COMMANDSMANAGER_H

#include <string>
#include <vector>

#include "Command.h"
#include "StartCommand.h"
#include "GameManager.h"
#include "GameRooms.h"
#include "JoinCommand.h"
#include "ListGamesCommand.h"
#include "CloseClientsSocketsCommand.h"
#include <map>

using namespace std;

/**
 * CommandsManager class. responsible of manage the requests of clients to the
 * appropriate command.
 */
class CommandsManager {
public:
    /**
     * constructor.
     * @param rooms game rooms
     * @param manager  GameManager
     */
    CommandsManager(GameRooms* rooms, GameManager* manager);

    /**
     * destructor.
     */
    ~CommandsManager();

    /**
     * executeCommand function.
     * map the string that was received from user to the actual command class,
     * and than use the execute() function of that command.
     * @param command string represent the command
     * @param args args of socket and name of game.
     */
    void executeCommand(string command, vector<string> args);
private:
    /**
     * map from string represent the command to pointer to actual command.
     */
    map<string, Command*> commandsMap;
};


#endif //LAST_COMMANDSMANAGER_H

