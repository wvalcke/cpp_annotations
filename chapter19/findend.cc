    #include <algorithm>
    #include <string>
    #include <iterator>
    #include <iostream>
    using namespace std;

    bool twice(size_t first, size_t second)
    {
        return first == (second << 1);
    }

    int main()
    {
        string sarr[] =
            {
                "alpha", "bravo", "charley", "delta", "echo",
                "foxtrot", "golf", "hotel",
                "foxtrot", "golf", "hotel",
                "india", "juliet", "kilo"
            };
        string search[] =
            {
                "foxtrot",
                "golf",
                "hotel"
            };
        auto past = end(sarr);

        copy
        (
            find_end(sarr, past, search, search + 3),   // sequence starting
            past, ostream_iterator<string>{ cout, " " } // at 2nd 'foxtrot'
        );
        cout << '\n';

        size_t range[] = { 2, 4, 6, 8, 10, 4, 6, 8, 10 };
        size_t nrs[]   = { 2, 3, 4 };

        copy                // sequence of values starting at last sequence
        (                   // of range[] that are twice the values in nrs[]
            find_end(range, range + 9, nrs, nrs + 3, twice),
            range + 9, ostream_iterator<size_t>{ cout, " " }
        );
        cout << '\n';
    }
    //  Displays:
    //      foxtrot golf hotel india juliet kilo
    //      4 6 8 10
