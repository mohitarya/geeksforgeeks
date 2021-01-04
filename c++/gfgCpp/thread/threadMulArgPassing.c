#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 5

void *fun(void *tid)
{
    int id = *(int *)tid;
    printf("Hello World %d\n", id);
    //pthread_exit(NULL);
}

int main()
{
    // Driver Fundtion
    // What needs to be implement
    //  Create 5 threads
    //  Each thread should print "Hello World msg with the thread ID"

    pthread_t thread[NUM_THREADS];

    int t[NUM_THREADS];
    int i;
    for (i = 0; i < NUM_THREADS; i++)
    {
        int res;
        t[i] = i;
        res = pthread_create(&thread[i], NULL, fun, &t[i]);
        if(res == 0)
        {
            printf("Thread created Successfully ID = %d\n", i);
        }
        else
        {
            printf("Thread creation Fail Id = %d\n", i);
        }
    }
    // If pthread_exit() in main thread then main process exit
    // and it allows other thread to continue 
    pthread_exit(NULL);
}
