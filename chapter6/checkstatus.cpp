#include <iostream>
#include <fstream>
using namespace std;

void writeStatus(istream& p_Stream)
{
    cout << "Bad bit : " << p_Stream.bad() << '\n';
    cout << "EOF bit : " << p_Stream.eof() << '\n';
    cout << "Fail bit : " << p_Stream.fail() << '\n';
}

int main(int argc, char*argv[])
{
    string l_Line;
    getline(cin, l_Line);
    cout << "Read : " << l_Line << '\n';
    writeStatus(cin);

    ifstream l_Input("nonewline.txt");
    writeStatus(l_Input);
    getline(l_Input, l_Line);
    cout << "Read : " << l_Line << '\n';
    writeStatus(l_Input);

    l_Input.close();
    l_Input.open("nonewline.txt");

    // Here we can see that the explanation in the cpp annotations is wrong
    // istream &getline(char *buffer, int len, char delim = '\n')
    // the fail bit is not set, the EOF bit is set
    // So the behavior is the same as the std::getline() method
    char l_Buffer[100];
    l_Input.getline(l_Buffer, 100, '\n');
    std::cout << "Read " << l_Input.gcount() << " bytes" << '\n';
    writeStatus(l_Input);
}

