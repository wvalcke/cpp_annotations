    #include <numeric>
    #include <algorithm>
    #include <vector>
    #include <iostream>
    #include <iterator>

    using namespace std;

    int main()
    {
        vector<size_t> uv(10);

        iota(uv.begin(), uv.end(), 0);

        copy(uv.begin(), uv.end(), ostream_iterator<int>{ cout, " " });
        cout << '\n';
    }
    // Displays:   0 1 2 3 4 5 6 7 8 9
