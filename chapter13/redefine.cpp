class Truck: public Car
{
    size_t d_mass;

    public:
        Truck();
        Truck(size_t tractor_mass, size_t speed, char const *name,
                size_t trailer_mass);

        void setMass(size_t tractor_mass, size_t trailer_mass);
        size_t mass() const;
};

Truck::Truck(size_t tractor_mass, size_t speed, char const *name,
                size_t trailer_mass)
:
    Car(tractor_mass, speed, name),
    d_mass(tractor_mass + trailer_mass)
{}

setMass method van Car is hidden, maw je kan niet zeggen

 mytruck.setMass(400);

 Je moet expliciet zetten : mytruck.Car::setMass(400)

 Wil je dit niet, dan moet je in de Truck klasse zetten

class Truck: public Car
{
    public:
        using Car::setMass;
        void setMass(size_t tractor_mass, size_t trailer_mass);
};

Nu worden ALLE overloads van Car::setMass toegevoegd aan de interface van Truck
Je kan nu zeggen : truck.setMass(500)

Mocht Truck classe zelf een setMass(int) definieren, dan zal de using declaratie een compilatie
fout geven

