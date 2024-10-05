#include <iostream>

using namespace std;

class Outer
{
    int d_value;
    static int s_value;

    public:
        Outer()
        :
            d_value(12)
        {}
        class Inner
        {
            public:
                Inner()
                {
                    cout << "Outer's static value: " << s_value << '\n';
                }
                Inner(Outer &outer)
                {
                    cout << "Outer's value: " << outer.d_value << '\n';
                }
        };
};
class Extern            // won't compile!
{
    public:
        Extern(Outer &outer)
        {
            // does not compile, the member is private
            //cout << "Outer's value: " << outer.d_value << '\n';
        }

        Extern()
        {
            // dos not compile, the static is private
            //cout << "Outer's static value: " << Outer::s_value << '\n';
        }
};

int Outer::s_value = 123;
int main()
{
    Outer outer;
    Outer::Inner in1;
    Outer::Inner in2{ outer };
}
