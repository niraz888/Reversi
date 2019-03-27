//
// Created by natanno4 on 26/12/17.
//

#ifndef LAST_ONLINESTARTGAMEMENU_H
#define LAST_ONLINESTARTGAMEMENU_H

#include <iostream>
#include <cstring>
#include <unistd.h>
#include "Client.h"
#include <cstdio>

using namespace std;
#define MAXCOMMAND 60
#define STARTNAMEBEGIN 7
#define JOINNAMEBEGIN 6

class OnlineStartGameMenu {

public:
    /**
     * constructor.
     *
     */
    OnlineStartGameMenu();

    /**
     * printPlayerOptions function.
     * print the option of playing against remote player:
     * 1)start new game 2)join to existing game and start playing 3)get the available games
     */
    void printPlayerOptions();

    /**
     * handlePlayerOption function.
     * receieve pointer to client, and in function receive request from user as string, and handle according
     * to command by writing to server.
     * @param client client
     */
    void handlePlayerOption(Client *client);

private:
    /**
     * bool to check if client enter to menu first time.
     */
    bool firstTime;

    /**
     * checkIfCommand function.
     * check if the input from user is in format of command.
     * @param playerCommand input from user.
     * @param command command
     * @return true if correct, otherwise false.
     */
    bool checkIfCommand(string playerCommand, string command);

    /**
     * showAvailableGames function.
     * display the games that are available to join.
     * @param socket socket of client
     */
    void showAvailableGames(int socket);

    /**
     * gameExist function.
     * check if game exist.
     * @param socket socket of client
     * @return true if exist otherwise false
     */
    bool gameExist(int socket);

    /**
     * emptyBuffer function.
     * empty the buffer that reads from user.
     * @param buffer buffer.
     */
    void emptyBuffer(char * buffer);

};


#endif //LAST_ONLINESTARTGAMEMENU_H
