#ifndef INCLUDED_NEWALLOC_H_
#define INCLUDED_NEWALLOC_H_

#include <ostream>

template <typename Data>
class NewAlloc: public std::allocator<Data>
{
    template<typename IData>
    friend std::ostream &operator<<(std::ostream &out,
                                    NewAlloc<IData> const &alloc);
    Data *d_data;

    public:
        NewAlloc();
        NewAlloc(Data const &data);
        NewAlloc(NewAlloc<Data> const &other);
        ~NewAlloc();
        operator Data &();
        NewAlloc &operator=(Data const &data);
};

template<typename Data>
NewAlloc<Data>::NewAlloc()
:
    d_data(0)
{
    std::cout << "Default constructor NewAlloc called" << std::endl;
}

template<typename Data>
NewAlloc<Data>::NewAlloc(Data const &data)
:
    d_data(new Data(data))
{
    std::cout << "Constructor NewAlloc with argument " << data << " called" << std::endl;
}

template<typename Data>
NewAlloc<Data>::NewAlloc(NewAlloc<Data> const &other)
:
    d_data(new Data(*other.d_data))
{
    std::cout << "Copy constructor NewAlloc called" << std::endl;
}

template<typename Data>
NewAlloc<Data>::~NewAlloc()
{
    delete d_data;
    std::cout << "Destructor NewAlloc called" << std::endl;
}

template<typename Data>
NewAlloc<Data>::operator Data &()
{
    return *d_data;
}

template<typename Data>
NewAlloc<Data> &NewAlloc<Data>::operator=(Data const &data)
{
    *d_data = data;
    std::cout << "Operator= NewAlloc called with argument " << data << std::endl;
}

template<typename IData>
inline std::ostream &operator<<(std::ostream &out,
                                NewAlloc<IData> const &alloc)
{
    return out << *alloc.d_data;
}


#endif
