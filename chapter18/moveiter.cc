#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

size_t fstNonEmpty(vector<string> const &vs)
{
    return
        find_if(vs.begin(), vs.end(),
                [&](string const &str)
                {
                    return str != "";
                }
        ) - vs.begin();
}

int main()
{
    vector<string> vs;

    copy(istream_iterator<string>(cin), istream_iterator<string>(),
            back_inserter(vs));

    cout << "vs contains " << vs.size() << " words\n"
            "first non-empty word at index " << fstNonEmpty(vs) << "\n"
            "moving the first half into vector v2\n";

    vector<string> v2{ make_move_iterator(vs.begin()),
                       make_move_iterator(vs.begin() + vs.size() / 2) };

    cout << "vs contains " << vs.size() << " words\n"
            "first non-empty word at index " << fstNonEmpty(vs) << "\n"
            "v2 contains " << v2.size() << " words\n";
}
