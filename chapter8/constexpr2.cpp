class Data
{
    int d_x;

    public:
        constexpr Data(int x)
        :
            d_x(x)
        {}

        // This method must be defined as const, otherwise the call d2.cMember() will not compile
        // as a non const method is called on a const Data object. We have a const Data object because
        // it was defined via a constexpr 
        int constexpr cMember() const
        {
            return d_x;
        }

        int member() const
        {
            return d_x;
        }
};

Data d1{ 0 };           // OK, but not a constant expression

//enum e1 {
//    ERR = d1.cMember()  // ERROR: cMember(): no constant
//};                      //        expression anymore

constexpr Data d2{ 0 }; // OK, constant expression

enum e2 {
    OK = d2.cMember(),  // OK: cMember(): now a constant
                        //                expression
//    ERR = d2.member(),  // ERR: member(): not a constant
};                      //                expression


int main(int argc, char*argv[])
{

}
