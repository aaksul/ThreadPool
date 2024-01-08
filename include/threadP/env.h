#include <thread>


namespace THREADP {

typedef std::thread::id tid;

class Env {

    public:

    
    Env();

    static Env* Default();

    virtual tid getThreadID() = 0;

    virtual void SetBackGroundThread(int num,int index=0) = 0;
};


}