//
// Created by nir on 10/12/17.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H


#include "ClientHandler.h"
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>

/**
 * server Class. responsible of creating the first connection with clients.
 */
class Server {
public:

    /**
     * server Class. responsible of creating the first connection with clients.
     */
    Server(int port, ClientHandler *handler);

    /**
     * constructor.
     * @param port port
     * @param handler clienthandler
     */
    void start();

    /**
     * start function.
     * start the server and create the thread that responsible of accept the clients.
     */
    void stop();

private:

    /**
     * port of server
     */
    int port;
    /**
     * socket of server.
     */
    int serverSocket;
    /**
     * pointer the client handler
     */
    ClientHandler *clientHandler;
    /**
     * pointer to thread that accept clients
     */
    pthread_t thread;

};


#endif //SERVER_SERVER_H
