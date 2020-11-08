#include <iostream>

using namespace std;

class Base
{
    int x;
    int &ref;

    public:
        Base(int a=0) : x(a), ref(x) {}

        void print() 
        {
            cout << ref << endl;
        }

        void setX(int b)
        {
            x = b;
        }
        Base &operator = (const Base &obj)
        {
            x = obj.x;
            return *this;
        }
};

int main()
{
    Base t1(5);
    Base t2(10);
    t2 = t1;
    t1.setX(15);
    t2.print();
    return 0;
}
