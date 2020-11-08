#include <iostream>

using namespace std;

class Test {
    int x;
    int y;
    int &z;
    // Constructor
    public:
        Test(int a, int b, int &c) : x(a), y(b), z(c) {}

    void print()
    {
        cout << "x = " << x << " y = " << y << " z = " << z <<endl;
    }
    // Distructor
    ~Test() {}
};

int main()
{
    int z = 5;
    Test t(3, 7, z);
    t.print();
    return 0;
}
