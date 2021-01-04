#include <iostream>
#include <queue>

using namespace std;

namespace mlib{
    
    // Using the template for queue
    // for generic queue implementation
    // Queue is not bounded
    //
    template <class M, class C=deque<M>>
    class sync_queue : protected queue<M, C>
    {
        public:
            // Constructor
            // Currently Nothing to do in constructor
            sync_queue(){};

    };

};
