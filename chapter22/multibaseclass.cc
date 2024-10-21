#include <iostream>
#include <string>
#include <utility>

template<typename ...BaseClasses>
class Combi : public BaseClasses...
{
public:
    Combi(BaseClasses&& ...baseClasses)
    : BaseClasses(std::forward<BaseClasses>(baseClasses))...
    {}
};

int main(int argc, char*argv[])
{
    using Multi = Combi<std::string, std::pair<int, int>>;
    Multi m{"String", {7, 10}};
    std::cout << "First " << m.first << '\n';
    std::cout << "Second " << m.second << '\n';
    std::cout << "Length " << m.length() << '\n';
}
