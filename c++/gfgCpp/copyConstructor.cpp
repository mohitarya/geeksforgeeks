#include <iostream>

using namespace std;

class Point {
    private:
        int x, y;

    public:
        // Constructor
        Point(int a, int b) {
            x = a;
            y = b;
        }
        // Copy Constructor
        //Point (Point &p2){
        //    x = p2.x;
        //    y = p2.y;
        //}

        void print(){
            cout << "x = " << x << "y = " <<y << endl;
        }
};

int main()
{
    Point p1(10, 20);
    p1.print();

    Point p3(p1);
    p3.print();
    return 0;
}
