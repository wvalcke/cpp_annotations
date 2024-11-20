#include <iostream>
#include <vector>
#include <functional>

using namespace std;

enum
{
    ADD,
    SUB,
};

template<typename LHS, typename RHS, int operation>
struct BinExpr
{
    template<typename Type>
    struct BasicType;

    template<typename LH, typename RH, int oper>
    struct BasicType<BinExpr<LH, RH, oper>>;

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

    template <typename LH, typename RH, int oper>
    struct Operation;

    value_type operator[](size_t ix) const
    {
        return Operation<LHS, RHS, operation>::cpt(d_lhs[ix], d_rhs[ix]);
                // *************** this causes
                //                 calling
                //                 the proper
                //                 cpt          ****************
    }

    operator ObjType() const
    {
        ObjType retVal;

        retVal.reserve(size());

        for (size_t ix = 0, end = size(); ix != end; ++ix)
            new(&retVal[ix]) value_type{ (*this)[ix] };

        return retVal;
    }
};

template<typename LHS, typename RHS, int operation>
template<typename Type>
struct BinExpr<LHS, RHS, operation>::BasicType
{
    using ObjType = Type;
};

template<typename LHS, typename RHS, int operation>
template<typename LH, typename RH, int oper>
struct BinExpr<LHS, RHS, operation>::BasicType<BinExpr<LH, RH, oper>>
{
    using ObjType = typename BinExpr<LH, RH, oper>::ObjType;
};

template<typename LHS, typename RHS, int operation>
template <typename LH, typename RH>
struct BinExpr<LHS, RHS, operation>::Operation<LH, RH, ADD>
{
    static value_type cpt(value_type const &lhs, value_type const &rhs)
    {
        return lhs + rhs;
    };
};

template<typename LHS, typename RHS, int operation>
template <typename LH, typename RH>
struct BinExpr<LHS, RHS, operation>::Operation<LH, RH, SUB>
{
    static value_type cpt(value_type const &lhs, value_type const &rhs)
    {
        return lhs - rhs;
    };
};

template<typename LHS, typename RHS>
BinExpr<LHS, RHS, ADD>  operator+(LHS const &lhs, RHS const &rhs)
{
    return BinExpr<LHS, RHS, ADD>(lhs, rhs);
}


template<typename LHS, typename RHS>
BinExpr<LHS, RHS, SUB>  operator-(LHS const &lhs, RHS const &rhs)
{
    return BinExpr<LHS, RHS, SUB>(lhs, rhs);
}



struct VI: public vector<int>           // define the data structure to
{                                       // operate on
    static size_t const s_max = 1;//0000;

    VI()
    :
        vector<int>(s_max, 1)
    {}
};

int main()
{
//    vector<int> one {1, 2, 3};
//    vector<int> two {4, 5, 6};
//
//    vector<int> three = one + two + (one + two);
//
//    auto four = one + two + (one + two);
//
//    auto z = "hello world";
//
//    cout << z << '\n';
//
//    cout << three[0] << ' ' << three[2] << '\n';
//    cout << four[0] << ' ' << four[2] << '\n';

    VI a, b, c, d;

    d = a + b;

//    d = a - b - c - d - (a - b - c - d);
//
//    d = a + b - (c + d) - (a + b - c + d);
//
//    d = VI{};
//
//    d = a + b + c + d + (a + b + c + d);
//
    cout << d.front() << ", " << d.back() << '\n';
}
