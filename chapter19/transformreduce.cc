    #include <numeric>
    #include <algorithm>
    #include <iterator>
    #include <iostream>
    #include <string>
    using namespace std;

    class Cat
    {
        std::string  d_sep;
        public:
            Cat(string const &sep)
            :
                d_sep(sep)
            {}
            string operator()
                (string const &s1, string const &s2) const
            {
                return s1 + d_sep + s2;
            }
    };
    int main()
    {
        size_t ia1[] = { 1, 2, 3, 4, 5, 6, 7 };

                    // instead of inner_product:
        cout << "The sum of all squares in ";
        copy(ia1, ia1 + 7, ostream_iterator<size_t>{ cout, " " });
        cout << "is " << transform_reduce(ia1, ia1 + 7, ia1, 0) << '\n';

        size_t ia2[] = { 7, 6, 5, 4, 3, 2, 1 };

        cout << "The sum of all cross-products in ";
        copy(ia1, ia1 + 7, ostream_iterator<size_t>{ cout, " " });
        cout << "and ";
        copy(ia2, ia2 + 7, ostream_iterator<size_t>{ cout, " " });
        cout << "is " << transform_reduce(ia1, ia1 + 7, ia2, 0) << '\n';

        string names1[] = { "Frank", "Karel", "Piet" };
        string names2[] = { "Brokken", "Kubat", "Plomp"};

        cout << "All combined names of ";
        copy(names1, names1 + 3, ostream_iterator<string>{ cout, " " });
        cout << "and ";
        copy(names2, names2 + 3, ostream_iterator<string>{ cout, " " });
        cout << "are:" <<
            transform_reduce(names1, names1 + 3, names2, ""s,
                Cat{ "\n\t"}, Cat{ " " }) << '\n';
    }
    // Displays:
    //  The sum of all squares in 1 2 3 4 5 6 7 is 140
    //  The sum of all cross-products in 1 2 3 4 5 6 7 and 7 6 5 4 3 2 1 is 84
    //  All combined names of Frank Karel Piet and Brokken Kubat Plomp are:
    //          Frank Brokken
    //          Karel Kubat
    //          Piet Plomp
