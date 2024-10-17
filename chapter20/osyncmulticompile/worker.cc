#include "main.ih"

//code
void worker()
{
    Task task;

    while (true)
    {
        g_worker.wait();                    // wait for a request

        if (g_taskQ.empty())                // no task in the taskQ?
            break;

        g_taskQ.popFront(task);             // get the next task
        g_dispatcher.notify_all();          // notify the dispatcher: another
                                            // task can be pushed

        task();                             // execute the task
    }

    g_worker.notify_all();
}
//=
