#pragma once
#include "threadP/env.h"

namespace THREADP {

class ThreadStatusUpdater;

class ThreadUtil{

public:

    static void RegisterThread(Env* env, uint64_t thread_id);

    static bool MaybeInitThreadStatusUpdater(Env* env);

    static thread_local ThreadStatusUpdater* thread_local_updater_cache;
    
};

}