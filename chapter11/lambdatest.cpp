#include <iostream>

struct S2 
{
    double ohseven = .007;

    auto f() 
    {
        return [this]                       // (1, see below)
                {
                    return [*this]          // (2)
                            {
                                return ohseven; // OK
                            };
                }();                         // (3)
    }

/*     auto g() 
    {
        return [] 
                {
                    return [*this] 
                    { 
                        // error: *this not captured by 
                        // the outer lambda-expression 
                    }; 
                }();
    }*/
};

int main(int argc, char*argv[])
{
    S2 s;
    std::cout << s.f()() << '\n';
}
