#include <iostream>
#include <string>

using namespace std;

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

    std::string &at(size_t idx) const;
    size_t size() const;
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
