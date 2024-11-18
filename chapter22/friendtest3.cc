#include <iostream>
#include <string>

using namespace std;

// Die template declaratie moet hier staan, anders compileert het niet
// maar die declaratie is er niet bij friendtest4 ?? en toch werkt het daar
template<typename Type>
bool operator==(Type const& lhs, Type const& rhs);

template <typename Type>
struct String
{
    struct iterator
    {
        std::string::iterator d_iter;


        friend bool operator==<>(iterator const &lhs, iterator const &rhs);

    /* Waarom moet hier expliciet operator==<> staan ipv operator== */
    /* De reden is dat de free method eigenlijk een template moet zijn want het werkt
     * met de argumenten iterator dewelke impliciet afhankelijk zijn van de class template String
     * Door die <> zeggen we expliciet dat de free function een specialization is van 
     * een function template
     * Doen we dit niet geeft de compiler volgende warning
     *         warning: friend declaration ‘bool operator==(const String<Type>::iterator&, const String<Type>::iterator&)’ declares a non-template function [-Wnon-template-friend]
   16 |         friend bool operator==(iterator const &lhs, iterator const &rhs);
      |                                                                        ^
/mnt/DV/wim/cppannotations_12.5/chapter22/friendtest3.cc:16:72: note: (if this is not what you intended, make sure the function template has already been declared and add ‘<>’ after the function name here)
    };

     * 
    */

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

//template<typename Type>
//bool operator==(typename String<Type>::iterator const& lhs, typename String<Type>::iterator const& rhs)
//{
//    return lhs.d_iter == rhs.d_iter;
//}


template<typename Type>
bool operator==(Type const& lhs, Type const& rhs)
{
    return lhs.d_iter == rhs.d_iter;
}

// Alles werkt uiteindelijk hier, maar er is een probleem als we meer dan 1 klasse hebben ala String
// Zie voorbeeld friendtest4. Het probleem dat daar ontstaat is dat de template implementatie 
// van de free function template operator== niet werkt voor het type Container
// We moeten dus een onderscheid kunnen maken in argumenten. 
// Dit is de reden van bovenstaande implementatie maar die werkt ook niet.

int main(int argc, char*argv[])
{
    String<int> str;
    return  str.begin() == str.begin();
}
