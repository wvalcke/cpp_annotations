#include <iostream>

using namespace std;

class Surround
{
    static int s_variable;
    public:
        class FirstWithin
        {
            friend class Surround;
            static int s_variable;  // identically named
            public:
                int value();
        };
        int value();

    private:
        class SecondWithin
        {
            friend class Surround;
            static int s_variable;  // identically named
            public:
                int value();
        };
        static void classMember();
};
inline int Surround::value()
{                                   // scope resolution expression
    FirstWithin::s_variable = SecondWithin::s_variable;
    return s_variable;
}
inline int Surround::FirstWithin::value()
{
    Surround::s_variable = 4;       // scope resolution expressions
    Surround::classMember();
    // we can do this as we are inside Surround, and Surround is a friend of SecondWithin
    SecondWithin::s_variable = 11;
    return s_variable;
}
inline int Surround::SecondWithin::value()
{
    Surround::s_variable = 40;      // scope resolution expression
    // also possible, see above 
    FirstWithin::s_variable = 90;
    return s_variable;
}

void Surround::classMember()
{

}

int Surround::FirstWithin::s_variable = 9;
int Surround::SecondWithin::s_variable = 10;

int main(int argc, char*argv[])
{

}

