#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    ifstream in(argv[1]);
    double   value{0.0};

    // reads double in raw, binary form from file.
    in.read(reinterpret_cast<char *>(&value), sizeof(double));
    if (in)
    {
        std::cout << "Stream is in good state" << '\n';
    }
    else
    {
        std::cout << "Stream is not in good state" << '\n';
    }
    std::cout << "Stream bad bit " << in.bad() << '\n';
    std::cout << "Stream eof bit " << in.eof() << '\n';
    std::cout << "Stream fail bit " << in.fail() << '\n';
    
    std::cout << "Double value is " << value << '\n';
}
