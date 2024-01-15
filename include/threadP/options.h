#include "env.h"


namespace THREADP {

class Options {
    public:

    void setBackgroundThread(int num);

    private:

    Env* env = Env::Default();
};

}
