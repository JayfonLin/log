
//Created on 2016-04-06
//@author: jeff


#include <iostream>

#include <unistd.h>
#include <stdarg.h>
#include "logger.h"
#include "posix_log_thread.h"
#include "server_logger.h"


using namespace std;
using namespace log;

void wrap_log(Logger* info_log, const char* prefix, const char* format, ...);

int main()
{
    PosixLogThread* pt;
    ServerLogger* logger = &ServerLogger::GetInstance();
    pt = new PosixLogThread();
    pt->SetLogger(logger);
    pt->start();


    int count = 0;
    const char* m = "GOGOGOGOG";
    while(true) {
        count++;
        wrap_log(logger, log::kLogInfo, "count:%d msg:%s", count, m);
        sleep(1);
    }
    return 0;
}

void wrap_log(Logger* info_log, const char* prefix, const char* format, ...) {
    va_list ap;
    va_start(ap, format);
    info_log->Logv(prefix, format, ap);
    va_end(ap);
}
