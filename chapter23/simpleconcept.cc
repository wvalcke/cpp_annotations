#include <string>
#include <map>

template <typename Type>
concept HasStrIndex =
requires(Type tp)
{
    tp[std::string{}];
};

template <HasStrIndex Type>
auto value(Type &obj, std::string const &key)
{
    return obj[key];
}

int main()
{
    std::map<std::string, double> msd;
    value(msd, "hi");
    //std::map<int, std::string> omap;
    //value(omap, "hi");
}
