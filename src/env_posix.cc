#include <vector>
#include <thread>

#include "threadP/env.h"
#include "util/thread_pool.h"
#include "monitoring/thread_status_updater.h"
namespace THREADP {

ThreadStatusUpdater* CreateThreadStatusUpdater() {
    return new ThreadStatusUpdater();
}

class EnvPosix : public Env {
    public:

    EnvPosix();

    virtual void SetBackGroundThread(int total_thread,int index) override;

    virtual uint64_t getThreadID() override;

    friend Env* Default();

    struct JoinThreadsOnExit {
        JoinThreadsOnExit(EnvPosix& env_to_exit) : env_to_exit_{env_to_exit} {} 
        ~JoinThreadsOnExit() {
            for (int i = 0; i < env_to_exit_.thread_pools_.size(); i++) {
                env_to_exit_.thread_pools_[i].JoinAllThreads();
            }
        }

        EnvPosix& env_to_exit_;
    };

    private:
    std::vector<ThreadPool> thread_pools_;

};

EnvPosix::EnvPosix() : thread_pools_(4) {
    for (ThreadPool& tP : thread_pools_) {
        tP.SetHostEnv(this);
    }
    thread_status_updater_ = CreateThreadStatusUpdater();
}

void EnvPosix::SetBackGroundThread(int total_thread,int index) {
    thread_pools_[index].SetBackgroundThreads(total_thread);
}

uint64_t EnvPosix::getThreadID() {
    std::hash<std::thread::id> hasher;
    return hasher(std::this_thread::get_id());
}

Env* Env::Default() {

    static EnvPosix& env = *new EnvPosix();
    static EnvPosix::JoinThreadsOnExit join_thread{env};
    return &env;
}

}