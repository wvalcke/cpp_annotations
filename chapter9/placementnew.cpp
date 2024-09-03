#include <iostream>
#include <string>

class Strings
{
public:
    Strings() = default;
    ~Strings();
    void reserve(size_t capacity);
    void append(std::string const &next);
    std::string const &at(size_t idx) const;
    size_t size() const;
private:
    void destroy();
    std::string* d_memory = nullptr;
    size_t d_capacity = 1;
    size_t d_size = 0;
};

Strings::~Strings()
{
    destroy();
}

void Strings::reserve(size_t capacity)
{
    using std::string;
    if(capacity <= d_capacity)
    {
        return;
    }

    d_capacity *= 2;

    string *newMemory = static_cast<string *>(                  // 1
                            operator new(d_capacity * sizeof(string)));
    for (size_t idx = 0; idx != d_size; ++idx)                  // 2
        new (newMemory + idx) string{ d_memory[idx] };
    destroy();                                                  // 3
    d_memory = newMemory;
}

void Strings::destroy()
{
    using namespace std;
    for (std::string *sp = d_memory + d_size; sp-- != d_memory; )
        sp->~string();

    operator delete(d_memory);
}

void Strings::append(std::string const& next)
{
    reserve(d_size+1);
    new (d_memory + d_size) std::string{ next };
    ++d_size;
}

std::string const & Strings::at(size_t idx) const
{
    return d_memory[idx];
}

size_t Strings::size() const
{
    return d_size;
}

int main(int argc, char*argv[])
{

}
