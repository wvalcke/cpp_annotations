#include <iostream>
#include <string>

using namespace std;

class String
{
public:
    String(std::string data) : m_data(data)
    {
        cout << "Constructor called String() " << m_data << '\n';
    }
    String(String&& other)
    {
        cout << "Calling move constructor " << other.m_data << '\n';
        m_data = other.m_data;
    }
    ~String()
    {
        cout << "Destructor called ~String() " << m_data << '\n';
    }
    String(String const& other)
    {
        cout << "Calling copy constructor from " << other.m_data << '\n';
        m_data = other.m_data;
    }
    void modify(std::string const& data)
    {
        m_data = data;
    }
private:
    std::string m_data;
};

void fie(String const& data)
{
    cout << "Called fie (String const&)" << '\n';
}

void fie(String && data)
{
    cout << "Called fie (String &&)" << '\n';
}

String apply(String data)
{
    cout << "Entering method apply" << '\n';
    String retfie("retfie");
    return retfie;
}

String factory(int a)
{
    cout << "Entering factory method" << '\n';
    String l_Ret("factoryreturn");
    return l_Ret;
}

int main(int argc, char*argv[])
{
    fie(String(""));
    cout << "--------------------" << '\n';
    String input("input");
    String ret = apply(input);
    ret.modify("retmain");


    // The g++ compiler will only call the constructor for the 'store' element
    // once. Actually inside factory function for the l_Ret element
    // The compiler is smart enough to see that the return value of factory is put
    // inside store, therefore it does not copy construct store from the return value
    // In the end the destructor is called only once for the store element when main function is left
    // The principle here is that the constructed object inside factory is moved into the store element
    // as such creating something, take a copy and then delete the original is avoided
    cout << "----------------------" << '\n';
    String store(factory(0));
    store.modify("store");
    cout << "After store creation" << '\n';

}
