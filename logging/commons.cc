
//Created on 2016-04-06
//@author: jeff

#include <ctime>
#include "commons.h"

namespace log {

FILE* CreateLogFileByCurTime() {
    time_t t = time(0);
    char file_name[64];
    strftime(file_name, sizeof(file_name), "%Y-%02m-%02d.log", localtime(&t));
    FILE* log_file = fopen(file_name, "a+");
    return log_file;
}


} // end namespace log
