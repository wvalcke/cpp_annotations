#include <iostream>
#include <string>

using namespace std;

template <typename Type>
struct String
{
    struct iterator
    {
        std::string::iterator d_iter;

        friend bool operator==(iterator const &lhs, iterator const &rhs)
        {
            return lhs.d_iter == rhs.d_iter;
        }
    };

    iterator begin()
    {
        return iterator{};
    }
};

int main(int argc, char*argv[])
{
    String<int> str;
    return  str.begin() == str.begin();
}
