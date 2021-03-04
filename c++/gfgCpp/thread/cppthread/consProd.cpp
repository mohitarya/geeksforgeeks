#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <counting_semaphore>

using namespace std;

queue<int> data;

mutex pcm;

counting_semaphore empty(5);
counting_semaphore full(0);

void producer()
{
    cout << "In producer" << endl;
    empty.acquire();
    pcm.lock();
    data.push(5);
    pcm.unlock();
    full.release();
}

void consumer()
{
    cout << "In consumer" << endl;
    full.acquire();
    pcm.lock();
    if(!data.empty())
    {
        cout << "Cons Data is " << data.front() << endl;
        data.pop();
    }
    pcm.unlock();
    empty.release();
}

int main()
{
    // Create two thread
    // thread1 - Producer
    // thread2 - Consumer

    thread prodT(producer);
    thread consT(consumer);

    prodT.join();
    consT.join();
    return 0;
}
