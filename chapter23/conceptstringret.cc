#include <iostream>
#include <string>
#include <concepts>

using namespace std;

std::string fun(int);
std::string fun(double);

// Define the `StringFun` concept
template<typename Type>
concept StringFun = 
    requires(Type param)
    {
        { fun(param) } -> std::same_as<std::string>;
    };

// Define an overloaded `fun` function for integers
std::string fun(int value)
{
    return "Integer: " + std::to_string(value);
}

// Define an overloaded `fun` function for doubles
std::string fun(double value)
{
    return "Double: " + std::to_string(value);
}

// Template function constrained by the `StringFun` concept
template<StringFun Type>
void process(Type value)
{
    cout << "Processing: " << fun(value) << endl;
}

int main()
{
    int a = 42;
    double b = 3.14;

    process(a); // Uses fun(int)
    process(b); // Uses fun(double)

    // Uncommenting the following lines would cause a compilation error
    // because `fun(char)` is not defined and `char` does not satisfy the `StringFun` concept.
    // char c = 'c';
    // process(c);

    return 0;
}
