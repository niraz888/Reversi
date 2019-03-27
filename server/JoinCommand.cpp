//
// Created by nir on 27/12/17.
//

#include "JoinCommand.h"
#include <string>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

JoinCommand::JoinCommand(GameRooms *rooms, GameManager *mng) :gameManager(mng)
        ,gameRooms(rooms){}

void JoinCommand::execute(vector<string> vec) {
    string str = vec[1];
    const char* chSocket = vec[0].c_str();
    int secondSocket = atoi(chSocket);
    int firstSocket;
    //check if game exist in rooms and waits
    if(gameRooms->isGameInRooms(str)) {
        //get the socket of the player that opened the games.
        firstSocket = gameRooms->getClientSocketWaitingGame(str);
        int x = 0, y = 2;
        //send 0 to the client to represent that the game will start.
        int n = write(secondSocket, &x, sizeof(x));
        if (n == -1) {
            cout << "error in writing";
            return;
        }

        int k = 1;
        //first player turn
        n = write(firstSocket, &k, sizeof(k));
        if (n == -1) {
            cout << "error in writing";
            return;
        }
        //second player turn
        n = write(secondSocket, &y, sizeof(y));
        if (n == -1) {
            cout << "error in writing";
            return;
        }
    } else {
        int x = -1;
        //game no found ,send -1 to client
        int n = write(secondSocket, &x, sizeof(x));
        if (n == -1) {
            cout << "error in writing";
            return;
        }
        close(secondSocket);
        return;
    }

    //remove the players from the waiting room
    gameRooms->removeWaitingGame(str);
    //add the player to the list of players that play now.
    gameRooms->addPlayersInGames(firstSocket,secondSocket);
    //run the game.
    gameManager->runGame(firstSocket, secondSocket);
    //remove the players from the playing list.
    gameRooms->removePlayersInGames(firstSocket, secondSocket);
    close(firstSocket);
    close(secondSocket);
}