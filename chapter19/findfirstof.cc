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
        (                                                 // sequence starting
            find_first_of(sarr, past, search, search + 3),// at 1st 'foxtrot'
            past, ostream_iterator<string>{ cout, " " }
        );
        cout << '\n';

        size_t range[] = {2, 4, 6, 8, 10, 4, 6, 8, 10};
        size_t nrs[]   = {2, 3, 4};

            // copy the sequence of values in 'range', starting at the
            // first element in 'range' that is equal to twice one of the
            // values in 'nrs', and ending at the past element of 'range'
        copy
        (
            find_first_of(range, range + 9, nrs, nrs + 3, twice),
            range + 9, ostream_iterator<size_t>{ cout, " " }
        );
        cout << '\n';
    }
    //  Displays:
    //      foxtrot golf hotel foxtrot golf hotel india juliet kilo
    //      4 6 8 10 4 6 8 10
