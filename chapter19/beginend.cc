    #include <iterator>
    #include <iostream>
    #include <string>
    using namespace std;

    int main()
    {
        string sarr[] =
            { "Alpha", "Bravo", "Charley", "Delta", "Echo" };

        // since sarr == begin(sarr), begin(...) is not used here
        auto next = end(sarr);

        cout << "sarr has " << size(sarr) <<
                " (== " << (next - sarr) << ") elements\n"
                "the last char. of the first element is " <<
                *(end(sarr[0]) - 1) << '\n';
    }
    //  Displays:
    //    sarr has 5 (== 5) elements
    //    the last char. of the first element is a
