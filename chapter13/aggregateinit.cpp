#include <iostream>
#include <string>

using namespace std;

struct Base
{
    int value;
};

struct Derived: public Base
{
    string text;
};


int main(int argc, char*argv[])
{
    // Initializiation of a Derived object:
    int myval = 8;
    Derived der{{myval}, "hello world"};
    //          -------
    //          initialization of Derived's base struct.

}
