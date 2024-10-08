    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <iterator>
    #include <vector>
    using namespace std;
    using StrVect = vector<string>;

    bool judge(string const &word)
    {
        return count(word.begin(), word.end(), 'a') > 1;
    }

    void show(auto const &begin, auto const &end)
    {
        copy(begin, end, ostream_iterator<string>(cout, ", "));
        cout << "\n";
    }

    int main()
    {
        StrVect words =
            {
                "kilo", "alpha", "lima", "mike", "alpha", "november",
                "alpha", "alpha", "alpha", "papa", "quebec"
            };

        auto src{ words };

        cout << "Removing all \"alpha\"s:\n";
        auto end = remove(src.begin(), src.end(), "alpha");
        show(src.begin(), end);
        cout << "Leftover elements are:\n";
        show(end, src.end());

        src = words;
        cout << "Remove_copy_if removes words having > 1 'a' chars:\n";
        StrVect kept;
        remove_copy_if(src.begin(), src.end(), back_inserter(kept), judge);
        show(kept.begin(), kept.end());

    }
    //  Displays:
    //    Removing all "alpha"s:
    //    kilo, lima, mike, november, papa, quebec,
    //    Leftover elements are:
    //    alpha, alpha, alpha, , ,
    //    Remove_copy_if removes words having > 1 'a' chars:
    //    kilo, lima, mike, november, quebec,
