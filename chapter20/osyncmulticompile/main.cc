#include "main.ih"

// call as tmp/bin/binary < files.in

int main()
{
    workforce();                    // start the worker threads

    jobs();                         // job queueing is now at the main thread

    for (thread &thr: g_thread)     // wait for the workers to join
        thr.join();

    results();                      // show the results
}
