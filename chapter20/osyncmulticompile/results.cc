#include "main.ih"

//code
void results()
{
    g_out.seekg(0);

    int value;
    string line;
    string errorDisplay;

    while (g_out >> value >> line)      // process g_out's content
    {
        g_out.ignore(100, '\n');

        if (value == 0)                 // no error: show the source file
        {
            cerr << line << '\n';
            continue;
        }
                                        // at compilation errors:
        if (not errorDisplay.empty())   // after the 1st error: skip
        {
            do
            {
                getline(g_out, line);
            }
            while (line != g_marker);

            continue;
        }
                                        // first compilation error:
        errorDisplay = line + '\n';     // keep the the name of the source
        while (true)                    // and its error messages
        {
            getline(g_out, line);

            if (line == g_marker)
                break;

            errorDisplay += line + '\n';
        }
    }

    cerr << errorDisplay;               // eventually insert the error-info
}                                       // (if any)
//=
