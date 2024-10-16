#include "main.ih"

//code
void worker()
{
    Task task;
    while (true)
    {
        g_worker.wait();                    // wait for an available task

        if (g_taskQ.empty())                // no task? then done
            break;

        g_taskQ.popFront(task);
        g_dispatcher.notify_all();          // notify the dispatcher that
                                            // another task can be pushed
        task();
    }
    g_worker.notify_all();                  // no more tasks: notify the other
}                                           // workers.
//=
