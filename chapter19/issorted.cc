    #include <algorithm>
    #include <vector>
    #include <iostream>
    using namespace std;

    int main()
    {
        vector<int> uv = { 1, -2, 3, -4, 5, -6, 7, -8, 9};

        cout << "sorted before: " <<
                is_sorted(uv.begin(), uv.end()) << '\n';

        sort(uv.begin(), uv.end());

        cout << "sorted after " <<
                is_sorted(uv.begin(), uv.end()) << '\n';
    }
    // Displays:
    //    sorted before: 0
    //    sorted after 1
