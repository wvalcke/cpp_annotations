//#define XERR
#include "floats.ih"

Floats::Floats(int argc, char **argv)
:
    d_action((*argv[1] == 'r') ? READ  :
             (*argv[1] == 'w') ? WRITE :
                                 ERROR)
{
    if (argc < 3 or d_action == ERROR)
        throw runtime_error{
                    "incorrect arguments, restart without arguments" };

    d_filename = argv[2];               // store the filename
}
