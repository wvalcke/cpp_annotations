    #include <algorithm>
    #include <string>
    #include <iostream>
    #include <cctype>
    using namespace std;

    void lowerCase(char &ch)                     // `ch' *is* modified
    {
        ch = tolower(static_cast<unsigned char>(ch));
    }

    void capitalizedOutput(string const &str)   // `str' is *not* modified
    {
        char *tmp = new char[str.size() + 1]();
        str.copy(tmp, str.size());

        for_each(tmp + 1, tmp + str.size(), lowerCase);

        tmp[0] = toupper(*tmp);
        cout << tmp << ' ';
        delete[] tmp;
    }

    int main()
    {
        string sarr[] =
            {
                "alpha", "BRAVO", "charley", "DELTA",  "echo",
                "FOXTROT", "golf", "HOTEL"
            };

        for_each(sarr, end(sarr), capitalizedOutput)("that's all, folks");
        cout << '\n';
    }
    // Displays:
    // Alpha Bravo Charley Delta Echo Foxtrot Golf Hotel That's all, folks
