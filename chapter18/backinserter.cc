    #include <iostream>
    #include <algorithm>
    #include <iterator>
    using namespace std;

    class Insertable
    {
        public:
            using value_type = int;
            using const_reference = int const &;

            void push_back(int const &)
            {}
    };

    int main()
    {
        int arr[] = {1};
        Insertable insertable;

        copy(arr, arr + 1, back_inserter(insertable));
    }
