Class &operator=(Class const &other)
{
    Class tmp{ other };
    swap(tmp);
    return *this;
}

Class &operator=(Class &&tmp)
{
    swap(tmp);
    return *this;
}    

// we can implement the first by using the && version as follows

Class &operator=(Class const &other)
{
    Class tmp{ other };
    return *this = std::move(tmp);
}


/*
* algemene regel voor move 
* the move construcor must ensure that after the destination object has grabbed the source object's 
* data the source object remains in a valid state. That's easily accomplished by assigning the same values 
* to its data members as set by the default constructor.
*/
