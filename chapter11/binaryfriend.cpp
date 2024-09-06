class Binary
{
    friend Binary operator+(Binary const &lhs, Binary const &rhs);

    public:
        Binary();
        Binary(int value);

        Binary &operator+=(Binary const &other);

    private:
        void add(Binary const &other);
};


Binary &Binary::operator+=(Binary const &rhs)
{
    Binary tmp{ *this };
    tmp.add(rhs);           // this might throw
    // the strong guarantee
    swap(tmp);
    return *this;
}

Binary operator+(Binary const &lhs, Binary const &rhs)
{
    Binary tmp{ lhs };
    // we can call the add method because it is a friend of the class
    tmp.add(rhs);
    return tmp;
}

