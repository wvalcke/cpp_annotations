#include <iostream>

template <typename Type>
struct Base
{
    template <typename Tp>
    static void fun();
};

template<typename Type>
template<typename Tp>
void Base<Type>::fun()
{
    std::cout << "func implementation\n";
}

template <typename Type>
struct Der: public Base<Type>
{
    //template <typename Tp>    // 'call' may be a member template
    //static                    // 'call' may be a static member
    void call()
    {
        //fun<int>();                      // won't compile
        //Base<Type>::fun<int>();          // won't compile
        Base<Type>::template fun<int>();    // OK
        // Base<Type>::template fun<Tp>();     // OK if call is a 
                                            //    member template
    };                                      // (activate typename Tp)
};

int main(int argc, char*argv[])
{
    Base<int>::fun<double>();
    Der<int> l_Der;
    l_Der.call();
}
