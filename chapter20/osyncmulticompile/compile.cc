#include "main.ih"

//code
void compile(string const &line)
{
    if (g_done.load())
        return;

    string command("/usr/bin/g++ -Wall -c " + line);

    CmdFork cmdFork(command);
    cmdFork.fork();

    int exitValue = cmdFork.childExit();

    osyncstream out(g_out);
    out << exitValue << ' ' << line << '\n';

    if (exitValue != 0)
    {
        out << cmdFork.childOutput() << '\n' << g_marker << '\n';
        g_done = true;
    }
    // out.emit();          // handled by out's destructor
}
//=
