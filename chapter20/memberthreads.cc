#include <iostream>
#include <thread>

using namespace std;

//main
struct Demo
{
    int d_value = 0;

    void fun(int value)
    {
        d_value = value;
        cout << "fun sets value to " << value << "\n";
    }
};

int main()
{
    Demo demo;

    thread thr{&Demo::fun, ref(demo), 12 };
    thr.join();
    cout << "demo's value: " << demo.d_value << '\n';   // 12

    thr = thread{&Demo::fun, &demo, 42 };
    thr.join();
    cout << "demo's value: " << demo.d_value << '\n';   // 42

    thr = thread{&Demo::fun, demo, 77 };
    thr.join();
    cout << "demo's value: " << demo.d_value << '\n';   // 42: the thread
                                                        // copied demo
}
//=
