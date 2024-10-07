    #include <algorithm>
    #include <string>
    #include <iostream>
    #include <iterator>
    using namespace std;

    int main()
    {
        string sarr[] =
            {
                "alpha", "bravo", "charley", "delta", "echo",
                "foxtrot", "golf", "hotel"
            };
        auto past = end(sarr);

        copy
        (
            copy_backward(sarr + 3, past, past - 3),
            past,
            ostream_iterator<string>(cout, " ")
        );
        cout << '\n';
    }
    // Displays:    golf hotel foxtrot golf hotel foxtrot golf hotel
