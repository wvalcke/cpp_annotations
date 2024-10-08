    // compile as: g++ -O2 reduce.cc -ltbb
    #include <numeric>
    #include <vector>
    #include <execution>
    #include <iostream>
    using namespace std;

    int main()
    {
        int         ia[] = {1, 2, 3, 4};
        vector<int> iv(ia, ia + 4);

                            // for demonstration purpose: it's unlikely that
        cout <<             // for 4 values parallel execution is used
            "Sum: " << reduce(execution::par,
                        iv.begin(), iv.end(), int()) << "\n"
            "Product: " << reduce(iv.begin(), iv.end(), int(1),
                                            multiplies<int>{}) << "\n";
    }
    //  Displays:
    //      Sum: 10
    //      Product: 24
