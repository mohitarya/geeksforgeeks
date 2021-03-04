// Reader Writer Problem
//
//   5-Reader 3-Writer accessing a shared resource
//   Multiple reader can access but Multiple writer can not
//   Reader reading the data and displaying with thread ID
//   Writer increament the data by 5
//   Every reader and writer in a loop and doing this for 5 time

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAXREADT 5
#define MAXWRITET 3
#define LOOPNO 5
#define SLEEP 1

// Shared Resource
int sharedData;

pthread_rwlock_t rwlockData;

// Read data Function
void *readData(void *tid)
{
    int id = *(int *)tid;
    int i;
    for(i =0; i < LOOPNO; i++)
    {
        // Take a read Lock
        pthread_rwlock_rdlock(&rwlockData);
        // Read the data
        printf("In read Fun ID = %d Data = %d\n", id, sharedData);

        pthread_rwlock_unlock(&rwlockData);
        sleep(1); 
    }
    pthread_exit(NULL);
}

void *writeData(void *tid)
{
    int id = *(int *)tid;
    printf("In write Fun ID = %d\n", id);
    // Take a read Lock
    pthread_rwlock_wrlock(&rwlockData);
    // Read the data
    printf("In write updating data id = %d\n", id);
    sharedData += 50;
    pthread_rwlock_unlock(&rwlockData);

    pthread_exit(NULL);
}
int main()
{
    int i, rc;
    pthread_t readthread[MAXREADT];
    pthread_t writethread[MAXWRITET];
    int id[MAXREADT + MAXWRITET];

    // init read write lock
    pthread_rwlock_init(&rwlockData, NULL);

    // Initalizing Read the thread
    for(i=0; i < MAXREADT; i++)
    {
        id[i] = i;
        rc = pthread_create(&readthread[i], NULL, readData, &id[i]);
        if(!rc)
        {
            printf("Read Thread Created with ID = %lu\n", readthread[i]);
        }
        else
        {
            printf("Read Thread Creation Failed for ID = %d\n", i);
        }
    }
    for(i=0; i < MAXWRITET; i++)
    {
        id[MAXREADT + i] = MAXREADT + i;
        rc = pthread_create(&writethread[i], NULL, writeData, &id[i + MAXREADT]);
        if(!rc)
        {
            printf("Write Thread Created with ID = %lu\n", writethread[i]);
        }
        else
        {
            printf("Write Thread Creation Failed for ID = %d\n", i);
        }
    }

    // Join the pthread
    for(i=0; i < MAXREADT; i++)
    {
        rc = pthread_join(readthread[i], NULL);
        if(!rc)
        {
            printf("Joining Read Thread  = %lu\n", readthread[i]);
        }
        else
        {
            printf("Joining Failed for Read Thread ID = %lu\n", readthread[i]);
        }
    }
    for(i=0; i < MAXWRITET; i++)
    {
        rc = pthread_join(writethread[i], NULL);
        if(!rc)
        {
            printf("Joining Write Thread  = %lu\n", writethread[i]);
        }
        else
        {
            printf("Joining Failed for Write Thread ID = %lu\n", writethread[i]);
        }
    }
    pthread_exit(NULL);
}
