#pragma once
#include <thread>


namespace THREADP {

class ThreadStatusUpdater;


class Env {

    public:

    
    Env() {}

    ~Env() = default;

    static Env* Default();

    virtual uint64_t getThreadID() = 0;

    virtual void SetBackGroundThread(int num,int index=0) = 0;

    virtual ThreadStatusUpdater* GetThreadStatusUpdater() const {
        return thread_status_updater_;
    }

    protected:

    ThreadStatusUpdater* thread_status_updater_;
};


}