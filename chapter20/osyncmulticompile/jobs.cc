#include "main.ih"

//code
void jobs()
{
    while (true)
    {
        string line = nextCommand();
        if (line.empty())                   // no command? jobs() done.
            break;

        g_dispatcher.wait();                // wait for an available worker

        if (g_done.load())
            break;

                                            // push the command on the queue
        g_taskQ.push(Task{ line, PackagedTask(compile) });

        g_worker.notify_all();              // inform the workers: job is
                                            // available
    }

    g_worker.notify_all();
}
//=
