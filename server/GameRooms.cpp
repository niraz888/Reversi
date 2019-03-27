//
// Created by natanno4 on 26/12/17.
//

#include "GameRooms.h"


GameRooms::GameRooms() {
}

bool GameRooms::addWaitingGame(string name, int socket) {
    const char* gameName = name.c_str();
    for(map<string, int>::iterator it = waitingGameRoom.begin(); it !=
            waitingGameRoom.end(); it++) {
        const char *temp = it->first.c_str();
        //check if game exist in rooms
       if(!(strcmp(temp, gameName))) {
           return false;
       }
    }
    //add game to room by name
    waitingGameRoom[name] = socket;
    return true;
}

bool GameRooms::addPlayersInGames(int firstSocket, int secondSocket) {
    playersInRunningGame.push_back(firstSocket);
    playersInRunningGame.push_back(secondSocket);
}

int GameRooms::getClientSocketWaitingGame(string name) {
    return waitingGameRoom[name];
}

void GameRooms::removeAllPlayersInGames() {
    // remove the players that currently play socket
    for (vector<int>:: iterator it = playersInRunningGame.begin();
         it != playersInRunningGame.end(); it++) {
        close(*it);
    }
    // remove waiting players's sockets
    for(map<string, int>::iterator it = waitingGameRoom.begin();
        it != waitingGameRoom.end(); it++) {
        close(waitingGameRoom[it->first]);
    }
}

void GameRooms::removeWaitingGame(string name) {
    waitingGameRoom.erase(name);
}

void GameRooms::removePlayersInGames(int firstSocket, int secondSocket) {
    for (vector<int>:: iterator it = playersInRunningGame.begin();
            it != playersInRunningGame.end(); it++) {
        //find the players that play a game.
        if (firstSocket == *it) {
            playersInRunningGame.erase(it);
            continue;
        }
        if(secondSocket == *it) {
            playersInRunningGame.erase(it);
        }
    }
}

string GameRooms::getWaitingGames() {
    string games = "";
    //create a string from the waiting games.
    for(map<string, int>::iterator it = waitingGameRoom.begin(); it !=
            waitingGameRoom.end(); it++) {
        games += it->first;
        games += ',';
    }
    return games;
}

bool GameRooms::isGameInRooms(string game) {
    const char* gameName = game.c_str();
    for(map<string, int>::iterator it = waitingGameRoom.begin(); it !=
            waitingGameRoom.end(); it++) {
        const char *temp = it->first.c_str();
        //check if games exist.
        if (!strcmp(gameName, temp)) {
            return true;
        }
    }
    return false;
}