#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template <typename Type>
using Vector = std::vector<Type>;

int main(int argc, char*argv[])
{
    Vector<std::string> l_Vector;
    l_Vector.push_back("A");
    l_Vector.push_back("B");
    l_Vector.push_back("C");
    l_Vector.push_back("D");
    
    std::copy(l_Vector.begin(), l_Vector.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << '\n';
}
