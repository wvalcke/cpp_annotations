    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <cstring>
    using namespace std;

    bool caseString(string const &first, string const &second)
    {
        return strcasecmp(first.c_str(), second.c_str()) <= 0;
    }

    string const &call(bool first, string const &lhs, string const &rhs)
    {
        return first? max(lhs, rhs) : min(lhs, rhs);
    }

    string const &call(bool first, string const &lhs, string const &rhs,
                bool (*cmp)(string const &, string const &))
    {
        return first? max(lhs, rhs, cmp) : min(lhs, rhs, cmp);
    }

    int main(int argc, char **argv) // no args: use max, else min
    {
        bool fun = argc == 1;
        char const *where = fun ? "last\n" : "first\n";

        cout << "Word '" << call(fun, "first", "second") <<
                            "' is lexicographically " << where <<

                "Word '" << call(fun, "first", "SECOND") <<
                            "' is lexicographically " << where <<

                "Word '" << call(fun, "first", "SECOND", caseString) <<
                            "' is lexicographically " << where;
    }
    //  Displays when calling without args:
    //      Word 'second' is lexicographically last
    //      Word 'first' is lexicographically last
    //      Word 'SECOND' is lexicographically last
    //  and with an argument:
    //      Word 'first' is lexicographically first
    //      Word 'SECOND' is lexicographically first
    //      Word 'first' is lexicographically first
