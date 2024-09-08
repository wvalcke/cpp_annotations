// beide zijn equivalent

int constexpr change10(int n)
{
    return [n] 
            { 
                return n > 10 ? n - 10 : n + 10; 
            }();
}

// constexpr mag hier weg want de lambda is gedefinieerd in een constexpr functie
// door dat constexpr in de lambda staat, moeten wel de () gezet worden (hierboven was dit niet nodig)

int constexpr change10(int n)
{
    return [n] () constexpr  
            { 
                return n > 10 ? n - 10 : n + 10; 
            }();
}

/*
* If there are multiple return statements returning values of different types then the lambda expression's 
* return type must explicitly be specified using a late-specified return type
*/

 [](bool neg, double y) -> int
    {
        return neg ? -y : y;
    }
