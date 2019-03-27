//
// Created by natanno4 on 27/12/17.
//


#include "ClientHandler.h"
struct cmd {
    CommandsManager *mng;
    int sock;
};

ClientHandler::ClientHandler(CommandsManager *cManagar):
        commandsManager(cManagar){
    threadPool = new ThreadPool(THREADS_NUM);
}

/**
 * handleClientCommand function.
 * the function starts a thread that handles the client command.
 * gets the command as string from the client and send it to the command
 * manager.
 */
void * handleClientCommand(void * cmnd) {
    vector<string> args;
    int counter = 0;
    char buffer[MAX_SIZE_COMMAND] = {0};
    struct cmd * command = (struct cmd *)cmnd;
    int socket = command->sock;
    //get client command
    int n = read(socket, buffer, sizeof(buffer));

    if (n == -1) {
        cout << "error in reading";
        throw "error in reading";
    }
    //convert client socket to string

    stringstream val;
    val << socket;
    args.push_back(val.str());
    char * token, *c;
    //get client input after command
    token = strtok(buffer, " ");
    c = token;
    while (token != NULL)
    {
        if(counter > 0) {
            args.push_back(token);
        }
        token = strtok (NULL, " ");
        counter++;
    }
    //execute command
    command->mng->executeCommand(c, args);
    free(command);
}

void ClientHandler::handleClient(int socket) {
    struct cmd* c = (struct cmd*)malloc(sizeof(struct cmd*));
    c->mng = commandsManager;
    c->sock = socket;
    Task *task = new Task(handleClientCommand, (void *)c);
    threadPool->addTask(task);


}


void ClientHandler::closeAllClients() {
    //close thread pool
    threadPool->terminate();
    vector<string> args;
    //close sockets in games.
    commandsManager->executeCommand("closeSockets", args);

}

ClientHandler::~ ClientHandler() {
    delete threadPool;
}


