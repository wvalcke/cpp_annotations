    // compile as: g++ -O2 sort.cc -ltbb
    #include <algorithm>
    #include <cstdlib>
    #include <execution>
    #include <functional>
    #include <iostream>
    #include <iterator>
    #include <string>
    using namespace std;

    int main()
    {
        string words[] =
                {
                    "november", "kilo", "mike", "lima",
                    "oscar", "quebec", "papa"
                };

        sort(words, words + 7);
        copy(words, words + 7, ostream_iterator<string>(cout, " "));
        cout << '\n';

        sort(words, words + 7, greater<string>());
        copy(words, words + 7, ostream_iterator<string>(cout, " "));
        cout << '\n';

        int *vect = new int[10'000];
        generate(execution::par, vect, vect + 10'000, random);
        cout << "sorted: " << is_sorted(vect, vect + 10'000) << '\n';

        sort(execution::par, vect, vect + 10'000);
        cout << "sorted: " << is_sorted(vect, vect + 10'000) << '\n';

        delete[] vect;

        // stable-sorting:

        using Pair = pair<size_t, string>;  // days & nrs of the months
        vector<Pair> months =
        {
            { 31, "Jan." }, { 28, "Feb." }, { 31, "Mar." }, { 30, "Apr." },
            { 31, "May." }, { 30, "Jun." }, { 31, "Jul." }, { 31, "Aug." },
            { 30, "Sep." }, { 31, "Oct." }, { 30, "Nov." }, { 31, "Dec." },
        };

        stable_sort(months.begin(), months.end(),
                    [&](Pair const &lhs, Pair const &rhs)
                    {
                        return lhs.first > rhs.first;
                    }
        );

        for (size_t idx = 0; auto const &month: months)
            cout << month.first << ": " << month.second <<
                (++idx % 4 == 0 ? "\n" : "  ");

    }
    //  Displays:
    //      kilo lima mike november oscar papa quebec
    //      quebec papa oscar november mike lima kilo
    //      unordered sequence
    //      sorted sequence
    //      31: Jan.  31: Mar.  31: May.  31: Jul.
    //      31: Aug.  31: Oct.  31: Dec.  30: Apr.
    //      30: Jun.  30: Sep.  30: Nov.  28: Feb.
