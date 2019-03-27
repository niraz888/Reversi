//
// Created by natanno4 on 24/12/17.
//

#include "CommandsManager.h"


CommandsManager::CommandsManager(GameRooms* rooms, GameManager* manager) {
    commandsMap["start"] = new StartCommand(rooms);
    commandsMap["list_games"] = new ListGamesCommand(rooms);
    commandsMap["join"] = new JoinCommand(rooms, manager);
    commandsMap["closeSockets"] = new CloseClientsSocketsCommand(rooms);
}

void CommandsManager::executeCommand(string command, vector<string> args) {
    Command *commandObj = commandsMap[command];
    commandObj->execute(args);
}

CommandsManager::~CommandsManager() {
    map<string, Command*>::iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end() ; it++) {
        delete it->second;
    }
}