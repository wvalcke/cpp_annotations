#include "dir.ih"

//dir
Dir::Dir(char const *dir)
:
    d_dirPtr(opendir(dir)),             // prepare the entries
    d_path( dir )
{
    if (d_path.back() != '/')           // ensure that dirs end in '/'
        d_path += '/';
}
//=
