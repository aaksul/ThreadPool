#include "thread_util.h"

namespace THREADP {


    ThreadStatusUpdater* ThreadUtil::thread_local_updater_cache = nullptr;



    void ThreadUtil::RegisterThread(Env* env, tid thread_id) {
        //get env thread status updater which holds table
        //create an entry
        //lock mutex of table
        //update table with thread_id information.
    }


}