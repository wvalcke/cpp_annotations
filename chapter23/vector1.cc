#include <vector>
using namespace std;

template<typename Data, template <typename> class Vect>
void fun()
{
    // Vect<Data, std::allocator<Data>> vd; // fails
    Vect<Data> vd;                          // OK, uses std::allocator
}

template<typename Data,
         template <typename, typename> class Vect>
void gun()
{
    Vect<Data, std::allocator<Data>> vd;    // allocator type is required
}

template<typename Data,
         template <typename, typename = std::allocator<Data>> class Vect>
void hun()
{
    Vect<Data> vd;                          // uses default allocator type
}

int main()
{
    fun<int, vector>();
    gun<int, vector>();
    hun<int, vector>();
}
