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
        string first1[] =
            {
                "alpha", "bravo", "charley", "delta",  "echo",
                "foxtrot", "golf", "hotel"
            };
        auto past1 = end(first1);

        string first2[] =
            {
                "Alpha", "bravo", "Charley", "delta",  "Echo",
                "foxtrot", "Golf", "hotel"
            };
        auto past2 = end(first2);

        string second[] = { "charley", "foxtrot", "hotel" };

        cout << "The elements of `second' are " <<
            (includes(first1, past1, second, second + 3) ? "" : "not") <<
               " contained in the first sequence:\n"
               "second is a subset of first1\n"

            "The elements of `first1' are " <<
            (includes(second, second + 3, first1, past1) ? "" : "not") <<
            " contained in the second sequence\n"

            "The elements of `second' are " <<
            (includes(first2, past2, second, second + 3) ? "" : "not") <<
            " contained in the first2 sequence\n"

            "Using case-insensitive comparison,\n"
            "the elements of `second' are " <<
            (includes(first2, past2, second, second + 3, caseString) ?
                                                           "" : "not") <<
            " contained in the first2 sequence\n";
    }
    //  Displays:
    //     The elements of `second' are  contained in the first sequence:
    //     second is a subset of first1
    //     The elements of `first1' are not contained in the second sequence
    //     The elements of `second' are not contained in the first2 sequence
    //     Using case-insensitive comparison,
    //     the elements of `second' are  contained in the first2 sequence
