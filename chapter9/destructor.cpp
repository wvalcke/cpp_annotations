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
    ~Strings();

    std::string const &at(size_t idx) const;
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

Strings::~Strings()
{
    delete[] d_string;
}

size_t Strings::size() const
{
    return d_size;
}

std::string const& Strings::at(size_t idx) const
{
    return d_string[idx];
}

void display(Strings const &store)
{
    for (size_t idx = 0; idx != store.size(); ++idx)
        cout << store.at(idx) << '\n';
}

Strings *process(char *argv[], size_t argc)
{
    Strings store{ argv, argc };
    display(store);
    return new Strings{ argv, argc };
}

int main(int argc, char*argv[])
{
    Strings *sp = process(argv, argc);
    delete sp;

    char buffer[sizeof(Strings)];
    sp = new (buffer) Strings{ argv, static_cast<size_t>(argc) };
    sp->~Strings();
}
