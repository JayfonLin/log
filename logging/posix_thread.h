
//Created on 2016-04-03
//@author: jeff

#ifndef POSIX_THREAD_H_INCLUDED
#define POSIX_THREAD_H_INCLUDED

#include "thread.h"

class PosixThread: public Thread {
public:
    PosixThread();
    ~PosixThread();

    void start();
    void run() = 0;
    void stop();

    void finish();

private:
    static void* start_thread(void* arg);
};

#endif // POSIX_THREAD_H_INCLUDED
