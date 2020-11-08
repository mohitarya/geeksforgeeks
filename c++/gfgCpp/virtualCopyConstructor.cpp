#include <iostream>

using namespace std;

// How to create derived1 or derived2 object
// From Pointer reference to base class pointing derived object

class Base {
    public:
        //Constrcutor
        Base() {};

        // Virtual Cunstructor
        static Base *create(int id);

        virtual Base *clone() = 0;
        virtual void changeAttributes() = 0;
        virtual ~Base()
        {
            cout << "Base class distructor" << endl;
        }

};

class Derived1 : public Base
{
    public:
        Derived1()
        {
            cout << "In Derived1 Cons " << endl;
        }
        Derived1(const Derived1 &rhs)
        {
            cout << "In Derived1 copy cons" << endl;
        }
        ~Derived1()
        {
            cout << "In Derived1 Dest" << endl;
        }
        Base *clone()
        {
            return new Derived1(*this);
        }
        void changeAttributes()
        {
            cout << "In Fun Derived1 changeAttributes()" << endl;
        }
};

class Derived2 : public Base
{
    public:
        Derived2()
        {
            cout << "In Derived2 Cons " << endl;
        }
        Derived2(const Derived2 &rhs)
        {
            cout << "In Derived2 copy cons" << endl;
        }
        ~Derived2()
        {
            cout << "In Derived2 Dest" << endl;
        }
        Base *clone()
        {
            return new Derived2(*this);
        }
        void changeAttributes()
        {
            cout << "In Fun Derived2 changeAttributes()" << endl;
        }

};


class Derived3 : public Base
{
    public:
        Derived3()
        {
            cout << "In Derived3 Cons " << endl;
        }
        Derived3(const Derived2 &rhs)
        {
            cout << "In Derived3 copy cons" << endl;
        }
        ~Derived3()
        {
            cout << "In Derived3 Dest" << endl;
        }
        Base *clone()
        {
            return new Derived3(*this);
        }
        void changeAttributes()
        {
            cout << "In Fun Derived3 changeAttributes()" << endl;
        }

};


Base *Base::create(int id)
{
    // if-lese ladder
    if(id == 1)
    {
        return new Derived1;
    }
    else if(id == 2)
    {
        return new Derived2;
    }
    else if(id == 3)
    {
        return new Derived3;
    }
}

class User
{
    private:
        Base *pBase;
    public:
        User() : pBase(0)
    {
        // Create any object of base heirarchey
        int input;

        cout << "Input an ID (1 or 2 or 3)" << endl;
        cin >> input;
        while(input != 1 && input != 2 && input != 3)
        {
            cout << "Input an ID (1 or 2 or 3)" << endl;
            cin >> input;
        }

        // Create object via virtual cunstructor
        pBase = Base::create(input);
    }

    void action()
    {
        // Duplicate current object

        Base *newPBase = pBase->clone();
        newPBase->changeAttributes();
        delete newPBase;
    }

    ~User()
    {
        if (pBase)
        {
            delete pBase;
            pBase = 0;
        }
    }
};


int main()
{
    User *user = new User();

    // Virtual copy constructor which create a copy
    user->action();

    if(user)
    {
        delete user;
        user = 0;
    }
    return 0;
}
