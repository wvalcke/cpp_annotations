#include <string>
#include <iostream>
#include <concepts>

using namespace std;

template <typename LHS, typename RHS>
struct Less
{
    bool operator()(LHS lhs, RHS rhs) const
    {
        return lhs < rhs;
    }
};

template <template<typename LHS, typename RHS> typename Pred,
          typename LHS, typename RHS>
bool cmp(LHS lhs, RHS rhs)
    requires std::relation<Pred<LHS, RHS>, LHS, RHS>
{
    return Pred<LHS, RHS>{}(lhs, rhs);
}

int main()
{
    std::cout << cmp <Less>(5, 4.9) << '\n';
    // does not compile
    //std::cout << cmp <Less>(5, "hello world") << '\n';
}
