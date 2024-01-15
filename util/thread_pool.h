#pragma once
#include <memory>
#include "threadP/env.h"

namespace THREADP {

class ThreadPool {
public:
    ThreadPool();

    void SetHostEnv(Env*);

    void SetBackgroundThreads(int num);

    void JoinAllThreads();

    struct Impl;
    
private:
    Impl* impl_;
};



}