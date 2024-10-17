#include "main.ih"

string nextCommand()
{
    string ret;

    while (true)
    {
        if (not getline(cin, ret))    // done or no more lines
            break;

        if (not ret.empty())                    // line content required
            break;
    }

    return ret;
}
