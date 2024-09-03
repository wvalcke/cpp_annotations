#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// how to implement an efficient operator= by reusing existing constructor/destructor functionality

class Strings
{
    std::string *d_string;
    size_t d_size;
public:
    Strings();
    Strings(char const *const *cStrings, size_t n);
    //copy constructor
    // called in the following cases
    // Strings s2;
    // Strings s3(s2);
    // also in this case
    // Strings s3 = s2; this is not an assignment operator called here !
    Strings(Strings const& other);
    ~Strings();

    Strings& operator=(Strings const& other);

    std::string &at(size_t idx) const;
    size_t size() const;

    void swap(Strings & other);
};

Strings::Strings()
:
    d_string(0),
    d_size(0)
{}

Strings::Strings(char const *const *cStrings, size_t size)
:
    d_string(new std::string[size]),
    d_size(size)
{
    for (size_t idx = 0; idx != size; ++idx)
        d_string[idx] = cStrings[idx];
}

Strings::Strings(Strings const& other)
: d_string(new string[other.d_size]),
d_size(other.d_size)
{
    for (size_t idx = 0; idx < other.d_size; idx++)
    {
        d_string[idx] = other.d_string[idx];
    }
}

Strings::~Strings()
{
    delete[] d_string;
}

Strings& Strings::operator=(Strings const& other)
{
    Strings tmp(other);
    swap(tmp);
    return *this;
}

void Strings::swap(Strings& other)
{
    std::swap(d_size, other.d_size);
    std::swap(d_string, other.d_string);
}

size_t Strings::size() const
{
    return d_size;
}

std::string & Strings::at(size_t idx) const
{
    return d_string[idx];
}

void display(Strings const &store)
{
    for (size_t idx = 0; idx != store.size(); ++idx)
        cout << store.at(idx) << '\n';
}

void process(Strings store)
{
    store.at(3) = "modified"; // doesn't modify store
}

Strings copy(Strings const &store)
{
    return store;
}

int main(int argc, char*argv[])
{
    Strings outer(argv, argc);
    process(outer);
}
