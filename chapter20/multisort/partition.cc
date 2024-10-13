#include "main.ih"

//code
void partition(Pair const &range)
{
    if (range.second - range.first < 2)
        return;

    auto rhsBegin = partition(range.first + 1, range.second,
                                  [=](int value)
                                  {
                                      return value < *range.first;
                                  }
                              );
    auto lhsEnd = rhsBegin - 1;

    swap(*range.first, *lhsEnd);

    pushTask(range.first, lhsEnd);
    pushTask(rhsBegin, range.second);
}
//=
