#include <iostream>

using namespace std;

class Constructor {
    public:
        int a, b;

    // Default constructor have no function parameter
    //Constructor(){
    Constructor(int x, int y){
        //a = 10;
        //b = 20;
        a = x;
        b = y;
    }
};

int main()
{
    Constructor con(20,30);
    cout << "a = " << con.a << " b = " << con.b << endl;
    return 0;
}
