#include <iostream>
#include <iomanip>

using namespace std;

int main(int arcc, char*argv[])
{
    ios::fmtflags l_OrigFlags;
    ios l_oldState(nullptr);
    l_oldState.copyfmt(cout);

    cout << 12.45 << '\n';

    cout.setf(ios::internal, ios::adjustfield);
    cout << internal;       // same, using the manipulator

    cout << '\'' << setw(5) << -5 << "'\n";  // displays '-   5'

    cout.setf(ios::left, ios::adjustfield);
    cout << left;           // same, using the manipulator

    cout << '\'' << setw(5) << "hi" << "'\n";  // displays 'hi   '

    cout.setf(ios::right, ios::adjustfield);
    cout << right;          // same, using the manipulator

    cout << '\'' << setw(5) << "hi" << "'\n";  // displays '   hi'

    cout.setf(ios::dec, ios::basefield);
    cout << dec;            // same, using the manipulator
    cout << 0x10 << '\n';           // displays 16

    cout.setf(ios::hex, ios::basefield);
    cout << hex;            // same, using the manipulator
    cout << 16 << '\n';             // displays 10

    cout.setf(ios::oct, ios::basefield);
    cout << oct;            // same, using the manipulator
    cout << 16 << '\n';             // displays 20

    cout << setbase(8);     // octal numbers, use 10 for
                            // decimal, 16 for hexadecimal
    cout << 16 << '\n';             // displays 20

    cout.setf(ios::boolalpha);
    cout << boolalpha;      // same, using the manipulator
    cout << (1 == 1) << '\n';       // displays true

    cout.setf(ios::showbase);
    cout << showbase;       // same, using the manipulator
    cout << hex << 16 << '\n';      // displays 0x10

    cout.setf(ios::showpos);
    cout << dec << showpos;            // same, using the manipulator
    cout << 16 << '\n';                 // displays +16
    cout.unsetf(ios::showpos);  // Undo showpos
    cout << 16 << '\n';                 // displays 16

    cout.setf(ios::uppercase);
    cout << uppercase;            // same, using the manipulator
    cout << hex << showbase <<
            3735928559 << '\n';           // displays 0XDEADBEEF
    cout << dec;                

    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(3);          // 3 digits behind the .

    // Alternatively:
    cout << setiosflags(ios::fixed) << setprecision(3);

    cout << 3.0 << " " << 3.01 << " " << 3.001 << '\n';
    cout << 3.0004 << " " << 3.0005 << " " << 3.0006 << '\n';
    // Results in:
    // 3.000 3.010 3.001
    // 3.000 3.001 3.001

    cout.setf(ios::scientific, ios::floatfield);
    cout << scientific;         // same, using the manipulator
    cout << 12.25;              // displays 1.22500e+01                

    cout << fixed << setprecision(3);   // 3 digits behind .

    cout.setf(ios::showpoint);      // set the flag
    cout << showpoint;              // same, using the manipulator

    cout << 16.0 << ", " << 16.1 << ", " << 16 << '\n';
    // displays: 16.000, 16.100, 16

    cout.copyfmt(l_oldState);

    cout << 12.45 << '\n';

    cout.unsetf(ios::showpoint);    // unset the flags

    cout << 16.0 << ", " << 16.1 << '\n';
    // displays: 16, 16.1

}
