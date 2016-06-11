
//Created on 2016-04-04
//@author: jeff

#include <unistd.h>

#include "posix_thread.h"
#include "posix_logger.h"
#include "posix_log_thread.h"
#include "commons.h"

namespace log {

PosixLogThread::PosixLogThread() {

}

PosixLogThread::~PosixLogThread() {
    delete logger_;
}

void PosixLogThread::run() {
    while (is_running_) {
        logger_->Lock();
        if (logger_->IsLogEmpty()) {
            logger_->UnLock();
            usleep(300000); //微秒单位：百万分之一秒
        } else {
            vector<LogItem*>* write_logs = logger_->ExtractLogs();
            logger_->UnLock();

            logger_->Check();
            logger_->DumpLogs(write_logs);
        }
    }

    finish();
}

void PosixLogThread::SetLogger(PosixLogger* logger) {
    logger_ = logger;
}

} //namespace log
