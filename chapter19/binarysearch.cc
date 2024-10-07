    #include <algorithm>
    #include <string>
    #include <iostream>
    #include <functional>
    using namespace std;

    int main()
    {
        string sarr[] =
            {
                "alpha", "bravo", "charley", "delta", "echo",
                "foxtrot", "golf", "hotel"
            };
        auto past = end(sarr);
        bool result = binary_search(sarr, past, "foxtrot");
        cout << (result ? "found " : "didn't find ") << "foxtrot" << '\n';

        reverse(sarr, past);                // reverse the order of elements
                                            // binary search now fails:
        result = binary_search(sarr, past, "foxtrot");
        cout << (result ? "found " : "didn't find ") << "foxtrot" << '\n';
                                            // ok when using appropriate
                                            // comparator:
        result = binary_search(sarr, past, "foxtrot", greater<string>());
        cout << (result ? "found " : "didn't find ") << "foxtrot" << '\n';

        // alternatively, using a lambda expression showing the used 'sarr'
        // indices and the value of the second parameter:

        result = binary_search(sarr, past, "foxtrot",
            [&](string const &sarrEl, string const &value)
            {
                cout << "comparing element " << (&sarrEl - sarr) <<
                        " (" << sarrEl << ") to " << value << '\n';
                return sarrEl > value;
            }
        );
        cout << "found it: " << result << '\n';
    }
    //  Displays:
    //      found foxtrot
    //      didn't find foxtrot
    //      found foxtrot
    //      comparing element 4 (delta) to foxtrot
    //      comparing element 2 (foxtrot) to foxtrot
    //      comparing element 1 (golf) to foxtrot
    //      comparing element -3 (foxtrot) to foxtrot
    //      found it: 1
