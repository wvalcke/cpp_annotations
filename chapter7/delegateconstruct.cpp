class Stat
{
    public:
        Stat()
        :
            Stat("", "")        // no filename/searchpath
        {}
        Stat(std::string const &fileName)
        :
            Stat(fileName, "")  // only a filename
        {}
        Stat(std::string const &fileName, std::string const &searchPath)
        :
            d_filename(fileName),
            d_searchPath(searchPath)
        {
            // remaining actions to be performed by the constructor
        }
};

// overule default data member initializer

class Stat
{
    bool d_hasPath = false;

    public:
        Stat(std::string const &fileName, std::string const &searchPath)
        :
            d_hasPath(true)     // overrule the interface-specified
        {}                      // value
};

