    #include <algorithm>
    #include <iostream>
    #include <functional>

    using namespace std;

    int main()
    {
        vector<size_t> uv(10);

        auto values = minmax(5, 2, less<int>{});
        // just put the line below out of comment, and the compiler fails to compile
        // telling you what type values is. (deduced auto type)
        //int a = values;
        //pair<const int&, const int&> otherpair = minmax(5, 2, less<int>{});
        auto otherpair = minmax(5, 2, less<int>{});
        cout << values.first << " is smaller than " << values.second << '\n';
    }
    // Displays:   2 is smaler than 5
