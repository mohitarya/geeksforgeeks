#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    char s1[] = "Hello Boss";
    char s2[] = "Hi";
    bool result;
    //cout << sizeof(s1) << endl;
    result = lexicographical_compare(s1, s1+sizeof(s1)-1, s2, s2+sizeof(s2)-1);
    if(result){
        cout << "s1 is lexicographical smaller then s2" <<endl;
    }
    else{
        cout << "s2 is lexicographical smaller then s1" << endl;
    }
    return 0;
}
