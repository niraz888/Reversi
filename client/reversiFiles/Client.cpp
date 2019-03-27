#include "Client.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

#include "Point.h"
using namespace std;

Client::Client(const char *serverIP, int serverPort) : serverIP(serverIP),
                                                       serverPort(serverPort), clientSocket(0){}


void Client::connectToServer() {
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        throw "error opening socket";
    }

    struct in_addr address;
    if (!inet_aton(serverIP, &address)) {
        throw "can't parse ip address";
    }

    struct hostent *server;
    server = gethostbyaddr((const void*)&address, sizeof(address), AF_INET);
    if (server == NULL) {
        throw "server unreachable";
    }

    struct sockaddr_in serverAddress;
    bzero((char*)&address, sizeof(address));

    serverAddress.sin_family = AF_INET;
    memcpy((char*)&serverAddress.sin_addr.s_addr, (char*)server->h_addr, server->h_length);

    serverAddress.sin_port = htons(serverPort);

    if (connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress))
            == -1) {
       throw "Error connecting to server";
    }
    cout << "connect to server" << endl;
}

void Client::writeToServer(int x, int y) {
    int n = write(clientSocket, &x, sizeof(x));
    if (n == -1) {
        throw "error in writing";
    }
    int n2 = write(clientSocket, &y, sizeof(x));
    if (n2 == -1) {
        throw "error in writing";
    }
}

char* Client::readFromServer(int &x, int &y) {
    int n1 = read(clientSocket, &x, sizeof(x));
    if (n1 == -1 || n1 == 0) {
        throw "error in reading";
    }

    int n2 = read(clientSocket, &y, sizeof(y));
    if (n2 == -1 || n2 == 0 ) {
        throw "error in reading";
    }
    char *data;
    return data;
}

int Client::updateSign(){
    int num, n;
    n = read(clientSocket, &num, sizeof(num));
    if (n == -1 || n == 0) {
        throw "error in reading";
    }
    return num;
}

int Client::getClientSocket() {
    return clientSocket;
}
