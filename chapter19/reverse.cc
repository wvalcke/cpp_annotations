    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <vector>
    #include <iterator>
    using namespace std;
    using StrVect = vector<string>;

    void show(StrVect const &vect)
    {
        copy(vect.begin(), vect.end(), ostream_iterator<string>(cout, " "));
        cout.put('\n');
    }

    int main(int argc, char **argv)
    {
        StrVect words =
            {
                "alpha", "kilo", "lima", "mike",
                "november", "oscar", "papa"
            };

        if (argc == 1)          // no args: plain reverse
        {
            reverse(words.begin(), words.end());
            show(words);
            return 0;
        }

        using StrVect = vector<string>;
        StrVect dest;

        reverse_copy(words.begin(), words.end(),
                     back_inserter(dest));
        show(dest);
    }
    // Displays:
    //    papa oscar november mike lima kilo alpha
