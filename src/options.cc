#include "threadP/options.h"


namespace threadP {
    void Options::setBackgroundThread(int num) {
        env->SetBackGroundThread(num);
    }
}