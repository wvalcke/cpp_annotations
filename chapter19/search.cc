    #include <algorithm>
    #include <iostream>
    #include <iterator>
    using namespace std;

    bool absEq(int i1, int i2)
    {
        return abs(i1) == abs(i2);
    }

    int main()
    {
        int range1[] =  {-2, -4, -6, -8, 2, 4, 4, 6, 8};
        int range2[] =  {6, 8};

        copy
        (
            search(range1, end(range1), range2, range2 + 2),
            end(range1), ostream_iterator<int>(cout, " ")
        );
        cout << '\n';

        copy
        (
            search(range1, end(range1), range2, range2 + 2, absEq),
            end(range1), ostream_iterator<int>(cout, " ")
        );
        cout << '\n';

        copy
        (
            search_n(range1, end(range1), 2, 4, absEq),
            end(range1), ostream_iterator<int>(cout, " ")
        );
        cout << '\n';
    }
    //  Displays:
    //      6 8
    //      -6 -8 2 4 4 6 8
    //      4 4 6 8
