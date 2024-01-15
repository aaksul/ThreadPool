#include <mutex>
#include <unordered_set>

namespace THREADP
{

struct ThreadStatusData
{
    uint64_t hash_t;
    int thread_type;
};

class ThreadStatusUpdater
{
public:
    ThreadStatusUpdater() {}

    virtual ~ThreadStatusUpdater() {}

    void RegisterThread(int thread_type, uint64_t thread_id);

private:
    static thread_local ThreadStatusData* thread_status_data_;

    std::mutex thread_list_mutex_;

    std::unordered_set<ThreadStatusData*> thread_status_set_;
};

} // namespace THREADP
