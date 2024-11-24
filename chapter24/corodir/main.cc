#include "main.ih"


inline bool accept(DirEntry const &entry)
{
    return entry.d_name != "."s and entry.d_name != ".."s;
}

    // yield all `DirEntry`s contained in the particular `path` (as long as it
    // is a directory)

//     if (not dirPtr)
//        co_return;
// removed from 'dirEntries' after calling opendir: like Dir, let's assume
// that the demo allows us to assume that opendir succeeds.

//+dir
Generator<DirEntry> dirEntries(char const *path)
{
    DIR *dirPtr = opendir(path);

    while (auto entry = readdir(dirPtr))
    {
        if (accept(*entry))
            co_yield *entry;
    }
    closedir(dirPtr);
}
//+dir

    // keep track of the _full_ path rather than only the entry's own name
//+path
Generator<Pair> dirPathEntries(char const *path)
{
    for (auto const &entry: dirEntries(path))
        co_yield make_pair(entry,
                    (string{path} + '/' + entry.d_name).c_str());
}
//+path

    // Recursively visit the directory tree:
    // yield all entries in the current directory and if an entry is
    // a directory, recursively handle that directory
//+allentries
RecursiveGenerator<Pair> visitAllEntries(char const *path)
{
    for (auto &entry_pair: dirPathEntries(path))
    {
        co_yield entry_pair;

        auto [entry, entry_path] = entry_pair;
        if (entry.d_type == DT_DIR)
            co_yield visitAllEntries(entry_path);
    }
}
//+allentries

    // Run this program with a directory path as single argument
    // (it defaults to `.`, i.e., the current directory).
    // It (recursively lists all files and directories in that directory
//main
int main(int argc, char **argv)
{
    char const *path = argc == 1 ? "." : argv[1];

    for (auto [entry, entryPath ]: visitAllEntries(path))
        cout << entryPath << '\n';
}
//=
