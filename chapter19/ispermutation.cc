    #include <algorithm>
    #include <iostream>
    using namespace std;

    int main()
    {
        int one[] = { 1, -2, 3, -4, 5, -6, 7, -8, 9};
        int two[] = { -8, -2, -4, -6, 3, 1, 5, 9, 7};
        int three[] = { -8, -8, -4, -6, 3, 1, 5, 9, 7};

        cout << "one is a permutation of two: " <<
            is_permutation(one, end(one), two) << "\n"

            "one is a permutation of three: " <<
            is_permutation(one, end(one), three, end(three)) << '\n';
    }
    // Displays: one is a permutation of two: 1
    //           one is a permutation of three: 0
