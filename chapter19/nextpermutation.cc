    #include <algorithm>
    #include <iterator>
    #include <iostream>
    #include <string>
    #include <cstring>
    using namespace std;

    bool caseString(string const &first, string const &second)
    {
        return strcasecmp(first.c_str(), second.c_str()) < 0;
    }

    // to obtain previous permutations change 'next_' to 'prev_'

    int main()
    {
        string saints[] = {"Oh", "when", "the", "saints"};

        cout << "All permutations of 'Oh when the saints':\n"
                "Sequences:\n";
        do
        {
            copy(saints, saints + 4, ostream_iterator<string>{ cout, " " });
            cout << '\n';
        }
        while (next_permutation(saints, saints + 4, caseString));

        cout << "After first sorting the sequence:\n";
        sort(saints, saints + 4, caseString);
        cout << "Sequences:\n";
        do
        {
            copy(saints, saints + 4, ostream_iterator<string>{ cout, " " });
            cout << '\n';
        }
        while (next_permutation(saints, saints + 4, caseString));
    }
    //  Displays (partially):
    //      All permutations of 'Oh when the saints':
    //      Sequences:
    //      Oh when the saints
    //      saints Oh the when
    //      saints Oh when the
    //      saints the Oh when
    //      ...
    //      After first sorting the sequence:
    //      Sequences:
    //      Oh saints the when
    //      Oh saints when the
    //      Oh the saints when
    //      Oh the when saints
    //      ...
