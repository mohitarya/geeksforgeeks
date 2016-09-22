#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print(void *);

int main()
{
    pthread_t thread1;
    int ret_val= -1;
    int *thread_ret = NULL;
    char *msg = "Hello Ji Ki hal hai";
    // Creating the thread
    
    ret_val = pthread_create(&thread1, NULL, print, (void *)msg);
    printf("Thread ID = %ld\n", thread1);

    // Joining the thread
    pthread_join(thread1, (void **)&thread_ret);
    printf("Returned value is %d\n", *thread_ret);
    return 0;
}

void *print(void *msg)
{
    int *pthread_status;
    pthread_status = (int *)malloc(sizeof(int));
    *pthread_status = 5;
    printf("I am in print for thread1\n");
    printf("msg = %s\n", (char *)msg);
    pthread_exit((void *)pthread_status);
}
