
// Land derives class vehicle
// constructor of Land calls constructor of Vehicle, which is a non default constructor
Land::Land(size_t mass, size_t speed)
    :
        Vehicle(mass),
        d_speed(speed)
    {}


//     copy constructor

Land::Land(Land const &other)   // assume a copy constructor is needed
    :
        Vehicle(other),             // copy-construct the base class part.
        d_speed(other.d_speed)      // copy-construct Land's data members
    {}

// move constructor can be implemented if
// 1) it supports move construction for its data members
// 2) its base class is move-aware

// derivation is Vehicle <- Land <- Car

Car::Car(Car &&tmp)
    :
        Land(std::move(tmp)),           // anonymize `tmp'
        d_brandName(tmp.d_brandName)    // move the char *'s value, d_brandname is member van Car
    {
        tmp.d_brandName = 0;
    }

    Land(Land &&tmp)
    :
        Vehicle(std::move(tmp)),    // move-aware Vehicle
        d_speed(tmp.d_speed)        // plain copying of plain data
    {}


// move assignmentn als Car beschikt over een swap method
Car &Car::operator=(Car &&tmp)
    {
        swap(tmp);
        return *this;
    }

// case when Car has no swap method

Car &Car::operator=(Car &&tmp)
    {
        // we moeten een & hebben om een lvalue te hebben, en we maken gebruik van de 
        // move assignment operator van de basis klasse Land
        static_cast<Land &>(*this) = std::move(tmp);
        
        // move Car's own data members next

        return *this;
    }

