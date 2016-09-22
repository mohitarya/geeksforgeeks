#include <stdio.h>
#include <pthread.h>

void *print(void *);

int main()
{
    pthread_t thread1, thread2;
    int ret_val;
    // Initializing the variables for thread
    char *arg1 =" I am for thread 1";
    char *arg2 = "I am for thread 2";

    //Creating the thread
    ret_val = pthread_create(&thread1, NULL, print, (void *)arg1);
    printf("Thread 1 ID is %ld\n", thread1);
    ret_val = pthread_create(&thread2, NULL, print, (void *)arg2);
    printf("Thread 2 ID is %ld\n", thread2);

    // Joining the thread
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

// Function to execute under thread
void *print(void *msg)
{
    printf("In thread = %ld\n", pthread_self);
    printf("Message = %s\n", msg);
}
