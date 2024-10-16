#include "main.ih"

//code
void jobs()
{
    while (true)
    {
        string line = nextCommand();
        if (line.empty())                   // no command? jobs() done.
        {
            g_done = true;
            break;
        }

        g_dispatcher.wait();                // wait for an available worker

        if (g_done.load())                  // if a worker found an error
            break;                          // then quit anyway

        newTask(line);                      // push a new task (and its
                                            // results)

        g_worker.notify_all();              // inform the workers: job is
                                            // available
    }

    g_worker.notify_all();                  // end the workers at an empty Q
}
//=
