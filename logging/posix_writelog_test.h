
//Created on 2016-04-08
//@author: jeff

#ifndef _POSIX_WRITE_LOG_TEST_H_
#define _POSIX_WRITE_LOG_TEST_H_

#include <cstdlib>
#include <pthread.h>
#include "posix_thread.h"

class PosixWriteLogTest: public PosixThread {
public:
    PosixWriteLogTest();
    ~PosixWriteLogTest();
    void run() = 0;

private:
    pthread_mutex_t mutex_;

};

#endif // _POSIX_WRITE_LOG_TEST_H_
