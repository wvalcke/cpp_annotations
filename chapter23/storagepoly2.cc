#include <iostream>
#include <vector>

using namespace std;

template<int x>
struct IntType
{
    enum {value = x};
};

template<bool selector, typename FirstType, typename SecondType>
struct IfElse
{
    using type = FirstType;
};

template<typename FirstType, typename SecondType>
struct IfElse<false, FirstType, SecondType>
{
    using type = SecondType;
};

template <typename Type, bool isPolymorphic>
class Storage
{
    using DataType = typename IfElse<isPolymorphic, Type*, Type>::type;
    vector<DataType> d_data;
public:
    void add(Type const& obj);
private:
    void add(Type const& obj, IntType<true>);
    void add(Type const& obj, IntType<false>);
};

template <typename Type, bool isPolymorphic>
void Storage<Type, isPolymorphic>::add(Type const& obj)
{
    add(obj, IntType<isPolymorphic>());
}

template<typename Type, bool isPolymophic>
void Storage<Type, isPolymophic>::add(Type const& obj, IntType<true>)
{
    cout << "Calling polymorphic version with value " << obj << '\n';
}

template<typename Type, bool isPolymorphic>
void Storage<Type, isPolymorphic>::add(Type const& obj, IntType<false>)
{
    cout << "Calling NON polymorphic version with value " << obj << '\n';
}

int main(int argc, char*argv[])
{
    Storage<double, true> l_DoubleStorage;
    Storage<int, false> l_IntStorage;
    l_DoubleStorage.add(34.9);
    l_IntStorage.add(56);
}
