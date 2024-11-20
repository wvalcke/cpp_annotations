#include <iostream>
#include <vector>
#include <functional>

using namespace std;

template<typename LHS, typename RHS,
            typename Operation>
struct BinExpr;

template<typename Type>
struct BasicType
{
    using ObjType = Type;
};

template<typename LHS, typename RHS, typename Operation>
struct BasicType<BinExpr<LHS, RHS, Operation>>
{
    using ObjType = typename BinExpr<LHS, RHS, Operation>::ObjType;
};

template<typename LHS, typename RHS, typename Operation>
struct BinExpr
{
    using ObjType = typename BasicType<RHS>::ObjType;
    using value_type = typename ObjType::value_type;

    LHS const &d_lhs;
    RHS const &d_rhs;
    Operation &d_functor;

    BinExpr(LHS const &lhs, RHS const &rhs, Operation &functor)
    :
        d_lhs(lhs),
        d_rhs(rhs),
        d_functor(functor)
    {}

    size_t size() const
    {
        return d_lhs.size();
    }

    value_type operator[](size_t ix) const
    {
        return d_functor(d_lhs[ix], d_rhs[ix]);
    }

    operator ObjType() const
    {
        ObjType retVal;

        retVal.resize(size());

        retVal.reserve(size());

        for (size_t ix = 0, end = size(); ix != end; ++ix)
            new(&retVal[ix]) value_type{ (*this)[ix] };

        return retVal;
    }
};

auto add =
    [](auto const &lhs, auto const &rhs)
    {
        return lhs + rhs;
    };

template<typename LHS, typename RHS>
BinExpr<LHS, RHS, decltype(add)>  operator+(LHS const &lhs, RHS const &rhs)
{
    return BinExpr<LHS, RHS, decltype(add)>(lhs, rhs, add);
}

struct VI: public vector<int>
{
    static size_t const s_max = 10000;


    VI()
    :
        vector<int>(s_max, 1)
    {}
};

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        cout << "arg1: number of iterations\n";
        return 0;
    }

    VI a, b, c, d;

    for (size_t idx = 0, count = stoul(argv[1]); idx != count; ++idx)
        d = a + b + c + d + a + b + c + d;

    cout << d.front() << ", " << d.back() << '\n';
}
