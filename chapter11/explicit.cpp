class Person
{

};

class Database
{
public:
    Database(Person const& person);
    Database(istream &in);
    Database(size_t count, istream &in = cin);
};

int main(int argc, char*argv[])
{
    Database db;
    Database db2;
    Person person;

    db2 = db;
    db2 = person; // can be done via conversion of Person to Database
    db2 = 10; // can be done via conversion size_t to Database
    db2 = cin; // can be done via conversion to Database


}

We veranderen 


class Database
{
public:
    explicit Database(Person const& person);
    explicit Database(istream &in);
    explicit Database(size_t count, istream &in = cin);
};

Dan moet nu het volgende gebeuren

int main(int argc, char*argv[])
{
    Database db;
    Database db2;
    Person person;

    db2 = db;
    db2 = Database{person}; // de impliciete conversie gebeurt niet meer, we moeten effectief de 
                            // constructor oproepen
    db2 = Database{10}; // can be done via conversion size_t to Database
    db2 = Datbase{cin}; // can be done via conversion to Database


}


// explicit conversion

void process(bool value);

    class StreamHandler
    {
        public:
            operator bool() const;      // true: object is fit for use
            ...
    };

    int fun(StreamHandler &sh)
    {
        int sx;

        if (sh)                         // intended use of operator bool()
            ... use sh as usual; also use `sx'

        process(sh);                    // typo: `sx' was intended
    }

Maak explicit via
 

When defining explicit conversion operators implicit conversions like the one shown in the example 
are prevented. Such conversion operators can only be used in situations where the converted type is 
explicitly required (as in the condition clauses of if or while statements), or is explicitly requested 
using a static_cast. To declare an explicit bool conversion operator in class StreamHandler's interface 
replace the above declaration by:

explicit operator bool() const;

Since the C++14 standard istreams define an explicit operator bool() const

while (cin.get(ch)) // compiles OK
        ;

    bool fun1()
    {
        return cin;     // 'bool = istream' won't compile as 
    }                   // istream defines 'explicit operator bool'

    bool fun1()
    {
        return static_cast<bool>(cin); // compiles OK
    }

    