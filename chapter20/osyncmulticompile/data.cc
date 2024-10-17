#include "main.ih"

size_t g_sizeofWorkforce = 6;
atomic_bool g_done;
string g_marker{ "?|" };

vector<thread> g_thread;
fstream g_out{ "/tmp/out", ios::trunc | ios::in | ios::out };

TaskQueue g_taskQ;

Semaphore g_dispatcher(g_sizeofWorkforce);  // size of the workforce: number
                                            // of jobs the dispatcher can
                                            // dispatch at this point.

Semaphore g_worker(0);                      // number of currently busy
                                            // workers.
