//
// Created by natanno4 on 28/12/17.
//

#include "GameManager.h"


GameManager::GameManager(){}

void GameManager::runGame(int socketPlayer1, int socketPlayer2) {
    int res;
    while (true) {
        res = handleOneTurn(socketPlayer1, socketPlayer2);
        if (res == 1) {
            break;
        }
        res = handleOneTurn(socketPlayer2, socketPlayer1);
        if (res == 1) {
            break;
        }
    }
}

int GameManager::handleOneTurn(int sockRead, int sockWrite) {
    int x, y;
    int n = read(sockRead, &x, sizeof(x));
    if (n == -1) {
        cout << "Error in reading x" << endl;
        return 1;
    }

    if (n == 0) {
        cout << "Client Disconnect" << endl;
        return 1;
    }
    n = read(sockRead, &y, sizeof(y));
    if (n == -1) {
        cout << "Error in reading x" << endl;
        return 1;
    }

    if (n == 0) {
        cout << "Client Disconnect" << endl;
        return 1;
    }
    ///////////
    if (x == ENDGAME && y == ENDGAME) {
        n = write(sockWrite, &x, sizeof(x));
        n = write(sockWrite, &y, sizeof(y));
        return 1;
    }
    ///////////////////
    n = write(sockWrite, &x, sizeof(x));

    if (n == -1) {
        cout << "Error in reading x" << endl;
        return 1;
    }

    if (n == 0) {
        cout << "Client Disconnect" << endl;
        return 1;
    }

    n = write(sockWrite, &y, sizeof(y));
    if (n == -1) {
        cout << "Error in reading x" << endl;
        return 1;
    }

    if (n == 0) {
        cout << "Client Disconnect" << endl;
        return 1;
    }
    return 0;
}