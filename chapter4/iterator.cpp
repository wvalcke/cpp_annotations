#include <iostream>
#include <filesystem>

using namespace std;
using namespace filesystem;

int main(int argc, char* argv[])
{
    recursive_directory_iterator base{ "/var/log/" };
    auto iter = base;
                                // final two elements show identical paths,
                                // different from the first element.
    cout << *iter << ' ' << *++iter << ' ' << *base << '\n';

    auto secondit = begin(base);
    cout << *secondit << '\n';
}
