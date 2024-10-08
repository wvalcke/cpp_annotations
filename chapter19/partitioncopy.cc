    #include <algorithm>
    #include <string>
    #include <iostream>
    #include <iterator>
    using namespace std;

    bool pred(std::string const &str)
    {
        return "aeiou"s.find(str.front()) != string::npos;
    }

    void show(string const *begin, string const *end)
    {
        copy(begin, end, ostream_iterator<string>(cout, ", "));
        cout << '\n';
    }

    int main()
    {
        string sarr[] =
            {
                "alpha", "bravo", "charley", "delta", "echo",
                "foxtrot", "golf", "hotel"
            };
        string trueDest[size(sarr)];
        string falseDest[size(sarr)];

        pair<string *, string *> lastTF =   // lastTrue, lastFalse
            partition_copy(sarr, end(sarr), trueDest, falseDest, pred);

        cout << "pred() == true elements:\n";
        show(trueDest, lastTF.first);

        cout << "pred() == false elements:\n";
        show(falseDest, lastTF.second);

    }
    //  Displays:
    //    pred() == true elements:
    //    alpha, echo,
    //    pred() == false elements:
    //    bravo, charley, delta, foxtrot, golf, hotel,
