#include "main.ih"

// call as tmp/bin/binary < files.in

//code
int main()
{
    workforce();                    // start the worker threads
    jobs();                         // prepare the jobs: push all tasks on the
                                    // taskQ

    for (thread &thr: g_thread)     // wait for the workers to end
        thr.join();

    results();                      // show the results

}
//=
