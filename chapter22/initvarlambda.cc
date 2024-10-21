/*
* Er wordt hier gekeken naar de value 1, dit definieert het type voor value
*/

auto fun = [value = 1] 
    {
        return value;
    };


/*
* Een std::unique_ptr heeft geen assignment, of copy constructor
* het enige dat kan is een move assignment, of move constructor
* Normaal is dit een probleem met een lambda als we de capture by value willen doen
* Een oplossing nu is een expressie in de capture te zetten.
* Door de std::move kunnen we value 'copieren' door een move constructor op te roepen
* die wel ondersteund is door std::unique_ptr
*/
std::unique_ptr<int> ptr(new int(10));
auto fun = [value = std::move(ptr)] 
            {
                return *value;
            };

            