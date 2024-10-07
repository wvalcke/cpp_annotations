    #include <algorithm>
    #include <string>
    #include <cstring>
    #include <iostream>
    using namespace std;

    bool caseString(string const &first, string const &second)
    {
        return strcasecmp(first.c_str(), second.c_str()) == 0;
    }

    int main()
    {
        string first[] =
            {
                "Alpha", "bravo", "Charley", "delta", "Echo",
                "foxtrot", "Golf", "hotel"
            };
        string second[] =
            {
                "alpha", "bravo", "charley", "delta", "echo",
                "foxtrot", "golf", "hotel"
            };
        auto past = end(first);

        cout << "The elements of `first' and `second' are pairwise " <<
            (equal(first, past, second) ? "equal" : "not equal") <<
            '\n' <<
            "compared case-insensitively, they are " <<
            (
                equal(first, past, second, caseString) ?
                    "equal" : "not equal"
            ) << '\n';
    }
    //  Displays:
    //      The elements of `first' and `second' are pairwise not equal
    //      compared case-insensitively, they are equal
