#include <iostream>

template<typename Type>
void other(Type&& p)
{
    std::cout << "Argument " << p << '\n';
    //p.brol();
}

template<typename Type>
void add(Type&& p)
{
    other(p);
}

void fie(int const && p)
{
    std::cout << "Argument " << p << '\n';
}

int main(int argc, char*argv[])
{
    int const x = 7;
    int y = 10;
    // met templates lukt dit, het Type argument is dan int const& p
    add(x);
    // hier is de signatuur voor add : int & p
    add(y);


    // dit lukt niet zonder de std::move, dus zonder templates lukt dit niet om zomaar x als argument 
    // te geven
    fie(std::move(x));
}
