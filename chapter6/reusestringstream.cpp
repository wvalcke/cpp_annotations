#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, char **argv)
{
    stringstream io;
    for (size_t redo = 0; redo != 2; ++redo)
    {
        io.clear();                 // clears the not-good flags
        io.str("");
        io << argv[0] << '\n';

        io.seekg(0);
        string line;
        while (getline(io, line))   // results in io.eof()
            cout << line << '\n';
        cout << "IO status fail is : " << io.fail() << '\n';
        cout << "IO status bad is : " << io.bad() << '\n';
        cout << "IO status eof is : " << io.eof() << '\n';
    }
}
