//start
#include <iostream>
#include <cstdint>          // uint8_t

class Byte
{
    uint8_t d_byte;
//=
    public:
//init
        Byte();                     // CC available by default
        Byte(uint8_t byte);
//=

//assign
        Byte &operator=(Byte const &rhs) = default;
        Byte &operator=(uint8_t rhs);
//=
//uint8
        operator uint8_t &();
        operator uint8_t() const;
//=
};

//members
inline Byte::Byte()
:
    d_byte(0)
{}

inline Byte::Byte(uint8_t byte)
:
    d_byte(byte)
{}

Byte &Byte::operator=(uint8_t rhs)
{
    d_byte = rhs;
    return *this;
}

inline Byte::operator uint8_t &()
{
    return d_byte;
}

inline Byte::operator uint8_t () const // 16_t
{
    return d_byte;
}
//=

//io
inline std::ostream &operator<<(std::ostream &out, Byte const &byte)
{
    return out << byte.operator uint8_t();
}

inline std::istream &operator>>(std::istream &in, Byte &byte)
{
    return in >> byte.operator uint8_t &();
}
//=
//demo
using namespace std;

int main()
{
    Byte b1;            // default: d_byte = 0
    Byte b2{ 12 };      // construct from an int
    Byte b3{ b2 };      // copy-construct

    b1 = 65;            // direct assignment
    b1 += 8416;           // arithmetic assignment

    b1 <<= 1;           // shift-assignments
    b1 >>= 1;

    b1 |= 1;            // bit-or assignment

    uint8_t u8 = b1;    // assign Byte to an uint8_t

                        // some stream insertions
    cout << sizeof(Byte) << ',' << (b1 < b2) << ',' <<
            b1 << ',' << b3 << ',' << u8 << '\n';

                        // using 'write'
    cout.write(reinterpret_cast<char const *>(&b1), 1) << '\n';
}

// output:
//  hex values                                 text ( . : not printable)
//  31 2C 30 2C 55 2C 0C 2C 55 0A 55 0A        1,0,U,.,U.U.
//=
