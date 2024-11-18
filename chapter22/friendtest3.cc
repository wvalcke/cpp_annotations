#include <iostream>
#include <string>

using namespace std;

template<typename Type>
bool operator==(Type const& lhs, Type const& rhs);

template <typename Type>
struct String
{
    struct iterator
    {
        std::string::iterator d_iter;

        friend bool operator==<>(iterator const &lhs, iterator const &rhs);
    };

    iterator begin()
    {
        return iterator{};
    }
};

/*
* Alhoewel dit compileert linkt het programma niet. De friend declaratie bovenaan verwacht 
* een bepaalde signatuur zijnde 2 parameters String<Type>::iterator
* Het probleem voor de compiler zijn de 2 typename items hieronder. Hierdoor beslist de compiler
* dat deze niet overeenkomt met de friend declaratie hieboven, waardoor de referentie naar die 
* friend declaratie zogezegd niet bestaat, en daardoor het link probleem vertoont.
*/
template<typename Type>
bool operator==(typename String<Type>::iterator const& lhs, typename String<Type>::iterator const& rhs)
{
    return lhs.d_iter == rhs.d_iter;
}

int main(int argc, char*argv[])
{
    String<int> str;
    return  str.begin() == str.begin();
}
