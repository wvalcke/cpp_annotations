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

    bool isAlpha(string const &str)
    {
        return str == "alpha";
    }

    int main()
    {
        StrVect words =
            {
                "kilo", "alpha", "lima", "mike", "alpha", "november",
                "alpha", "oscar", "alpha", "alpha", "papa"
            };

        // replace(words.begin(), words.end(), "alpha"s, "ALPHA"s);
        // show(words);

        // or, using replace_if:
        //
        // replace_if(words.begin(), words.end(), isAlpha, "ALPHA"s);
        // show(words);

        // or, using replace_copy:
        //
        // StrVect result;
        // replace_copy(words.begin(), words.end(), result.begin(),
        //              "alpha"s, "ALPHA"s);
        // show(result);

        // or, using replace_copy_if:
        //
        StrVect result;
        replace_copy_if(words.begin(), words.end(), back_inserter(result),
                     isAlpha, "ALPHA"s);
         show(result);
    }
    /*
        Displays
            kilo ALPHA lima mike ALPHA november ALPHA oscar ALPHA ALPHA papa
    */
