class Base1 final               // cannot be a base class
    {};
    class Derived1: public Base1    // ERR: Base1 is final
    {};

    class Base2                     // OK as base class
    {};
    class Derived2 final: public Base2  // OK, but Derived2 can't be
    {};                                 //     used as a base class
    class Derived: public Derived2      // ERR: Derived2 is final
    {};

class Base
{
    virtual int v_process();    // define polymorphic behavior
    virtual int v_call();
    virtual int v_display();
};
class Derived: public Base      // Derived restricts polymorphism
{                               // to v_call and v_display
    virtual int v_process() final;
};
class Derived2: public Derived
{
    // int v_process();            No go: Derived:v_process is final
    virtual int v_display();    // OK to override
};

class Base
{
    virtual int v_process();
    virtual int v_call() const;
    virtual int v_display(std::ostream &out);
};
class Derived: public Base
{
    virtual int v_proces() override;    // ERR: v_proces != v_process
    virtual int v_call() override;      // ERR: not const
                                        // ERR: parameter types differ
    virtual int v_display(std::istream &out) override;
};

