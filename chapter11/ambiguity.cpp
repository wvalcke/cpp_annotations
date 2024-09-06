class A;

class B
{
    public:
        B(A const &a);
};

class A
{
    public:
        A();
        A(B const &b);
};

A operator+(A const &a, B const &b);
B operator+(B const &b, A const &a);

int main()
{
    A a;

    // this is a problem as both operator+ methods could be used
    // in the first case a promotion to second argument is possible
    // in the second case a promotion to the first argument is possible
    a + a;

    // We can solve this 
    a + B{a}; // selects the first operator+
};


/*
* BELANGRIJK

No promotions occur when neither operand is of the intended class type

*/

/*
* een method operator+= bvb zal steeds als een member method gedefinieerd worden
* Dit omdat de linkse operand steeds een object is en kunnen we dus als een gewone member
* de operator+= definieren
* Typisch wordt dit dan:
* A& operator+=(int b);
*/


class Binary
{
    public:
        Binary();
        Binary(int value);

        Binary &operator+=(Binary const &rhs);
};

Binary operator+(Binary const &lhs, Binary const &rhs);

// exception strong guarantee
Binary &Binary::operator+=(Binary const &rhs)
{
    Binary tmp{ *this };
    tmp.add(rhs);           // this might throw
    swap(tmp);
    return *this;
}

