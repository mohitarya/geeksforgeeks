#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>

void *thread1_fun(void *);
// Global variable which can be acced from thread
char msg[] = "I am in a global value";

int main()
{
    // initializing thread Id variable
    pthread_t thread1;
    void *exit_msg;
    int ret;
    // creating the thread function
    ret = pthread_create(&thread1, NULL, thread1_fun, (void *)msg);
    if(ret != 0){
        printf("Failed to create a thread return value = %d, errono = %d\n", ret, errno);        return 1;   
    }
    printf("Thread ID = %ld\n", thread1);
    pthread_join(thread1, &exit_msg);
    printf("Exit message from thread1 is %s\n", (char *)exit_msg);
    printf("Changes global msg is %s\n", msg);
}

void *thread1_fun(void *msg1)
{
    printf("In thread execution\n");
    printf("Message recived = %s\n", (char *)msg1);
    strcpy(msg, "msg");
    pthread_exit("thread1 completed");
}
