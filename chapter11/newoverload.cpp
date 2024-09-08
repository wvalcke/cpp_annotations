#include <cstring>
#include <iosfwd>
#include <cstddef>
#include "string.h"
#include <iostream>
using namespace std;

class String
{
    std::string *d_data;

    public:
        void *operator new(size_t size)
        {
            return memset(::operator new(size), 0, size);
        }
        // overload placement new
        void *operator new(size_t size, char *memory)
        {
            return memset(memory, 0, size);
        }
        void operator delete(void *ptr)
        {
            // any operation considered necessary, then, maybe:
            // HOW does C++ knows how many bytes to delete ?
            ::operator delete(ptr);
        }
        bool empty() const
        {
            return d_data == 0;
        }
};


int main()
{
    String *sp = new String;

    cout << boolalpha << sp->empty() << '\n';   // shows: true
    delete sp;
/*
    char buffer[sizeof(String)];        // predefined memory
    String *sp2 = new(buffer) String;    // placement new call
    cout << sp2->empty() << '\n';*/
}
