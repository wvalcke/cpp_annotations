#include <iostream>

using namespace std;

// seekg clears the eof bit

int main()                  // in 'src.cc'
{
    cin.setstate(ios::eofbit | ios::failbit);
    cerr << cin.good() << ' ' << cin.eof() << '\n';

    cin.seekg(0);
    cerr << cin.good() << ' ' << cin.eof() << '\n' <<
            (cin.get() == EOF ? "failed" : "OK") << '\n';

    cin.clear();
    cerr << cin.good() << ' ' << cin.eof() << '\n' <<
            (cin.get() == EOF ? "failed" : "OK") << '\n';
}

//
// outputs when called as 'a.out < src.cc':
//         0 1
//         0 0
//         failed
//         1 0
//         OK
