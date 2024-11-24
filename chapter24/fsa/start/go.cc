#include "start.ih"

//go
void  Start::go()
{
    d_handle.resume();      // maybe protect using 'if (d_handle)'
}
//=
