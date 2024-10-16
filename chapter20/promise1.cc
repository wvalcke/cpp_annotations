#include <iostream>
#include <future>

using namespace std;

//code
void compute(promise<int> &ref)
{
    ref.set_value(9);
}

int main()
{
    std::promise<int> prom;
    std::thread(compute, ref(prom)).detach();

    cout << prom.get_future().get() << '\n';
}
//=
