#include <concepts>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename Container, typename Predicate>
concept Find_ifConcept =
    std::predicate<Predicate, typename Container::value_type>
    and
    requires(Container container)
    {
        { container.begin() } -> std::same_as<typename Container::iterator>;
        { container.end() }   -> std::same_as<typename Container::iterator>;
        { container.size() }  -> std::same_as<size_t>;
    };

template <typename Container, typename Predicate>
size_t findIdx_if(Container const &cont, size_t from, Predicate const &pred)
    requires Find_ifConcept<Container, Predicate>
{
    auto iter = std::find_if(cont.begin() + from, cont.end(), pred);
    return iter == cont.end() ? cont.size() : iter - cont.begin();
}

int main()
{
    std::cout << "Index at " <<
        findIdx_if(std::string{ "hello world" }, 0,
            [&](int ch)
            {
                return ch == ' ';
            }
        ) << '\n';
}
