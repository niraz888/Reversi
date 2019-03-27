//
// Created by nir on 26/12/17.
//

#include "ListGamesCommand.h"
#include <string>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

ListGamesCommand::ListGamesCommand(GameRooms *rooms): gameRooms(rooms) {}

void ListGamesCommand::execute(vector<string> vec) {
    string str = gameRooms->getWaitingGames();
    const char* s = vec[0].c_str();
    int socket = atoi(s);
    const char * newS = str.c_str();
    //length of string og all games
    int length = strlen(newS);
    //first sending length of string
    int r = write (socket, &length, sizeof(length));
    if (r == - 1) {
        cout << "error in writing";
        return;
    }
    if (length == 0) {
        close(socket);
        return;
    }
    //sending the actual string
    int n = write(socket, newS, sizeof(newS));
    if (n == -1) {
        cout << "error in writing";
        return;
    }
    close(socket);
}