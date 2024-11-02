
#include <iostream>


template <typename Type>
class Outer
{
    public:
        template <typename InType>
        class Inner
        {
            public:
                template <typename X>
                void nested();
        };
};

template <typename T1, typename T2>
class Usage
{
    public:
        void caller(typename Outer<T1>::Inner<T2> &obj);
};

template<typename Type>
template<typename InType>
template<typename X>
void Outer<Type>::Inner<InType>::nested()
{
    std::cout << "This is the implementation\n";
}

template<typename T1, typename T2>
void Usage<T1, T2>::caller(typename Outer<T1>::Inner<T2> &obj)
{
    std::cout << "This is the caller implementation\n";
}

int main(int argc, char*argv[])
{
    Usage<int, double> l_Usage;
    Outer<int>::Inner<double> l_Outer;
    l_Usage.caller(l_Outer);
}

