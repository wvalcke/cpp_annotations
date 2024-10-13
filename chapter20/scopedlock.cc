#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>

using namespace std;

//code
int value;
mutex valueMutex;
mutex coutMutex;

void fun1()
{
    scoped_lock sl{ coutMutex, valueMutex };
    cout << "fun 1 locks cout\n";
    sleep(1);
    cout << "fun 1 locks value\n";
}

void fun2()
{
    scoped_lock sl{ valueMutex, coutMutex };
    cout << "fun 2 locks value\n";
    sleep(1);
    cout << "fun 2 locks cout\n";
}

int main()
{
    thread t1(fun1);
    fun2();
    t1.join();
}
//  Displays:
//    fun 2 locks value
//    fun 2 locks cout
//    fun 1 locks cout
//    fun 1 locks value
//=
