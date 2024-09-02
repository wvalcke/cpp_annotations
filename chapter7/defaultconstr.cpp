// Compiler does not provide a default constructor when defining your own constructor.
// By declaring = default this default constructor will be made by the compiler
// = delete makes sure the default compiler generated copy constructor in this case is not
// generated

class Strings
{
    public:
        Strings() = default;
        Strings(std::string const *sp, size_t size);

        Strings(Strings const &other) = delete;
};

