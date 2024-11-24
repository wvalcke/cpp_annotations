#include "main.ih"

//main
int main(int argc, char **argv)
{
    Dir dir{ argc == 1 ? "." : argv[1] };

    while (char const *entryPath = dir.entry())
        cout << entryPath << '\n';
}
//=
