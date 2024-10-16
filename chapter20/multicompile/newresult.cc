#include "main.ih"

//code
bool newResult(Result &result)
{
    if (g_resultQ.empty())
        return false;

    result = g_resultQ.front().get();
    g_resultQ.pop();

    return true;
}
//=
