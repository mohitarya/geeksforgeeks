#include <iostream>
#include <algorithm>

using namespace std;

// all_of checkes a given property on all of the array
// Comple it like :: "gcc -std=gnu++11 stlArrayAlgoAll_of.cpp -lstdc++"

int main()
{
    int arr[] = {3, 4, 6, 7, -4, 1, 3, 5, 50};
    int size = sizeof(arr)/sizeof(arr[0]);
    int arr1[size];

    all_of(arr, arr+size, [](int x) {return (x > 0);}) ? cout << "All are positive elements" << endl : cout << "All elements are not positive" << endl;


// any_of :: any element satisfying the given property
    any_of(arr, arr+size, [](int x) {return (x == 0);}) ? cout << "Property Satisfied" << endl : cout << "Not Property Satisfied " << endl;

//  none_of :: return true of none satisfied the property
    any_of(arr, arr+size, [](int x) {return (x == 0);}) ? cout << "No Zero Property Satisfied" << endl : cout << "No Zero property not Satisfied " << endl;

// copy_n :: copy n elements to new array
    copy_n(arr, size, arr1); 

    for(int i=0; i< size; i++)
    {
        cout << " " << arr1[i];
    }
    cout << endl;

// iota :: assign continuous values to array
    iota(arr1, arr1+size, 10);

    for(int i=0; i< size; i++)
    {
        cout << " " << arr1[i];
    }
    cout << endl;

    return 0;
}
