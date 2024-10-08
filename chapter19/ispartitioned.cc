    #include <algorithm>
    #include <iterator>
    #include <vector>
    #include <iostream>
    using namespace std;

    bool pCheck(int value)
    {
        return value < 3;
    }

    int main()
    {
        vector<int> uv = { 1, -2, 3, -4, 5, -6, 7, -8, 9};

        cout << "partitioned before: " <<
                is_partitioned(uv.begin(), uv.end(), pCheck) << "\n"

                "first value returning 'false' when partitioning: " <<
                *partition(uv.begin(), uv.end(), pCheck) << '\n';

        copy(uv.begin(), uv.end(), ostream_iterator<int>{ cout, " " });
        cout << '\n';

        cout << "partitioned after: " <<
                is_partitioned(uv.begin(), uv.end(), pCheck) <<'\n';

    }
    // Displays:  partitioned before: 0
    //            first value returning 'false' when partitioning: 5
    //            1 -2 -8 -4 -6 5 7 3 9 
    //            partitioned after: 1
