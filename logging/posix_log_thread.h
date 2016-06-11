
//Created on 2016-04-04
//@author: jeff

#ifndef POSIX_LOG_THREAD_H_INCLUDED
#define POSIX_LOG_THREAD_H_INCLUDED



#include "posix_thread.h"
#include "posix_logger.h"

namespace log {

//class PosixLogger;

class PosixLogThread: public PosixThread {

public:
    PosixLogThread();
    ~PosixLogThread();

    bool IsSameDayLog();
    void run();
    void SetLogger(PosixLogger* logger);

private:
    PosixLogger* logger_;

};

} //namespace log

#endif // POSIX_LOG_THREAD_H_INCLUDED
