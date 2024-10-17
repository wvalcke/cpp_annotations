template <typename Type, size_t Size>
Type sum(Type const (&array)[Size])
{
    Type tp{};  // note: the default constructor must exist.

    for (size_t idx = 0; idx < Size; idx++)
        tp += array[idx];

    return tp;
}


// function prevalence rule
Type tp(Type()) 

Type() wordt gezien als Type (*) ()
Dus een pointer naar een functie die geen argumenten heeft en een Type retourneert
Type tp(Type()) wordt gezien als een functie tp die een pointer naar een functie heeft als argument (zie boven)
en Type retourneert.

Wat met ?

Type tp = Type(); 
Hier kan tp niet geassigneerd worden aan een pointer naar een funtie. Dus wordt Type() niet als Type (*)() gezien
(geen function prevalance rule mogelijk)
Hier wordt dus tp een default constucted Type

