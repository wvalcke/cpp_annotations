#include <iostream>
#include <filesystem>

using namespace std;
using namespace filesystem;

int main(int argc, char* argv[])
{
    for (auto &entry : directory_iterator("/usr/local/bin"))
    {
        cout << "Entry : " << entry << endl;
    }

    cout << endl;

    for (auto iter = directory_iterator("/usr/local/bin"),
        end = directory_iterator{};
        iter != end;
        iter++
    )
    {
        cout << "Entry : " << *iter << endl;
    }

    recursive_directory_iterator base{ "/var/log/" };
    auto iter = base;
                                // final two elements show identical paths,
                                // different from the first element.
    cout << *iter << ' ' << *++iter << ' ' << *base << '\n';

}
