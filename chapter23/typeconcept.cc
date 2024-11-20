#include <vector>
#include <string>

using namespace std;

template <typename Type>
concept Iteratable =
    requires(Type tp)
    {
        typename Type::iterator;
        tp.begin();
    };

template <Iteratable Type>
auto iter(Type const &obj)
{
    return obj.begin();
}

int main(int argc, char*argv[])
{
    vector<string> l_V;
    auto it = iter(l_V);
}
