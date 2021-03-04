#include <iostream>

using namespace std;

void fun(int arr3[2][3])
{
    cout << arr3 << endl;
    cout << &arr3 << endl;
    cout << arr3 + 1 << endl;
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = arr;
    int arr1[2][3] = {{1, 2, 3},{4, 5, 6}};
    int (*p1)[3] = arr1;
    int ** p2;
    int i;
    p2 = (int **) malloc(sizeof(int *) * 5);
    for(i = 0; i < 5; i++)
    {
        *(p2 + i) = (int *) malloc(sizeof(int) * 5);
    }
    cout << "arr = " << arr << " arr+1" << arr+1 << " arr[0] = " << arr[0] << endl;
    cout << "*p++" << *p++ << endl;
    cout << "*++p "<< *++p << endl;
    cout << "arr1 " << arr1[0][0] << endl;
    cout << "p1 " << *(*(p1+1)+0) << endl;
    cout << "*****" << endl;
    cout << arr1 << endl;
    cout << &arr1 << endl;
    cout << arr1 + 1 << endl;
    fun(arr1);
    return 0;
}
