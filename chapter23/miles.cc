#include <iostream>

using namespace std;

template <char c>
int constexpr cVal()
{
    return '0' <= c <= '9' ? c - '0' : 10 + c - 'a';
}

template <size_t base, size_t acc, char c, char  ...Chars>
struct NM2km
{
    enum
    {
        value = NM2km<base, base * acc + cVal<c>(),
                                    Chars ...>::value
    };
};

template <size_t base, size_t acc, char c>
struct NM2km<base, acc, c>
{
    enum { value = base * acc + cVal<c>() };
};

template <char ...Chars>
struct NM2kmBase
{
    enum
    {
        value = NM2km<10, 0, Chars ...>::value
    };
};

template <char ...Chars>
struct NM2kmBase<'0', Chars ...>        // "0..."
{
    enum
    {                                   // octal value: base 8
        value = NM2km<8, 0, Chars ...>::value
    };
};

template <char ...Chars>
struct NM2kmBase<'0', 'b', Chars ...>   // "0b..."
{
    enum
    {                                   // binary value: base 2
        value = NM2km<2, 0, Chars ...>::value
    };
};

template <char  ...Chars>
struct NM2kmBase<'0', 'x', Chars ...>   // "0x..."
{
    enum
    {                                   // hex value: base 16
        value = NM2km<16, 0, Chars ...>::value
    };
};

template <char ... Chars>
size_t constexpr operator "" _NM2km()
{
    return static_cast<size_t>(         // forward Chars to NM2kmBase
            static_cast<double>(NM2kmBase<Chars ...>::value) * 1.852);
}

int main(int argc, char*argv[])
{
    cout << "10 nautical miles is " << 10_NM2km << " kilometers\n";
}
