#include <cmath>
#include <iostream>
#include <string>
#include <tuple>

//+1
class Euclid
{
    size_t d_x;
    size_t d_y;

    public:
        Euclid(size_t x = 0, size_t y = 0);
        double distance() const;        // sqrt(d_x * d_x + d_y * d_y)
};
//+1

Euclid::Euclid(size_t x, size_t y)
:
    d_x(x),
    d_y(y)
{}

double Euclid::distance() const
{
    return sqrt(d_x * d_x + d_y * d_y);
}

//+1
class Data
{
    std::string d_text{ "hello from Data" };
    Euclid d_euclid;

public:
    void setXY(size_t x, size_t y);

    Euclid factory() const;
    double distance() const;
    std::string const &text() const;
    //+1
    //+2
    template <size_t Nr>
    auto get() const
    {
        if constexpr (Nr == 0)
            return factory();

        if constexpr (Nr == 1)
            return distance();

        if constexpr (Nr == 2)
            return text();

        static_assert(Nr >= 0 and Nr < 3);
    }
    //+2

//+1
};
//+1

void Data::setXY(size_t x, size_t y)
{
    d_euclid = Euclid{ x, y };
}

Euclid Data::factory() const
{
    return d_euclid;
}

double Data::distance() const
{
    return d_euclid.distance();
}

std::string const &Data::text() const
{
    return d_text;
}

//+3
template<>
struct std::tuple_size<Data>
{
    static size_t const value = 3;
};
//+3

//+4
template<size_t Nr>
struct std::tuple_element<Nr, Data>
{
    using type = decltype( declval<Data>().get<Nr>() );
    // if get<Nr> is a free function use:
    //           decltype( get<Nr>( declval<Data>() ) );

};
//+4

using namespace std;

//+5
int main()
{
    Data data;
    auto &[ ef, dist, txt ] = data;
    // or maybe:
    // auto &&[ ef, dist, txt ] = Data{};

    cout << dist << ' ' << txt << '\n';

    Data array[5];
    for (auto &[ ef, dist, txt]: array)
        cout << "for: " << dist << ' ' << txt << '\n';
}
//+5
