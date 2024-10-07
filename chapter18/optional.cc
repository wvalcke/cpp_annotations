#include <iostream>
#include <sstream>
#include <string>
#include <optional>

using namespace std;

optional<string> nextLine(istream &in)
{
    std::optional<std::string> opt;

    string line;
    if (getline(in, line))
        opt = move(line);

    cout << "internal: has value: " << opt.has_value() <<
                                ", value = " << *opt << '\n';
    return opt;
}

int main()
{
    istringstream in{ "hello world\n" };

    auto opt = nextLine(in);

    cout << "main:     has value: " << opt.has_value() <<
                                ", value = " << *opt << '\n';
    opt = nextLine(in);

    cout << "main:     has value: " << opt.has_value() <<
                                ", value = " << *opt << '\n';
}
