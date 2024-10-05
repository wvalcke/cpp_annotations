#include <iostream>

using namespace std;

class SecondWithin;

class Surround
{
    // class SecondWithin;      not required (but no error either): 
    //                          friend declarations (see below)
    //                          are also forward declarations

    static int s_variable;
    public:
        class FirstWithin
        {
            friend class Surround;
            // deze friend declaratie is niet nodig
            //friend class SecondWithin;
            friend class ::SecondWithin;

            static int s_variable;
            public:
                int value();
        };
        int value();            // implementation given above
    private:
        class SecondWithin
        {
            friend class Surround;
            // deze friend declaratie is niet nodig
            //friend class FirstWithin;

            static int s_variable;
            public:
                int value();
        };
};

inline int Surround::value()
{                                   // scope resolution expression
    FirstWithin::s_variable = SecondWithin::s_variable;
    return s_variable;
}

inline int Surround::FirstWithin::value()
{
    Surround::s_variable = SecondWithin::s_variable;
    return s_variable;
}

inline int Surround::SecondWithin::value()
{
    Surround::s_variable = FirstWithin::s_variable;
    return s_variable;
}

int Surround::FirstWithin::s_variable = 1;
int Surround::SecondWithin::s_variable = 2;

int main(int argc, char*argv[])
{

}
