#include <iostream>

class BaseClass
{
    public:
        // BaseClass constructor(s)
        BaseClass()
        {
            std::cout << "BaseClass constructor" << '\n';
        }
        BaseClass(int p)
        {
            std::cout << "BaseClass constructor (int) " << p << '\n';
        }
};

class DerivedClass: public BaseClass
{
    public:
        using BaseClass::BaseClass; // No DerivedClass constructors
                                    // are defined
};

class DerivedClass2: public BaseClass
{
public:
    // using declaratie moet er niet expliciet staan, zolang we zelf geen constructor definieren
    // in de afgeleide klasse
};

class DerivedClass3: public BaseClass
{
public:
    DerivedClass3(std::string p)
    : BaseClass()
    {

    }

    // dit moet er nu wel expliciet staan, want anders hebben we geen default constructor 
    // van DerivedClass3, maw DerivedClass2 myobject; zal niet compileren
    using BaseClass::BaseClass;
};

int main(int argc, char*argv[])
{
    DerivedClass d1;
    DerivedClass d2(6);

    DerivedClass2 d3;
    DerivedClass2 d4(7);

    DerivedClass3 d5;
}

