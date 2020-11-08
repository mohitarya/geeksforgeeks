#include <iostream>

using namespace std;


// Namespace gives the scope to the named data and functions scope

namespace ns
{
    int data;

    class Base
    {
        public:
        int x;
        void display()
        {
            cout << "Namespace -> Base -> display" << endl;
        }
    };
}

int main()
{
    ns::Base b1;
    b1.display();
    return 0;
}
