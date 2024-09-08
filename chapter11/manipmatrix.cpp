#include <iostream>
#include <string>

class Matrix
{
public:
    static std::ostream &nop(std::ostream &out);
    std::ostream &(*operator()(char const *valueSep, char const *lineSep) ) 
                                                            (std::ostream &);
private:
    std::string d_valueSep;
    std::string d_lineSep;                                                        
};

 // static       (alternatively a free function could be used)
std::ostream &Matrix::nop(std::ostream &out)
{
    return out;
}

std::ostream &( 
    *Matrix::operator()(char const *valueSep, char const *lineSep) ) 
                                                    (std::ostream &)
{
    d_valueSep = valueSep;
    d_lineSep = lineSep;
    return nop;
}

std::ostream& operator<< (std::ostream& stream, Matrix const& matrix)
{
    stream << "Streaming matrix";
    return stream;
}

int main(int argc, char*argv[])
{
    Matrix matrix;
    std::cout << matrix(" ", "\n") << matrix << '\n';
}
