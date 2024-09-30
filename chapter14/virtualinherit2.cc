    #include <iostream>
    using namespace std;

//CLASSES
    class First
    {
        public:
            First()
            {
                cout << "First()\n";
            }
            First(int x)
            {
                cout << "First(int) " << x << '\n';
            }
    };
    class Second: public virtual First      // note: virtual
    {
        public:
            Second(int x)
            :
                First(x)
            {}
    };
    class Third: public Second
    {
        public:
            Third(int x)
            :
                Second(x),
                First(x)
            {}
    };
    int main()
    {
        Third third{ 3 };   // displays `First()'
    }
//=
