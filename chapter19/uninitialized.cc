#include <memory>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    char raw[4 * sizeof(string)];       // raw memory to receive strings
    string *ptr = reinterpret_cast<string *>(raw);  // pointer to strings

                                        // construct 4 strings in raw
    uninitialized_default_construct_n(ptr, 4);
    destroy(ptr, ptr + 4);              // call the strings' destructors

    vector<string> vs(4, "string");     // move 4 strings to raw memory
    uninitialized_move(vs.begin(), vs.end(), ptr);

    cout << vs.front() << ", " << vs.back() << '\n' <<
            ptr[0] << ", " << ptr[3] << '\n';

    destroy(ptr, ptr + 4);              // call the strings' destructors
}
//  Displays:
//      ,
//      string, string
