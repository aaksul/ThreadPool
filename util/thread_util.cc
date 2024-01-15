#include "thread_util.h"
#include "monitoring/thread_status_updater.h"

namespace THREADP {


    thread_local ThreadStatusUpdater* ThreadUtil::thread_local_updater_cache = nullptr;



    void ThreadUtil::RegisterThread(Env* env, uint64_t thread_id) {
        //get env thread status updater which holds table
        if (MaybeInitThreadStatusUpdater(env)) {
            return;
        }
        thread_local_updater_cache->RegisterThread(1,env->getThreadID());
    }

    bool ThreadUtil::MaybeInitThreadStatusUpdater(Env* env) {
        if (env != nullptr) {
            thread_local_updater_cache= env->GetThreadStatusUpdater();
        }
        return (thread_local_updater_cache != nullptr);
    }


}