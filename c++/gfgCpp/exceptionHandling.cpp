#include <iostream>
#include <typeinfo>
#include <cstring>

using namespace std;

class PolyM
{
    virtual void member(){}
};

int main()
{
    int x = -1;

    cout << "Before exceptioon Handeling Try statement" << endl;

    try
    {
        PolyM *pb = 0;
        typeid(*pb);
    }
    
    catch (exception &e)
    {
        cout << "Exception Caught: " << e.what() << endl;
    }

    try
    {
        cout << "In try" << endl;
        if(x < 0)
        {
            char *p;
            p = new char[10];
            strcpy(p, "Hello");
            throw p;
            cout << "After throw (Never executed)" << endl;
        }
    }
    //catch (int x)
    catch (char *str)
    {
        cout << "In CAtch string " << str <<endl;
    }

    catch (...)
    {
        cout << "In CAtch" << endl;
    }
    cout << "After Catch All good" << endl;
    return 0;
}
