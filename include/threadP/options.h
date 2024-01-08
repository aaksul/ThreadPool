#include "env.h"


namespace threadP {

class Options {


    void setBackgroundThread(int num);

    private:

    Env* env = Env::Default();
};

}
