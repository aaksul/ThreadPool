#include "thread_status_updater.h"


namespace THREADP
{
    thread_local ThreadStatusData* ThreadStatusUpdater::thread_status_data_ = nullptr;
    
    void ThreadStatusUpdater::RegisterThread(int ttype, uint64_t thread_id) {
        thread_status_data_ = new ThreadStatusData();
        thread_status_data_->hash_t = thread_id;
        thread_status_data_->thread_type = ttype;
        std::lock_guard<std::mutex> lck(thread_list_mutex_);
        thread_status_set_.insert(thread_status_data_);
    }
    
} // namespace THREADP
