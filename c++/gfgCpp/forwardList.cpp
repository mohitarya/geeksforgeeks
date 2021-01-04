#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
    forward_list<int> l1, l2;

    l1.assign({1, 2, 3});
    l2 = {0, 55, 66, 77};

    l1.assign(5, 10);

    l1.push_front(20);

    l1.emplace_front(30);

    l1.pop_front();
    
    forward_list<int>::iterator it;


    it = l1.insert_after(l1.begin(), 44);
    advance(it, 2);

    l1.insert_after(it, 44);

    //l1.erase_after(it);

    l1.remove(55);

    //l1.remove_if([](int x) {return x == 10;});
    //
    //Transfer element from one list (here l1) to other list (here l2) from iterator position provided ( herel2.begin())
    //l2.splice_after(l2.begin(), l1);

    l2 = l1;

    //l2.merge(l1);
    //
    //
    //Sort and unique
    l1.sort();
    l1.unique(); 

    l1.reverse();
    l2.swap(l1);

    l1.clear();

    cout << "Empty " << ((l1.empty()) ? "True" : "False") << endl;
    cout << "Empty " << ((l2.empty()) ? "True" : "False") << endl;

    //print
    for(int &a : l1)
    {
        cout << " " << a;
    }
    cout << endl;

    //print
    for(int &b : l2)
    {
        cout << " " << b;
    }
    cout << endl;

    return 0;
}
