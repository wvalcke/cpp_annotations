//code
#include <iostream>
#include <syncstream>
#include <string>
#include <thread>

using namespace std;

void fun(char const *label, size_t count)
{
    osyncstream out(cout);

    for (size_t idx = 0; idx != count; ++idx)
    {
        this_thread::sleep_for(1s);
        out << label << ": " << idx << " running...\n";
    }
    out << label << " ends\n";
}

int main(int argc, char **argv)
{
    cout << "the 1st arg specifies the #iterators "
            "using 3 iterations by default\n";

    size_t count = argc > 1 ? stoul(argv[1]) : 3;

    thread thr1{ fun, "first", count };
    thread thr2{ fun, "second", count };

    thr1.join();
    thr2.join();
}
//=
