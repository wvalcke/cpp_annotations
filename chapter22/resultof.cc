#include <iostream>
#include <sstream>

using namespace std;

template<typename Class>
class Filter
{
    Class obj;
public:
    template<typename Arg>
    typename std::result_of<Class(Arg)>::type 
    operator()(Arg const& arg) const
    {
        return obj(arg);
    }
};

struct Math
{
    double operator()(int x) const
    {
        return x;
    }
    std::string operator()(double x) const
    {
        ostringstream l_Stream;
        l_Stream << x;
        return  l_Stream.str();
    }
};

int main(int argc, char*argv[])
{
    Filter<Math> l_Filter;
    cout << "Filter output " << l_Filter(34.7) << '\n';
}
