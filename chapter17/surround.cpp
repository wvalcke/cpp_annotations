/*
* alhoewel de friend declaratie na de definitie komt van FirstWithin::value() 
* mag die method al gebruik maken van het feit dat we later de friend declaratie geven
*/

class Surround
{
    public:
        class FirstWithin
        {
            static int s_variable;
            public:
                int value()
                {
                    FirstWithin::s_variable = SecondWithin::s_variable;
                    return s_variable;
                }
            friend class Surround;
        };
    private:
        class SecondWithin
        {
            friend class Surround;
            static int s_variable;
        };
};

