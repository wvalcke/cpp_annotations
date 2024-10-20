/*
* Bij de lambda hebben we een it parameters, maar we weten niet wat het type hier is
* We willen dat de 2e parameter value van het type typevanit::ValueType is
* maw it moet een type zijn waarbij <type>::ValueType bestaat
* via decltype(it) weten we al het type, maar in dit geval is dit al een referentie naar ...
* Ook zou it een referentie naar een const kunnen zijn
* Via decay_t kunnen we het effective type te weten komen, zonder const, ref, volatile, ...
*/

auto generic = 
[](auto &it, 
    typename std::decay_t<decltype(it)>::ValueType value)
{
    using Type = std::decay_t<decltype(it)>;
    typename Type::ValueType val2{ value };
    Type::staticMember();
};


/*
* Zelfde lambda implementatie, maar hier effectief als een template
* Voordeel is nu dat we it zijn type nu direct hebben via de template parameter
* We hebben dus decay_t & decltype hier niet nodig
* Let op de template header moet direct na de lambda introducer [] komen
*/
auto generic = 
[]<typename Type>(Type &it, typename Type::ValueType value)
{
    typename Type::ValueType val2{ value };
    Type::staticMember();
};
