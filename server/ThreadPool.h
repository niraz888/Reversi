

#ifndef SERVER_THREADPOOL_H
#define SERVER_THREADPOOL_H
#include"Task.h"
#include<queue>
#include<pthread.h>

using namespace std;

/**
* ThreadPool class. 
*/
class ThreadPool {
    public:
	/**
	* constructor. receieve number of threads to initiliaze..
	*/
        ThreadPool(int threadsNum);
	/**
	* addTask function.
	* add tast the the taskQueue.
	*/
        void addTask(Task *task);
	/**
	* terminate function.
	* close all threads and delete threadpool.
	*/
        void terminate();
        virtual~ThreadPool();
    private:
        queue<Task *> tasksQueue;
        pthread_t * threads;
        void executeTasks();
        bool stopped;
        pthread_mutex_t lock;
        static void *execute(void *arg);


};


#endif //SERVER_THREADPOOL_H
