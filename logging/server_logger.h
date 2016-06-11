
//Created on 2016-04-05
//@author: jeff

#ifndef _SERVER_LOGGER_H_
#define _SERVER_LOGGER_H_

#include <stdio.h>
#include "posix_logger.h"
#include "commons.h"

class ServerLogger : public log::PosixLogger {
public:
    static ServerLogger& GetInstance();
    bool Check();

private:
    ServerLogger(FILE* f);
    ~ServerLogger();
    ServerLogger(const ServerLogger&);
    ServerLogger& operator=(const ServerLogger&);
    bool IsSameDayLog();

private:
    static ServerLogger* instance_;

};


#endif // _SERVER_LOGGER_H_
