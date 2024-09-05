#include <iostream>
using namespace std;

class Delegate
{
    char *d_p1;
    char *d_p2;

    public:
        Delegate()      // succeeds -> object constructed
        :
            Delegate(0)
        {
            d_p2 = new char[10];
            cout << "default, throws...\n";
            throw 12;   // but considered constructed
        }
        ~Delegate()
        {
            delete[] d_p1;
            delete[] d_p2;
            cout << "destructor\n";
        }

    private:
        Delegate(int x)         // completes OK
        :
            d_p1(0),
            d_p2(0)
        {
            cout << "delegated\n";
        }
};

int main()
try
{
    Delegate del;           // throws

    cout << "never reached\n";
} // del's destructor is called here
catch (...)
{
    cout << "main's catch clause\n";
}
