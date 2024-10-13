#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

//stop
void fun(std::stop_token stop)
{
    while (not stop.stop_requested())
    {
        cout << "next\n";
        this_thread::sleep_for(1s);
    }
}

void stopFun()
{
    cout << "stopFun called via stop_callback\n";
}

int main()
{
    jthread thr(fun);

    stop_callback sc{ thr.get_stop_token(), stopFun };

    this_thread::sleep_for(3s);

    thr.request_stop();
    // not needed
//    thr.join();
}
//=
