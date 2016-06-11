//Created on 2016-03-27
//@author: jeff

#ifndef POSIX_LOGGER_H_
#define POSIX_LOGGER_H_

#include <vector>
#include <ctime>
#include <stdio.h>

#include <pthread.h>

#include "logger.h"

using std::vector;

namespace log {

struct LogItem;

class PosixLogger : public Logger {
protected:
    FILE* file_;
    vector<LogItem*>* log_vec_;
    tm* log_time_;
    pthread_mutex_t mutex_;

public:
    PosixLogger(FILE* f);
    virtual ~PosixLogger();
    void Logv(const char* prefix, const char* format, va_list ap);
    void DumpLogs(vector<LogItem*>* write_logs);
    vector<LogItem*>* ExtractLogs();
    bool IsLogEmpty();
    bool ChangeFile(FILE* f);
    bool Check();
    bool Lock();
    bool UnLock();
};

} // namespace log

#endif // POSIX_LOGGER_H_
