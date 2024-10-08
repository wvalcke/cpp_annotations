    #include <algorithm>
    #include <string>
    #include <cstring>
    #include <iostream>
    #include <utility>
    using namespace std;

    bool caseString(string const &first, string const &second)
    {
        return strcasecmp(first.c_str(), second.c_str()) == 0;
    }

    int main()
    {
        string range1[] = { "alpha", "bravo", "foxtrot", "hotel", "zulu" };
        string range2[] = { "alpha", "bravo", "foxtrot", "Hotel", "zulu" };
        pair<string *, string *> pss = mismatch(range1, range1 + 5, range2);

        cout << "The elements " << *pss.first << " and " << *pss.second <<
                " differ at index " << (pss.first - range1) << '\n';
        if
        (
            mismatch(range1, range1 + 5, range2, caseString).first
            ==
            range1 + 5
        )
            cout << "When compared case-insensitively they match\n";
    }
    /*
        Displays:
            The elements hotel and Hotel at offset 3 differ
            When compared case-insensitively they match
    */
