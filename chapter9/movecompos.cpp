/*
* This is not correct, tmp.dname is not an anonymous object anymore, so the 
* move constructor for d_name and d_address will not be called
*/

Person::Person(Person &&tmp)
    :
        d_name(tmp.d_name),
        d_address(tmp.d_address)
    {}


/*
* The solution is
*/    

Person::Person(Person &&tmp)
    :
        d_name( std::move(tmp.d_name) ),
        d_address( std::move(tmp.d_address) )
    {}

/*
* in this example callee with the rvalue reference will be called
* But calling fun will use the Class const& version
* The reason is that tmp is a named rvalue inside callee, so it is not
* anonymous anymore
* If the compiler would have called fun(Class&&) version, then it might
* be possible that fun would have taken over the anonymous object 
* but the callee method could even use tmp later on and maybe call 
* another time fun(tmp), but at this moment tmp would be gone
* that's the reason why the compiler chooses to use the Class const& version of fun
* If you really want to let it call the fun(Class&&) then do
* fun(std::move(tmp));            // last call!
* But beware not to use tmp after this call.
*/
Class factory();

void fun(Class const &other);   // a
void fun(Class &&tmp);          // b

void callee(Class &&tmp)
{
    fun(tmp);                   // 1
}

int main()
{
    callee(factory());
}
