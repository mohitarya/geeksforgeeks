#include <iostream>
#include <algorithm>

using namespace std;

void print(int *p, int size)
{
    for(int i=0; i < size; i++)
    {
        cout << *(p+i) << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {4, 10, 5, 9, 10, 6, 2, 8};

    cout << "before Sorting" << endl;
    print(arr, 8);

    cout << "After Sorting" << endl;
    sort(arr, arr + 8);
    print(arr, 8);

    if(binary_search(arr, arr + 8, 5))
    {
        cout << "Element found in array" << endl;
    }
    else
    {
        cout << "Element Not found in array" << endl;
    }
    if(binary_search(arr, arr + 8, 50))
    {
        cout << "Element found in array" << endl;
    }
    else
    {
        cout << "Element Not found in array" << endl;
    }



    return 0;
}
