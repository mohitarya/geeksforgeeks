#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string s = "Hello:My:Friend";

    string substr;
    int pos;

    pos = s.find(':');
    cout << "position is " << pos << endl;

    substr = s.substr(pos+1, 2);

    cout << "Sub String After : is = " << substr << endl;
    return 0;
}
