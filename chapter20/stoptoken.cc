#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void fun(std::stop_token stop)
{
    while (not stop.stop_requested())
    {
        cout << "next\n";
        this_thread::sleep_for(1s);
    }
}

int main()
{
    jthread thr(fun);

    this_thread::sleep_for(3s);

    thr.request_stop();

    // thr.join() not required.
}
