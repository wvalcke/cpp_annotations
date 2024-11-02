
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

template <typename T1, typename T2, typename T3>
class Usage
{
    public:
        void caller(Outer<T1>::template Inner<T2> &obj);
};

template<typename Type>
template<typename InType>
template<typename X>
void Outer<Type>::Inner<InType>::nested()
{
    std::cout << "This is the nested implementation\n";
}

template<typename T1, typename T2, typename T3>
void Usage<T1, T2, T3>::caller(Outer<T1>::template Inner<T2> &obj)
{
    std::cout << "This is the caller implementation\n";
    obj.template nested<T3>();
}

int main(int argc, char*argv[])
{
    Usage<int, double, size_t> l_Usage;
    Outer<int>::Inner<double> l_Outer;
    l_Usage.caller(l_Outer);
}

