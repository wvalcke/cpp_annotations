#include <iostream>

class Class
{
    public:
        Class() = default;

        // This line MUSt be there, as the default copy constructor is not generated
        // because a move constructor is defined
        Class(Class const &other) = default;
        Class(Class &&tmp)
        {}
};

int main()
{
    Class one;
    Class two{ one };
}

