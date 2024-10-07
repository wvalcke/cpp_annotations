    #include <algorithm>
    #include <string>
    #include <iostream>
    #include <iterator>
    using namespace std;

    bool pred(std::string const &str)
    {
        return "aceg"s.find(str.front()) == string::npos;
    }

    int main()
    {
        string sarr[] =
            {
                "alpha", "bravo", "charley", "delta", "echo",
                "foxtrot", "golf", "hotel"
            };
        auto last = end(sarr);

        copy(sarr + 2, last, sarr); // move all elements two positions left

                     // copy to cout using an ostream_iterator for strings
        copy(sarr, last, ostream_iterator<string>(cout, " "));
        cout << '\n';

                    // using copy_if:
        copy_if(sarr, sarr + size(sarr), sarr, pred);
        copy(sarr, sarr + size(sarr), ostream_iterator<string>(cout, " "));
        cout << '\n';

    }
    //  Displays:
    //  charley delta echo foxtrot golf hotel golf hotel
    //  delta foxtrot hotel hotel golf hotel golf hotel
