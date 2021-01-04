#include <iostream>
#include <set>
#include <iterator>

using namespace std;


void printSet(set<int> s1)
{
    set<int>::iterator it;
    for(it=s1.begin(); it != s1.end(); it++)
    {
        cout << " " << *it;
    }
    cout << endl;
}

int main()
{
    set<int> s1;
    s1.lower_bound(10);

    s1.upper_bound(70);

    s1.insert(45);
    s1.insert(5);
    s1.insert(75);
    s1.insert(20);
    s1.insert(10);
    s1.insert(5);

    printSet(s1);

    s1.erase(10);
    printSet(s1);

    // Set Upper Bound and Lower Bound
    printSet(s1);

    s1.insert(2);
    return 0;
}
