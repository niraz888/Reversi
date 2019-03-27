#include "Server.h"


using namespace std;
#define MAX_CONNECTED_CLIENTS 100

struct clientAd {
    int *serverSock;
    ClientHandler * clientHandler;
};

Server::Server(int port, ClientHandler *handler) : port(port)
        , serverSocket(0), clientHandler(handler) {}

/**
 * handleClientsAccept function.
 * the function starts a thread that handles the client connections
 * and handles the clients given command.
 */
void * handleClientsAccept(void * serverInfo) {
    struct clientAd * ca = (struct clientAd *) serverInfo;
    int socket = *(ca->serverSock);
    ClientHandler *clientHandler = ca->clientHandler;
    free(ca);
    // Define the client socket's structures
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen = sizeof(clientAddress);
    while (true) {
        cout << "Waiting for client connections..." << endl;
        // Accept a new client connection
        int clientSocket = accept(socket, (struct sockaddr *)&clientAddress,
               &clientAddressLen);
        cout << "Client connected" << endl;
        if (clientSocket == -1)
            throw "Error on accept";
        clientHandler->handleClient(clientSocket);
    }
    return NULL;
}


void Server::start() {
    // Create a socket point
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        throw "Error opening socket";
    }
    // Assign a local address to the socket
    struct sockaddr_in serverAddress;bzero((void *)&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error on binding";
    }
    // Start listening to incoming connection requests
    listen(serverSocket, MAX_CONNECTED_CLIENTS);

    struct clientAd *c = (struct clientAd *)malloc(sizeof(struct clientAd *));
    c->serverSock = &serverSocket;
    c->clientHandler = clientHandler;
    int rc = pthread_create(&thread, NULL, handleClientsAccept,(void *)c);

    if (rc) { cout << "Error: unable to create thread, " << rc << endl;
        exit(-1);
    }


}

void Server::stop() {
    pthread_cancel(thread);
    close(serverSocket);
}
