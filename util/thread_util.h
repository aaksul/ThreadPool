#include "threadP/env.h"

namespace THREADP {

class ThreadStatusUpdater;

class ThreadUtil{

public:

    static void RegisterThread(Env* env, tid thread_id);

    static thread_local ThreadStatusUpdater* thread_local_updater_cache;

};

}