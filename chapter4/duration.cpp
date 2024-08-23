#include <ratio>
#include <chrono>
#include <iostream>

using namespace std;
using namespace chrono;

int main()
{
    minutes halfHour(30);

    minutes fullHour = minutes{ 30 } + halfHour;
    fullHour = 2 * halfHour;
    halfHour = fullHour / 2;
    fullHour = halfHour + halfHour;

    halfHour /= 2;
    halfHour *= 2;

    hours oneHour{ 1 };

    cout << (oneHour + halfHour).count() << '\n';   // displays: 90

    halfHour += oneHour;            // OK
    // oneHour += halfHours;        // won't compile

    milliseconds ms = 1min;
    std::cout << ms.count() << endl;

    // hours testH = 1ms; // NO compile

    // define own duration type
    duration<int64_t, ratio<1, 1000>> l_MyMs(10);
    duration<int64_t, ratio<30, 1>> l_HalfMinute(1);
    std::cout << "Total sum is " << (l_MyMs+l_HalfMinute).count() << '\n';

}
