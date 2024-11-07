#include <iostream>
#include <vector>

template <typename Data>
struct Plain: public std::pair<Data *, Data *>
{};

template <typename Data, template <typename> class Container>
struct Size: public Container<Data>
{
    size_t size()
    {                           // relies on the container's `size()'
                                // note: can't use `this->size()'
        return Container<Data>::size();
    }
};

template <typename Data>
struct Size<Data, Plain>: public Plain<Data>
{
    size_t size()
    {                           // relies on pointer data members
        std::cout << "calling specialization\n";
        return this->second - this->first;
    }
};

template <typename Data, template <typename> class Store>
class Wrapper: public Size<Data, Store>
{};


int main()
{
    Wrapper<int, std::vector> wiv;
    std::cout << wiv.size() << "\n";

    Wrapper<int, Plain> wis;
    std::cout << wis.size() << "\n";

    Size<int, Plain> siz;
    std::cout << siz.size() << "\n";
    Size<int, std::vector> sizv;
    std::cout << sizv.size() << "\n";
}
