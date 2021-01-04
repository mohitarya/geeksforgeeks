#include <iostream>
#include <pthread.h>

using namespace std;

namespace mlib{
    class thread{
        public:
            thread(){};

            // Create a thread
            void t_create(pthread_t &tid, void *func, int &id)
            {
                pthread_create(tid, 0, func, id);
            }

            void t_join(pthread_t tid)
            {
                pthread_join(tid);
            }
    };
};
