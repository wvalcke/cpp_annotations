        #include <iostream>

        struct Cons
        {
            Cons()
            {
                std::cout << "Cons called\n";
            }
        };
        void called(char const *time)
        {
            std::cout << time << "time called() activated\n";
            /*
             * Geloof het of niet, maar de initialisatie van deze static zal enkel in 1 thread gebeuren
             * Dit is vastgelegd in de C++11 standaard
             */
            static Cons cons;
        }
        int main()
        {
            std::cout << "Pre-1\n";
            called("first");
            called("second");
            std::cout << "Pre-2\n";
            Cons cons;
        }
    /*
        Displays:
            Pre-1
            firsttime called() activated
            Cons called
            secondtime called() activated
            Pre-2
            Cons called
    */
