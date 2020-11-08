#include <iostream>

using namespace std;

class Complex
{
    private:
        int real;
        int imag;

    public:
        Complex(int x=0, int y=0) : real(x), imag(y) {}
        friend ostream &operator << (ostream &out, Complex &c);
        friend istream &operator >> (istream &in, Complex &c);
};

ostream &operator << (ostream &out, Complex &c)
{
    out << c.real;
    out << " +i" << c.imag << endl;
    return out;
}

istream &operator >> (istream &in, Complex &c)
{
    cout << "Input Real No.";
    in >> c.real;
    cout << "Input Imaginary No.";
    in >> c.imag;
    return in;
}

int main()
{
    Complex c1;
    cin >> c1;
    cout << c1;
    return 0;
}
