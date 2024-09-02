#include <iostream>
#include "Data.h"

Data::Data()
{}

Data d1()
{
    std::cout << "hello world\n";
    return Data{};
}

int main()
{
    Data d1();

    d1();
    Data (*pf)() = d1;

    pf();   // or (same): (*pf)()
}
