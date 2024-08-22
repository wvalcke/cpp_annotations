#include <ratio>
#include <iostream>
using namespace std;

int main()
{
    cout << ratio<5, 1000>::num << ',' << ratio<5, 1000>::den << '\n' <<
            milli::num << ',' << milli::den << '\n';
    cout << kilo::num << ',' << kilo::den << '\n';
}
