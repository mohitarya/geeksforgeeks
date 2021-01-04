#include <iostream>
#include <include/mlib/syncQue.h>
#include <pthread.h>
#include <include/mlib/thread.h>

#define NTHREADS 8

using namespace std
using namespace mlib


struct result{
    int prime;
    int worker;
};

consumer(void *id)
{
    sleep(1);
    cout << "I am in consumer thread" << endl;
    cout << "Thread Id is " << *(int *)id << endl;
}

void prime_queue()
{
    // Create queue for numbers
    // Create queue for prime Numbers and its worker
    // who get that a number is prime
    sync_queue<int> num;
    sync_queue<result> primes;

    // Create thread
    thread *consumer[NTHREADS];
    //thread *producer[NTHREADS];
    
    pthread_t c_tid[NTHREADS];
    //pthread_t p_tid[NTHREADS];

    // Start consumer threads
    for (i=0; i < NTHREADS; i++)
    {
        consumer[i] = thread();
        consumer[i]->t_create(c_tid[i], consumer, i);
    }

    // Join all the threads
    for (i=0; i < NTHREADS; i++)
    {
        consumer[i]->t_join(c_tid[i]);
    }

}

int main()
{
    // prime number Queues
        // Create queue to hold prime No
        // Start Producer and consumer thread
        // Once all the prime number add to the queue
        // from the given rsnge then exit
    prime_queue();
}
