    #include <numeric>
    #include <vector>
    #include <iostream>
    using namespace std;

    int main()
    {
        int         ia[] = {1, 2, 3, 4};
        vector<int> iv(ia, ia + 4);

        cout <<
            "Sum: " << accumulate(iv.begin(), iv.end(), int()) << "\n"
            "Product: " << accumulate(iv.begin(), iv.end(), int(1),
                                            multiplies<int>{}) << '\n';
    }
    //  Displays:
    //      Sum: 10
    //      Product: 24
