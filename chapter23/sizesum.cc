#include <iostream>
#include <string>
#include <queue>
#include <vector>

#include <concepts>

using namespace std;

template <typename Types>
concept HasSize =
requires (Types type)
{
    { type.size() } -> std::same_as<size_t>;
};

size_t sum()
{
    return 0;
}

template <typename First, typename  ...Types>
size_t sum(First &&first, Types &&...types)
{
    return first.size() + sum(std::forward<Types>(types)...);
}

template <HasSize ...Types>
void fun(Types &&...obj)
{
    sum(std::forward<Types &&>(obj)...);
}

size_t sum2()
{
    return 0;
}

template <HasSize First, HasSize  ...Types>
size_t sum2(First &&first, Types &&...types)
{
    return first.size() + sum2(std::forward<Types>(types)...);
}

int main()
{
    fun(queue<int>{}, vector<int>{}, string{});
    cout << sum2(queue<int>{}, vector<int>{1, 2, 3}, string{}) << '\n';
}

