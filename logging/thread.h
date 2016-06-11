
//Created on 2016-04-03
//@author: jeff

#ifndef THREAD_H_INCLUDED
#define THREAD_H_INCLUDED

class Thread {

public:
    virtual ~Thread() {}
    virtual void start() = 0;
    virtual void run() = 0;
    virtual void stop() = 0;
    virtual void finish() = 0;

protected:
    bool is_running_;
};

#endif // THREAD_H_INCLUDED
