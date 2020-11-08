#include <iostream>

using namespace std;

class B
{
    virtual void fun(){}
};

class D : public B
{};

int main()
{
    B *b = new D;
    D *d = dynamic_cast<D*>(b);
    if (d != NULL)
    {
        cout << "Works" << endl;
    }
    else
    {
        cout << "Not Work" << endl;
    }
    return 0;
}
