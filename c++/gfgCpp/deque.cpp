#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void printDeq(deque<int> q)
{
    deque<int>::iterator it;
    for(it=q.begin(); it != q.end(); it++)
    {
        cout << " " << *it;
    }
    cout << endl;
}

int main()
{
    deque<int> q1;

    q1.push_back(20);
    q1.push_back(10);
    q1.push_front(5);
    q1.push_front(7);
    printDeq(q1);

    cout << "Size = " << q1.size() << endl;
    cout << "Max Size = " << q1.max_size() << endl;
    cout << "at(2) = " << q1.at(2) << endl;
    cout << "Front = " << q1.front() << endl;
    cout << "Back = " << q1.back() << endl;

    // Pop from Front
    q1.pop_front();
    printDeq(q1);

    // Pop from back 
    q1.pop_back();
    printDeq(q1);


    // Insert element to deque

    // Methos 1
    q1.insert(q1.begin(), 22);
    printDeq(q1);

    std::deque<int>::iterator it = q1.begin();
    advance(it, 2);
    // Method 2
    q1.insert(it, 3, 77);
    printDeq(q1);


    // Method 3
    vector<int> v1 = {1, 2,3,4,5,6,7};

    q1.insert(it, v1.begin(), v1.end());
    printDeq(q1);
    return 0;
}
