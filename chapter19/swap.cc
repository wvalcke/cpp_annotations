    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <iterator>
    using namespace std;

    void show(string const *begin, string const *end)
    {
        copy(begin, end, ostream_iterator<string>(cout, " "));
        cout << '\n';
    }

    int main()
    {
        string first[] = { "alpha", "bravo", "charley" };
        string second[] = { "echo", "foxtrot", "golf" };

        cout << "Before:\n";
        show(first, end(first));
        show(second, end(second));

        for (size_t idx = 0; idx < size(first); ++idx)
            swap(first[idx], second[idx]);

        cout << "After:\n";
        show(first, end(first));
        show(second, end(second));

        swap_ranges(first, end(first), second);

        cout << "After swap_ranges:\n";
        show(first, end(first));
        show(second, end(second));

    }
    //  Displays:
    //    Before:
    //    alpha bravo charley
    //    echo foxtrot golf
    //    After:
    //    echo foxtrot golf
    //    alpha bravo charley
    //    After swap_ranges:
    //    alpha bravo charley
    //    echo foxtrot golf
