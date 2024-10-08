    #include <algorithm>
    #include <iostream>
    #include <functional>
    #include <iterator>
    using namespace std;

    int main()
    {
        int ia[] = { 1, 9, 5, 3, 7, 2, 4, 6, 8, 10 };
        int ia2[6];

        partial_sort_copy(ia, ia + 10, ia2, ia2 + 6);
        cout << "the 6 smallest elements: ";
        copy(ia2, ia2 + 6, ostream_iterator<int>(cout, " "));
        cout << '\n';

        partial_sort(ia, ia + 3, ia + 10);

        cout << "find the 3 smallest elements:\n";
        copy(ia, ia + 3, ostream_iterator<int>(cout, " "));
        cout << '\n';

        cout << "find the 5 largest elements:\n";
        partial_sort(ia, ia + 5, ia + 10, greater<int>());
        copy(ia, ia + 5, ostream_iterator<int>(cout, " "));
        cout << '\n';
    }
    //  Displays:
    //      the 6 smallest elements: 1 2 3 4 5 6
    //      find the 3 smallest elements:
    //      1 2 3
    //      find the 5 biggest elements:
    //      10 9 8 7 6
