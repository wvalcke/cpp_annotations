#include "main.ih"

void workforce()
{
    for (size_t idx = 0; idx != g_sizeofWorkforce; ++idx)
        g_thread.push_back(thread{ worker });   // create the worker threads
}
