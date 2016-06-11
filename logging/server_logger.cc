
//Created on 2016-04-06
//@author: jeff

#include <ctime>
#include "server_logger.h"


ServerLogger* ServerLogger::instance_ = NULL;

ServerLogger& ServerLogger::GetInstance() {
    if (instance_ == NULL) {
        FILE* f = log::CreateLogFileByCurTime();
        instance_ = new ServerLogger(f);
    }

    return *instance_;
}

ServerLogger::ServerLogger(FILE* f) : PosixLogger(f) {}

ServerLogger::~ServerLogger() {}

bool ServerLogger::Check() {
    if (!IsSameDayLog()) {
        FILE* f = log::CreateLogFileByCurTime();
        ChangeFile(f);
        return true;
    }

    return false;
}

bool ServerLogger::IsSameDayLog() {
    time_t t = time(0);
    tm* cur_tm = localtime(&t);
    if (log_time_->tm_year == cur_tm->tm_year &&
        log_time_->tm_mon == cur_tm->tm_mon &&
        log_time_->tm_mday == cur_tm->tm_mday){
        return true;
    }

    return false;
}
