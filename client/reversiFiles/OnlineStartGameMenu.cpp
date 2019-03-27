//
// Created by natanno4 on 26/12/17.
//



#include "OnlineStartGameMenu.h"



OnlineStartGameMenu::OnlineStartGameMenu() {
    firstTime = false;
}

void OnlineStartGameMenu::printPlayerOptions(){
    if (!firstTime) {
        cout << "you chose to play against a remote player." << endl;
        firstTime = true;
    }
    cout << "choose your next option:" << endl;
    cout << "1.to start a new game - start <name>" << endl;
    cout << "2.to join a waiting game - join <name>" << endl;
    cout << "3.get the list of the waiting games - list_games" <<endl;
}

void OnlineStartGameMenu::handlePlayerOption(Client *client) {
    char buffer[MAXCOMMAND] = {0};
    char * temp;
    int counter, n, m = 0, socket;
    char dummy;
    char c;
    while(true) {
        //print menu
        printPlayerOptions();
        //get \n from previous cin
        if(!m) {
            dummy = getchar();
        }
        m++;
        counter = 0;
        //get string by characters.
        do {
            c = getchar();
            if (c == '\n') {
                break;
            }
            buffer[counter] = c;
            counter++;

        } while(c != '\n');
        buffer[counter] = '\0';

        //ceck if start comman
        if(checkIfCommand(buffer, "start")) {
            //connect to server
            client->connectToServer();
            //notify server
            n = write(client->getClientSocket(), buffer, strlen(buffer));
            if (n == -1) {
                throw "error in writing";
            }
            //check if game exist
            if (gameExist(client->getClientSocket())) {
                return;
            }
            //wrong start command
            temp = buffer;
            temp += STARTNAMEBEGIN;
            emptyBuffer(buffer);
            cout << "the game name " << temp << "already exist" << endl;
            continue;
        }
        //check if join command
        if(checkIfCommand(buffer, "join")) {
            //connect to server
            client->connectToServer();
            //notify server
            n = write(client->getClientSocket(), buffer, strlen(buffer));
            if (n == -1) {
                throw "error in writing";
            }
            //check if game exist
            if (gameExist(client->getClientSocket())) {
                return;
            }
            //wrong join command
            temp = buffer;
            temp += JOINNAMEBEGIN;
            emptyBuffer(buffer);
            cout << "the game "<< temp << "is not exist" << endl;
            continue;
        }
        const char * check = buffer;
        //check if list_games command
        if(!strcmp(check, "list_games")) {
            //connect to server
            client->connectToServer();
            //notify server
            n = write(client->getClientSocket(), buffer, strlen(buffer));
            if (n == -1) {
                throw "error in writing";
            }
            //print games list
            showAvailableGames(client->getClientSocket());
            emptyBuffer(buffer);
            continue;
        }
        cout << "wrong input" << endl;
    }
}

bool OnlineStartGameMenu::checkIfCommand(string playerCommand, string command) {
    char * convert = (char *) playerCommand.c_str();
    char * cmd = strtok(convert, " ");
    const char * temp = command.c_str();
    if(!strcmp(temp, cmd)) {
        while (cmd != NULL)
        {
            cmd = strtok (NULL, " ");
            if(cmd == NULL) {
                return false;
            }
            //check for game name
            const char* check = cmd;
            if(strlen(check) > 0) {
                return true;
            } else {
                return false;
            }
        }
    }
    return false;

}


void OnlineStartGameMenu::showAvailableGames(int socket) {
    int length,n, count = 0;
    //get size of string to read
    n = read(socket, &length, sizeof(int));
    if(n == -1 || n == 0) {
        throw "error in reading";
    }
    //no games
    if (length == 0) {
        cout << "no available games" << endl;
        return;
    }
    char buffer[length];
    //read game lists.
    n = read(socket, &buffer, sizeof(buffer));
    if(n == -1 || n == 0) {
        throw "error in reading";
    }

    buffer[length] = '\0';
    char * token = strtok(buffer, ",");
    cout << "the available games:" << endl;
    while (token != NULL)
    {
        count++;
        cout << token << "|";
        token = strtok (NULL, ",");
        //print 5 games in line.
        if(count == 5) {
            count = 0;
            cout << endl;
        }
    }
    cout << endl;
}

bool OnlineStartGameMenu::gameExist(int socket) {
    int check;
    //read if game exist.
    int n = read(socket, &check, sizeof(int));
    if (n == -1 || n == 0) {
        throw "error in reading";
    }
    if (check == -1) {
        return false;
    }
    return true;
}

void OnlineStartGameMenu::emptyBuffer(char * buffer) {
    int counter = 0;
    while (buffer[counter] != '\0') {
        //empty buffer
        buffer[counter] = '\0';
        counter++;
    }
}