#include "semaphore.ih"

size_t  Semaphore::size() const
{
    std::lock_guard<mutex> lk(d_mutex);
    return d_nAvailable;
}
