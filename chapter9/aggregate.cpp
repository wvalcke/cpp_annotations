
#include <string>

struct Outer
{
    struct Inner
    {
        int     d_int;
        double  d_double;
    };

    std::string d_string;
    Inner d_inner;
};


int main(int argc, char*argv[])
{
    Outer out{ "hello", { 1, 12.5} };
}
