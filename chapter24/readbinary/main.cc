#include "main.ih"

//+main
int main(int argc, char **argv)
//+main
try
//+main
{
//+main
    if (argc == 1)
        usage();                // throws

//+main
    Floats floats(argc, argv);
    floats.run();
}
//+main
catch (...)
{
    return handle(current_exception());
}
