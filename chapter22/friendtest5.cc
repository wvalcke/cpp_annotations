template <typename T>   // a function template
void fun(T *t)
{
    t->not_public();
};

template<typename X>
class A;

template<typename X>    // a free member function template
bool operator==(A<X> const &lhs, A<X> const &rhs);

template <typename X>   // a class template
class A
{                       // fun() is used as friend bound to A,
                        // instantiated for X, whatever X may be
    friend void fun<>(A<X> *);
    //friend void fun<A<X>>(A<X> *);
                        // operator== is a friend for A<X> only
    friend  bool operator==<>(A<X> const &lhs, A<X> const &rhs);
    //friend  bool operator==<X>(A<X> const &lhs, A<X> const &rhs);

    int d_data = 10;

    public:
        A();

    private:
        void not_public();
};

template <typename X>
A<X>::A()
{
    fun(this);
}

template <typename X>
void A<X>::not_public()
{}

template<typename X>    // may access lhs/rhs's private data
bool operator==(A<X> const &lhs, A<X> const &rhs)
{
    return lhs.d_data == rhs.d_data;
}

int main()
{
    A<int> a;

    fun(&a);            // fun instantiated for A<int>.
}