#include "main.ih"

int handle(exception_ptr ptr)
try
{
   rethrow_exception(ptr);
}
catch (exception const &exc)
{
    cout << "error: " << exc.what() << '\n';
    return 1;
}
catch (int ret)
{
    return ret;
}
catch (...)
{
    cout << "unexpected exception\n";
    return 1;
}
