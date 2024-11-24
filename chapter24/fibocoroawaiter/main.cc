#include "main.ih"

int main(int argc, char **argv)
{
    Fibo fibo = fiboCoroutine();
    cout << "After coroutine construction\n";

    size_t sum = 0;

    for (                       // the sequence of fibonacci numbers
        size_t begin = 0, end = argc == 1 ? 10 : stoul(argv[1]);
            begin != end;
                ++begin
    )
        sum += fibo.next();

    cout << sum << '\n';
}
