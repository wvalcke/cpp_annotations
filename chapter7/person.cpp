#include "person.h" 
#include <iostream>                
using namespace std;

Person::Person()
{
    d_mass = 0;
}

Person::Person(string const &name, string const &address,
                   string const &phone, size_t mass)
{
    d_name = name;
    d_address = address;
    setPhone(phone);
    d_mass = mass;
}

void Person::setName(string const &name)
{
    d_name = name;
}

void Person::setAddress(string const &address)
{
    d_address = address;
}

void Person::setMass(size_t mass)
{
    d_mass = mass;
}

bool Person::hasOnly(char const *characters, string const &object)
{
                    // object only contains 'characters'
    return object.find_first_not_of(characters) == string::npos;
}

void Person::setPhone(string const &phone)
{
    if (phone.empty())
        d_phone = " - not available -";
    else if (hasOnly("0123456789 ", phone))
        d_phone = phone;
    else
        cout << "A phone number may only contain digits\n";
}

string const &Person::name() const
{
    return d_name;
}
string const &Person::address() const
{
    return d_address;
}
string const &Person::phone() const
{
    return d_phone;
}
size_t Person::mass() const
{
    return d_mass;
}
