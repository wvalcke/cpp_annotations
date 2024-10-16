#include "main.ih"

//code
void results()
{
    Result result;

    string errorDisplay;

    while (newResult(result))
    {
        if (result.ok)
            cerr << result.display;
        else if (errorDisplay.empty())
            errorDisplay = result.display;  // remember the output of
    }                                       // the first compilation error
    if (not errorDisplay.empty())           // which is displayed at the end
        cerr << errorDisplay;
}
//=
