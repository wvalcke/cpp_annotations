    #include <algorithm>
    #include <iterator>
    #include <iostream>
    #include <string>
    using namespace std;

    int main()
    {
        string first[] = { "alpha", "bravo", "charley" };
        string second[] = { "echo", "foxtrot", "golf" };

        cout << "Before:\n";
        copy(first, first + 3, ostream_iterator<string>(cout, " "));
        cout << '\n';
        copy(second, second + 3, ostream_iterator<string>(cout, " "));
        cout << '\n';

        for (size_t idx = 0; idx != 3; ++idx)
            iter_swap(first + idx, second + idx);

        cout << "After:\n";
        copy(first, first + 3, ostream_iterator<string>(cout, " "));
        cout << '\n';
        copy(second, second + 3, ostream_iterator<string>(cout, " "));
        cout << '\n';
    }
    //  Displays:
    //      Before:
    //      alpha bravo charley
    //      echo foxtrot golf
    //      After:
    //      echo foxtrot golf
    //      alpha bravo charley
