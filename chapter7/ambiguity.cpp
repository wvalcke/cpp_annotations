class Data
{
    public:
        Data() {};
        Data(int one) {};
        Data(int one, int two) {};

        void display() {};
};

int main(int argc, char*argv[])
{
    // This is seen as a function declaration, not an object instance !
    // Solve by Data d1;
    // Solve by Data d1{};
    // Solve by Data d1 = Data{};
    // Solve by Data d1 = Data();

    // Defines di instance of Data, taking int (default value 0) as argument
    //  Data di{ int{} };

    Data d1();
    Data d2(argc);
}
