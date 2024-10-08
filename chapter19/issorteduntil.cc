    #include <iterator>
    #include <algorithm>
    #include <vector>
    #include <iostream>
    using namespace std;

    int main()
    {
        vector<int> uv = { 1, -2, 3, -4, 5, -6, 7, -8, 9};

        auto iter = is_sorted_until(uv.begin(), uv.end());

        if (iter == uv.begin() + 1)
            cout << "no initially sorted subrange\n";

        sort(uv.begin(), uv.end());
        uv[5] = uv[0];                  // force a sorted subrange

        cout << "sorted subrange: ";
        copy(uv.begin(), is_sorted_until(uv.begin(), uv.end()),
            ostream_iterator<int>{ cout, " " });
        cout << '\n';
    }
    // Displays:
    //    no initially sorted subrange
    //    sorted subrange: -8 -6 -4 -2 1
