class Container
{
    Data *d_data = 0;
    size_t d_size = 0;
    size_t d_nr = ++s_nObjects;

    static size_t s_nObjects;

    public:
        Container() = default;
        Container(Container const &other);
        Container(Data *data, size_t size);
        Container(Container &&tmp);
};


// de volgende constructor shared de member initialisatie van boven
// dus de d_nr wordt ingesteld op ++s_nObjects alhoewel dit hier niet 
// expliciet wordt gedaan.

Container(Container &&tmp)
:
    d_data(tmp.d_data),
    d_size(tmp.d_size)
{
    tmp.d_data = 0;
}

// what is an aggregate?
// An aggregate is an array or a class (usually a struct with no user-defined constructors, 
// no private or protected non-static data members, 
// no base classes (cf. chapter 13), and no virtual functions (cf. chapter 14)).

struct POD      // defining aggregate POD
{
    int first = 5; 
    double second = 1.28; 
    std::string hello{ "hello" };
};


// initialise and aggregate via braced initializer list
POD pod{ 4, 13.5, "hi there" };

// mag ook 
POD pod{ 4 };   // uses second: 1.28, hello: "hello"
