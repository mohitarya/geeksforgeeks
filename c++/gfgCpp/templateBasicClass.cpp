#include <iostream>

using namespace std;

template <typename T>
class Array
{
    T *ptr;             // Generic Pointer to array
    int size;           // Size of the array

    public:
        Array(T *p, int sz);
        void print();
};

template <typename T>
Array<T>::Array(T *p, int sz)
{
    ptr = new T[sz];
    size = sz;
    if(ptr)
    {
        for(int i=0; i < size; i++)
        {
            *(ptr + i) = *(p + i);
        }
    }
}

template <typename T>
void Array<T>::print()
{
    for(int i=0; i< size; i++)
    {
        cout << *(ptr + i) << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 50, 45, 34, 23, 32};
    Array<int> a(arr, 7);
    a.print();
    return 0;
}
