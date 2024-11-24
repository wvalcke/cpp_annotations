#ifndef INCLUDED_FLOATS_
#define INCLUDED_FLOATS_

#include <string>

//floats
class Reader;
class Writer;

class Floats
{
    enum Action
    {
        READ,
        WRITE,
        ERROR,
    };

    Action d_action;
    std::string d_filename;                     // name of the binary file

    static void (Floats::*s_action[])() const;  // pointers to read and write

    public:
        Floats(int argc, char **argv);
        void run() const;

    private:
        void read() const;
        Reader coRead() const;

        void write() const;
        static Writer coWrite();

};

inline void Floats::run() const
{
    (this->*s_action[d_action])();
}
//=
#endif
