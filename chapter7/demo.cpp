#include <iostream>
using namespace std;

class Demo
{
    public:
        Demo();
};

Demo::Demo()
{
    cout << "Demo constructor called\n";
}

Demo d;

int main()
{
    cout << "This is written in main" << '\n';
}

/*
    Generated output:
Demo constructor called
*/
