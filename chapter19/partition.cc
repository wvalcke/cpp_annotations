    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <iterator>
    using namespace std;

    void show(int *begin, int *end)
    {
        copy(begin, end, ostream_iterator<int>{ cout, " " });
        cout << '\n';
    }

    int main()
    {
        int org[] = { 1, 3, 5, 7, 9, 10, 2, 8, 6, 4 };
        int ia[10];

        copy(org, org + 10, ia);

        auto lessThan4 = [=](int value)
                        {
                            return value <= 4;
                        };

        int *split = partition(ia, ia + 10, lessThan4);

        cout << "Last ia[]- element <= 4 is ia[" << split - ia - 1 << "]\n";
        show(ia, end(ia));

        copy(org, org + 10, ia);
        split = stable_partition(ia, ia + 10, lessThan4);
        cout << "Last org[]-element <= 4 is ia[" << split - ia - 1 << "]\n";
        show(ia, end(ia));

        cout << "org[]-elements up to the partition point 4 are:\n";
        show(org, partition_point(org, org + 10, lessThan4));
    }
    //  Displays:
    //    Last ia[]- element <= 4 is ia[3]
    //    1 3 4 2 9 10 7 8 6 5
    //    Last org[]-element <= 4 is ia[3]
    //    1 3 2 4 5 7 9 10 8 6
    //    org[]-elements up to the partition point 4 are:
    //    1 3
