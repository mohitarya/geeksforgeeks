#include <iostream>
#include <algorithm>
#include <vector>

// Comple it using 
// gcc -std=c++11 partitionOpration.cpp -lstdc++

using namespace std;

int main()
{
    vector<int> arr = {1, 2, 5, 6, 8, 2, 4, 10};

    is_partitioned(arr.begin(), arr.end(), [](int x)
            {
                return x%2;
            })?
            cout << "Partitioned" << endl:
                cout << "Not Partitioned" << endl;
    // Partitioning vector using partition
    partition(arr.begin(), arr.end(), [](int x)
            {
                return x%2;
            });
    cout << "The partitioned vect is" << endl;
    for(int &x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
