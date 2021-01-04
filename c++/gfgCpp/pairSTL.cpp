#include <iostream>
#include <utility>
#include <algorithm>
#include <bits/stdc++.h>
#include <tuple>

using namespace std;

int main()
{
    //pair<int, int> pair1(20, 30);
    pair<string, double> pair1;
    pair1 = make_pair("Hello", 5.6);
    pair<string, double> pair2;
    pair2 = make_pair("Follow", 2.3);

    // Swap of pairs
    //pair1.swap(pair2);
    swap(pair1, pair2);  
    //pair1 = pair2;

    //pair1.first = 10;
    //pair1.second = 50;
    int y;
    string x;
    tie(x, y) = pair1;

    cout << "First =" << pair1.first << endl;
    cout << "Second =" << pair1.second << endl;
    cout << "x =" << x << "y " << y << endl;
    return 0;
}
