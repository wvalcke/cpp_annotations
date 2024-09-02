#include <string>
#include <cstddef>
#include <string.h>

using namespace std;

class Directory
{
    string d_currentPath;
    static char s_path[];

    public:
        static void setpath(char const *newpath);
        static void preset(Directory &dir, char const *newpath);
};
inline void Directory::preset(Directory &dir, char const *newpath)
{
                                                // see the text below
    dir.d_currentPath = newpath;                // 1
}

char Directory::s_path[200] = "/usr/local";     // 2

void Directory::setpath(char const *newpath)
{
    if (strlen(newpath) >= 200)
        throw "newpath too long";

    strcpy(s_path, newpath);                    // 3
}

int main()
{
    Directory dir;

    Directory::setpath("/etc");                 // 4
    dir.setpath("/etc");                        // 5

    Directory::preset(dir, "/usr/local/bin");   // 6
    dir.preset(dir, "/usr/local/bin");          // 7
}