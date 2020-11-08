#include <iostream>

using namespace std;

class Circle {
    protected:
        int pro_var;
    public:
        float r;

    //private:
        double area()
        {
            return 3.14 * r * r;
        }

        double perimeter(float radius)
        {
            r = radius;
            return 2 * 3.14 * radius;
        }
        void func()
        {
            cout << "Without param" << endl;
        }
        void func(int xx)
        {
            cout << "With param int xx = " << xx << endl;
        }
        void func(double xx)
        {
            cout << "With param int xx = " << xx << endl;
        }


};

class Shape : public Circle {
    public:
        void setId(int id)
        {
            pro_var = id;
        }

        void printID()
        {
            cout << "ID = " << pro_var << endl;
            cout << "r = " << r << endl;
            cout << "area = " << area() << endl;
        }
};

int main()
{
    double area;
    double p;
    Circle cirObj;
    cirObj.func();
    cirObj.func(45);
    cirObj.func(45.5);
    p = cirObj.perimeter(5);
    cout << "perimeter = " << p << endl;
    area = cirObj.area();
    cout << "Area = " << area << endl;
    Shape s;
    s.setId(50);
    s.r = 10;
    s.printID();
    return 0;
}
