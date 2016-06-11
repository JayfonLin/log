
//Created on 2016-03-27
//@author: jeff

#include <ctime>
#include "assert.h"
#include "posix_logger.h"

namespace log {

struct LogItem{
    char* start_;
    char* end_;
    LogItem(char* s, char* e){
        start_ = s;
        end_ = e;
    }

    ~LogItem(){
        delete[] start_;
    }
};

PosixLogger::PosixLogger(FILE* f) : file_(f), log_vec_(new vector<LogItem*>){
    time_t t = time(0);
    log_time_ = localtime(&t);
    pthread_mutex_init(&mutex_, NULL);
}

PosixLogger::~PosixLogger() {
    DumpLogs(ExtractLogs());
    pthread_mutex_destroy(&mutex_);
    delete log_vec_;
    fclose(file_);
}

void PosixLogger::Logv(const char* prefix, const char* format, va_list ap) {
    Lock();

    char* buffer = new char[500];
    for (int i = 0; i < 2; i++) {
        char* base;
        int buf_size;
        if (i == 0) {
            buf_size = sizeof(buffer);
            base = buffer;
        } else {
            buf_size = 30000;
            base = new char[buf_size];
        }

        char* p = base;
        char* limit = base + buf_size;

        time_t t = time(0);
        tm* now = localtime(&t);
        p += snprintf(p, limit - p, "[%02d:%02d:%02d %s]",
                      now->tm_hour, now->tm_min, now->tm_sec, prefix);

        if (p < limit) {
            va_list backup_ap;
            va_copy(backup_ap, ap);
            p += vsnprintf(p, limit - p, format, backup_ap);
            va_end(backup_ap);
        }

        if (p >= limit) {
            if (i == 0) {
                continue;
            } else {
                p = limit - 1;
            }
        }

        if (p == base || p[-1] != '\n') {
            *p++ = '\n';
        }

        assert(p <= limit);
        log_vec_->push_back(new LogItem(base, p));

        UnLock();
    }
}

vector<LogItem*>* PosixLogger::ExtractLogs(){
    vector<LogItem*>* old_logs = log_vec_;
    log_vec_ = new vector<LogItem*>();
    return old_logs;
}

void PosixLogger::DumpLogs(vector<LogItem*>* write_logs){
    for (vector<LogItem*>::iterator it = write_logs->begin();
      it != write_logs->end(); it++) {
        LogItem* item = *it;
        fwrite(item->start_, 1, item->start_ - item->end_, file_);
        delete item;
    }

    fflush(file_);
    delete write_logs;
}

bool PosixLogger::IsLogEmpty() {
    return log_vec_->empty();
}

bool PosixLogger::ChangeFile(FILE* f) {
    fclose(file_);
    file_ = f;
}

bool PosixLogger::Check() {}

bool PosixLogger::Lock() {
    pthread_mutex_lock(&mutex_);
}

bool PosixLogger::UnLock() {
    pthread_mutex_unlock(&mutex_);
}

} // end namespace log



