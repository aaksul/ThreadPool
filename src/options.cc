#include "threadP/options.h"


namespace THREADP {
    void Options::setBackgroundThread(int num) {
        env->SetBackGroundThread(num-3,0);
        env->SetBackGroundThread(1,1);
        env->SetBackGroundThread(1,2);
        env->SetBackGroundThread(1,3);
    }
}