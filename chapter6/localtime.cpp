#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace chrono;

auto localTime(time_point<system_clock> const &tp, char const *fmt)
{
    time_t secs = system_clock::to_time_t( tp );
    // put_time is a manipulator for a stream
    return put_time(localtime(&secs), fmt);
}

int main(int argc, char* argv[])
{
    // used as:
    cout << localTime(system_clock{}.now(), "%c") << '\n';
}
