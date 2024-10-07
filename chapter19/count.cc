    #include <algorithm>
    #include <iostream>
    using namespace std;

    bool pred(int value)
    {
        return value & 1;
    }

    int main()
    {
        int ia[] = {1, 2, 3, 4, 3, 4, 2, 1, 3};

        cout << "Number of times the value 3 is available: " <<
                count(ia, ia + size(ia), 3) << "\n"
                "Number of odd values in the array is: " <<
                count_if(ia, ia + size(ia), pred) << '\n';

    }
    // Displays:    Number of times the value 3 is available: 3
    //              Number of odd values in the array is: 5
