#include "floats.ih"

//read
void Floats::read() const
{
    Reader reader = coRead();           // coRead: the coroutine
                                        // reader: the coroutine's handler
    while (auto opt = reader.next())    // retrieve the next value
        cout << opt.value() << ' ';

    cout << '\n';
}
//=
