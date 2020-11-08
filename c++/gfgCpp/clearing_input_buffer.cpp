#include<iostream>
#include <ios>
#include <limits>

using namespace std;

int main()
{
    int a;

    char str1[100];

    cin >> a;

    // discard input buffer
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    //
    //cin.sync() Not working
    //cin.sync();
    //
    // cin >> ws working fine 
    //cin >> ws;

    cin.getline(str1, 100);

    cout << a << endl;

    cout << str1 << endl;

    return 0;
}
