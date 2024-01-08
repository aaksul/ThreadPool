#include "thread_pool.h"
#include <mutex>
#include <condition_variable>
#include <thread>
#include <vector>
#include "threadP/env.h"
#include "thread_util.h"
namespace THREADP {


struct ThreadPool::Impl {

    void SetBackgroundThreads(int num);

    void SetHostEnv(Env* env);
    
    private:

    static void threadFunc(void* arg);

    Env* env_;
    std::mutex mu_;
    std::condition_variable bg_;
    std::vector<std::thread> bgthreads_;
};

struct ThreadArg {
    ThreadPool::Impl* thread_pool_;
};


void ThreadPool::Impl::threadFunc(void* arg) {
    ThreadArg* threadArg = reinterpret_cast<ThreadArg*>(arg);
    ThreadPool::Impl* tp = threadArg->thread_pool_;
    Env* env = tp->env_;
    ThreadUtil::RegisterThread(env,env->getThreadID());   
    
}

ThreadPool::ThreadPool() : impl_{new Impl()} {}

void ThreadPool::Impl::SetBackgroundThreads(int num) {
    std::lock_guard<std::mutex> lck(mu_);
    while (bgthreads_.size() < num)
    {

    }
        
}

void ThreadPool::Impl::SetHostEnv(Env* env) {
    env_ = env;
}

void ThreadPool::SetBackgroundThreads(int num) {
    impl_->SetBackgroundThreads(num);
}

void ThreadPool::SetHostEnv(Env* env) {
    impl_->SetHostEnv(env);
}
}