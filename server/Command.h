//
// Created by natanno4 on 24/12/17.
//

#ifndef LAST_COMMAND_H
#define LAST_COMMAND_H


#include<vector>
#include<string>
using namespace std;

/**
 * class Command. pure virtual class that responsible of client's requests that
 * can be many kinds of.
 */
class Command {
public:
    /**
     * execute function.
     * execute the command and getting help by vec of args that contains socket
     * of relevant client and possibly name of game to start/join
     * @param args
     */
    virtual void execute(vector<string> args) =0;

    /**
     * destructor.
     */
    virtual~Command() {}
};


#endif //LAST_COMMAND_H
