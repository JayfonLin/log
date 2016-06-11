//Created on 2016-03-27
//@author: jeff

#ifndef LOGGER_H_
#define LOGGER_H_

#include <stdarg.h>

namespace log {

const static char* kLogInfo = "INFO";
const static char* kLogErr = "ERR";
const static char* kLogWarn = "WARN";


class Logger {
public:
    Logger() {}
    virtual ~Logger() {}
    virtual bool Check() = 0;

    virtual void Logv(const char* prefix, const char* format, va_list ap) = 0;

private:
    // No copying allowed
    Logger(const Logger&);
    void operator=(const Logger&);
};

}

#endif // LOGGER_H_
