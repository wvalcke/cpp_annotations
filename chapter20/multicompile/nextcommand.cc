#include "main.ih"

//code
string nextCommand()
{
    string ret;
    while (true)
    {
        if (not getline(cin, ret))    // no more lines
            break;

        if (not ret.empty())          // ready once there's line content.
            break;
    }
    return ret;
}
//=
