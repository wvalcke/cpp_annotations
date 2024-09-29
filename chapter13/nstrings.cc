#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

string *nStrings(size_t size, char const *fname)
{
    static thread_local ifstream in;

    struct Xstr: public string
    {
        Xstr()
        :
            string(nextLine())
        {}
        static string nextLine()
        {
            string line;

            getline(in, line);
            return line;        // copy elision turns this
        }                       // into Xstr's base class string
    };
    in.open(fname);
    string *sp = new Xstr[size];
    in.close();

    return sp;
}

int main(int argc, char*argv[])
{
    string *sp = nStrings(10, "nstrings.cc");
    copy(sp, sp + 10, ostream_iterator<string>{ cout, "\n" });
}
