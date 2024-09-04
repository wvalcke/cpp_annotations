#include <cctype>
#include <iostream>

using namespace std;

struct Fails
{
    int d_int = 0;
    double d_double = 0;
    int (*d_is)(int) = isalnum;

    private:
        int d_private;
};

struct Data
{
    int d_int = 0;
    double d_double = 0;
    int (*d_is)(int) = isalnum;
};

int main()
{
    Fails fails;

    // auto &[i, d, fun, priv] = fails; // won't compile: d_private
                                        // is inaccessible

    // auto &[i, d, fun] = fails;       // won't compile: not all of Fails's
                                        // members are used

    Data data;

    auto &[i, d, fun] = data;           // OK

                                        // d_int modified through ++i
    cout << ++i << ' ' << data.d_int << ' ' <<
            fun('a') << ' ' << fun(',') << '\n';
}
