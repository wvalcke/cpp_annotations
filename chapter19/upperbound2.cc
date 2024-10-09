#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    using pic =  pair<int, char>;

    pic picArr[] =
        { {1, 'f'}, {5, 'r'}, {5, 'a'}, {7, 'n'}, {8, 'k'} };
    pic *picArrEnd = picArr + size(picArr);

    cout << "Sequence: ";
    for (auto &pair: picArr)
        cout << '{' << pair.first << ',' << pair.second << "}, ";
    cout << '\n';

    auto iter = lower_bound(picArr, picArrEnd, 5,
                    [&](pic const &range, int value)
                    {
                        return range.first < value;
                    }
                );
    cout << "  lower bound, <,  {5,?} can be inserted before {" <<
                iter->first << ',' << iter->second << "}\n";

    iter = upper_bound(picArr, picArrEnd, 5,
                    [&](int value, pic const &range)
                    {
                        return value < range.first;
                    }
                );
    cout << "  upper_bound, <,  {5,?} can be inserted before {" <<
                iter->first << ',' << iter->second << "}\n";

    iter = upper_bound(picArr, picArrEnd, 9,
                    [&](int value, pic const &range)
                    {
                        return value < range.first;
                    }
                );
    cout << "  upper_bound, <,  {9,?} can be inserted " <<
                ( &*iter == picArrEnd ? "at the end" : "???") << '\n';

    sort(picArr, picArrEnd,
        [](pic const &lhs, pic const &rhs)
        {
            return lhs.first > rhs.first;
        }
    );

    cout << "\nSequence: ";
    for (auto &pair: picArr)
        cout << '{' << pair.first << ',' << pair.second << "}, ";
    cout << '\n';

    iter = lower_bound(picArr, picArrEnd, 5,
                    [&](pic const &range, int value)
                    {
                        return range.first > value;
                    }
                );
    cout << "  lower_bound, >,  {5,?} can be inserted before {" <<
                iter->first << ',' << iter->second << "}\n";

    iter = upper_bound(picArr, picArrEnd, 5,
                    [&](int value, pic const &range)
                    {
                        return value > range.first;
                    }
                );
    cout << "  upper_bound, >,  {5,?} can be inserted before {" <<
                iter->first << ',' << iter->second << "}\n";

    iter = upper_bound(picArr, picArrEnd, 0,
                    [&](int value, pic const &range)
                    {
                        return value > range.first;
                    }
                );
    cout << "  upper_bound, >,  {0,?} can be inserted " <<
                ( &*iter == picArrEnd ? "at the end" : "???") << '\n';
}
// Displays:
// Sequence: {1,f}, {5,r}, {5,a}, {7,n}, {8,k},
//   lower bound, <,  {5,?} can be inserted before {5,r}
//   upper_bound, <,  {5,?} can be inserted before {7,n}
//   upper_bound, <,  {9,?} can be inserted at the end
//
// Sequence: {8,k}, {7,n}, {5,r}, {5,a}, {1,f},
//   lower_bound, >,  {5,?} can be inserted before {5,r}
//   upper_bound, >,  {5,?} can be inserted before {1,f}
//   upper_bound, >,  {0,?} can be inserted at the end
