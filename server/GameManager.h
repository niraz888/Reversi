//
// Created by natanno4 on 28/12/17.
//

#ifndef SERVER_GAMEMANAGER_H
#define SERVER_GAMEMANAGER_H

#define ENDGAME (-1)

#include <pthread.h>
#include <iostream>
#include <unistd.h>

using namespace std;

/**
 * GameManager class. responsible of managing the game while running.
 */
class GameManager {

public:
    /**
     * constructor.
     */
    GameManager();

    /**
     * runGame function.
     * receive the socket's of two players in handle each turn.
     * @param socketPlayer1 socket of first
     * @param socketPlayer2 socket of second
     */
    void runGame(int socketPlayer1, int socketPlayer2);

private:
    /**
     * handleOneTurn function.
     * receive two sockets of clients, and read the point from player 1.
     * check if the point that was sent mean the game is over. if yes ->
     * update the other player, else write him the point if first player.
     * @param sockRead sock of playing client
     * @param sockWrite sock of waiting player
     * @return status of game
     */
    int handleOneTurn(int sockRead, int sockWrite);

};


#endif //SERVER_GAMEMANAGER_H
