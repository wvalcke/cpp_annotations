#include <iostream>

using namespace std;

template<typename Type>
void OpenMethod(Type p);

template<typename Type>
class ClassTemplate
{
    friend void OpenMethod<ClassTemplate<Type>>(ClassTemplate<Type>);
    // friend void OpenMethod<>(ClassTemplate<Type>); // werkt ook
    // Deze werkt niet
    // friend void OpenMethod(ClassTemplate<Type>);
    /*
    * De compiler geeft een warning al dat de method als non template friend wordt gezien (maw gewone method)
    * Het compileert wel, maar bij linken vindt de compiler de OpenMethod(ClassTemplate<int>) niet.
    * Dus de <> moeten er minstens bijstaan na de funtienaam OpenMethod
    */
    Type d;
    Type getValue()
    {
        return d;
    }
public:
    ClassTemplate(Type p)
    : d(p)
    {

    }
};

template<typename Type>
void OpenMethod(Type p)
{
    cout << p.getValue() << '\n';
}

int main(int argc, char*argv[])
{
    ClassTemplate<int> v(9);
    OpenMethod(v);
}
