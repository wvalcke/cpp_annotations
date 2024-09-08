#include <iostream>

using namespace std;

class Dotted
{
    std::string d_dotted;
    
    public:
        std::string const &dotted() const
        {
            return d_dotted;
        }
        std::string const &dotted(size_t ip)
        {
            auto octet = 
                [](size_t idx, size_t numeric)
                {
                    return to_string(numeric >> idx * 8 & 0xff);
                };

            d_dotted = 
                    octet(3, ip) + '.' + octet(2, ip) + '.' +
                    octet(1, ip) + '.' + octet(0, ip);

            return d_dotted;
        }
};

int main(int argc, char*argv[])
{
    Dotted l_Dot;
    l_Dot.dotted(0x5A000001);
    cout << "IP = " << l_Dot.dotted() << '\n';
}

