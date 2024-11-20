#include <iostream>
#include <vector>
#include <functional>

// See also addis.cc

using namespace std;

    enum
    {
        ADD,
        SUB,
        MUL
    };


template<typename LHS, typename RHS, int operation>
struct BinExpr
{
    template<typename Type>                                     // -> 69
    struct BasicType;

    template<typename LH, typename RH, int oper>                // -> 76
    struct BasicType<BinExpr<LH, RH, oper>>;

    using ObjType = typename BasicType<RHS>::ObjType;   // LHS, RHS must
    using value_type = typename ObjType::value_type;    // define a value_type


    LHS const &d_lhs;
    RHS const &d_rhs;

    BinExpr(LHS const &lhs, RHS const &rhs)             // std constructor
    :                                                   // sets the refs
        d_lhs(lhs),
        d_rhs(rhs)
    {}

    size_t size() const                             // LHS, RHS must define
    {                                               // size: the size of the
        return d_lhs.size();                        // orig. LHS type
    }                                               // (RHS size is also OK)

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

template<typename LHS, typename RHS, int operation>                     // 69
template<typename Type>
struct BinExpr<LHS, RHS, operation>::BasicType
{
    using ObjType = Type;
};

template<typename LHS, typename RHS, int operation>                     // 76
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


struct VI                               // define the data structure to
{                                       // operate on
    static size_t s_count;
    using value_type = int;

    VI() = default;

    VI(VI const &other)
    {
        (*this)[0] = other[0];
        cout << "CC, count = " << s_count << '\n';
    }

    VI(VI &&tmp)
    {
        (*this)[0] = tmp[0];
        cout << "MC, count = " << s_count << '\n';
    }

    int d_value = 0;

    size_t size() const
    {
        return 1;
    };

    void reserve(size_t count)
    {};

    int &operator[](size_t idx)
    {
        ++s_count;
        return d_value;
    }

    int const &operator[](size_t idx) const
    {
        ++s_count;
        return d_value;
    }
};

size_t VI::s_count;


int main()
{
    VI a, b, c, d;

    VI e = a + b  + c + d;
//    (a + b + c + d).operator VI();  // the resulting sum is computed once
                                    // the conversion operator is called.
//    static_cast<VI>(a + b + c + d);

// 2nd cout avoids the 'not used' compiler warning
//    cout << "# index computations: " << VI::s_count << '\n';
    cout << "# index computations: " << e.s_count << '\n';
}
