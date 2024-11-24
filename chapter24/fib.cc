#include <iostream>
#include <string>

using namespace std;

class Fibo
{
    size_t d_return = 0;
    size_t d_next = 1;

    public:
        size_t next();
};

size_t Fibo::next()
{
    size_t ret = d_return;      // the next fibonacci number

    d_return = d_next;          // at the next call: return d_next;
    d_next += ret;              // prepare d_next as the sum of the
                                // original d_return and d_next
    return ret;
}

int main(int argc, char **argv)
{
    Fibo fibo;                  // create a Fibo object

    size_t sum = 0;

                                // use its 'next' member to obtain
    for (                       // the sequence of fibonacci numbers
        size_t begin = 0, end = argc == 1 ? 10 : stoul(argv[1]);
            begin != end;
                ++begin
    )
        sum += fibo.next();

    cout << sum << '\n';
}
