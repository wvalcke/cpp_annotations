#include <iostream>
#include <string>

using namespace std;

class OtherClass
{
public:
    OtherClass()
    {
        m_Int = new int[80];
    }
    ~OtherClass()
    {
        cout << "Calling destructor of OtherClass" << '\n';
        delete [] m_Int;
    }
private:
    int *m_Int;
};

union urUnion 
{
    int m_Int;
    //OtherClass m_Other;
    std::string m_Other;

    urUnion()
    {
        //new(&m_Other) OtherClass();
        new(&m_Other)  std::string(50000, 'X');
    }
    ~urUnion()
    {
        // empty;
    }
};

class MyClass
{
    std::string mS;
    OtherClass m_Other;
public:
    MyClass()
    {
        mS = "This is not leaked";
    }
    ~MyClass()
    {
        // empty
        /*
        * Het feit dat de destructor leeg is wil niet zeggen dat het hier stopt
        * C++ zal nog steeds de destructor oproepen voor alle members
        * Mochten die members pointers zijn, dan gebeurt er verder niet veel, het is aan
        * deze destructor om de data waarnaar ze wijzen op te kuisen.
        * Dus voor alle aggregates (non primitive) objecten wordt de destructor wel opgeroepen
        */
    }
};

int main(int argc, char *argv[])
{
    MyClass l_C1;
    //int* l_Leak = new int[80];
    urUnion l_Union;

}
