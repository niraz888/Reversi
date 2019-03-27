//
// Created by nir on 26/12/17.
//

#include "StartCommand.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include "GameRooms.h"
#include <unistd.h>
using namespace std;

StartCommand::StartCommand(GameRooms *room) : gameRooms(room) {

}

void StartCommand::execute(vector<string> vec) {
    int x;
    // first, convert the string represent the socket to an actual socket
    // then take the string represent to name of game, and add the pair (name, socket) to map
    //writing to socket of client status of game
    // return
    //vec[0] is the socket number
    //vec[1] is name of game
    const char* str = vec[0].c_str();
    int socket = atoi(str);
    //check if game exist
    if (!gameRooms->addWaitingGame(vec[1], socket)) {
        x = -1;
        //write error
        int n = write(socket, &x, sizeof(x));
        if (n == -1) {
            cout << "error in writing";
            return;
        }
        close(socket);
    }
    else  {
        x = 0;
        //write ok sign to client.
        int n = write(socket, &x, sizeof(x));
        if (n == -1) {
            cout << "error in writing";
            return;
        }
    }
}