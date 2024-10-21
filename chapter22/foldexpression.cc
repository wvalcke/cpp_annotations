#include <iostream>

using namespace std;

template<typename ReturnType, typename ...Params>
ReturnType sum(Params ...params)
{
    return (... + params);
}

template<typename ReturnType, typename ...Params>
ReturnType sumdouble(Params ...params)
{
    return (... + (1+params));
}

template<typename ReturnType, typename ...Params>
ReturnType othersum(Params ...params)
{
    return (params + ...);
}

template<typename ...Pack>
ostream& out2(ostream& out, Pack&& ...args)
{
    return (out << ... << args);
}

template<typename ...Pack>
void call(Pack&& ...args)
{
    (... , (args()));
}

int main(int argc, char*argv[])
{
    std::cout << "Sum is " << sum<int>(1, 2, 3) << '\n';
    std::cout << "Sum is " << othersum<int>(1, 2, 3) << '\n';
    std::cout << "Sum double is " << sumdouble<int>(1, 2, 3) << '\n';
    out2(cout, 1, 2, 3, "This is text", 5);
    cout << '\n';

    call([]() {cout << "This is the first\n"; }, [](){cout << "This is the second\n";});

}
