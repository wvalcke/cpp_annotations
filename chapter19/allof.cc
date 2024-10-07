    #include <algorithm>
    #include <string>
    #include <iostream>
    using namespace std;

    bool contains_a(string const &str)
    {
        return str.find('a') != string::npos;
    }

    int main()
    {
        string sarr[] =
            { "Alpha", "Bravo", "Charley", "Delta", "Echo" };
        auto past = end(sarr);      // see the next section

        cout << "All elements contain 'a': " <<
            all_of(sarr, past, contains_a) << "\n"
            "At least one element contains 'a': " <<
            any_of(sarr, past, contains_a) << "\n"
            "None of the elements contains 'a': " <<
            none_of(sarr, past, contains_a) << '\n';
    }
    //  Displays:
    //      All elements contain 'a': 0
    //      At least one element contains 'a': 1
    //      None of the elements contains 'a': 0
