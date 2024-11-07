#include <iostream>
#include <vector>

template <typename Type>
using Vector = std::vector<Type>;

template <typename Type, template <typename> class Container>
class Generic: public Container<Type>
{
};

int main(int argc, char*argv[])
{
    Vector<int> l_IntVector;
    Generic<int, Vector> l_IntVector2;
}
