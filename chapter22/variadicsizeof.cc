#include <iostream>
using namespace std;

template<typename ...Params>
struct StructName
{
    enum: size_t { s_size = sizeof...(Params) };
};

int main(int argc, char*argv[])
{
    cout << "Number of template parameters " << StructName<int, double>::s_size << "\n";
}
