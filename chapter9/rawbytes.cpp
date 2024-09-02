int main(int argc, char*argv[])
{
    // moet zijn operator new, new alleen compileert niet
    char *l_Data = static_cast<char*>(operator new (56));

    struct POD
    {
        int iVal;
        double dVal;
    };

    // () achter de new zorgt voor de initialisatie op 0, anders gebeurt dit niet
    new POD[5]();       // returns a pointer to 5 0-initialized PODs
    new double[9]();    // returns a pointer to 9 0-initialized doubles

    // haakjes kunnen ook {} zijn
    new POD[5]{};       // returns a pointer to 5 0-initialized PODs
    new double[9]{};    // returns a pointer to 9 0-initialized doubles

    struct Data
    {
        int value = 100;
    };
    struct POD2
    {
        int iVal = 12;
        double dVal;
        Data data;
    };

    // iVal is dan 12, dVal is dan 0, en val in Data is 100
    POD2 *pp = new POD2[5]();

    // first 3 elements are 1, 2, 3, the last 2 are 0
    new int[5](1, 2, 3);

}
