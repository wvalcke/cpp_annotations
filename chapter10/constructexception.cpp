#include <iostream>

/*
Als de constructor een exceptie gooit, wordt de destructor nooit opgeroepen
Je kan dan bvb ervoor zorgen dat je lokaal de exceptie opvangt inde constructor body
Dan kan je ervoor zorgen dat de destructor dan toch wordt opgeroepen
Maar wat moet je doen als de exceptie gebeurt bij de intializer list of
bij constructie van basis klasse ?
Je kan dan bvb een function try block gebruiken
class Incomplete2
{
    Composed d_composed;
    public:
        Incomplete2()
        try
        :
            d_composed( aguments ... )
        {
            // body
        }
        catch (...)
        {}
};

Maar bij een function try block in combinatie met een constructor zal er steeds een exceptie
verder gegooid worden (als je het zelf niet doet). 
Dus altijd gaat de exceptie verder, maw in dit geval wordt de destructor niet opgeroepen
Dus is de constructor hier verantwoordelijk om eem memory leak te vermijden
(de zogenaamde basic guarantee)

Maar hoe ??
De catch clause van een function try block kan NIET aan de member data....
Feiten:
* Bij overerving als een basis klasse correct geconstrueerd is, maar ergens in een latere klasse hebben
  we een exceptie dan zal de basis klasse destructor worden opgeroepen, want dit object is volledig
  geconstrueerd
* Bij compositie : deze elementen worden destructed, het zijn immers volledig gecontrueerde objecten
* Als je met plain pointers zit, gebruik dan smart pointers. Daar dit 'objecten' zijn (compositie)
  wordt dus de destructor hiervaan ook opgeroepen
* Als plain pointers effectief een must zijn, dan moet je een try-catch hebben in de body van de 
  constructor. Zet dan de pointers op nullptr in de initalizer list, en doe de allocatie in de body
  van de constructor

class Incomplete2
{
    Composed d_composed;
    char *d_cp;         // plain pointers
    int *d_ip;

    public:
        Incomplete2(size_t nChars, size_t nInts)
        try
        :
            d_composed( arguments ),    // might throw
            d_cp(0),
            d_ip(0)
        {
            try
            {
                preamble();                     // might throw
                d_cp = new char[nChars];        // might throw
                d_ip = new int[nChars];         // might throw
                postamble();                    // might throw
            }
            catch (...)
            {
                delete[] d_cp;                  // clean up
                delete[] d_ip;
                throw;                          // retrow the exception
            }
        }
        catch (...)
        {
            // maybe write a log-entry, but also throws 
            // the original exception
        }
};
*/

using namespace std;

class Incomplete
{
    public:
        Incomplete()
        {
            cerr << "Allocated some memory\n";
            throw 0;
        }
        ~Incomplete()
        {
            cerr << "Destroying the allocated memory\n";
        }
};

int main()
{
    try
    {
        cerr << "Creating `Incomplete' object\n";
        Incomplete{};
        cerr << "Object constructed\n";
    }
    catch(...)
    {
        cerr << "Caught exception\n";
    }
}
