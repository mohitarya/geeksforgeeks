#include <iostream>
#include <queue>

using namespace std;

void printQ(priority_queue<int> que)
{
    priority_queue<int> q = que;
    while(!q.empty())
    {
        cout << " " << q.top();
        q.pop();
    }
    cout << endl;
}

int main()
{
    //queue<int> q1;
    priority_queue<int> q1;
    q1.push(10);
    q1.push(20);
    q1.emplace(30);
    q1.push(40);
    q1.emplace(50);

    cout<< q1.top() << endl;

    printQ(q1);


    return 0;
}

