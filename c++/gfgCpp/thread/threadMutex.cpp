#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#define VECLEN 100
#define NUMTHREADS 4
// Global Structure

typedef struct _dotdata{
    double *x;
    double *y;
    double sum;
    int vecsize;
}DOTDATA;

DOTDATA gdata;
pthread_mutex_t myMutex;


void *dotproduct(void *tdata)
{
    int offset = *(int *)tdata;
    double *a, *b, tsum;
    int i, start, end, len;
    a = gdata.x;
    b = gdata.y;
    tsum = 0;
    len = gdata.vecsize;
    start = offset * len;
    end = start + len;
    printf("Start = %d...End = %d ID = %d\n", start, end, offset);
    for(i = start; i < end; i++)
    {
        tsum += (a[i] * b[i]);
    }
    
    // Add it to the shared Mem
    // Take the mutex Lock
    pthread_mutex_lock(&myMutex);
    printf("Updating global sum to = %lf\n", tsum);
    gdata.sum = tsum;
    pthread_mutex_unlock(&myMutex);

    pthread_exit(NULL);
}

int main()
{
    // Two Vec list of float numbers
    // Thread should do a dot product of the vec
    // Result should be saved in a variable which is memeber os the global structure
    // Above sturcture also have the vec list
    // Each thread should add its entry in mutually exclusive way

    // Driver Logic 
    // Fill up the data in the globla struct
    
    double *a, *b;
    int i;
    pthread_t thread[NUMTHREADS];
    int rc;
    void *res;
    int id[NUMTHREADS];
    
    pthread_mutex_init(&myMutex, NULL);
    // Assign the memory
    a = (double *)malloc(sizeof(double) * VECLEN * NUMTHREADS);
    b = (double *)malloc(sizeof(double) * VECLEN * NUMTHREADS);

    gdata.x = a;
    gdata.y = b;
    gdata.vecsize = VECLEN;
    gdata.sum = 0;
    
    // Insert the data to vec
    for(i = 0; i < VECLEN * NUMTHREADS; i++)
    {
        a[i] = 1.0 + (i / VECLEN);
        b[i] = a[i];
    }
    for(i = 0; i < VECLEN * NUMTHREADS; i++)
    {
        printf("%lf ", b[i]);
    }
    printf("\n");

    // Initialize the threads
    for (i = 0; i < NUMTHREADS; i++)
    {
        id[i] = i;
        rc = pthread_create(&thread[i], NULL, dotproduct, &id[i]);
        if(!rc)
        {
            printf("Successfully Create the thread with ID = %lu\n", thread[i]);
        }
        else
        {
            printf("Failed to create the thread\n");
        }
    }
    for (i = 0; i < NUMTHREADS; i++)
    {
        printf("%lu\n", thread[i]);
    }
    // Join the thread and display the result
    for(i = 0; i < NUMTHREADS; i++)
    {
        rc = pthread_join(thread[i], &res);
        if(!rc)
        {
            printf("Thread Joined Successfully %lu\n", thread[i]);
        }
        else
        {
            printf("Thread failed to join %lu\n", thread[i]);
        }
    }
    printf("Sum = %lf\n", gdata.sum);
    free(a);
    free(b);

    pthread_mutex_destroy(&myMutex);
    pthread_exit(NULL);
    return 0;
}
