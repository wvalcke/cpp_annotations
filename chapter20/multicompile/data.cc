#include "main.ih"

size_t g_sizeofWorkforce = 6;

atomic_bool g_done;

vector<thread> g_thread;
TaskQueue g_taskQ;

mutex g_resultQMutex;
queue<shared_future<Result>> g_resultQ;

Semaphore g_dispatcher(g_sizeofWorkforce);  // size of the workforce: number
                                            // of jobs the dispatcher can
                                            // dispatch at this point.

Semaphore g_worker(0);                      // number of currently busy
                                            // workers.
