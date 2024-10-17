#include "main.ih"

//code
Result compile(string const &line)
{
    /*string command("/usr/bin/g++ -Wall -c " + line);

    CmdFork cmdFork(command);
    cmdFork.fork();

    Result ret {cmdFork.childExit() == 0,
                line + "\n" + cmdFork.childOutput()};

    if (not ret.ok)
        g_done = true;*/

    Result ret {true, "This is the result\n"};

    return ret;
}
//=
