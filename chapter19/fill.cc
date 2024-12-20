    #include <algorithm>
    #include <vector>
    #include <iterator>
    #include <iostream>
    using namespace std;

    int main()
    {
        vector<int> iv(8);

        fill(iv.begin(), iv.end(), 8);
        copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " "));
        cout << '\n';

        fill_n(iv.begin() + 2, 4, 4);
        copy(iv.begin(), iv.end(), ostream_iterator<int>(cout, " "));
        cout << '\n';
     }
    // Displays:    8 8 8 8 8 8 8 8
    //              8 8 4 4 4 4 8 8
