#include <iostream>
#include <string.h>

class Person
{
    char *d_name = nullptr;
    char *d_address = nullptr;
    char *d_phone = nullptr;

    public:
        Person() = default;
        Person(char const *name, char const *addr, char const *phone);
        ~Person();
        Person& operator=(Person const &other);
    private:
        char *strdupnew(char const *src);   // returns a copy of src.
};

// strdupnew is easily implemented, here is its inline implementation:
inline char *Person::strdupnew(char const *src)
{
    return strcpy(new char [strlen(src) + 1], src);
}

Person::Person(char const *name, char const *addr, char const *phone)
{
    d_name = strdupnew(name);
    d_address = strdupnew(addr);
    d_phone = strdupnew(phone);
}

Person::~Person()
{
    delete[] d_name;
    delete[] d_address;
    delete[] d_phone;
}

 Person& Person::operator=(Person const &other)
{
    delete[] d_name;                      // delete old data
    delete[] d_address;
    delete[] d_phone;

    d_name = strdupnew(other.d_name);   // duplicate other's data
    d_address = strdupnew(other.d_address);
    d_phone = strdupnew(other.d_phone);

    return *this;
}

void tmpPerson(Person const &person)
{
    Person tmp;

    tmp = person;
    tmp.operator=(person);  // the same thing
}

void tmpPersonPointer(Person const &person)
{
    Person *tmp = new Person;

    // moet zo opgeroepen worden als het via een pointer is
    tmp->operator=(person);
    *tmp = person;          // yes, also possible...

    delete tmp;
}

int main(int argc, char*argv[])
{
    Person person("Name", "Address", "Phone");
    tmpPerson(person);
    tmpPersonPointer(person);
}
