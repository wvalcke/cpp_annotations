#include <iostream>
#include <tuple>

template<typename ...Params>
class Wrapper
{
    std::tuple<Params...> d_tuple;
public:
    Wrapper(Params&& ...params)
    : d_tuple(std::forward<Params>(params)...)
    {

    }
};

int main(int argc, char*argv[])
{
    using tuple_idsc = std::tuple<int, double &, std::string, char const *>;

    double pi = 3.14;
    tuple_idsc idsc(59, pi, "hello", "fixed");

    // access a field:
    std::get<2>(idsc) = "hello world";

    std::get<1>(idsc) = 90.09;
    std::cout << "Double value " << pi << '\n';

    std::cout << "Tuple size " << std::tuple_size<tuple_idsc>::value << '\n';

    std::tuple_element<2, tuple_idsc>::type text = "Hello World";

    std::cout << text << '\n';

    Wrapper<std::string, int, double> wrapper("Hello", 5, 4.56);
}
