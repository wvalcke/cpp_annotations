#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

int main(int argc, char*argv[])
{
    steady_clock::time_point p1;
    steady_clock::time_point p2;

    p1 = steady_clock::now();

    system_clock::duration oneDay{24h};
    cout << "One day is " << oneDay.count() << endl;
    cout << "Clock period is " << system_clock::period::den << endl;

    time_point<system_clock, seconds> point1;
    cout << "Time since epoch : " << point1.time_since_epoch().count() << endl;

    cout << (point1 + milliseconds(20)).time_since_epoch().count() << endl;

    cout << (point1 + 1h).time_since_epoch().count() << endl;

    cout << 
        time_point<system_clock>::min().time_since_epoch().count() << '\n';
        // shows -9223372036854775808
    cout << 
        time_point<system_clock>::max().time_since_epoch().count() << '\n';

    cout << system_clock::now().time_since_epoch().count() << '\n';

    cout << duration<int64_t, nano>::min().count() << '\n';
    cout << duration<int64_t, nano>::max().count() << '\n';

    cout << duration<int64_t, milli>::min().count() << '\n';
    cout << duration<int64_t, milli>::max().count() << '\n';

    p2 = steady_clock::now();

    steady_clock::duration runtime = p2.time_since_epoch() - p1.time_since_epoch();
    cout << "Run took " << runtime.count()/1000000.0 << " millis" << '\n';
}
