#include <memory>
#include "threadP/env.h"
namespace THREADP {

class ThreadPool {
public:
    ThreadPool();

    void SetHostEnv(Env*);

    void SetBackgroundThreads(int num);

    struct Impl;
    
private:
    std::unique_ptr<Impl> impl_;
};



}