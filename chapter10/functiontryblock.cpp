#include <iostream>

/*

Ander function try block sample: 
De inializer list komt du na de try

!!!!
C++ standard: at the end of a catch-handler belonging to a constructor or destructor function 
try block, the original exception is automatically rethrown.

PersonDb::PersonDb(Person *pData, size_t size)
    try
    :
        d_data(pData),
        d_size(size),
        d_support(d_data, d_size)
    {}
    catch (...)
    {
        delete[] d_data;
    }

*/

class Throw
{
    public:
        Throw(int value)
        try
        {
            throw value;
        }
        catch(...)
        {
            std::cout << "Throw's exception handled locally by Throw()\n";
            throw;
        }
};

class Composer
{
    Throw d_t;
    public:
        Composer()
        try             // NOTE: try precedes initializer list
        :
            d_t(5)
        {}
        catch(...)
        {
            // alhoewel we zelf geen exceptie gooien, zal de C++ standaard dit hier doen
            // (als we het zelf dus niet doen) omdat we een constructor functie hebben
            std::cout << "Composer() caught exception as well\n";
        }
};

int main()
{
    try
    {
        Composer c;

    }
    catch(...)
    {

    }
}
