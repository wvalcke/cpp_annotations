#include <iostream>
#include <vector>

using namespace std;

template <typename ...Types>
struct TypeList;

template <typename Head, typename ...Tail>
struct TypeList<Head, Tail...>
{
    enum { size = 1 + TypeList<Tail...>::size };
};

template<>
struct TypeList<>
{
    enum { size = 0 };
};

template <class Type>
struct Vector: public std::vector<Type>
{
    Vector(std::initializer_list<Type> iniValues)
    :
        std::vector<Type>(iniValues)
    {}
};

template <size_t nr, typename Type>
struct UWrap: public Type
{
    UWrap(Type const &type)
    :
        Type(type)
    {}
};

template <size_t nr, typename ...PolicyTypes>
struct MultiBase;

template <size_t nr>
struct MultiBase<nr>
{};

template <size_t nr, typename PolicyT1, typename ...PolicyTypes>
struct MultiBase<nr, PolicyT1, PolicyTypes...> :
                            public UWrap<nr, PolicyT1>,
                            public MultiBase<nr + 1, PolicyTypes...>
{
    using Type = PolicyT1;
    using Base = MultiBase<nr + 1, PolicyTypes...>;

    MultiBase(PolicyT1 && policyt1, PolicyTypes &&...policytypes)
    :
        UWrap<nr, PolicyT1>(std::forward<PolicyT1>(policyt1)),
        MultiBase<nr + 1, PolicyTypes...>(
                            std::forward<PolicyTypes>(policytypes)...)
    {}
};

template <template <typename> class Policy, typename ...Types>
struct Multi: public MultiBase<0, Policy<Types>...>
{
    using PlainTypes = TypeList<Types...>;
    using Base = MultiBase<0, Policy<Types>...>;

    enum { size = PlainTypes::size };

    Multi(Policy<Types> &&...types)
    :
        MultiBase<0, Policy<Types>...>(
                        std::forward<Policy<Types>>(types)...)
    {}
};

template <size_t index, typename Multi>
class typeAt
{
    template <size_t idx, typename MultiBase>
    struct PolType;

    template <size_t idx,
                size_t nr, typename PolicyT1, typename ...PolicyTypes>
    struct PolType<idx, MultiBase<nr, PolicyT1, PolicyTypes...>>
    {
        using Type = typename PolType< idx - 1, MultiBase<nr + 1,
                                        PolicyTypes...> >::Type;
    };

    template <size_t nr, typename PolicyT1, typename ...PolicyTypes>
    struct PolType<0, MultiBase<nr, PolicyT1, PolicyTypes...>>
    {
        using Type = PolicyT1;
    };
public:
    typeAt(typeAt const &) = delete;
    using Type = typename PolType<index, typename Multi::Base>::Type;
};

template <size_t index, typename Multi>
class plainTypeAt
{
    template <size_t idx, typename List>
    struct At;

    template <size_t idx, typename Head, typename ...Tail>
    struct At<idx, TypeList<Head, Tail...>>
    {
        using Type = typename At<idx - 1, TypeList<Tail...>>::Type;
    };

    template <typename Head, typename ...Tail>
    struct At<0, TypeList<Head, Tail...>>
    {
        using Type = Head;
    };

public:
    plainTypeAt(plainTypeAt const &) = delete;
    using Type = typename At<index, typename Multi::PlainTypes>::Type;
};

template <size_t idx, typename Multi>
inline typename typeAt<idx, Multi>::Type &get(Multi &multi)
{
    return static_cast<
            UWrap<idx, typename typeAt<idx, Multi>::Type> &>(multi);
}

template <typename Type>
struct Policy
{
    Type d_type;
    Policy(Type &&type)
    :
        d_type(std::forward<Type>(type))
    {}
};

int main(int argc, char*argv[])
{
    Multi<Policy, string> ms{ Policy<string>{ "hello" } };
    Multi<Policy, string, string> ms2s{ Policy<string>{ "hello" },
                                       Policy<string>{ "world" } };


     using MPSI = Multi<Policy, string, int>;
     MPSI mpsi{ string{ "hello" }, 4 };

     cout << "There are " << MPSI::size << " types in MPSI\n"
            "There are " << mpsi.size << " types in mpsi\n";

    plainTypeAt<0, MPSI>::Type sx = "String type";
    plainTypeAt<1, MPSI>::Type ix = 12;

    cout << static_cast<Policy<string> &>(mpsi).d_type << '\n' <<
            static_cast<Policy<int> &>(mpsi).d_type << '\n';
    
    using MPII = Multi<Policy, int, int>;
    MPII mpii{ 4, 18 };

    cout << get<0>(mpii).d_type << ' ' << get<1>(mpii).d_type << '\n';

    using MVID = Multi<Vector, int, double>;
    MVID mi{ {1, 2, 3}, {1.2, 3.4, 5.6, 7.8} };

    typeAt<0, Multi<Vector, int>>::Type vi = {1, 2, 3};

    cout << get<0>(mi)[2] << '\n';
    get<1>(mi)[3] = get<0>(mi)[0];
    cout << get<1>(mi)[3] << '\n';
}
