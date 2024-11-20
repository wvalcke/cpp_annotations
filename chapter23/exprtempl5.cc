#include <iostream>
#include <vector>
#include <functional>

using namespace std;

auto add =
    [](auto const &lhs, auto const &rhs)
    {
        return lhs + rhs;
    };

template <typename Type>
struct Adder
{
    Type operator()(Type const &lhs, Type const &rhs) const
    {
        return add(lhs, rhs);
    }
};


template<typename LHS, typename RHS, template<typename> class Operation>
struct BinExpr;

template<typename Type>
struct BasicType
{
    using ObjType = Type;
};

template<typename LHS, typename RHS, template<typename> class Operation>
struct BasicType<BinExpr<LHS, RHS, Operation>>
{
    using ObjType = typename BinExpr<LHS, RHS, Operation>::ObjType;
};

template<typename LHS, typename RHS, template <typename> class  Operation>
struct BinExpr
{
    using ObjType = typename BasicType<RHS>::ObjType;
    using value_type = typename ObjType::value_type;

    LHS const &d_lhs;
    RHS const &d_rhs;

    BinExpr(LHS const &lhs, RHS const &rhs)
    :
        d_lhs(lhs),
        d_rhs(rhs)
    {}

    size_t size() const
    {
        return d_lhs.size();
    }

    value_type operator[](size_t ix) const
    {
        static Operation<value_type> operation;

        return operation(d_lhs[ix], d_rhs[ix]);
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

template<typename LHS, typename RHS>
BinExpr<LHS, RHS, Adder>  operator+(LHS const &lhs, RHS const &rhs)
{
    return BinExpr<LHS, RHS, Adder>(lhs, rhs);
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
