    #include <algorithm>
    #include <iostream>
    #include <iterator>
    #include <vector>
    #include <functional>
    using namespace std;

    int main()
    {
        int     ia[] = { 10, 20, 30 };

        cout << "Sequence: ";
        copy(ia, ia + 3, ostream_iterator<int>(cout, " "));
        cout << "\n"
                "15 can be inserted before " <<
                *lower_bound(ia, ia + 3, 15) << "\n"
                "35 can be inserted after " <<
                (lower_bound(ia, ia + 3, 35) == ia + 3 ?
                                    "the last element" : "???") << '\n';

        cout << "Sequence: ";
        copy(ia, ia + 3, ostream_iterator<int>(cout, " "));
        cout << "\n"
                "15 can be inserted before " <<
                *lower_bound(ia, ia + 3, 15, less<int>()) << "\n"
                "35 can be inserted before " <<
                (lower_bound(ia, ia + 3, 35, less<int>()) == ia ?
                                    "the first element " : "???") << '\n';

        vector<int> array{ 5, 10, 20, 20, 20, 30 };
        auto iter = lower_bound(array.begin(), array.end(), 20,
                        [&](int &arrayEl, int value)
                        {
                            cout << "Comparing " << arrayEl <<
                                " (index: " << (&arrayEl - &array[0]) << ")"
                                " to " << value << '\n';
                            return arrayEl < value;
                        }
                    );
        cout << "New 20 to insert at idx " << (iter - array.begin()) << '\n';
    }
    //  Displays:
    //      Sequence: 10 20 30
    //      15 can be inserted before 20
    //      35 can be inserted after the last element
    //      Sequence: 10 20 30
    //      15 can be inserted before 20
    //      35 can be inserted before ???
    //      Comparing 20 (index: 3) to 20
    //      Comparing 10 (index: 1) to 20
    //      Comparing 20 (index: 2) to 20
    //      New 20 to insert at idx 2
