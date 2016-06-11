
//Created on 2016-04-06
//@author: jeff

#include <pthread.h>
#include <cstdio>

#include "posix_thread.h"



PosixThread::PosixThread() {
    is_running_ = false;
}

PosixThread::~PosixThread() {
    stop();
}

void PosixThread::start() {
    int status;
    pthread_t run_thread_id;
    is_running_ = true;

    status = pthread_create(&run_thread_id, NULL, start_thread, (void*)this);
    if (status != 0) {
        printf("Create run thread failed\n");
    } else {
        printf("Create thread:%d", run_thread_id);
    }
}


void PosixThread::stop() {
    is_running_ = false;
}

void PosixThread::finish() {
    pthread_t tid;
    printf("thread:%d finish\n", tid);
    //stop();
    pthread_exit(NULL);
}

void* PosixThread::start_thread(void* arg) {
    PosixThread* t = (PosixThread*)arg;
    t->run();
}

