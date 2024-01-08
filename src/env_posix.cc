#include <vector>
#include <thread>

#include "threadP/env.h"
#include "util/thread_pool.h"

namespace THREADP {

class EnvPosix : public Env {
    public:

    EnvPosix();

    virtual void SetBackGroundThread(int total_thread,int index) override;

    virtual tid getThreadID() override;

    friend Env* Default();

    private:
    std::vector<ThreadPool> thread_pools_;

};

EnvPosix::EnvPosix() : thread_pools_(4) {
    for (ThreadPool& tP : thread_pools_) {
        tP.SetHostEnv(this);
    }
}

void EnvPosix::SetBackGroundThread(int total_thread,int index) {
    thread_pools_[index].SetBackgroundThreads(total_thread);
}

tid EnvPosix::getThreadID() {
    return std::this_thread::get_id();
}

Env* Env::Default() {

    static EnvPosix env = EnvPosix{};
    return &env;
}

}