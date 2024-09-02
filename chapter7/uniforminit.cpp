#include <iostream>

class Vector
{
    public:
        Vector(size_t size) {
            std::cout << "Constructor with size_t argument" << '\n';
        }
/*        Vector(std::initializer_list<int> const &values) {
            std::cout << "Constructor with initializer list" << '\n';
        }*/
};

void func()
{

}

struct Fun
{
    Fun(void (*f)())
    {
        std::cout << "Constructor\n";
    };

    void process()
    {
        std::cout << "process\n";
    }
};

int main(int argc, char*argv[])
{
    Vector v1(4);
    Vector v2{4};
    Vector v3 = {4};

    Fun(func).process();
    // Next is seen as Fun func; which is actually a default constructed Fun object, which does not compile
    //Fun(func);
    // next does compile, and is an anonymous object
    Fun{func};
}
