#include <iostream>

using namespace std;

class MyClass
{
    int m_Id;
public:
    MyClass()
    {
        count++;
        m_Id = count;
        cout << "MyClass() constructor id " << count << '\n';
    }
    ~MyClass()
    {
        cout << "MyClass~ destructor id " << m_Id << '\n';
    }
    MyClass(MyClass&& ref)
    {
        count++;
        m_Id = count;
        cout << "MyClass(MyClass&&) move constructor id " << count << '\n';
    }
private:
    static int count;
};

void fun(MyClass&& ref)
{
    cout << "Calling fun with MyClass&& parameter" << '\n';
    MyClass mc{move(ref)};
}

int MyClass::count{0};

int main(int argc, char* argv[])
{
    cout << "Part 1\n"; 
    MyClass mc;
    cout << "Part 2\n";
    fun(move(mc));
    cout << "Part 3\n";
    fun(MyClass());
    cout << "Part 4\n";
    MyClass mc2 = MyClass();
}
