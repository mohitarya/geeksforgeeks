#include <iostream>

using namespace std;


class Complex
{
    private:
        int real;
        int imag;

    public:
        Complex(int x=0, int y=0): real(x), imag(y) {}
        // Operator overloading between two objects
        //Complex operator + (Complex const &obj)
        //{
        //    cout << "In class operator fun" << endl;
        //    Complex newObj;
        //    newObj.real = real + obj.real;
        //    newObj.imag = real + obj.imag;
        //    return newObj;
        //}
        
        void print()
        {
            cout << "Complex No is = " << real << " +" << imag << "i" << endl;
        }
        // GLobal operator function
        friend Complex operator + (Complex const &obj1, Complex const &obj2);
};
// Global Opearator fun

Complex operator + (Complex const &obj1, Complex const &obj2)
{
    cout << "In global operator fun" << endl;
    return Complex((obj1.real + obj2.real), (obj1.imag + obj2.imag));
}


int main()
{
    Complex c1(5, 10), c2(20, 30);
    Complex c3 = c1 + c2;
    c3.print();
    return 0;
}
