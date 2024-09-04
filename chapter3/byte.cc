#include <iostream>
#include <cstddef>

#include <cstdint>          // uint8_t

using namespace std;

//ostream &operator<<(ostream &out, uint8_t value)
//{
//    return out << static_cast<uint16_t>(value);
//}

int main()
{
//    uint8_t u8 = 40;         // works great!
//    cout << u8 << '\n';

//init
    byte value{ 0x23 };     // #1 (see the text above)
//  byte error{ 0x123 };    // #2

    char ch = 0xfb;
//  byte error{ ch };       // #3

    byte b1 = byte( ch );   // #4
    value = byte( 0x123 );  // #5
//=

//    cout << (value == byte{ 0 }) << '\n';
//    cout << hex << static_cast<size_t>(value) << '\n';

    if (value > b1)
        value &= byte(0xf0);
}
