    #include <algorithm>
    #include <iostream>
    using namespace std;

    bool absCompare(int first, int second)
    {
        return abs(first) < abs(second);
    };

    int *maxMin(bool high, int *begin, int *end)
    {
        return high ? max_element(begin, end) : min_element(begin, end);
    }

    int *maxMin(bool high, int *begin, int *end, bool (*comp)(int, int))
    {
        return high ? max_element(begin, end, comp)
                    : min_element(begin, end, comp);
    }

                // no args: calls max_element, else min_element
    int main(int argc, char **argv)
    {
        bool max = argc == 1;
        char const *type = max? "max" : "min";

        int     ia[] = {-4, 7, -2, 10, -12};

        cout << "The " << type << ". int value is " <<
                *maxMin(max, ia, ia + 5) << "\n"
                "The " << type << ". absolute int value is " <<
                *maxMin(max, ia, ia + 5, absCompare) << '\n';
    }
    //  Displays, when called without arguments:
    //      The max. int value is 10
    //      The max. absolute int value is -12
    //  otherwise:
    //      The minimum int value is -12
    //      The minimum absolute int value is -2
