// Thread Sync using Condition variable
//
// Problem Statement::
//  Main routine creates 3 thread
//  Two of the threads perform work and update a count variable
//  Third thread waits untill the count reaches to a specific value
//
//


#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


#define NUMTHREAD 3
#define SPECCONDCOUNT 12

// Shared Resource
int count;
pthread_mutex_t myMutex;
pthread_cond_t count_thrh_cv;

void *incCount(void *tid)
{
    int i;
    int id = *(int *)tid;
    for(i = 0; i < 10; i++){
        count++;
        pthread_mutex_lock(&myMutex);
        if(count == SPECCONDCOUNT)
        {
            pthread_cond_signal(&count_thrh_cv);
            printf("Signalling to other thread\n");
        }
        pthread_mutex_unlock(&myMutex);
        sleep(1);
   }
   pthread_exit(NULL);
}

void *waitforCond(void *tid)
{
    int id = *(int *)tid;
    printf("Starting watch Count\n");
    pthread_mutex_lock(&myMutex);
    while(count < SPECCONDCOUNT)
    {
        pthread_cond_wait(&count_thrh_cv, &myMutex);
        printf("Signal Recived:: tid = %d\n", id);
    }
    count = count + 125;
    pthread_mutex_unlock(&myMutex);
    printf("Count Now is  count = %d , id = %d\n", count, id);
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread[NUMTHREAD];
    int id[NUMTHREAD];
    
    // Initialize the mutex
    pthread_mutex_init(&myMutex, NULL);
    //Initialize Cond Var
    pthread_cond_init(&count_thrh_cv, NULL);
    // Create 3 threads
    pthread_create(&thread[0], NULL, incCount, &id[0]);
    pthread_create(&thread[1], NULL, incCount, &id[1]);
    pthread_create(&thread[2], NULL, waitforCond, &id[2]);

    // Join the threads
    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);
    pthread_join(thread[2], NULL);

    pthread_exit(NULL);
    return 0;
}
