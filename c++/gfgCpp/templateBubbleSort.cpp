#include <iostream>

using namespace std;

template <typename T>
void bubbleSort(T *p, int size)
{
    for(int i=0; i < size; i++)
    {
        for(int j=0; j < (size - i - 1); j++)
        {
            // Bubble Sort Logic
            if(*(p + j) > *(p + j + 1))
            {
                swap(*(p + j), *(p + j + 1));
            }
        }
    }
}

int main()
{
    int arr[] = {1, 5, 6, 2, 10, 5, 8};
    bubbleSort<int>(arr, 7);
    for(int i=0; i < 7; i++)
    {
        cout << " " << arr[i];
    }
    cout << endl;

    char arr1[] = {'a', 'z', 'p', 't', 'b', 's', 'y'};
    bubbleSort<char>(arr1, 7);
    for(int i=0; i < 7; i++)
    {
        cout << " " << arr1[i];
    }
    cout << endl;

    float arr3[] = {1.1, 5.8, 1.2, 2.3, 2.1, 5.2, 8};
    bubbleSort<float>(arr3, 7);
    for(int i=0; i < 7; i++)
    {
        cout << " " << arr3[i];
    }
    cout << endl;


    return 0;
}
