    #include <algorithm>
    #include <string>
    #include <cstring>
    #include <iterator>
    #include <iostream>
    using namespace std;

    class CaseName
    {
        std::string  d_string;

        public:
            CaseName(char const *str): d_string(str)
            {}
            bool operator()(std::string const &element) const
            {
                return strcasecmp(element.c_str(), d_string.c_str()) == 0;
            }
    };

    void show(string const *begin, string const *end)
    {
        if (begin == end)
            cout << "No elements were found";
        else
            copy(begin, end, ostream_iterator<string>{ cout, " " });
        cout << '\n';
    }

    int main()
    {
        string sarr[] =
            {
                "Alpha", "Bravo", "Charley", "Delta", "Echo"
            };
        auto past = end(sarr);

        show(find(sarr, past, "Delta"), past);
        show(find(sarr, past, "India"), past);

        show(find_if(sarr, sarr + size(sarr), CaseName{ "charley" }), past);

        if (find_if(sarr, sarr + size(sarr), CaseName{ "india" }) == past)
            cout << "`india' was not found in the range\n";

        show(find_if_not(sarr, sarr + size(sarr), CaseName{ "alpha" }), past);
    }
    //  Displays:
    //      Delta Echo
    //      No elements were found
    //      Charley Delta Echo
    //      `india' was not found in the range
    //      Bravo Charley Delta Echo
