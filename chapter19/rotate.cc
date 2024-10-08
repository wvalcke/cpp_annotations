    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <iterator>
    #include <vector>
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
                "kilo", "lima", "mike", "november", "oscar",
                "foxtrot", "golf", "hotel", "india", "juliet"
            };

        if (argc == 1)          // no args: plain rotate
        {
            rotate(words.begin(), words.begin() + words.size() / 2,
                   words.end());
            show(words);
            return 0;
        }

        using StrVect = vector<string>;
        StrVect dest;

        rotate_copy(words.begin(), words.begin() + words.size() / 2,
                    words.end(), back_inserter(dest));
        show(dest);
    }
    //  Displays:
    //      foxtrot golf hotel india juliet kilo lima mike november oscar
