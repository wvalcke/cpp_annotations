#include <iostream>
using namespace std;

class Vehicle
{
    size_t d_mass;

    public:
        Vehicle();
        Vehicle(size_t mass);

        size_t mass() const;
        void setMass(size_t mass);
};
    
class Land: public Vehicle
{
    size_t d_speed;
    public:
        Land();
        Land(size_t mass, size_t speed);

        void setSpeed(size_t speed);
        size_t speed() const;
};

class Car: public Land
{
    std::string d_brandName;

    public:
        Car();
        Car(size_t mass, size_t speed, std::string const &name);

        std::string const &brandName() const;
};

class Truck: public Car
{
    size_t d_mass;

    public:
        Truck();
        Truck(size_t tractor_mass, size_t speed, std::string const& name,
                size_t trailer_mass);

        void setMass(size_t tractor_mass, size_t trailer_mass);
        size_t mass() const;
};

class TruckV2 : public Car, public Vehicle
{
public:
    TruckV2(size_t tractor_mass, size_t speed, std::string const& name,
                size_t trailer_mass);

    size_t mass() const;

};

class TrailerVeh: public Vehicle
{
    public:
        TrailerVeh(int mass)
        :
            Vehicle(mass)
        {}
};

class TruckV3: public Car, public TrailerVeh
{
    public:
        TruckV3();
        TruckV3(int engine_mass, int sp, std::string const& name, int trailer_mass);
        void setMass(size_t engine_mass, size_t trailer_mass);
        size_t mass() const;
};

Vehicle::Vehicle()
: d_mass(0)
{
}

Vehicle::Vehicle(size_t mass)
: d_mass(mass)
{
}

size_t Vehicle::mass() const
{
    return d_mass;
}

void Vehicle::setMass(size_t mass)
{
    d_mass = mass;
}

Land::Land()
: Vehicle(), d_speed(0)
{}

Land::Land(size_t mass, size_t speed)
: Vehicle(mass), d_speed(speed)
{
}

void Land::setSpeed(size_t speed)
{
    d_speed = speed;
}

size_t Land::speed() const
{
    return d_speed;
}

Car::Car()
{
}

Car::Car(size_t mass, size_t speed, std::string const& name)
: Land(mass, speed), d_brandName(name)
{
}

std::string const& Car::brandName() const
{
    return d_brandName;
}

Truck::Truck()
{

}

Truck::Truck(size_t tractor_mass, size_t speed, std::string const& name,
                size_t trailer_mass)
: Car(tractor_mass, speed, name), d_mass(trailer_mass)
{
}

void Truck::setMass(size_t tractor_mass, size_t trailer_mass)
{
    Car::setMass(tractor_mass);
    d_mass = trailer_mass;
}

size_t Truck::mass() const
{
    return Car::mass() + d_mass;
}

TruckV2::TruckV2(size_t tractor_mass, size_t speed, std::string const& name,
                size_t trailer_mass)
: Car(tractor_mass, speed, name), Vehicle(trailer_mass)
{

}

/*
* next part does not compile, as calling Vehicle::mass() could be resolved via Car or via Vehicle
*/
/*size_t TruckV2::mass() const
{
    return Car::mass() + Vehicle::mass();
}*/

TruckV3::TruckV3()
: TrailerVeh(0)
{}

TruckV3::TruckV3(int engine_mass, int sp, std::string const& name, int trailer_mass)
: Car(engine_mass, sp, name), TrailerVeh(trailer_mass)
{
}

void TruckV3::setMass(size_t engine_mass, size_t trailer_mass)
{
    Car::setMass(engine_mass);
    TrailerVeh::setMass(trailer_mass);
}

// now there is no problem as TrailerVeh refers to his Vehicle, and not of Car
size_t TruckV3::mass() const
{
    return Car::mass() + TrailerVeh::mass();
}

int main(int argc, char*argv[])
{
    TruckV3 truck{3000, 120, "Mercedes", 9000};
    std::cout << "Truck has total mass of " << truck.mass() << '\n';
}
