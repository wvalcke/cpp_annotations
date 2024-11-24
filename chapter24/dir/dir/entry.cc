#include "dir.ih"

//+entry
char const *Dir::entry()
{
    // first part here

    // second part here

//+entry
//first
        // first part
    if (d_recursive)                                    // recursion active
    {
        if (char const *entry = d_recursive->entry())   // next entry
            return entry;                               // return it

        delete d_recursive;                             // delete the object
        d_recursive = 0;                                // end the recursion
    }
//=

//second
        // second part
    while (DirEntry const *dirEntry = readdir(d_dirPtr))// visit all entries
    {
        char const *name = dirEntry->d_name;            // get the name

        if (name == "."s or name == ".."s)              // ignore dot-names
            continue;

        name = (d_entryPath = d_path + name).c_str();   // entry-name
                                                        // (as path)

        if (dirEntry->d_type == DT_DIR)                 // a subdir?
            d_recursive = new Dir{ name };              // handle it next

        return name;                                    // return the entry
    }
//=
//+entry
    return 0;
}
//+entry
