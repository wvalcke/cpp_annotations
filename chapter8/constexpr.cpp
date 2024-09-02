#include <cstddef>
using namespace std;

class Data
{
    static size_t const s_size = 7;

    public:
        static size_t constexpr size();
        size_t constexpr mSize();
};

size_t constexpr Data::size()
{
    return s_size;
}

size_t constexpr Data::mSize()
{
    return size();
}

double data[ Data::size() ];        // OK: 7 elements
short data2[ Data().mSize() ];      // also OK: see below

int main(int argc, char* argv[])
{

}
