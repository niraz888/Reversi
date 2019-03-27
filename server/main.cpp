#include <iostream>
#include "Server.h"
#include <stdlib.h>
#include <fstream>

using namespace std;

int main() {
    string port;
    ifstream in;
    in.open("server_settings.txt");
    if (!in.is_open()) {
        return 1;
    }
    getline(in, port);
    const char* portStr = port.c_str();
    int n = atoi(portStr);
    in.close();
    ////////////////////
    GameManager* manager = new GameManager();
    GameRooms *rooms = new GameRooms();
    CommandsManager *commandsManager = new CommandsManager(rooms, manager);
    ClientHandler handler(commandsManager);
    Server server(n, &handler);
    try {
        server.start();
        string exit;
        //wait for exit input to turn down the server
        do {
            cin >> exit;

        }while(exit.compare("exit"));
        //close threads and sockets.
        handler.closeAllClients();

    } catch (const char* msg) {
        delete  manager;
        delete rooms;
        delete commandsManager;
        cout << "cannot start the server because: " << msg << endl;
        exit(-1);
    }
    server.stop();
    delete  manager;
    delete rooms;
}