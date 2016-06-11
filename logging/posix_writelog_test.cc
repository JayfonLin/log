
//Created on 2016-04-08
//@author: jeff


#include <unistd.h>
#include <stdarg.h>
#include "posix_writelog_test.h"
#include "logger.h"

PosixWriteLogTest::PosixWriteLogTest(){

}

PosixWriteLogTest::~PosixWriteLogTest(){

}

void PosixWriteLogTest::run(){

    while (is_running_) {
        //pthread_mutex_lock(&mutex_);
        srand(time(NULL));
        int n = (rand()%1000);
        n *= 1000;
        usleep(n);

        //pthread_mutex_unlock(&mutex_);
    }
}

void Log(log::Logger* info_log, const char* prefix, const char* format, ...) {
    va_list ap;
    va_start(ap, format);
    info_log->Logv(prefix, format, ap);
    va_end(ap);
}
