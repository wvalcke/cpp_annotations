#ifndef INCLUDED_DIR_
#define INCLUDED_DIR_

#include <dirent.h>
#include <string>

//hdr
class Dir
{
    using DirEntry = dirent;

    DIR *d_dirPtr = 0;
    Dir *d_recursive = 0;

    char const *d_entry;        // returned by entry()
    std::string d_path;         // Dir's directory name, ending in '/'
    std::string d_entryPath;

    public:
        Dir(char const *dir);   // dir: the name of the directory to visit
        ~Dir();

        char const *entry();
};
//=

//dir
inline Dir::~Dir()
{
    closedir(d_dirPtr);
}
//=

#endif
