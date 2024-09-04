#include <iostream>
#include <string>

using namespace std;

union Union
{
    enum Field
    {
        TEXT,
        VALUE
    };

    private:
        std::string u_text;
        int u_value;
        static void (Union::*s_destroy[])();
        static void (Union::*s_copy[])(Union const &other);
        static void (Union::*s_swap[][2])(Union &other);

        void destroyText();
        void destroyValue();
        void copyText(Union const& other);
        void copyValue(Union const& other);

        void swap2Text(Union &other);            // swaps equal types
        void swapTextValue(Union &other);

        void swapValueText(Union &other);        // (reverses operands)
        void swap2Value(Union &other);           // swaps equal types


    public:
        Union(Union const &other) = delete;
        ~Union();               // empty

        Union(int value);
        Union(std::string const &text);
        
        void destroy(Field type);

        Union(Union const &other, Field type);
        Union(Union &&tmp, Field type);

        void swap(Field current, Union &other, Field next);
        void copy(Field type, Union const &other, Field next);
/*
* Let op met &&
* Een niet anoniem object meegeven compileert niet !
*/    
        void move(Field type, Union &&tmp, Field next);
};

class Data
{
    Union::Field d_field;
    Union d_union;

    public:
        Data(int value = 0);
        Data(std::string const &text);
        Data(Data const &other);
        Data(Data &&tmp);

        ~Data();                // empty body

        Data& operator=(Data const& other);
        Data& operator=(Data && other);

        void swap(Data &other);

        Union::Field field() const;
};

/*
* Code lijkt wat vreemd, maar wat hier staat is dat s_destroy een array is van pointers
* naar een member functie van Union, die void retourneert en geen argumenten heeft, vandaar die () voor =
*/
void (Union::*Union::s_destroy[])() = 
{
    &Union::destroyText,
    &Union::destroyValue
};

void (Union::*Union::s_copy[])(Union const&) = 
{
    &Union::copyText,
    &Union::copyValue
};

void (Union::*Union::s_swap[][2])(Union &other) = 
{
    {  &Union::swap2Text,     &Union::swapTextValue},
    {  &Union::swapValueText, &Union::swap2Value},
};

Union::~Union()
{
    // do nothing
}

Union::Union(int value)
: u_value(value)
{
}

Union::Union(std::string const& text)
: u_text(text)
{
}

void Union::destroyValue()
{
    // nothing to do
}

void Union::destroyText()
{
    u_text.std::string::~string();
}

void Union::destroy(Field type)
{
    // let op de haakjes rond this->*...
    (this->*s_destroy[type])();
}

void Union::copyValue(Union const &other)
{
    u_value = other.u_value;
}

/*
* Waarom deze rare vorm van implementeren ?
* We willen hier een hulpmethod maken voor de (copy) constructor van Union(Union const &other, Field type)
* De normale copy constructor Union::Union(Union const&) versie is expliciet = delete gezet
* Dit moesten we doen omdat we niet zomaar alles kunnen copieren, want we moeten weten over welk field
* het hier gaat. Daarom is er een nieuwe method gemaakt Union(Union const &other, Field type)
* waarbij we dus meegeven welk Field we willen copieren. Die implementatie maakt gebruik van de s_copy array methods
* om de functionaliteit generiek te kunnen implementeren onafhankelijk van het field type
* Nu als we die (copy) constructor gebruiken Union(Union const &other, Field type) dan kunnen we enkel
* in die implementatie een initializer list gebruiken ( zoals : m_data(p_data), ...) hiermee kunnen we voor class 
* type values de correcte eventuele parameters meegeven, en vermijden we inefficientie
* Maar hier gaat dat niet want de moeten die initializer list aanpassen afhankelijk van wat in Field type staat
* We moeten dus in de {} implementatie het dan maar doen. Als we in die code zitten, dan is het Union object
* qua data nog compleet nonsens, er is gewoon geheugen voorzien, maar geen enkele constructor is opgeroepen,
* dus ook niet voor het std::string member. Voor gewone primitieve types kunnen we gewoon een assignment doen
* want een non init float bvb kan je assigneren aan 0.0 bvb. Maar dit gaat niet met een std::string bvb
* want om de operator= op te roepen met je wel een geconstrueerd object hebben.
* Daarom moeten we dus de constructor oproepen van die std::string member in dit geval. En de enige manier
* om dit te doen is via placement new en laten verwijzen naar dat std::string geheugen stuk om daarop de std::string
* constructor op los te laten
* 
*/
void Union::copyText(Union const &other)
{
    new(&u_text) string{ other.u_text };
}

Union::Union(Union const &other, Field type)
{
    (this->*s_copy[type])(other);
}

Union::Union(Union&& tmp, Field type)
{
    swap(VALUE, tmp, type);
}

void Union::swap(Field here, Union &other, Field there)
{
    (this->*s_swap[here][there])(other);
}


void Union::swap2Text(Union& other)
{
    u_text.swap(other.u_text);
}

void Union::swap2Value(Union& other)
{
    int l_Temp;
    l_Temp = u_value;
    u_value = other.u_value;
    other.u_value = l_Temp;
}

void Union::swapValueText(Union &other)
{
    other.swapTextValue(*this);
}

void Union::swapTextValue(Union &other)
{
    int value = other.u_value;  // save the int value
                                // install string at other
    new(&other.u_text) string{ std::move(u_text) }; 
    u_text.~string();           // remove the old field's union

    u_value = value;            // store current's new value
}

void Union::copy(Field type, Union const &other, Field next)
{
    Union tmp{ other, next };   // create a copy
    swap(type, tmp, next);      // swap *this and tmp
    tmp.destroy(type);          // destroy tmp
}
    
void Union::move(Field type, Union &&tmp, Field next)
{
    swap(type, tmp, next);
}

Data::~Data()
{
    d_union.destroy(d_field);
}

Data::Data(int value)
:
    d_field(Union::VALUE),
    d_union(value)
{}
    
Data::Data(string const &txt)
:
    d_field(Union::TEXT),
    d_union(txt)
{}

Data::Data(Data const& other)
: d_field(other.d_field),
    d_union(other.d_union, d_field)
{

}

Data::Data(Data&& tmp)
: d_field(Union::VALUE),
    d_union(0)
{
    swap(tmp);
}

void Data::swap(Data &other)
{
    d_union.swap(d_field, other.d_union, other.d_field);

    Union::Field field = d_field;   // swap the fields
    d_field = other.d_field;
    other.d_field = field;
}

Data &Data::operator=(Data const &other)    // copy-assignment
{
    Data tmp{ other };
    swap(tmp);
    return *this;
}

Data &Data::operator=(Data &&tmp)           // move-assignment
{
    swap(tmp);
    return *this;
}

Union::Field Data::field() const
{
    return d_field;
}

int main(int argc, char*argv[])
{
    Union* u1 = new Union("U1");
    Union* u2 = new Union("U2");
    u1->move(Union::TEXT, Union("TEMP"), Union::TEXT);
    delete u2;
    delete u1;
}
