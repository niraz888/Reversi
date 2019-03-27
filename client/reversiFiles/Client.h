//
// Created by nir on 08/12/17.
//

#ifndef LAST_CLIENT_H
#define LAST_CLIENT_H

#include "Point.h"

class Client {
public:
    /**
     * constructor.
     * @param serverIP ip address of server work with
     * @param serverPort port of server work with
     */
    Client(const char* serverIP, int serverPort);
    /**
     * connect Toserver.
     * responsible of connecting to the server.
     */
    void connectToServer();
    /**
     * readFromServer.
     * read data from server, that will be two integers in an agreed
     * order such 1)x,  2)y ->that will be a point.
     * @param x x value
     * @param y y value
     * @return return message
     */
    char* readFromServer(int &x, int &y);
    /**
     * writeToServer.
     * write to server two ints (that are composed a point) tp the server.
     * @param x value
     * @param y value
     */
    void writeToServer(int x, int y);
    /**
     * updateSign.
     * by connecting to the server, expect to recieve number represent
     * the type of player: 1 for X's player. and 2 for O's player.
     * @return int represent type of player
     */
    int updateSign();

    /**
     * getClientSocket function.
     * return client socket
     * @return socket
     */
    int getClientSocket();


private:
    const char *serverIP;
    int serverPort;
    int clientSocket;

};


#endif //LAST_CLIENT_H
