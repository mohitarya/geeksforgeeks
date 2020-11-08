#include <iostream>

using namespace std;

class Base
{
    public:
        Base() {};

        void fun()
        {
            cout << "In Base class fun " << endl;
        }
        void fun() const
        {
            cout << "In BAse class fun const" << endl;
        }
        void fun2(const int &i)
        {
            cout << "In Base class const int &i" << endl;
        }
        void fun2(int &i)
        {
            cout << "In Base class int &i" << endl;
        }

};
    

int main()
{
    Base s1;
    const Base s2;
    s1.fun();
    s2.fun();
    int i = 5;
    s1.fun2(i);
    return 0;
}
