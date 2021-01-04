#include <iostream>
#include <set>
#include <iterator>
#include <vector>
#include <algorithm>
#include <utility>
#include <bits/stdc++.h>


using namespace std;

typedef pair<int, int> iPair;
int main()
{
    vector<vector<int>> vec = {{1, 2, 3},
                             {1, 2, 5},
                             {3, 2, 1},
                             {6, 7, 8}};

    // Logic Count no of unique triange using Set
    // Sort the Numbers
    // Add it to set
    // Caclucale the size of set
    //
    int a, b, c, size;

    //set<pair<int, ipair>> s;
    set < pair< int, iPair > > s; 
    for(int i = 0; i < vec.size(); i++)
    {
        sort(vec[i].begin(), vec[i].end());
        s.insert({vec[i][0], {vec[i][1], vec[i][2]}});

        cout << "Vec is " << vec[i][0] << " " << vec[i][1] << " "<< vec[i][2];
        cout << endl;
    }
    cout << endl;
    cout << "Size is " <<s.size() << endl;
    return 0;
}
