#include <iostream>

using namespace std;

class Binary
{
    friend Binary operator+(Binary const &lhs, Binary const &rhs);
    friend Binary operator+(Binary &&lhs, Binary const &rhs);
public:
    Binary();
    Binary(int value);
    Binary(Binary const& other);
    Binary(Binary && other);
    ~Binary();

    Binary &operator+=(Binary const &rhs);
private:
    int m_Data;
};

Binary operator+(Binary const &lhs, Binary const &rhs);
Binary operator+(Binary &&lhs, Binary const &rhs);

Binary::Binary()
: m_Data{0}
{
    cout << "Binary()" << '\n';
}

Binary::Binary(int value)
: m_Data{value}
{
    cout << "Binary(" << value << ")" << '\n';
}

Binary::Binary(Binary const& other)
: m_Data{other.m_Data}
{
    cout << "Binary(Binary const&)" << '\n';
}

Binary::Binary(Binary && other)
: m_Data{other.m_Data}
{
    cout << "Binary(Binary&&)" << '\n';
}

Binary::~Binary()
{
    cout << "~Binary(" << m_Data << ")" << '\n';
}

Binary& Binary::operator+=(Binary const& rhs)
{
    m_Data += rhs.m_Data;
    return *this;
}

Binary operator+(Binary const &lhs, Binary const &rhs)
{
    cout << "operator+ (const &, const &)" << '\n';
    return Binary{lhs.m_Data+rhs.m_Data};
}

Binary operator+(Binary &&lhs, Binary const &rhs)   
{
    cout << "operator+ (&&, const &)" << '\n';
    Binary ret{std::move(lhs)};
    ret.m_Data += rhs.m_Data;
    return ret;
}

int main(int argc, char*argv[])
{
    Binary b1{10};
    Binary b2{11};
    Binary b3{30};
    Binary b4 = b1 + b2 + b3 + b3 + b3;

}
