class Base
{ ... };
class Derived: public Base
{
    ...
    public:
        // assume Derived has a member void process()

        static void deleter(Base *bp);
};
void Derived::deleter(Base *bp)
{
    delete static_cast<Derived *>(bp);
}
int main()
{
    unique_ptr<Base, void (*)(Base *)> bp(new Derived, &Derived::deleter);
    static_cast<Derived *>(bp.get())->process(); // OK!

} // here ~Derived is called: no polymorphism required.

