#include <iostream>

class Person
{
    int m_Data;

public:
    Person()
    : m_Data(0)
    {
        initData();
    }

    void initData()
    {
        m_Data = 1;
    }

};

int main(int argc, char*argv[])
{
    Person const l_P;
    // l_P.initData(); gaat niet, maar de constructor kan dit wel alhoewel het een const object is
    // Volgens de CPP annotations 10.11 zou dit niet gaan. ??
}
