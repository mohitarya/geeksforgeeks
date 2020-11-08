#include <iostream>
#include <cstdlib>

using namespace std;

class Array
{
    int *p;
    int size;

    public:
        Array(int *, int);
        int &operator [] (int index);
        void print() const;
};

Array::Array(int *ptr, int s)
{
    size = s;
    p = NULL;
    if(s != 0)
    {
        p = new int[s];
        for(int i=0; i < s; i++)
        {
            p[i] = ptr[i];
        }
    }
}

int &Array::operator [] (int index)
{
    if(index >= size)
    {
        cout << "Out of bound" << endl;
        exit(0);
    }
    return p[index];
}

void Array::print() const
{
    for(int i=0; i < size; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[] = {0,1,2,3,4,5,6,7};
    Array a1(a, 8);
    a1.print();
    a1[5] = 50;
    a1.print();
    a1[10] = 25;
    return 0;
}
