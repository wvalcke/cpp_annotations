    #include <algorithm>
    #include <string>
    #include <iostream>
    #include <iterator>
    using namespace std;

    void show(string const *begin, string const *end)
    {
        copy(begin, end, ostream_iterator<string>(cout, ", "));
        cout << '\n';
    }

    int main()
    {
        string sarr[] = { "alpha", "bravo", "charley", "delta" };
        string dest[4] = { "", };

        auto last = end(sarr);

        auto lastDest = move(sarr, last, dest); // move all elements to dest

        cout << "sarr after move:\n";
        show(sarr, last);

        cout << "dest after move:\n";
        show(dest, lastDest);

        move_backward(dest, lastDest, last); // move_backward to sarr
        cout << "sarr after move_backward:\n";
        show(sarr, last);

        cout << "dest after move_backward:\n";
        show(dest, lastDest);
    }
    //  Displays:
    //    sarr after move:
    //    , , , ,
    //    dest after move:
    //    alpha, bravo, charley, delta,
