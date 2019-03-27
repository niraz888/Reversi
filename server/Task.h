//
// Created by natanno4 on 20/01/18.
//

#ifndef SERVER_TASK_H
#define SERVER_TASK_H


class Task {

public:
    /**
    * constructor. recieve a function to execute and args needed to.
    */	
    Task(void * (*func)(void *arg), void *arg) : func(func), arg(arg) {}
    /**
    * execute function.
    * execute task by calling the given function in costructor with the given args.
    */
    void execute() { func(arg); }
    virtual~Task() {}
private:
    void * (*func)(void *arg);
    void *arg;

};


#endif //SERVER_TASK_H
