#include "floats.ih"

    // this function merely uses the coroutine's next value.

//write
void Floats::write() const
{
    ofstream out{ d_filename };

    Writer writer = coWrite();          // coWrite: the coroutine,
                                        // writer: the coroutine's handler
    cout << "Enter values (one per prompt), enter 'q' to quit\n";

    while (true)
    {
        cout << "? ";
        auto opt = writer.next();       // retrieve the next value
        if (not opt)                    // stop if no more values
            break;
        out.write(&opt.value()[0], sizeof(float));
    }
}
//=
