//

int b = 18;
{
    // this is seen as Data b; (not an anonymous object Data created with value of b)
    Data(b);
    cout << b;
}


Data (*d4)(int);    // d4 is pointer to function taking int and return Data type
Data (*d5)(3);      // Seen as Data (*d5) = 3 or also as Data* d5 = 3;

// d5 is eigenlijk Data* d5 = &d1;
Data (*d5)(&d1);      // 2


// check eens volgende ??
// Likewise, if int x has been defined, `Data b1(int(x))' declares b1 as a function, 
// expecting an int (as int(x) represents a type), 
// -> int(x) x is geen type (het is een variable), dus hebben we int x (haakjes mogen weg)
// vandaar is dus b1 functie met int als argument

// while `Data b2((int)x)' defines b2 as a Data object, 
// using the constructor expecting a single int value.



//  int process(int Data);
// process is functie met een int argument

// int process(int (Data));
// process is functie met een pointer naar een functie met als argument Data
// en return value int

//  int process(int Data[10]);
// process is functie met als argument een array van int

// int process(int (Data[10]));
// process is een functie met als argument een pointer naar functie die een Data array als argument
// heeft en int terug geeft

// Summary:

/*
 * The compiler will try to remove superfluous parentheses;
 * But if the parenthesized construction represents a type, it will try to use the type;
 * More in general: when possible the compiler will interpret a syntactic construction as a 
 *   declaration, rather than as a definition (of an object or variable).
 * Most problems that result from the compiler interpreting constructions as declarations are 
 *   caused by us using parentheses. As a rule of thumb: use curly braces, rather than parentheses 
 *   when constructing objects (or values).
 */

