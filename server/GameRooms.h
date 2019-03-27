//
// Created by natanno4 on 26/12/17.
//

#ifndef SERVER_GAMEROOMS_H
#define SERVER_GAMEROOMS_H


#include <string>
#include <map>
#include <vector>
#include <cstring>
#include <iostream>
#include <unistd.h>

using namespace std;

/**
 * GameRooms class. responsible of holding all games that running and
 * game that waiting for second player to join.
 */
class GameRooms {

public:
    /**
     * constructor.
     */
    GameRooms();

    /**
     * addWaitingGame function.
     * add a game to waiting game list.
     * @param name name of game
     * @param socket socket of client who opened game.
     * @return true if game isnt in list, false if he is there.
     */
    bool addWaitingGame(string name, int socket);

    /**
     * addPlayersInGames function.
     * add a game to running game list.
     * @param firstSocket sokcet of first player
     * @param secondSocket same
     * @return true if game is in list, false if he isnt there.
     */
    bool addPlayersInGames(int firstSocket, int secondSocket);

    /**
     * getClientSocketWaitingGame.
     * get the socket of player waiting for other one to join him.
     * @param name name of game.
     * @return socket
     */
    int getClientSocketWaitingGame(string name);

    /**
     * removeWaitingGame.
     * remove a game from waiting game list.
     * @param name name of game
     */
    void removeWaitingGame(string name);

    /**
     * removePlayersInGames.
     * remove player's from running game list.
     * @param firstSocket .
     * @param secondSocket .
     */
    void removePlayersInGames(int firstSocket, int secondSocket);

    /**
     * getWaitingGames.
     * get the all waiting games in form of string.
     * @return string
     */
    string getWaitingGames();

    /**
     * removeAllPlayersInGames function.
     * remove all sockets of both running game's players and waiting games's players.
     */
    void removeAllPlayersInGames();

    /**
     * isGameInRooms function.
     * by a given name of game, check if he exist in waiting games list.
     * return true if he is, otherwise false.
     * @param game name of game.
     * @return explained above
     */
    bool isGameInRooms(string game);

private:
    /**
     * map from string represent the name of game to the socket of
     * player that opened the game.
     */
    map <string, int> waitingGameRoom;

    /**
     * vector that contains all sockets of players who currently play.
     */
    vector <int>playersInRunningGame;


};


#endif //SERVER_GAMEROOMS_H
