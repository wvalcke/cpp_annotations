#include "main.ih"

//code
void newTask(string const &line)
{
    Task task{ line, PackagedTask(compile) };

    pushResultQ(task.result());             // the results are in the resultQ
    g_taskQ.push(move(task));
}
//=
