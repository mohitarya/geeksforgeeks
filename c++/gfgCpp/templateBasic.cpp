#include <iostream>

using namespace std;

template <typename T>

T mymax(T x, T y)
{
    return (x > y) ? x : y;
}

int main()
{
    cout << mymax<int>(7, 6) << endl;
    cout << mymax<char>('a', 'b') << endl;
    cout << mymax<float>(3.5, 3.6) << endl;
    return 0;
}
